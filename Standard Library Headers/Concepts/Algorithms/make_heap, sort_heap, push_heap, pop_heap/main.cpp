//  C++20's std::ranges Algorithms (Standard Template Library): make_heap, sort_heap, push_heap, pop_heap
//  main.cpp
//  fig14_15
//
//  Created by Pharaoh Tornes on 5/5/25.
//

#include <algorithm>
#include <iterator>
#include <vector>
#include <array>
#include <iostream>

int main() {
    std::ostream_iterator <int> output (std::cout, " ");
    
    std::array heapArray {3, 100, 52, 77, 22, 31, 1, 98, 13, 40};
    std::cout << "heapArray before make_heap:\n";
    std::ranges::copy (heapArray, output);
    
    std::ranges::make_heap(heapArray);  //  create heap from heapArray
    std::cout << "\n\nheapArray after make_heap:\n";
    std::ranges::copy (heapArray, output);
    
    std::ranges::sort_heap(heapArray);  //  sort elements with sort_heap
    std::cout << "\n\nheapArray after sort_heap:\n";
    std::ranges::copy (heapArray, output);
    
    //  utilize a lambda to add an int to a heap; captures all variables from enclosing scope by reference [&]
    auto push {
        [&](std::vector <int> &heap, int value){
            std::cout << "\n\npushing: " << value << " onto heap";
            heap.push_back(value);  //  add value to the heap
            std::ranges::push_heap(heap);   //  insert last element into heap
            std::cout << "\nheap: ";
            std::ranges::copy (heap, output);
        }
    };
    
    //  utilize a lambda to remove an element from the heap; captures all variables from enclosing scope by reference [&]
    auto pop {
        [&](std::vector <int> &heap)
        {   std::ranges::pop_heap(heap);    //  remove max item from heap
            std::cout << "\n\npopping highest priority item: " << heap.back();
            heap.pop_back();    //  remove vector's last element
            std::cout << "\nheap: ";
            std::ranges::copy (heap, output);
        }
    };
    
    std::vector <int> heapVector {};
    
    //  place five integers into heapVector, maintaining it as a heap
    for (auto value: {3, 52, 100}) {
        push(heapVector, value);
    }
    
    pop(heapVector);    //  remove max element
    push(heapVector, 22);   //  add new item to heap
    
    pop(heapVector);    //  remove max element
    push(heapVector, 77);   //  add new item to heap
    
    pop(heapVector);    //  remove max element
    pop(heapVector);    //  remove max element
    pop(heapVector);    //  remove max element
    std::cout << "\n";
}
