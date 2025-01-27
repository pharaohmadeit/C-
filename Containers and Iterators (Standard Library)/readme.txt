Standard Library Containers and Iterators:

-Containers and C++20 ranges
-I/O stream iterators
-Use iterators to access container elements
-Vector, list & deque sequence containers
-Use ostream_iterators with the std::copy and std::ranges::copy algorithms 
-set, multiset, map & multimap ordered associative containers
-ordered vs. unordered associative containers
-stack, queueand priority_queue container adaptors 
-bitset “near container” to manipulate bit flags

Pro Tips:
-C++ Core Guidelines state vector is most performant for most types but ensure you choose the correct container based on use-case and performance requirements

-vector : expensive to insert or delete an element in the middle of the vector O(n) for insertion and deletion
-deque : for frequent insertions and deletions at both ends O(1) for insertions and deletions
-list : for frequent insertions and deletions in the middle and/or at the extremes
