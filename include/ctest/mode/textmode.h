/**
 * File containing an implementation responsible for printing the tests result
 * to the common output for the user (aka terminal).
 *
 * @author Matheus Nogueira
 * @version 1.0
 */
#ifndef CTEST_MODE_TEXTMODE_H
#define CTEST_MODE_TEXTMODE_H

#include <ctest/suite.h>

/**
 * Prints the result of the unit tests.
 * @param suite reference to the TestSuite used to test the application.
 */
void CTest_Output_Text(const struct CTest_TestSuite* suite);

#endif
