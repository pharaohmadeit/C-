# Resource Acquisition Is Initialization or RAII

Resource Acquisition Is Initialization or RAII, is a C++ programming technique[1][2] which binds the life cycle of a resource that must be acquired before use (allocated heap memory, thread of execution, open socket, open file, locked mutex, disk space, database connection—anything that exists in limited supply) to the lifetime of an object.

RAII can be summarized as encapsulate each resource into a class, where the constructor acquires the resource and establishes all class invariants or throws an exception if that cannot be done, the destructor releases the resource and never throws exceptions; always use the resource via an instance of a RAII-class that either has automatic storage duration or temporary lifetime itself, or has lifetime that is bounded by the lifetime of an automatic or temporary object.

Demonstrate automatic RAII by using block scope and global namespace scope rules


Automatic Storage Duration:
When an object is declared within a scope (e.g., a function, a block within a function, or a loop) without using the "new" keyword, it has automatic storage duration. This means the object is created when the program enters the scope and destroyed when the program exits the scope.
  
Destructor Call:
When an object with automatic storage duration goes out of scope, its destructor is automatically called. This is the key mechanism that enables RAII.
