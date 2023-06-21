# FT_CONTAINERS

## Overview

This project aims to provide a custom implementation of several C++ Standard Template Library (STL) containers, including `vector`, `stack`, `map`, `pair`, `lexographical_compare`, as well as various additional features like `iterator_traits`, `equal`, `queue`, `set`, `multimap`, `multiset`, functional STL, iterator system, and allocator.

## Motivation

The motivation behind this project is to deepen understanding of the inner workings of popular STL containers and algorithms by building custom implementations from scratch. By doing so, you can gain insights into the underlying data structures and algorithms used in the STL.

## Features

The project includes the following features:

- Custom implementation of the following containers:
  - `vector`: A dynamic array that provides random access.
  - `stack`: A Last-In-First-Out (LIFO) data structure.
  - `map`: An associative container that stores key-value pairs in a sorted order.
  - `pair`: A simple container that holds two values as a single entity.
  - `lexographical_compare`: A comparison function for comparing ranges lexicographically.
  - `iterator_traits`: A set of type traits for working with iterators.
  - `equal`: A function that checks if two ranges are equal.
- Additional STL-inspired features:
  - `queue`: A First-In-First-Out (FIFO) data structure.
  - `set`: An associative container that stores unique elements in a sorted order.
  - `multimap`: An associative container that allows multiple elements with the same key in a sorted order.
  - `multiset`: A set that allows multiple elements with the same value.
  - Functional STL: Various function objects and algorithms inspired by the STL.
  - Iterator system: Custom iterators for the implemented containers.
  - Allocator: A custom memory allocator for the containers.

## Usage

To use the custom STL containers and additional features, follow these steps:

Clone the repository:

   ```shell
   git clone https://github.com/Hoso1999/ft_containers.git
   ```
## Examples
### Example: Using the vector Container
```c++
#include <iostream>
#include "vector.hpp"

int main() {
    ft::vector<int> myVector;
    myVector.push_back(1);
    myVector.push_back(2);
    myVector.push_back(3);

    std::cout << "Size: " << myVector.size() << std::endl;
    std::cout << "Elements: ";
    for (const auto& element : myVector) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
```
### Example: Using the stack Container
```c++
#include <iostream>
#include "stack.hpp"

int main() {
    ft::stack<int> myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    while (!myStack.empty()) {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }
    std::cout << std::endl;

    return 0;
}
```
### Example: Using the map Container
```c++
#include <iostream>
#include "map.hpp"

int main() {
    ft::map<int, std::string> myMap;

    myMap.insert({1, "Apple"});
    myMap.insert({2, "Banana"});
    myMap.insert({3, "Cherry"});

    for (const auto& pair : myMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    return 0;
}
```
### Example: Using the queue Container
```c++
#include <iostream>
#include "queue.hpp"

int main() {
    ft::queue<int> myQueue;

    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    while (!myQueue.empty()) {
        std::cout << myQueue.front() << " ";
        myQueue.pop();
    }
    std::cout << std::endl;

    return 0;
}
```
### Example: Using Custom Functional Objects with map
```c++
#include <iostream>
#include <string>
#include "map.hpp"
#include "functional.hpp"

int main() {
    ft::map<std::string, int, ft::less<std::string>> myMap;

    myMap.insert({"apple", 3});
    myMap.insert({"banana", 5});
    myMap.insert({"cherry", 2});

    // Using custom comparison function
    ft::map<std::string, int, ft::less<std::string>>::iterator it;
    for (it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }

    return 0;
}
```
### Example: Using fill to Fill a Vector
```c++
#include <iostream>
#include "vector.hpp"
#include "algorithm.hpp"

int main() {
    ft::vector<int> myVector(5);

    // Filling the vector with a value
    ft::fill(myVector.begin(), myVector.end(), 42);

    // Printing the vector elements
    for (const auto& element : myVector) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
```
### Example: Using uninitialized_copy to Copy Elements to Uninitialized Memory
```c++
#include <iostream>
#include "vector.hpp"
#include "algorithm.hpp"

int main() {
    ft::vector<int> sourceVector{1, 2, 3, 4, 5};
    ft::vector<int> destinationVector(5);

    // Copying elements from sourceVector to destinationVector (uninitialized memory)
    ft::uninitialized_copy(sourceVector.begin(), sourceVector.end(), destinationVector.begin());

    // Printing the destinationVector elements
    for (const auto& element : destinationVector) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
```
### Example: Using Custom Allocator with vector
```c++
#include <iostream>
#include "vector.hpp"
#include "allocator.hpp"

int main() {
    // Custom allocator for int
    ft::allocator<int> myAllocator;

    // Creating a vector using the custom allocator
    ft::vector<int, ft::allocator<int>> myVector(myAllocator);

    // Adding elements to the vector
    myVector.push_back(1);
    myVector.push_back(2);
    myVector.push_back(3);

    // Printing the vector elements
    for (const auto& element : myVector) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
```
## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request on the project's GitHub repository.

When contributing, please adhere to the existing coding style and follow the repository's code of conduct.
