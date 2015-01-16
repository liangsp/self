#include <cstdarg>
#include "self_log.h "

#if defined(SELF_LOG_ENABLE)
log4cplus::Logger g_self_logger;
void self_log_make_str(char * out, int len, const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
#if defined(_MSC_VER)
    vsprintf_s(out, len, fmt, args);
#else
    vsnprintf(out, len, fmt, args);
#endif
    va_end(args);

    return;
}
#endif

#if defined(SELF_LOG_FUNCTION)
/*!
1. 实例化一个appender对象
2. 实例化一个layout对象
3. 将layout对象绑定(attach)到appender对象
4. 实例化一个logger对象,调用静态函数：log4cplus::Logger::getInstance("logger_name")
5. 将appender对象绑定(attach)到logger对象，如省略此步骤，标准输出（屏幕）appender对象会绑定到logger
6. 设置logger的优先级，如省略此步骤，各种有限级的消息都将被记录
**/

#define LOG4CPLUS_CONFIG_FILE
using namespace std;
using namespace log4cplus;  
using namespace log4cplus::helpers;

#pragma comment(lib,"log4cplusSD.lib")

void self_log_init()
{
#if defined(LOG4CPLUS_CONFIG_FILE)
	PropertyConfigurator::doConfigure("config.properties");
	g_self_logger = Logger::getInstance("self_log");
#endif
}

void self_log_fatal(const char *fmt, ...)
{
    char buffer[__BUFF_SIZE__] = {0};                                  
    self_log_make_str(buffer, __BUFF_SIZE__ - 1, fmt, ##__VA_ARGS__); 
	LOG4CPLUS_FATAL(g_self_logger, buffer); 
}

void self_log_error(const char *fmt, ...)
{
    char buffer[__BUFF_SIZE__] = {0};                                  
    self_log_make_str(buffer, __BUFF_SIZE__ - 1, fmt, ##__VA_ARGS__); 
	LOG4CPLUS_ERROR(g_self_logger, buffer); 
}

void self_log_warn(const char *fmt, ...)
{
    char buffer[__BUFF_SIZE__] = {0};                                  
    self_log_make_str(buffer, __BUFF_SIZE__ - 1, fmt, ##__VA_ARGS__); 
	LOG4CPLUS_WARN(g_self_logger, buffer); 
}

void self_log_info(const char *fmt, ...)
{
    char buffer[__BUFF_SIZE__] = {0};                                  
    self_log_make_str(buffer, __BUFF_SIZE__ - 1, fmt, ##__VA_ARGS__); 
	LOG4CPLUS_INFO(g_self_logger, buffer); 
}

void self_log_debug(const char *fmt, ...)
{
    char buffer[__BUFF_SIZE__] = {0};                                  
    self_log_make_str(buffer, __BUFF_SIZE__ - 1, fmt, ##__VA_ARGS__); 
	LOG4CPLUS_DEBUG(g_self_logger, buffer); 
}

void self_log_trace(const char *fmt, ...)
{
    char buffer[__BUFF_SIZE__] = {0};                                  
    self_log_make_str(buffer, __BUFF_SIZE__ - 1, fmt, ##__VA_ARGS__); 
	LOG4CPLUS_TRACE(g_self_logger, buffer); 
}

void test_log4cplus()
{
    //Priorities：优先权，包括TRACE, DEBUG, INFO, WARN, ERROR, FATAL。
#if defined(LOG4CPLUS_CONFIG_FILE)
    PropertyConfigurator::doConfigure("config.properties");
    Logger logger = Logger::getInstance("log");  
     
    LOG4CPLUS_TRACE_METHOD(logger, "test_log4cplus"); 

    LOG4CPLUS_DEBUG(logger, "This is a DEBUG message cnt = " << 10);  
    LOG4CPLUS_INFO(logger, "This is a INFO message" << 100);  
    LOG4CPLUS_WARN(logger, "This is a WARN message");  
    LOG4CPLUS_ERROR(logger, "This is a ERROR message");  
    LOG4CPLUS_FATAL(logger, "This is a FATAL message"); 
#else
    enum{PATH_MAX_LEN = 256};
    char szPath[PATH_MAX_LEN] = {0};
    GetCurrentDirectory(PATH_MAX_LEN,szPath);

    SharedAppenderPtr pConsoleAppender(new ConsoleAppender);
    pConsoleAppender->setName("test_log4cplus_console");

    //SharedAppenderPtr pAppender(new FileAppender("self.log",LOG4CPLUS_FSTREAM_NAMESPACE::ios::app));
    
    SharedAppenderPtr pFileAppender(new FileAppender("self.log",LOG4CPLUS_FSTREAM_NAMESPACE::ios::app));
    pFileAppender->setName("test_log4cplus_file_log");

    tstring format("%D{%y-%m-%d %H:%M:%S,%q} [%t] %-5p %.16c  - %m [%l]%n");
    std::auto_ptr<Layout> pConsoleLayout(new PatternLayout(format));
    std::auto_ptr<Layout> pFileLayout(new PatternLayout(format));

    pConsoleAppender->setLayout(pConsoleLayout);
    pFileAppender->setLayout(pFileLayout);

    Logger __logger = Logger::getInstance("testlogger");

    __logger.addAppender(pConsoleAppender);
    __logger.addAppender(pFileAppender);

    __logger.setLogLevel(DEBUG_LOG_LEVEL);

    Logger root = Logger::getRoot();
    root.addAppender(pConsoleAppender);
    root.addAppender(pFileAppender);
    SharedObjectPtr
    root.setLogLevel(ERROR_LOG_LEVEL);

    for (unsigned i=1; i<=100; ++i)
    {
        //LOG4CPLUS_DEBUG(root,"Debug infomation! index=" << i << "  " << __logger.getName());
        LOG4CPLUS_DEBUG(__logger,"Debug infomation! index=" << i << "  " << __logger.getName());
    }
#endif   
}

#endif

