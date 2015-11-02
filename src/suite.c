#include <ctest/suite.h>
#include <ctest/test.h>
#include <ctest/types.h>
#include <ctest/structure/queue.h>
#include <stdio.h>

/* Initialize the suite using its default values. */
void CTest_TestSuite_Init(struct CTest_TestSuite* testSuite) {
    testSuite->numberTests = 0;
    testSuite->numberFinishedTests = 0;
    testSuite->numberFailTests = 0;
    testSuite->testsQueue = CTest_FQueue_New();
    testSuite->errors = CTest_Queue_New();
}

/* Run all the tests in the suite. */
void CTest_TestSuite_Run(struct CTest_TestSuite* testSuite) {
    unsigned int i = 0;
    struct CTest_FQueue* queue = testSuite->testsQueue;
    struct CTest_Test* test;
    /* Iterate through the queue of tests */
    for (; i < testSuite->numberTests; ++i) {
        test = CTest_Test_New();
        struct CTest_FunctionMap* map = CTest_FQueue_Pop(queue);
        test->result->funcName = map->name;
        map->function(test);
        testSuite->numberFinishedTests += 1;
        if (test->status == FALSE) {
            /* Test has failed */
            testSuite->numberFailTests += 1;
            CTest_Queue_Add(testSuite->errors, (void*) test->result);
        }
    }
    /* Print results */
    testSuite->output(testSuite);
}
