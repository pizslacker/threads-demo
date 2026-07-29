# threads-demo
Here is a complete C program demonstrating how to use pthreads (POSIX threads) to run code concurrently. 

This example creates two separate threads that execute the same function at the same time.

It also demonstrates how to pass data to a thread using a struct, which is the standard way to pass multiple arguments in C.

When compiling a program that uses `pthreads`, you must explicitly tell the compiler to link the pthread library using the `-pthread` flag.

----

- `pthread_t`: This is the data type used to identify a thread. You need one of these for every thread you want to create.
- `void *arg`: Because a thread doesn't know what kind of data you will pass it, the system uses a generic void pointer. Inside the thread function, you must cast this back to the actual data type (like our ThreadData struct) before you can use it.
- `pthread_join()`: This is a blocking function. When the main() function calls this, it pauses execution and waits patiently until the specified thread finishes running. Without this, main() would reach return EXIT_SUCCESS; and forcefully kill all running threads instantly.
- Concurrency: When you run the program, you will notice the output of Thread 1 and Thread 2 interleaving. The operating system's scheduler is rapidly switching between the two threads while they process their loops.
