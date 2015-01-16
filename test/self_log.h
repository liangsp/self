#ifndef __SELF_LOG_H
#define __SELF_LOG_H

#define SELF_LOG_ENABLE

#if defined(SELF_LOG_ENABLE)

#include <log4cplus/logger.h>  
#include <log4cplus/consoleappender.h> 
#include <log4cplus/fileappender.h>
#include <log4cplus/layout.h> 
#include <log4cplus/loggingmacros.h> 
#include <log4cplus/configurator.h>

#pragma comment(lib,"log4cplusSD.lib")

#define __BUFF_SIZE__  2049

extern log4cplus::Logger g_self_logger;

void self_log_make_str(char * out, int len, const char *fmt, ...);

#define SELF_LOG_INIT()                                                    \
    do {                                                                   \
        log4cplus::PropertyConfigurator::doConfigure("config.properties"); \
        g_self_logger = log4cplus::Logger::getInstance("selfLog");         \
    } while (0)

#define SELF_TRACE_MATHOD(mathod)                                          \
        LOG4CPLUS_TRACE_METHOD(g_self_logger, mathod)                      \

#define SELF_FATAL(fmt, ...)                                               \
    do {                                                                   \
        char buffer[__BUFF_SIZE__] = {0};                                  \
        self_log_make_str(buffer, __BUFF_SIZE__ - 1, fmt, ##__VA_ARGS__);  \
        LOG4CPLUS_FATAL(g_self_logger, buffer);                            \
    } while (0)

#define SELF_ERROR(fmt, ...)                                               \
    do {                                                                   \
        char buffer[__BUFF_SIZE__] = {0};                                  \
        self_log_make_str(buffer, __BUFF_SIZE__ - 1, fmt, ##__VA_ARGS__);  \
        LOG4CPLUS_ERROR(g_self_logger, buffer);                            \
    } while (0) 

#define SELF_WARN(fmt, ...)                                                \
    do {                                                                   \
        char buffer[__BUFF_SIZE__] = {0};                                  \
        self_log_make_str(buffer, __BUFF_SIZE__ - 1, fmt, ##__VA_ARGS__);  \
        LOG4CPLUS_WARN(g_self_logger, buffer);                             \
    } while (0) 

#define SELF_INFO(fmt, ...)                                                \
    do {                                                                   \
        char buffer[__BUFF_SIZE__] = {0};                                  \
        self_log_make_str(buffer, __BUFF_SIZE__ - 1, fmt, ##__VA_ARGS__);  \
        LOG4CPLUS_INFO(g_self_logger, buffer);                             \
    } while (0) 

#define SELF_DEBUG(fmt, ...)                                               \
    do {                                                                   \
        char buffer[__BUFF_SIZE__] = {0};                                  \
        self_log_make_str(buffer, __BUFF_SIZE__ - 1, fmt, ##__VA_ARGS__);  \
        LOG4CPLUS_DEBUG(g_self_logger, buffer);                            \
    } while (0) 

#define SELF_TRACE(fmt, ...)                                               \
    do {                                                                   \
        char buffer[__BUFF_SIZE__] = {0};                                  \
        self_log_make_str(buffer, __BUFF_SIZE__ - 1, fmt, ##__VA_ARGS__);  \
        LOG4CPLUS_TRACE(g_self_logger, buffer);                            \
    } while (0) 

#else

#define SELF_LOG_INIT()            do {} while (0)

#define SELF_TRACE_MATHOD(mathod)  do {} while (0)

#define SELF_FATAL(fmt, ...)       do {} while (0)

#define SELF_ERROR(fmt, ...)       do {} while (0)

#define SELF_WARN(fmt, ...)        do {} while (0) 

#define SELF_INFO(fmt, ...)        do {} while (0) 

#define SELF_DEBUG(fmt, ...)       do {} while (0)

#define SELF_TRACE(fmt, ...)       do {} while (0) 

#endif


#if defined(SELF_LOG_FUNCTION)
#define SELF_FATAL(fmt, ...) \
	self_log_fatal(fmt, ##__VA_ARGS__)

#define SELF_ERROR(fmt, ...) \
	self_log_error(fmt, ##__VA_ARGS__)

#define SELF_WARN(fmt, ...) \
	self_log_warn(fmt, ##__VA_ARGS__)

#define SELF_INFO(fmt, ...) \
	self_log_info(fmt, ##__VA_ARGS__)

#define SELF_DEBUG(fmt, ...) \
	self_log_debug(fmt, ##__VA_ARGS__)

#define SELF_TRACE(fmt, ...) \
	self_log_trace(fmt, ##__VA_ARGS__)

void self_log_init();
void self_log_fatal(const char *fmt, ...);
void self_log_error(const char *fmt, ...);
void self_log_warn(const char *fmt, ...);
void self_log_info(const char *fmt, ...);
void self_log_debug(const char *fmt, ...);
void self_log_trace(const char *fmt, ...);

void test_log4cplus();

#endif//SELF_LOG_FUNCTION

#endif//__SELF_LOG_H



