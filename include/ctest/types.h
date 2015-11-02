/**
 * File containing the declaration of all types used across the library.
 * @author Matheus Nogueira
 * @version 1.0
 */
#ifndef TYPES_H
#define TYPES_H

// Foward declaration
struct CTest_Test;

/**
 * Type used by the test functions to say if the test has passed or not. It
 * is basically an emulation of the type boolean.
 */
typedef unsigned char CTest_Boolean;

/**
 * Type used as an alias to a pointer to an unit test function.
 */
typedef void (*CTest_Function)(struct CTest_Test*);
//typedef CTest_Boolean (*CTest_Function)();

/** Value for the boolean TRUE */
#define TRUE 1

/** Value for the boolean FALSE */
#define FALSE 0


#endif
