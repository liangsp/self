#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdarg.h>
#include <time.h>
#if defined(__LINUX_)
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#endif

#include "lp_log.h"

#if defined(_MSC_VER)
//#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable:4996) //È«²¿¹Øµô
#endif

#if defined(_MSC_VER)
static struct tm *localtime_r(const time_t *clock,struct tm *res)
{
	localtime_s(res,clock);
	return(res);
}

//int gettimeofday(struct timeval *tp,struct timezone *tz)
//{
//	SYSTEMTIME st;
//
//	if (tp!=NULL) 
//	{
//		tp->tv_sec = _time32(NULL);
//		GetLocalTime(&st);
//		tp->tv_usec = 1000L * st.wMilliseconds;
//	}
//
//	return(0);
//}
#endif

static void zc_time(char *time_str, size_t time_str_size)
{
    time_t tt;
    struct tm local_time;
   //struct timeval time_stamp;

    time(&tt);
    localtime_r(&tt, &local_time);
    //gettimeofday(&time_stamp, NULL);
#ifdef _MSC_VER
	strftime(time_str, time_str_size, "%Y-%m-%d %H:%M:%S", &local_time);
#else
	strftime(time_str, time_str_size, "%Y-%m-%d %T", &local_time);
#endif
    //sprintf(time_str+strlen(time_str),":%ld ", time_stamp.tv_usec);

    return;
}

int log_inner(LOG_FLAG_E flag, const char *file, const long line, const char *fmt, ...)
{
    va_list args;
    char time_str[32 + 1];
    FILE *fp = NULL;
    static char *debug_log = NULL;
    static char *error_log = NULL;
    static size_t init_flag = 0;
    
    if(!init_flag)
    {
        init_flag = 1;

#if defined(_MSC_VER)
		debug_log = getenv("LOG_DEBUG");
#else
        debug_log = getenv("LOG_DEBUG");
#endif

		if (NULL == debug_log)
		{
#if defined(_MSC_VER)
            _putenv("LOG_DEBUG=D:\\tmp\\lp_debug.log");
			debug_log = getenv("LOG_DEBUG");
#else      
			putenv("LOG_DEBUG=D:\\tmp\\lp_debug.log");
			debug_log = getenv("LOG_DEBUG");
#endif
		}
#if defined(_MSC_VER)
		error_log = getenv("LOG_ERROR");
#else
		error_log = getenv("LOG_DEBUG");
#endif
		if (NULL == error_log)
		{
#if defined(_MSC_VER)
            _putenv("LOG_ERROR=D:\\tmp\\lp_error.log");
			error_log = getenv("LOG_ERROR");
#else      
            putenv("LOG_ERROR=D:\\tmp\\lp_error.log");
			error_log = getenv("LOG_ERROR");
#endif
		}
    }
    
    switch(flag)
    {
        case LOG_DEBUG:
            if(debug_log == NULL)
            {
                fp = stdout;
            }
            else
            {
                fp = fopen(debug_log, "a");
            }
            if(!fp)
            {
                return -1;
            }
            zc_time(time_str, sizeof(time_str));
#if !defined(_MSC_VER)
			fprintf(fp, "%s DEBUG (%d:%s:%ld): ", time_str, getpid(), file, line);
#else
			fprintf(fp, "%s DEBUG (%s:%ld): ", time_str, file, line);
#endif
            break;
        
        case LOG_WARN:
            if(error_log == NULL)
            {
                fp = stdout;
            }
            else
            {
                fp = fopen(error_log, "a");
            }
            if(!fp)
            {
                return -1;
            }
            zc_time(time_str, sizeof(time_str));
#if !defined(_MSC_VER)
            fprintf(fp, "%s WARN  (%d:%s:%ld): ", time_str, getpid(), file, line);
#else
			fprintf(fp, "%s WARN (%s:%ld): ", time_str, file, line);
#endif
            break;
        
        case LOG_ERROR:
            if(error_log == NULL)
            {
                fp = stdout;
            }
            else
            {
                fp = fopen(error_log, "a");
            }
            if(!fp)
            {
                return -1;
            }
            zc_time(time_str, sizeof(time_str));
#if defined(_MSC_VER)
			fprintf(fp, "%s ERROR (%s:%ld): ", time_str, file, line);
#else
			fprintf(fp, "%s ERROR (%d:%s:%ld): ", time_str, getpid(), file, line);
#endif
            break;
    }
    /* writing file twice(time & msg) is not atomic
     * may cause cross
     * but avoid log size limit */
    va_start(args, fmt);
    vfprintf(fp, fmt, args);
    va_end(args);
    fprintf(fp, "\n");
    if(debug_log != NULL || error_log != NULL)
    {
        fclose(fp);
    }

    return 0;
}

