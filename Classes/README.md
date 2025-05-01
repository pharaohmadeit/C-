# Classes

A class is a user-defined type. A class can have the following kinds of members:

1) data members:
    a) non-static data members, including bit-fields.
    b) static data members

2) member functions:
    a) non-static member functions
    b) static member functions

3) nested types:
    a) nested classes and enumerations defined within the class definition
    b) aliases of existing types, defined with typedef or type alias (since C++11)declarations
    c) the name of the class within its own definition acts as a public member type alias of itself for the purpose of lookup (except when used to name a constructor): this is known as injected-class-name

4) enumerators from all unscoped enumerations defined within the class, or introduced by using-declarations or using-enum-declarations(since C++20)

5) member templates (variable templates, (since C++14)class templates or function templates) may appear in the body of any non-local class/struct/union.
