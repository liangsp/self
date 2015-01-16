#include "lp_time.h"
#include <ctime>

#if defined(_MSC_VER)
static struct tm *localtime_r(const time_t *clock,struct tm *res)
{
	localtime_s(res,clock);
	return(res);
}
#endif

/*!
*******************************************************************************
*   @brief  ±º‰¿‡
*******************************************************************************
*/
std::string COsTime::now()
{
	const char * format = "%Y-%m-%d %H:%M:%S";
	return Format(format);
}

std::string COsTime::Format(const char* format)
{
	std::string s;
	time_t lVal;
	struct tm local_time;
	//struct timeval time_stamp;
	char buffer[128] = {0x00};

	time(&lVal);

	if(NULL != localtime_r(&lVal,&local_time))
	{
		if (strftime(buffer, 128, format, static_cast<const struct tm *>(&local_time)) > 0)
			s = buffer;
	}

	return s;
}

std::string COsTime::GetCurrentTime()
{
	const char * format = "%Y%m%d%H%M%S";
	return Format(format);
}

std::string COsTime::GetYear()
{
	const char * format = "%Y";
	return Format(format);
}

std::string COsTime::GetMonth()
{
	const char * format = "%m";
	return Format(format);
}


std::string COsTime::GetWeekDay()
{
	const char * format = "%A";
	return Format(format);
}