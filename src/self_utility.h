/*!
 * =====================================================================================
 *    @file:    self_utility.h
 *    @brief:   基本操作头文件
 *    @author:  梁世平 (liangsp), shiping.liang@autonavi.com
 *    @version: 1.0
 *    @date:    修订说明：
 *              1.0-2013.07.24-shiping.liang-创建
 * =====================================================================================
 */

#ifndef __UTILITY_INC_
#define __UTILITY_INC_

#ifdef __cplusplus
extern "C" {
#endif

#ifdef   OS_GLOBALS
#define  OS_EXT
#else
#define  OS_EXT  extern
#endif

OS_EXT int g_count;//test

/*!
 ****************************************************************************************
 *  MACROS
 ****************************************************************************************
 */
#undef c_max
#define c_max(a,b) ((a) > (b) ? (a) : (b))

#undef c_min
#define c_min(a,b) ((a) < (b) ? (a) : (b))


#define xMalloc(n,Type)    (Type *)eMalloc((size_t)(n) * sizeof (Type))
#define xCalloc(n,Type)    (Type *)eCalloc((size_t)(n), sizeof (Type))
#define xRealloc(p,n,Type) (Type *)eRealloc((p), (n) * sizeof (Type))


/*!
 ****************************************************************************************
 *  FUNCTION PROTOTYPES
 ****************************************************************************************
 */
OS_EXT void* eMalloc(const size_t size);
OS_EXT void* eCalloc(const size_t count, const size_t size);
OS_EXT void* eRealloc(void *const ptr, const size_t size);
OS_EXT void  eFree(void * const ptr);


OS_EXT void  toLowerString(char *str);
OS_EXT void  toUpperString(char *str);
OS_EXT char* newLowerString(const char *str);
OS_EXT char* newUpperString(const char *str);


char* trimLeft(char *str, int length);
char* trimRight(char *str, int length);
char* trim(char *str, int length);


#ifdef __cplusplus
}
#endif

#endif //__UTILITY_INC_
