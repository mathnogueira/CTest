#include <ctest/test.h>
#include <ctest/types.h>
#include <stdlib.h>

struct CTest_Test* CTest_Test_New() {
    return (struct CTest_Test*) malloc(sizeof(struct CTest_Test));
}


void CTest_Test_Fail(struct CTest_Test* test, const char* err) {
    test->status = FALSE;
    test->errMsg = err;
}

void CTest_Test_Success(struct CTest_Test* test) {
    test->status = TRUE;
}
