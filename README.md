#CTest :: Unit Testing for C
### v1.0.2

CTest is a tool to automatize unit tests in applications that are built in C. It is easy to setup and to use. All the steps to install and use are described bellow.

## Installation
To start using CTest, you must clone it from this repository and compile it.
>$ git clone git@github.com:mathnogueira/CTest.git
>
> $ cd CTest
> 
> $ make

If everything works properly, you should have a new folder called **dist** inside the CTest directory. This is the shared object that you must link in your application in order to use CTest to test your code. PS: Do not forget to add the folder **include** in the include_path of your compiler.

## How to use

In order to make CTest to work, you got to have the tests main entry and other files that contain your test functions. Let's start with the main entry.

Let's call it as **test_main.c** and it is inside the directory **myapp/tests**.

```c
// test_main.c
#include <ctest/core.h>
// You can include functions that are implemented elsewhere
// and add them to the test suite.
#include <myapp/tests/mytest.h>

int main(int argc, const char* argv[]) {
    // Create a test suite
    struct CTest_TestSuite* suite = CTest_Init();
    // Define the output mode.
    // Since v1.0.2, CTest supports two modes
    // TEXT: Prints the test results in the terminal
    // EXTERNAL: Enable another function to receive the results and
    // do something with it.
    CTest_SetMode(suite, EXTERNAL);
    // If you choose EXTERNAL, you must use the following statement to
    // tell CTest what function will receive the results
    CTest_SetExternalListener(suite, myExternalFunction);
    // Add a test to the suit.
    // myTest is a function that is inside myapp/tests/mytest.h
    // The third parameter is the name of the function (it will be printed in the output)
    // You may add as many functions you like.
    CTest_Add(suite, myTest, "myTest");
    // Run all the tests
    CTest_TestSuite_Run(suite);
    // End of the main entry function.
    return 0;
}
 ```

Now, lets say we have a file called **mytest.h** in the same directory as **test_main.c**

```c
// mytest.h
#ifndef MYTEST_H
#define MYTEST_H

#include <ctest/test.h>
void myTest(struct CTest_Test*);
#endif
```
```c
// mytest.c
#include <myapp/tests/mytest.h>

void myTest(struct CTest_Test* test) {
    int meaningOfLife = 7 * 7;
    if (meaningOfLife != 42)
        // Something went wrong, so the test fails
        CTest_Test_Fail(test, "The meaning of life should be 42");
    else
        // Test went ok.
        CTest_Test_Success(test);
}
```
This test will output in the TEXT mode:
```
Test v1.0.2 -- Unit Test for C

Number of tests: 1      Number of failed tests: 1
>> myTest --> The meaning of life should be 42
```
