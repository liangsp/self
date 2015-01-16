/*!
 * =====================================================================================
 *    @file:    lp_log.h
 *    @brief:   简单的日志描述功能
 *				如果有环境变量 LOG_DEBUG 和 LOG_ERROR ，则写入文件；否则输出到控制台
 *				例如：LOG_DEBUG = ~/log.txt
 *    @author:  梁世平 (liangsp), shiping.liang@autonavi.com
 *    @version: 1.0
 *    @date:    修订说明：
 *              1.0-2013.08.02-shiping.liang-创建
 * =====================================================================================
 */
#ifndef _PROFILE_INC_
#define _PROFILE_INC_

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum log_flag_e
{
	LOG_DEBUG = 0,
	LOG_WARN  = 1,
	LOG_ERROR = 2
}LOG_FLAG_E;


#if defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L

	#define log_debug(...) \
		log_inner(LOG_DEBUG, __FILE__, __LINE__, __VA_ARGS__)
	#define log_warn(...) \
		log_inner(LOG_WARN, __FILE__, __LINE__, __VA_ARGS__)
	#define log_error(...) \
		log_inner(LOG_ERROR, __FILE__, __LINE__, __VA_ARGS__)
	#define log_profile(flag, ...) \
		log_inner(flag, __FILE__, __LINE__, __VA_ARGS__)

#elif defined __GNUC__

	#define log_debug(fmt, args...) \
		log_inner(LOG_DEBUG, __FILE__, __LINE__, fmt, ## args)
	#define log_warn(fmt, args...) \
		log_inner(LOG_WARN, __FILE__, __LINE__, fmt, ## args)
	#define log_error(fmt, args...) \
		log_inner(LOG_ERROR, __FILE__, __LINE__, fmt, ## args)
	#define log_profile(flag, fmt, args...) \
		log_inner(flag, __FILE__, __LINE__, fmt, ## args)

#else

	#define log_debug(fmt, ...) \
		log_inner(LOG_DEBUG, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
	#define log_warn(fmt, ...) \
		log_inner(LOG_WARN, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
	#define log_error(fmt, ...) \
		log_inner(LOG_ERROR, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
	#define log_profile(flag, fmt, ...) \
		log_inner(flag, __FILE__, __LINE__, fmt, ##__VA_ARGS__)

#endif


int log_inner(LOG_FLAG_E flag, 
		const char *file, const long line,
		const char *fmt, ...);

#ifdef __cplusplus
}
#endif

#endif
