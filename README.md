# Skip List Data Structure Implementation in C++

## Overview
This project implements a Skip List data structure in C++, providing an efficient alternative to balanced trees for implementing associative arrays. Skip lists are probabilistic data structures that offer logarithmic time complexity for search, insertion, and deletion operations, making them suitable for various applications where fast access to sorted data is required.

## Concept
Skip lists consist of multiple linked lists, each with nodes containing references to nodes in lower levels. By "skipping" ahead in multiple linked lists, skip lists provide faster search operations compared to traditional linked lists.

## Performance
- **Time Complexity**:
  - Search: O(log n)
  - Insertion: O(log n)
  - Deletion: O(log n)
- **Space Complexity**: O(n)

## Usage
```cpp
Skiplist* obj = new Skiplist();
bool param_1 = obj->search(target);
obj->add(num);
bool param_3 = obj->erase(num);
```

## Repository
- **GitHub Repository**: [RatulDawar/skip-list](https://github.com/RatulDawar/skip-list)
- **File**: [SkipList.cpp](https://github.com/RatulDawar/skip-list/blob/main/SkipList.cpp)

Feel free to explore the repository and use the Skip List implementation in your projects!


