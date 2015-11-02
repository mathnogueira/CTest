/**
 * File containing the struct responsible for testing and all of its functions.
 * 
 * @author Matheus Nogueira
 * @version 1.0
 */
#ifndef SUITE_H
#define SUITE_H

#include <ctest/types.h>
#include <ctest/structure/queue.h>

// Foward declaration
struct CTest_TestSuite;

// Pointer to output function
typedef void (*CTest_OutputFn)(const struct CTest_TestSuite*);

/**
 * Struct responsible for storing all the information about the tests, 
 * since the reference to the test functions and the result of every test
 * asserted.
 */
struct CTest_TestSuite {
    unsigned int numberTests; ///< Number of tests to be asserted.
    unsigned int numberFinishedTests; ///< Number of tests that ran.
    unsigned int numberFailTests; ///< Number of tests that have fail.
    struct CTest_FQueue* testsQueue; ///< Queue of tests to be asserted.
    struct CTest_Queue* errors;     ///< Queue of results of tests that have failed.
    CTest_OutputFn output;          ///< Pointer to the function that will print the output.
};

/**
 * Initialize the TestSuite using its default values.
 * @param testSuite reference to the TestSuite.
 */
void CTest_TestSuite_Init(struct CTest_TestSuite* testSuite);

/**
 * Run the TestSuite in order to assert all the tests added until the moment.
 * @param testSuite reference to the TestSuite.
 */
void CTest_TestSuite_Run(struct CTest_TestSuite* testSuite);

#endif
