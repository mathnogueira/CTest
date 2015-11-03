/**
 * File containing the declaration of all types used across the library.
 * @author Matheus Nogueira
 * @version 1.0
 */
#ifndef TYPES_H
#define TYPES_H

/* Foward declaration */
struct CTest_Test;
struct CTest_TestSuite;

/**
 * Type used by the test functions to say if the test has passed or not. It
 * is basically an emulation of the type boolean.
 */
typedef unsigned char CTest_Boolean;

/* Pointer to output function */
typedef void (*CTest_OutputFn)(const struct CTest_TestSuite*);

/**
 * Type used as an alias to a pointer to an unit test function.
 */
typedef void (*CTest_Function)(struct CTest_Test*);

/**
 * Structure used to map each function to its name, to make it easier to
 * detect where the problems are happening.
 */
struct CTest_FunctionMap {
    CTest_Function function;        /** Pointer to the test function */
    const char* name;               /** Name of the function */
};
/** Value for the boolean TRUE */
#define TRUE 1

/** Value for the boolean FALSE */
#define FALSE 0


#endif
