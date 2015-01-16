#ifndef __SELF_LOG_H
#define __SELF_LOG_H

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

#endif//__SELF_LOG_H



