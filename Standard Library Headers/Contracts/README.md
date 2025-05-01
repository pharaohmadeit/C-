# Contract Assertions -> C++26

Contract assertions allow the programmer to specify properties of the state of the program that are expected to hold at certain points during execution

C++26 Contract features tested through Compiler Explorer website (https://godbolt.org)
• Choose "x86-64 gcc (contracts)" as your compiler and compile contracts-based code using the compiler options described at https://gitlab.com/lock3/gcc-new/-/wikis/contract-assertions

Note: GNU C++ early-access implementation uses different keywords for preconditions and postconditions
• pre rather than expects
• post rather than ensures
