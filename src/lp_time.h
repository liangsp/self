/*!
 * =====================================================================================
 *
 * Copyright © 2013, AutoNavi Software Co., Ltd.
 *
 *    文件名: lp_time.h 
 *      作者: 梁世平 (liangsp), shiping.liang@autonavi.com 
 *  创建日期: 2013年12月5日
 *
 *  内容描述: 
 *  修改日志:
 *
 * =====================================================================================
 */

#ifndef TIME_INC_
#define TIME_INC_

#include <string>

/*!
 ********************************************************************************
 *   @brief 时间类，获取时间等操作
 ********************************************************************************
 */
class COsTime
{
public:
    COsTime(){}
    ~COsTime(){}
public:
    /**
    * @brief    获取现在时间  格式为：YYYY-MM-DD HH24:MM:SS
    * @param    无
    * @return   格式为YYYY-MM-DD HH24:MM:SS的字符串
    */
    static std::string now();

    /**
    * @brief    时间格式化
    * @param    [IN]    format 格式输入
    * @return   [OUT]   格式化后字符串
    */
    static std::string Format(const char* format);

    /**
    * @brief    获取现在时间  格式为：YYYYMMDDHH24MMSS
    * @param    无
    * @return   格式为YYYYMMDDHH24MMSS的字符串
    */
    static std::string GetCurrentTime();


    static std::string GetYear();
    static std::string GetMonth();
    static std::string GetWeekDay();
};


#endif//TIME_INC_
