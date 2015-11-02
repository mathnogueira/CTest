#include <ctest/core.h>
#include <ctest/suite.h>
#include <ctest/mode/textmode.h>
#include <ctest/structure/queue.h>

// Private pointer that points to the TestSuite used in the application.
// It will be initializated when the fist call of CTest_Init happens.
static struct CTest_TestSuite* suite = NULL;

// Start the Testing Suite
struct CTest_TestSuite* CTest_Init() {
    if (suite == NULL) {
        suite = (struct CTest_TestSuite*) malloc(sizeof(struct CTest_TestSuite));
        CTest_TestSuite_Init(suite);
    }
    return suite;
}

// Define the mode of the test suite
void CTest_SetMode(struct CTest_TestSuite* suite, enum CTest_Mode mode) {
    switch(mode) {
        case TEXT:
            suite->output = CTest_Output_Text;
    }
}

// Add a new test to the suite queue.
void CTest_Add(struct CTest_TestSuite* suite, CTest_Function function, const char* fnName) {
    struct CTest_FunctionMap* fnMap = (struct CTest_FunctionMap*) malloc(sizeof(struct CTest_FunctionMap));
    fnMap->function = function;
    fnMap->name = fnName;
    struct CTest_FQueue* queue = suite->testsQueue;
    CTest_FQueue_Add(queue, fnMap);
    suite->numberTests += 1;
}
