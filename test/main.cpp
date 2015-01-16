#include "test.h"
#include "self_log.h "
#include "t_vector.h"

int main(int argc, char** argv)
{
	/**< 日志初始化 */
	SELF_LOG_INIT();

    //unsigned int next_prime = test_lower_bound(100663319u + 1u);
    //SELF_INFO("NEXT_PRIME: %d", next_prime);

	test_vector();

    char ch = getchar();
	return 0;
}