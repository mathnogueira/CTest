#include <ctest/test.h>
#include <ctest/types.h>
#include <stdlib.h>


struct CTest_TestResult* CTest_TestResult_New() {
    struct CTest_TestResult *result = (struct CTest_TestResult*)
        malloc(sizeof(struct CTest_TestResult));
    return result;
}

struct CTest_Test* CTest_Test_New() {
    struct CTest_Test* test = (struct CTest_Test*) malloc(sizeof(struct CTest_Test));
    test->result = CTest_TestResult_New();
    return test;
}


void CTest_Test_Fail(struct CTest_Test* test, const char* err) {
    test->status = FALSE;
    test->result->errMsg = err;
}

void CTest_Test_Success(struct CTest_Test* test) {
    test->status = TRUE;
}
