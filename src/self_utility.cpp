/*!
 * =====================================================================================
 *
 * Copyright © 2013, AutoNavi Software Co., Ltd.
 *
 *    文件名: lp_utility.cpp 
 *      作者: 梁世平 (liangsp), shiping.liang@autonavi.com
 *  创建日期: 2013年07月24日
 *
 *  内容描述:
 *  修改日志:
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "self_utility.h"

static const char LINE_FEED				= (char)0x0a;			
static const char LF = LINE_FEED;
static const char CARRIAGE_RETURN		= (char)0x0d;			
static const char CR = CARRIAGE_RETURN;
static const char SPACES				= (char)0x20;
static const char SP = SPACES;
static const char HORIZONTAL_TEXT	    = (char)0x09;
static const char HT = HORIZONTAL_TEXT;

/*!
 ****************************************************************************************
 *  Memory allocation functions
 ****************************************************************************************
 */
extern void *eMalloc(const size_t size)
{
    void *buffer = malloc(size);
    if(buffer == NULL)
    {
        fprintf(stderr, "%s\n", "Fatal: out of memory");
    }
    return buffer;
}

extern void *eCalloc(const size_t count, const size_t size)
{
    void *buffer = calloc(count, size);
    if(buffer == NULL)
    {
        fprintf(stderr, "%s\n", "Fatal: out of memory");
    }
    return buffer;
}

extern void *eRealloc(void *const ptr, const size_t size)
{
    void *buffer;
    if(ptr == NULL)
    {
        buffer = eMalloc(size);
    }
    else
    {
        buffer = realloc(ptr, size);
        if(buffer == NULL)
        {
            fprintf(stderr, "%s\n", "Fatal: out of memory");
        }
    }
    return buffer;
}

extern void eFree(void * const ptr)
{
    if(ptr != NULL)
    {
        free(ptr);
    }
}


extern void toLowerString(char *str)
{
    assert(str != NULL);

    while(*str != '\0')
    {
        *str = tolower((int) * str);
        ++str;
    }
}

extern void toUpperString(char *str)
{
    assert(str != NULL);

    while(*str != '\0')
    {
        *str = toupper((int) * str);
        ++str;
    }
}


/*  Newly allocated string containing lower case conversion of a string.
 */
extern char *newLowerString(const char *str)
{
    assert(str != NULL);

    int i = 0;
    char *const result = xMalloc(strlen(str) + 1, char);
    do
    {
        result[i] = tolower((int)str[i]);
    }while(str[i++] != '\0');

    return result;
}

/*  Newly allocated string containing upper case conversion of a string.
 */
extern char *newUpperString(const char *str)
{
    assert(str != NULL);

    int i = 0;
    char *const result = xMalloc(strlen(str) + 1, char);
    do
    {
        result[i] = toupper((int)str[i]);
    }while(str[i++] != '\0');

    return result;
}

char* trimLeft(char *str, int length)
{
    if (*str == '\0' || length == 0 || str == NULL) return NULL;

    int index = 0;
    char *pTemp = NULL;
    char *start = NULL;
    
    pTemp = new char[length+1];
    memset(pTemp,0x00,length+1);
    memcpy(pTemp,str,length);

    start = pTemp;
    while (SP == (*start) || HT == (*start))
    {
        start ++;
    }

    memcpy(str,start,strlen(start));
    str[strlen(start)] = '\0';

    delete [] pTemp;

	return str;
}

char* trimRight(char *str, int length)
{
	if (*str == '\0' || length == 0 || str == NULL) return NULL;
    
    char *end = NULL;
    end = str + length - 1;

    while (SP == *end || HT == *end)
	{
		*end = '\0';
        if (end == str) break;
        end--;
	}

	return str;
}

char* trim(char *str, int length)
{
    char *s = NULL; 
    s = trimLeft(str,length);
    s = trimRight(str,strlen(s));

    return s;
}
