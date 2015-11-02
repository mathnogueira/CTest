#include <ctest/core.h>
#include <ctest/test.h>
#include <ctest/mode/textmode.h>
#include <stdio.h>

/* Prints the output in the common output (cout) */
void CTest_Output_Text(const struct CTest_TestSuite* suite) {
    printf("CTest v%s -- Unit Test for C\n\n", VERSION);
    printf("Number of tests: %d\t\t", suite->numberTests);
    printf("Number of failed tests: %d\n", suite->numberFailTests);
    if (suite->numberFailTests > 0) {
        unsigned int i = 0;
        for (; i < suite->numberFailTests; ++i) {
            struct CTest_TestResult* result = (struct CTest_TestResult*) CTest_Queue_Pop(suite->errors);
            printf(">> %s --> %s\n", result->funcName, result->errMsg);
        }
    }
}
