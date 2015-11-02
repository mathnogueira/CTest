/**
 * File containing the structure used to test a function.
 *
 * This file also contains some operations that can be used inside tests, such
 * as functions to indicate that the test has failed, or succeced.
 *
 * @author Matheus Nogueira
 * @version 1.0
 */
#ifndef CTEST_TEST_H
#define CTEST_TEST_H

#include <ctest/types.h>

/**
 * Structure used to carry information from the test function to the
 * TestSuite, so it can check if the test has failed or succeced.
 */
struct CTest_Test {
    CTest_Boolean status;   ///< Test status: failed = FALSE, succeced = TRUE
    const char* errMsg;
};

/**
 * Create a new test.
 * @return reference to the CTest_Test object.
 */
struct CTest_Test* CTest_Test_New();

/**
 * Indicate that the test has failed.
 * @param test reference to the CTest_Test object.
 * @param err message that will be shown to the user.
 */
void CTest_Test_Fail(struct CTest_Test* test, const char* err);

/**
 * Indicate that the test has succeced.
 * @param test reference to the CTest_Test object.
 */
void CTest_Test_Success(struct CTest_Test* test);

#endif
