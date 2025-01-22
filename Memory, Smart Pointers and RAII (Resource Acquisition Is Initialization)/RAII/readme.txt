Automatic RAII and Scope


Automatic Storage Duration:
When an object is declared within a scope (e.g., a function, a block within a function, or a loop) without using the "new" keyword, it has automatic storage duration. This means the object is created when the program enters the scope and destroyed when the program exits the scope.
  
Destructor Call:
When an object with automatic storage duration goes out of scope, its destructor is automatically called. This is the key mechanism that enables RAII.
