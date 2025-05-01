# Iterator Library (Concepts C++20)

A new system of iterators based on concepts that are different from C++17 iterators. While the basic taxonomy remains similar, the requirements for individual iterator categories are somewhat different.

Iterators are a generalization of pointers that allow a C++ program to work with different data structures (for example, containers and ranges(since C++20)) in a uniform manner. 
The iterator library provides definitions for iterators, as well as iterator traits, iterator adaptors, and utility functions.
Since iterators are an abstraction of pointers, their semantics are a generalization of most of the semantics of pointers in C++. This ensures that every function template that takes iterators works as well with regular pointers.
