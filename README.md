# threads-demo
Here is a complete C program demonstrating how to use pthreads (POSIX threads) to run code concurrently. 

This example creates two separate threads that execute the same function at the same time.

It also demonstrates how to pass data to a thread using a struct, which is the standard way to pass multiple arguments in C.

When compiling a program that uses `pthreads`, you must explicitly tell the compiler to link the pthread library using the `-pthread` flag.
