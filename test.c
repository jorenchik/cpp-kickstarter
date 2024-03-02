#include "MyLibrary.h"
#include "main_lib.h"
#include "munit.h"
#include <stdio.h>
#include <stdlib.h>

#if defined(_MSC_VER)
#pragma warning(disable : 4127)
#endif

static MunitResult test_should_pass(const MunitParameter params[],
                                    void *user_data) {
    int addition_result;
    addition_result = add(2, 3);
    munit_assert_int(addition_result, ==, 5);
    return MUNIT_OK;
}

static MunitResult test_add_should_fail(const MunitParameter params[],
                                        void *user_data) {
    int addition_result;
    addition_result = add(2, 8);
    munit_assert_int(addition_result, ==, 5);
    return MUNIT_OK;
}

static MunitResult test_one_of_main_functions(const MunitParameter params[],
                                              void *user_data) {
    int addition_result = functionToTest(5);
    munit_assert_int(addition_result, ==, 10);
    return MUNIT_OK;
}

static MunitTest tests_for_test_suite[] = {
    {(char *)"/mylib/addshouldnotfail", test_should_pass, NULL, NULL,
     MUNIT_TEST_OPTION_NONE, NULL},
    {(char *)"/mylib/addshouldfail", test_add_should_fail, NULL, NULL,
     MUNIT_TEST_OPTION_NONE, NULL},
    {(char *)"/main/functiontotest", test_one_of_main_functions, NULL, NULL,
     MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}};

static const MunitSuite test_suite = {(char *)"", tests_for_test_suite, NULL, 1,
                                      MUNIT_SUITE_OPTION_NONE};

int main(int argc, char *argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
    return munit_suite_main(&test_suite, (void *)"µnit", argc, argv);
}
