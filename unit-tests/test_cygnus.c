#include <string.h>
#include <ctype.h>

#include "cu_test.h"


/* 
 * void cu_assert(cu_test* tc, char* message, int condition);
 * void cu_assert_true(cu_test* tc, int condition);
 * void cu_assert_str_equals(cu_test* tc, char* expected, char* actual);
 * void cu_assert_int_equals(cu_test* tc, int expected, int actual);
 * void cu_assert_ptr_equals(cu_test* tc, void* expected, void* actual);
 * void cu_assert_ptr_not_null(cu_test* tc, void* pointer);
 * 
 * 
 */


void test_test(cu_test_t *tc);

cu_suite_t* test_vector_get_suite() {
	cu_suite_t* suite = cu_suite_new();
	
	SUITE_ADD_TEST(suite, test_test	);
	
	return suite;
}

void test_test(cu_test_t *tc) {
	cu_assert_int_equals(tc, 1, 1);
}