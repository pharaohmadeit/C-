Demonstrate the concept of rethrowing an exception in C++

Use-Cases for Rethrowing an Exception
• Log to a file for future debugging
• catch the exception, log it, then rethrow for further processing
• Throw a different exception type that's more specific to a particular library or application
• Wrap the original exception into the new exception by using the C++11 nested_exception class.
• Partially process an exception
• Release a resource then rethrow for further processing
• Exceptions are implicitly rethrown in function try blocks for constructors and destructors
