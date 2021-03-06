/**
 * File containing all the basic structures to create Unit tests for your
 * application.
 *
 * @author Matheus Nogueira
 * @version 1.0
 */
#ifndef CORE_H
#define CORE_H

#include <ctest/types.h>
#include <ctest/suite.h>
#include <ctest/test.h>
#include <stdlib.h>

/* Version of the library */
#define VERSION "1.0.2"

/**
 * List of modes available in the current version.
 */
enum CTest_Mode {
    TEXT,           /** Prints the result on the terminal. */
    EXTERNAL,       /** Send data to another function defined by the user. */
};

/**
 * Return a reference to a TestSuite.
 *
 * Note that if you invoke this function several times, it will always
 * return the same object.
 *
 * @return reference to a TestSuite.
 */
struct CTest_TestSuite* CTest_Init();

/**
 * Set the mode that the suite will show the results to the user.
 * @param mode mode that will be used to show the data to the user.
 */
void CTest_SetMode(struct CTest_TestSuite* testSuite, enum CTest_Mode mode);

/**
 * Set the function that will be called right after all the tests finish
 * running. That way the programmer can know if the software is broken in
 * a programatic way.
 *
 * @param suite pointer to the test suite.
 * @param function pointer the the external function.
 */
void CTest_SetExternalListener(struct CTest_TestSuite* suite, CTest_OutputFn function);

/**
 * Add a test to the queue of tests that must be asserted at the beginning
 * of the execution of the application.
 *
 * @param suite reference to the TestSuite object.
 * @param function pointer to the test function.
 * @param fnName name of the function (optional).
 * @return void
 */
void CTest_Add(struct CTest_TestSuite* suite, CTest_Function function, const char* fnName);
#endif
