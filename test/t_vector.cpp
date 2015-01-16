#include <vector>
#include <iostream>
#include <algorithm>
#include "t_vector.h"
#include "self_log.h "

using namespace std;

void test_vector()
{
    SELF_TRACE_MATHOD("test_vector");
    
	vector<int> iv(101,9);
    vector<int>::size_type index = 0;
    for (;index < iv.size(); ++index)
    {
        SELF_FATAL("iv size = %d, capacity = %d", iv.size(), iv.capacity());
        SELF_ERROR("iv size = %d, capacity = %d", iv.size(), iv.capacity());
        SELF_WARN("iv size = %d, capacity = %d", iv.size(), iv.capacity());
        SELF_INFO("iv size = %d, capacity = %d", iv.size(), iv.capacity());
        SELF_DEBUG("iv size = %d, capacity = %d", iv.size(), iv.capacity());
        SELF_TRACE("iv size = %d, capacity = %d", iv.size(), iv.capacity());
    }
}