Demonstrate robust business and mission-critical C++ exception handling with a look forward to Contracts in C++26

C++ Core Guidelines
-Many try...catch statements can be a sign of too much low-level resource management.
-Design your classes to use RAII (Resouce Acquisition Is Initialization)

-"If you can't throw exceptions, consider failing fast."
-Rather than catching an exception, processing it and leaving the program in a state where it might fail later, terminate immediately.
