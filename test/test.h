#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

//////////////////////////////////////////////////////////////////////////
void test1();
void test_trim();

//////////////////////////////////////////////////////////////////////////
typedef struct tagStudent 
{
    enum{NUM = 64};
    int id;
    char szName[NUM];
    char szOut[NUM]; 
}TAGSTUDENT;

typedef void (*PFUNC)(void *,int);
void test_callback(void * p, int n);
void test_function_pointer(PFUNC xCallback,void *pArg);

//////////////////////////////////////////////////////////////////////////

enum
{
    LS_AM = 0X01,
    LS_PM = 0X02,
    LS_WM = 0X04
};

void test_xor();

//////////////////////////////////////////////////////////////////////////
class Integer
{
public:
    Integer(int n):nData(n){}

    Integer& operator=(const int &v)
    {
        nData = v;
        return *this;
    }
    
    //��������ת������������������int i; Integer it;  i = it; itֱ��תΪint���ͣ�Ȼ��ֵ��i 
    operator int()
    {
        return nData;
    }

    void operator()()
    {
        std::cout << "���Ų�����" << std::endl;
    }

private:
    int nData;
};

void test_type_convert();

//////////////////////////////////////////////////////////////////////////
void test_const();
//////////////////////////////////////////////////////////////////////////
//�º�������������
template<class T>
struct display
{
    void operator()(const T &para)
    {
        std::cout << para << std::endl;
    }
};

template<class T>
struct minus2
{
    void operator()(T &para){para -= 2;}
};

void test_stl();

 template<class _inPara, class _outPara>
 class CSum:public std::unary_function<_inPara,_outPara>
 {
 private:
     _outPara __sum;
 
 public:
     CSum(_inPara init = 0)
     {
         __sum = init;
     }
 
     void operator()(_inPara _in)
     {
         __sum += _in;
     }
 
     _outPara getSum()
     {
         return __sum;
     }

     CSum & operator=(const CSum & other)
     {
         __sum = other.__sum;
         return *this;
     }
 };


//////////////////////////////////////////////////////////////////////////
///���ַ�
unsigned int test_lower_bound(unsigned int val);