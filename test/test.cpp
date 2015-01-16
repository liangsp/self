#include "test.h"
#include "UtilityInc.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#if defined(_MSC_VER)
#pragma warning(disable:4996) 
#endif

void test1()
{
	/*g_count = 0;*/
	const char * name = "LIANGSP";
	char * buffer = newLowerString(name);
	printf("name = %s\n",buffer);
	eFree(buffer);
}

void test_trim()
{
	const char * name = "  liangsp    ";
	char buffer[32] = {0x00};

	strncpy(buffer, name, sizeof(buffer)-1);

	trim(buffer,strlen(buffer));

	printf("buffer = |%s|\n", buffer);
}

void test_callback(void * p, int n)
{
    switch(n)
    {
    case 1:
        {
            const char * buffer = "OUT!";
            TAGSTUDENT *pArg = (TAGSTUDENT*)p;
            memcpy(pArg->szOut,buffer,strlen(buffer));
            printf("|%d-%s|\n",pArg->id,pArg->szName);
        }
        break;

    case 2:
        {
            printf("|nothing|\n");
        }
        break;

    default:break;
    }
}

void test_function_pointer(PFUNC xCallback,void *pArg)
{
    enum{FIRST = 1, SECOND = 2};
    xCallback(pArg,FIRST);
    xCallback(pArg,SECOND);
}

void test_xor()
{
    unsigned test = 0;

    test |= LS_AM;//二进制 第一位 置1
    test |= LS_PM;//二进制 第二位 置1
    test |= LS_WM;//二进制 第三位 置1

    //int tmp = test & LS_PM;
    if (test & LS_PM)//测试该位是否为1
    {
        test ^= LS_PM;//该位置0
    }
    bool b = false;
}

void test_type_convert()
{
    int i = 0;
    Integer nInteger(20);

    i = nInteger;//nInteger是Integer类型，这里直接把Integer类型转换为int，然后赋值给i 
    //如果没有重载了int()，需要类型转换的话，这里必须写成 i2 = (int)nInteger;  
}

void test_const()
{
    char buffer[64] = {0x00};

    strcpy(buffer,"hello");

    char *p1 = buffer;//非const指针，非const数据
    char * const p2 = buffer;//const指针，非const数据
    const char * p3 = buffer;//非const指针，const数据
    const char * const p4 = buffer;//const指针，const数据

    p3 = p1;
    *p2 = 'W';

    printf("p2 = %s\n",p2);
}

void test_stl()
{
    const char *keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default", 
        "do",
        "double", "else", "enum", "extern", "float", "for", "goto", 
        "if",
        "int", "long", "register", "return", "short", "signed", "sizeof", 
        "static",
        "struct", "switch", "typedef", "union", "unsigned", "void", "volatile",
        "while"
    };

    CHashtable<CInt32Helper,string> myhashtable;

    int num = sizeof(keywords)/sizeof(keywords[0]);
    for (int i=0; i<sizeof(keywords)/sizeof(keywords[0]); ++i)
    {
        string s(keywords[i]);
        myhashtable.put(i,s);
    }

    string h("hello world");
    myhashtable.put(3*num+8,h);

    string *str = myhashtable.get(18);
    cout << (*str).c_str() << endl;

    //unsigned int uint_max = ((1<<32) - 1);

    std::minus<int> m;
    cout << m(5,3) << endl;
    cout << std::multiplies<int>()(6,5) << endl;

    std::vector<int> myvector;
    myvector.push_back(11);
    myvector.push_back(12);
    myvector.push_back(13);
    myvector.push_back(14);
    myvector.push_back(15);
    std::for_each(myvector.begin(),myvector.end(),minus2<int>());
    std::for_each(myvector.begin(),myvector.end(),display<int>());
}

unsigned int test_lower_bound(unsigned int val)
{
    enum { NUM_PRIMES = 28 };

    static const unsigned int prime_list[NUM_PRIMES] =
    {
        53u,         97u,         193u,       389u,       769u,
        1543u,       3079u,       6151u,      12289u,     24593u,
        49157u,      98317u,      196613u,    393241u,    786433u,
        1572869u,    3145739u,    6291469u,   12582917u,  25165843u,
        50331653u,   100663319u,  201326611u, 402653189u, 805306457u, 
        1610612741u, 3221225473u, 4294967291u
    };

    const unsigned int* __first = prime_list;
    const unsigned int* __last  = prime_list + (int)NUM_PRIMES;
    const unsigned int* __middle; 
    int __length = (int)NUM_PRIMES;
    int __half = 0;

    while(__length>0)
    {
        __half = __length >> 1;
        __middle = __first;
        __middle += __half;
        if (*__middle < val)
        {
            __first = __middle;
            ++__first;
            __length = __length - __half - 1;
        }
        else
        {
            __length = __half;
        }
    }

    __first = (__first == __last) ? (__last - 1) : (__first);

    return (*__first);
}


