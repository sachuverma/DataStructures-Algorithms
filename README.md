# DATA STRUCTURES & ALGORITHMS

### `Resources and Solutions` `^_^`

> [DSA Crack Sheet](./DSA-Crack-Sheet)  
> [Companywise Interview Questions](./Companywise-Questions)  
> [Top Interview Preparation Questions](./Leetcode-Top-Interview-Questions)  
> [Leetcode Daily Challenge](./Leetcode-Daily-Challenge)

# C++ Data Structures and Algorithms Cheat Sheet

## Table of Contents

<!-- TOC depthFrom:1 depthTo:6 withLinks:1 updateOnSave:1 orderedList:0 -->

- [C++ Data Structures and Algorithms Cheat Sheet](#c-data-structures-and-algorithms-cheat-sheet)
  - [Table of Contents](#table-of-contents)
  - [1.0 Data Structures](#10-data-structures)
    - [1.1 Overview](#11-overview)
    - [1.2 Vector `std::vector`](#12-vector-stdvector)
    - [1.3 Deque `std::deque`](#13-deque-stddeque)
    - [1.4 List `std::list` and `std::forward_list`](#14-list-stdlist-and-stdforward_list)
    - [1.5 Map `std::map` and `std::unordered_map`](#15-map-stdmap-and-stdunordered_map)
    - [1.6 Set `std::set`](#16-set-stdset)
    - [1.7 Stack `std::stack`](#17-stack-stdstack)
    - [1.8 Queue `std::queue`](#18-queue-stdqueue)
    - [1.9 Priority Queue `std::priority_queue`](#19-priority-queue-stdpriority_queue)
    - [1.10 Heap `std::priority_queue`](#110-heap-stdpriority_queue)
  - [2.0 Trees](#20-trees)
    - [2.1 Binary Tree](#21-binary-tree)
    - [2.2 Balanced Trees](#22-balanced-trees)
    - [2.3 Binary Search](#23-binary-search)
    - [2.4 Depth-First Search](#24-depth-first-search)
    - [2.5 Breadth-First Search](#25-breadth-first-search)
  - [3.0 Algorithms](#30-algorithms)
    - [3.1 Insertion Sort](#31-insertion-sort)
    - [3.2 Selection Sort](#32-selection-sort)
    - [3.3 Bubble Sort](#33-bubble-sort)
    - [3.4 Merge Sort](#34-merge-sort)
    - [3.5 Quicksort](#35-quicksort)

<!-- /TOC -->

## 1.0 Data Structures

### 1.1 Overview

![DataStructures](DSA-Crack-Sheet/images/Data%20Structures.png "Data Structures")

![ComplexityChart](DSA-Crack-Sheet/images/Complexity%20Chart.png "Complexity Chart")

### 1.2 Vector `std::vector`

**Use for**

- Simple storage
- Adding but not deleting
- Serialization
- Quick lookups by index
- Easy conversion to C-style arrays
- Efficient traversal (contiguous CPU caching)

**Do not use for**

- Insertion/deletion in the middle of the list
- Dynamically changing storage
- Non-integer indexing

**Time Complexity**

| Operation    | Time Complexity |
| ------------ | --------------- |
| Insert Head  | `O(n)`          |
| Insert Index | `O(n)`          |
| Insert Tail  | `O(1)`          |
| Remove Head  | `O(n)`          |
| Remove Index | `O(n)`          |
| Remove Tail  | `O(1)`          |
| Find Index   | `O(1)`          |
| Find Object  | `O(n)`          |

**Example Code**

```c++
std::vector<int> v;

//---------------------------------
// General Operations
//---------------------------------

// Insert head, index, tail
v.insert(v.begin(), value);             // head
v.insert(v.begin() + index, value);     // index
v.push_back(value);                     // tail

// Access head, index, tail
int head = v.front();       // head
int value = v.at(index);    // index
int tail = v.back();        // tail

// Size
unsigned int size = v.size();

// Iterate
for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    std::cout << *it << std::endl;
}

// Remove head, index, tail
v.erase(v.begin());             // head
v.erase(v.begin() + index);     // index
v.pop_back();                   // tail

// Clear
v.clear();
```

---

### 1.3 Deque `std::deque`

**Use for**

- Similar purpose of `std::vector`
- Basically `std::vector` with efficient `push_front` and `pop_front`

**Do not use for**

- C-style contiguous storage (not guaranteed)

**Notes**

- Pronounced 'deck'
- Stands for **D**ouble **E**nded **Que**ue

**Example Code**

```c++
std::deque<int> d;

//---------------------------------
// General Operations
//---------------------------------

// Insert head, index, tail
d.push_front(value);                    // head
d.insert(d.begin() + index, value);     // index
d.push_back(value);                     // tail

// Access head, index, tail
int head = d.front();       // head
int value = d.at(index);    // index
int tail = d.back();        // tail

// Size
unsigned int size = d.size();

// Iterate
for(std::deque<int>::iterator it = d.begin(); it != d.end(); it++) {
    std::cout << *it << std::endl;
}

// Remove head, index, tail
d.pop_front();                  // head
d.erase(d.begin() + index);     // index
d.pop_back();                   // tail

// Clear
d.clear();
```

---

### 1.4 List `std::list` and `std::forward_list`

**Use for**

- Insertion into the middle/beginning of the list
- Efficient sorting (pointer swap vs. copying)

**Do not use for**

- Direct access

**Time Complexity**

| Operation    | Time Complexity |
| ------------ | --------------- |
| Insert Head  | `O(1)`          |
| Insert Index | `O(n)`          |
| Insert Tail  | `O(1)`          |
| Remove Head  | `O(1)`          |
| Remove Index | `O(n)`          |
| Remove Tail  | `O(1)`          |
| Find Index   | `O(n)`          |
| Find Object  | `O(n)`          |

**Example Code**

```c++
std::list<int> l;

//---------------------------------
// General Operations
//---------------------------------

// Insert head, index, tail
l.push_front(value);                    // head
l.insert(l.begin() + index, value);     // index
l.push_back(value);                     // tail

// Access head, index, tail
int head = l.front();                                           // head
int value = std::next(l.begin(), index);		        // index
int tail = l.back();                                            // tail

// Size
unsigned int size = l.size();

// Iterate
for(std::list<int>::iterator it = l.begin(); it != l.end(); it++) {
    std::cout << *it << std::endl;
}

// Remove head, index, tail
l.pop_front();                  // head
l.erase(l.begin() + index);     // index
l.pop_back();                   // tail

// Clear
l.clear();

//---------------------------------
// Container-Specific Operations
//---------------------------------

// Splice: Transfer elements from list to list
//	splice(iterator pos, list &x)
//  	splice(iterator pos, list &x, iterator i)
//  	splice(iterator pos, list &x, iterator first, iterator last)
l.splice(l.begin() + index, list2);

// Remove: Remove an element by value
l.remove(value);

// Unique: Remove duplicates
l.unique();

// Merge: Merge two sorted lists
l.merge(list2);

// Sort: Sort the list
l.sort();

// Reverse: Reverse the list order
l.reverse();
```

---

### 1.5 Map `std::map` and `std::unordered_map`

**Use for**

- Key-value pairs
- Constant lookups by key
- Searching if key/value exists
- Removing duplicates
- `std::map`
  - Ordered map
- `std::unordered_map`
  - Hash table

**Do not use for**

- Sorting

**Notes**

- Typically ordered maps (`std::map`) are slower than unordered maps (`std::unordered_map`)
- Maps are typically implemented as _binary search trees_

**Time Complexity**

**`std::map`**

| Operation         | Time Complexity |
| ----------------- | --------------- |
| Insert            | `O(log(n))`     |
| Access by Key     | `O(log(n))`     |
| Remove by Key     | `O(log(n))`     |
| Find/Remove Value | `O(log(n))`     |

**`std::unordered_map`**

| Operation         | Time Complexity |
| ----------------- | --------------- |
| Insert            | `O(1)`          |
| Access by Key     | `O(1)`          |
| Remove by Key     | `O(1)`          |
| Find/Remove Value | --              |

**Example Code**

```c++
std::map<std::string, std::string> m;

//---------------------------------
// General Operations
//---------------------------------

// Insert
m.insert(std::pair<std::string, std::string>("key", "value"));

// Access by key
std::string value = m.at("key");

// Size
unsigned int size = m.size();

// Iterate
for(std::map<std::string, std::string>::iterator it = m.begin(); it != m.end(); it++) {
    std::cout << *it << std::endl;
}

// Remove by key
m.erase("key");

// Clear
m.clear();

//---------------------------------
// Container-Specific Operations
//---------------------------------

// Find if an element exists by key
bool exists = (m.find("key") != m.end());

// Count the number of elements with a certain key
unsigned int count = m.count("key");
```

---

### 1.6 Set `std::set`

**Use for**

- Removing duplicates
- Ordered dynamic storage

**Do not use for**

- Simple storage
- Direct access by index

**Notes**

- Sets are often implemented with binary search trees

**Time Complexity**

| Operation | Time Complexity |
| --------- | --------------- |
| Insert    | `O(log(n))`     |
| Remove    | `O(log(n))`     |
| Find      | `O(log(n))`     |

**Example Code**

```c++
std::set<int> s;

//---------------------------------
// General Operations
//---------------------------------

// Insert
s.insert(20);

// Size
unsigned int size = s.size();

// Iterate
for(std::set<int>::iterator it = s.begin(); it != s.end(); it++) {
    std::cout << *it << std::endl;
}

// Remove
s.erase(20);

// Clear
s.clear();

//---------------------------------
// Container-Specific Operations
//---------------------------------

// Find if an element exists
bool exists = (s.find(20) != s.end());

// Count the number of elements with a certain value
unsigned int count = s.count(20);
```

---

### 1.7 Stack `std::stack`

**Use for**

- First-In Last-Out operations
- Reversal of elements

**Time Complexity**

| Operation | Time Complexity |
| --------- | --------------- |
| Push      | `O(1)`          |
| Pop       | `O(1)`          |
| Top       | `O(1)`          |

**Example Code**

```c++
std::stack<int> s;

//---------------------------------
// Container-Specific Operations
//---------------------------------

// Push
s.push(20);

// Size
unsigned int size = s.size();

// Pop
s.pop();

// Top
int top = s.top();
```

---

### 1.8 Queue `std::queue`

**Use for**

- First-In First-Out operations
- Ex: Simple online ordering system (first come first served)
- Ex: Semaphore queue handling
- Ex: CPU scheduling (FCFS)

**Notes**

- Often implemented as a `std::deque`

**Example Code**

```c++
std::queue<int> q;

//---------------------------------
// General Operations
//---------------------------------

// Insert
q.push(value);

// Access head, tail
int head = q.front();       // head
int tail = q.back();        // tail

// Size
unsigned int size = q.size();

// Remove
q.pop();
```

---

### 1.9 Priority Queue `std::priority_queue`

**Use for**

- First-In First-Out operations where **priority** overrides arrival time
- Ex: CPU scheduling (smallest job first, system/user priority)
- Ex: Medical emergencies (gunshot wound vs. broken arm)

**Notes**

- Often implemented as a `std::vector`

**Example Code**

```c++
std::priority_queue<int> p;

//---------------------------------
// General Operations
//---------------------------------

// Insert
p.push(value);

// Access
int top = p.top();  // 'Top' element

// Size
unsigned int size = p.size();

// Remove
p.pop();
```

---

### 1.10 Heap `std::priority_queue`

**Notes**

- A heap is essentially an instance of a priority queue
- A **min** heap is structured with the root node as the smallest and each child subsequently larger than its parent
- A **max** heap is structured with the root node as the largest and each child subsequently smaller than its parent
- A min heap could be used for _Smallest Job First_ CPU Scheduling
- A max heap could be used for _Priority_ CPU Scheduling

**Max Heap Example (using a binary tree)**

## 2.0 Trees

### 2.1 Binary Tree

- A binary tree is a tree with at most two (2) child nodes per parent
- Binary trees are commonly used for implementing `O(log(n))` operations for ordered maps, sets, heaps, and binary search trees
- Binary trees are **sorted** in that nodes with values greater than their parents are inserted to the **right**, while nodes with values less than their parents are inserted to the **left**

**Binary Search Tree**

### 2.2 Balanced Trees

- Balanced trees are a special type of tree which maintains its balance to ensure `O(log(n))` operations
- When trees are not balanced the benefit of `log(n)` operations is lost due to the highly vertical structure
- Examples of balanced trees:
  - AVL Trees
  - Red-Black Trees

---

### 2.3 Binary Search

**Idea:**

1. If current element, return
2. If less than current element, look left
3. If more than current element, look right
4. Repeat

**Data Structures:**

- Tree
- Sorted array

**Space:**

- `O(1)`

**Best Case:**

- `O(1)`

**Worst Case:**

- `O(log n)`

**Average:**

- `O(log n)`

### 2.4 Depth-First Search

**Idea:**

1. Start at root node
2. Recursively search all adjacent nodes and mark them as searched
3. Repeat

**Data Structures:**

- Tree
- Graph

**Space:**

- `O(V)`, `V = number of verticies`

**Performance:**

- `O(E)`, `E = number of edges`

### 2.5 Breadth-First Search

**Idea:**

1. Start at root node
2. Search neighboring nodes first before moving on to next level

**Data Structures:**

- Tree
- Graph

**Space:**

- `O(V)`, `V = number of verticies`

**Performance:**

- `O(E)`, `E = number of edges`

## 3.0 Algorithms

### 3.1 Insertion Sort

#### Idea

1. Iterate over all elements
2. For each element:
   - Check if element is larger than largest value in sorted array
3. If larger: Move on
4. If smaller: Move item to correct position in sorted array

#### Details

- **Data structure:** Array
- **Space:** `O(1)`
- **Best Case:** Already sorted, `O(n)`
- **Worst Case:** Reverse sorted, `O(n^2)`
- **Average:** `O(n^2)`

#### Advantages

- Easy to code
- Intuitive
- Better than selection sort and bubble sort for small data sets
- Can sort in-place

#### Disadvantages

- Very inefficient for large datasets

### 3.2 Selection Sort

#### Idea

1. Iterate over all elements
2. For each element:
   - If smallest element of unsorted sublist, swap with left-most unsorted element

#### Details

- **Data structure:** Array
- **Space:** `O(1)`
- **Best Case:** Already sorted, `O(n^2)`
- **Worst Case:** Reverse sorted, `O(n^2)`
- **Average:** `O(n^2)`

#### Advantages

- Simple
- Can sort in-place
- Low memory usage for small datasets

#### Disadvantages

- Very inefficient for large datasets

### 3.3 Bubble Sort

#### Idea

1. Iterate over all elements
2. For each element:
   - Swap with next element if out of order
3. Repeat until no swaps needed

#### Details

- **Data structure:** Array
- **Space:** `O(1)`
- **Best Case:** Already sorted `O(n)`
- **Worst Case:** Reverse sorted, `O(n^2)`
- **Average:** `O(n^2)`

#### Advantages

- Easy to detect if list is sorted

#### Disadvantages

- Very inefficient for large datasets
- Much worse than even insertion sort

### 3.4 Merge Sort

#### Idea

1. Divide list into smallest unit (1 element)
2. Compare each element with the adjacent list
3. Merge the two adjacent lists
4. Repeat

#### Details

- **Data structure:** Array
- **Space:** `O(n) auxiliary`
- **Best Case:** `O(nlog(n))`
- **Worst Case:** Reverse sorted, `O(nlog(n))`
- **Average:** `O(nlog(n))`

#### Advantages

- High efficiency on large datasets
- Nearly always O(nlog(n))
- Can be parallelized
- Better space complexity than standard Quicksort

#### Disadvantages

- Still requires O(n) extra space
- Slightly worse than Quicksort in some instances

### 3.5 Quicksort

#### Idea

1. Choose a **pivot** from the array
2. Partition: Reorder the array so that all elements with values _less_ than the pivot come before the pivot, and all values _greater_ than the pivot come after
3. Recursively apply the above steps to the sub-arrays

#### Details

- **Data structure:** Array
- **Space:** `O(n)`
- **Best Case:** `O(nlog(n))`
- **Worst Case:** All elements equal, `O(n^2)`
- **Average:** `O(nlog(n))`

#### Advantages

- Can be modified to use O(log(n)) space
- Very quick and efficient with large datasets
- Can be parallelized
- Divide and conquer algorithm

#### Disadvantages

- Not stable (could swap equal elements)
- Worst case is worse than Merge Sort

#### Optimizations

- Choice of pivot:
  - Choose median of the first, middle, and last elements as pivot
  - Counters worst-case complexity for already-sorted and reverse-sorted

# C++ Syntax Cheat Sheet

## Preface

Since the C++ language varies so heavily between versions (e.g. C++0x, C++11, C++17, etc.), I will preface this cheat sheet by saying that the majority of the examples here target C++0x or c++11, as those are the versions that I am most familiar with. I come from the aerospace industry (embedded flight software) in which we purposefully don't use the latest technologies for safety reasons, so most of the code I write is in C++0x and sometimes C++11. Nevertheless, the basic concepts of C++ and object oriented programming still generally apply to both past and future versions of the language.

## Table of Contents

<!-- TOC depthFrom:1 depthTo:6 withLinks:1 updateOnSave:0 orderedList:0 -->

- [C++ Syntax Cheat Sheet](#c-syntax-cheat-sheet)
  - [Table of Contents](#table-of-contents)
  - [1.0 C++ Classes](#10-c-classes)
    - [1.1 Class Syntax](#11-class-syntax)
      - [1.1.1 Class Declaration (`.h` file)](#111-class-declaration-h-file)
      - [1.1.2 Class Definition (`.cpp` file)](#112-class-definition-cpp-file)
      - [1.1.3 Class Utilization (Another `.cpp` file)](#113-class-utilization-another-cpp-file)
      - [1.1.4 Getters and Setters](#114-getters-and-setters)
    - [1.2 Inheritance](#12-inheritance)
      - [1.2.1 `Rectangle` Declaration (`.h` file)](#121-rectangle-declaration-h-file)
      - [1.2.2 `Rectangle` Definition (`.cpp` file)](#122-rectangle-definition-cpp-file)
      - [1.2.3 `Rectangle` Utilization (Another `.cpp` file)](#123-rectangle-utilization-another-cpp-file)
    - [1.3 Class Polymorphism](#13-class-polymorphism)
      - [1.3.1 Motivation](#131-motivation)
      - [1.3.2 Virtual Methods](#132-virtual-methods)
    - [1.4 Special Methods (Constructor, Destructor, ...)](#14-special-methods)
      - [1.4.1 Constructor and Destructor](#141-constructor-and-destructor)
        - [1.4.1.1 Use of `explicit` in Constructors](#1411-use-of-explicit-in-constructors)
        - [1.4.1.2 Member Initializer List](#1412-member-initializer-list)
      - [1.4.2. `new` and `delete`](#142-new-and-delete)
      - [1.4.3. Copy Constructor and Copy Assignment](#143-copy-constructor-and-copy-assignment)
      - [1.4.4. Move Constructor and Move Assignment](#144-move-constructor-and-move-assignment)
    - [1.5 Operator Overloading](#15-operator-overloading)
    - [1.6 Templates](#16-templates)
  - [2.0 General C++ Syntax](#20-general-c-syntax)
    - [2.1 Namespaces](#21-namespaces)
    - [2.2 References/Pointers](#22-references-and-pointers)
    - [2.3 Keywords](#23-keywords)
      - [2.3.1 General keywords](#231-general-keywords)
      - [2.3.2 Storage class specifiers](#232-storage-class-specifiers)
      - [2.3.3 `const` and `dynamic` Cast Conversion](#233-const-and-dynamic-cast-conversion)
    - [2.4 Preprocessor Tokens](#24-preprocessor-tokens)
    - [2.5 Strings ](#25-strings-stdstring)
    - [2.6 Iterators](#26-iterators-stditerator)
    - [2.7 Exceptions](#27-exceptions)
    - [2.8 Lambdas](#28-lambdas)

<!-- /TOC -->

## 1.0 C++ Classes

### 1.1 Class Syntax

#### 1.1.1 Class Declaration (`.h` file)

Here's a simple class representing a polygon, a shape with any number of sides.

The class _declaration_ typically goes in the header file, which has the extension `.h` (or, less commonly, `.hpp` to distinguish from C headers). The _declaration_ gives the class name, any classes it may extend, declares the members and methods, and declares which members/methods are public, private, or protected. You can think of the declaration as sort of saying: "there will be a thing and here's how it will look like". The declaration is used to inform the compiler about the future essence and use of a particular symbol.

```c++
// File: polygon.h

#include <string>

class Polygon {

// Private members and methods are only accessible via methods in the class definition
private:
    int num_sides;    	// Number of sides

// Protected members and methods are only accessible in the class definition or by classes who extend this class
protected:
    std::string name;   // Name of the polygon

// Public members and methods are accessible to anyone who creates an instance of the class
public:
    // Constructors
    Polygon(const int num_sides, const std::string & name); // <--- This constructor takes the number of sides and name as arguments

    // Getters and Setters
    int GetNumSides(void) const;
    void SetNumSides(const int num_sides);

    std::string & GetName(void) const;
    void SetName(const std::string & name);

}; // <--- Don't forget the semicolon!
```

#### 1.1.2 Class Definition (`.cpp` file)

The class _definition_ typically goes in the `.cpp` file. The _definition_ extends the declaration by providing an actual implementation of whatever it is that you're building. Continuing the example from the declaration, the definition can be thought of as saying: "Right, that thing I told you briefly about earlier? Here's how it actually functions". The definition thus provides the compileable implementation.

```c++
// File: polygon.cpp

#include <string>	// <--- Required for std::string

#include "polygon.h"    // <--- Obtains the class declaration

// Constructor
// You must scope the method definitions with the class name (Polygon::)
// Also, see the section on the 'explicit' keyword for a warning about constructors with exactly one argument
Polygon::Polygon(const int num_sides, const std::string & name) {
    this->num_sides = num_sides;	// 'this' is a pointer to the instance of the class. Members are accessed via the -> operator
    this->name = name;			// In this case you need to use 'this->...' to avoid shadowing the member variable since the argument shares the same name
}

// Get the number of sides
int Polygon::GetNumSides(void) const {	// The 'const' here tells the compiler that you guarantee that you won't modify the object when this function is called. This allows it to perform optimizations that it otherwise may not be able to do
    return this->num_sides;
}

// Set the number of sides
void Polygon::SetNumSides(const int num_sides) {
    this->num_sides = num_sides;
}

// Get the polygon name
std::string & Polygon::GetName(void) const {
    return this->name;
}

// Set the polygon name
void Polygon::SetName(const std::string & name) {
    this->name = name;
}
```

The getters and setters here don't do much, but you could imagine limiting the number of sides such that it must have at least 3 sides to be a useful polygon, in which case you could enforce that in `Polygon::SetNumSides()`. Of course, you'd also need to modify the constructor, which could then call `SetNumSides()` instead of setting the variable directly.

> NOTE: Regarding the use of `this->` in a class definition, there are places where it's strictly necessary for readability, e.g. when your method parameter shares the exact same name as a member variable, you use `this->` to avoid what's called shadowing. However, some prefer to always use `this->` explicitly regardless of whether it's necessary.

#### 1.1.3 Class Utilization (Another `.cpp` file)

```c++
// File: main.cpp

#include <string>
#include <iostream>

#include "Polygon.h"    // <--- Obtains the class declaration

int main(int argc, char * argv[]) {
    // Create a polygon with 4 sides and the name "Rectangle"
    Polygon polygon = Polygon(4, "Rectangle");

    // Check number of sides -- Prints "Rectangle has 4 sides"
    std::cout << polygon.GetName() << " has " << polygon.GetNumSides() << " sides"<< std::endl;

    // Change number of sides to 3 and rename to "Triangle"
    polygon.SetNumSides(3);
    polygon.SetName("Triangle");
}
```

#### 1.1.4 Getters and Setters

A shortcut often used for Getters/Setters is to define them in the class declaration (`.h`) file as follows:

```c++
// File: car.h

#include <string>

class Car {
private:
    int year;
    std::string make;

public:
    int GetYear(void) const { return this->year; }
    void SetYear(const int year) { this->year = year; }
    std::string & GetMake(void) const { return this->make; }
    void SetMake(const std::string & make) { this->make = make; }
};
```

This is often used for very basic getters and setters, and also for basic constructors. In contrast, you'll nearly always find more complex methods defined in the `.cpp` file. One exception to this is with class templates, in which the entire templated class declaration and definition must reside in the header file.

Another important consideration: If you have getters and setters for all of your members, you may want to reconsider the design of your class. Sometimes having getters and setters for every member is indicative of poor planning of the class design and interface. In particular, setters should be used more thoughtfully. Could a variable be set once in the constructor and left constant thereafter? Does it need to be modified at all? Is it set somewhere else in another method, perhaps even indirectly?

### 1.2 Inheritance

A class can extend another class, meaning that the new class inherits all of the data from the other class, and can also override its methods, add new members, etc. Inheritance is the key feature required for [polymorphism](#13-class-polymorphism).

It is important to note that this feature is often overused by beginners and sometimes unnecessary hierarchies are created, adding to the overally complexity. There are some good alternatives such as [composition](https://en.wikipedia.org/wiki/Composition_over_inheritance) and [aggregation](https://stackoverflow.com/a/269535), although, of course, sometimes inheritance is exactly what is needed.

**Example:** the class `Rectangle` can inherit from the class `Polygon`. You would then say that a `Rectangle` extends from a `Polygon`, or that class `Rectangle` is a sub-class of `Polygon`. In plain English, this means that a `Rectangle` is a more specialized version of a `Polygon`. Thus, all rectangles are polygons, but not all polygons are rectangles.

#### 1.2.1 `Rectangle` Declaration (`.h` file)

```c++
// File: rectangle.h

#include <string>       // <--- Explicitly include the string header, even though polygon.h also includes it

#include "polygon.h"	// <--- You must include the declaration in order to extend the class

// We extend from Polygon by using the colon (:) and specifying which type of inheritance
// will be used (public inheritance, in this case)

class Rectangle : public Polygon {
private:
    int length;
    int width;

    // <--- NOTE: The member variables 'num_sides' and 'name' are already inherited from Polygon
    //            it's as if we sort of get them for free, since we are a sub-class

public:
    // Constructors
    explicit Rectangle(const std::string &name);
    Rectangle(const std::string &name, const int length, const int width);

    // Getters and Setters
    const int GetLength(void) const { return this->length; }
    void SetLength(const int) { this->length = length; }

    const int GetWidth(void) const { return this->width; }
    void SetWidth(const int) { this->width = width; }

    // <--- NOTE: Again, the getters/setters for 'num_sides' and 'name' are already inherited from Polygon

    // Other Methods
    const int Area(void) const;
};
```

> NOTE: The inheritance access specifier (`public`, `protected`, or `private`) is used to determine the [type of inheritance](https://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm). If this is omitted then `private` inheritance is used by default. **Public inheritance is by far the most common type of inheritance**.

#### 1.2.2 `Rectangle` Definition (`.cpp` file)

```c++
// File: rectangle.cpp

#include "rectangle.h"	// <--- Only need to include 'Rectangle', since 'Polygon' is included in 'rectangle.h'

// This constructor calls the superclass (Polygon) constructor and sets the name and number of sides to '4', and then sets the length and width
Rectangle::Rectangle(const std::string &name, const int length, const int width) : Polygon(4, name) {
    this->length = length;
    this->width = width;
}

// This constructor calls the superclass (Polygon) constructor, but sets the length and width to a constant value
// The explicit keyword is used to restrict the use of the constructor. See section below for more detail
explicit Rectangle::Rectangle(const std::string &name) : Polygon(4, name) {
    this->length = 1;
    this->width = 1;
}

// Compute the area of the rectangle
int Rectangle::Area(void) const {
    return length * width;		// <--- Note that you don't explicitly need 'this->', you can directly use the member variables
}
```

#### 1.2.3 `Rectangle` Utilization (Another `.cpp` file)

```c++
// File: main.cpp

#include <iostream>

#include "Rectangle.h"

int main(int argc, char *argv[]) {
    Rectangle rectangle = Rectangle("Square", 6, 6);

    // Prints "Square has 4 sides, and an area of 36"
    std::cout << rectangle.GetName() << " has " << rectangle.GetNumSides() << " sides, and an area of " << rectangle.Area() << std::endl;
}
```

### 1.3 Class Polymorphism

Polymorphism describes a system in which a common interface is used to manipulate objects of different types. In essence various classes can inherit from a common interface through which they make certain guarantees about which methods/variables are available for use. By adhering to this common interface, one can use a pointer to an object of the base interface type to call the methods of any number of extending classes. Using polymorphism one can say "I don't care what type this really is; I know it implements `Foo()` and `Bar()` because it inherits from this interface", which is a pretty nifty feature.

The `virtual` keyword is used to ensure runtime polymorphism for class methods. Additionally, an overriding method can be forced by the compiler by not providing a default implementation in the interface, which is done by setting the method to `= 0`, as will be shown later.

#### 1.3.1 Motivation

Let's consider a similar class hierarchy using shapes as previously discussed. Considering a shape to be any 3 or more sided polygon from which we can compute certain attributes (like the shape's area), let's extend from it to create a rectangle class from which we can set the length/width and a circle class in which you can set the radius. **In both cases, we want to be able to compute the area of the shape.** This is a key observation that we will expand upon later.

For now, this (poorly implemented) shape class will suffice:

```c++
// File: shape.h

#include <cmath> 	// needed for M_PI constant

class Shape {
    // We'll leave Shape empty for now... not very interesting yet
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    // Constructor using a member initializer list instead of assignment in the method body
    Rectangle(const double w, const double l) : width(w), length(l) {}

    // Compute the area of a rectangle
    double Area(void) const {
        return length * width;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    explicit Circle(double r) : radius(r) {}

    // Compute the area of a circle
    double Area(void) const {
        return M_PI * radius * radius;  // pi*r^2
    }
};
```

> NOTE: As shown here, you can put multiple classes in a single header, although in practice unless you have a good reason for doing so it's probably best to use a separate header file per class.

> NOTE: I'm not using default value initialization for member variables (i.e. `double length = 0;`) and I'm using parentheses `()` instead of braces `{}` for the initializer list since older compilers (pre-C++11) may not support the new syntax.

So, we have our two classes, `Rectangle` and `Circle`, but in this case inheriting from `Shape` isn't really buying us anything. To make use of polymorphism we need to pull the common `Area()` method into the base class as follows, by using virtual methods.

#### 1.3.2 Virtual Methods

Imagine you want to have a pointer to a shape with which you want to compute the area of that shape. For example, maybe you want to hold shapes in some sort of data structure, but you don't want to limit yourself to just rectangles or just circles; you want to support all objects that call themselves a 'Shape'. Something like:

```c++
Rectangle rectangle(2.0, 5.0);
Circle circle(1.0);

// Point to the rectangle
Shape * unknown_shape = &rectangle; // Could point to *any* shape, Rectangle, Circle, Triangle, Dodecagon, etc.

unknown_shape->Area();  // Returns 10.0

// Point to the circle
unknown_shape = &circle;
unknown-shape->Area();  // Returns 3.14...
```

The way to achieve this is to use the `virtual` keyword on the base class methods, which specifies that when a pointer to a base class invokes the method of an object that it points to, it should determine, at runtime, the correct method to invoke. That is, when `unknown_shape` points to a `Rectangle` it invokes `Rectangle::Area()` and if `unknown_shape` points to a `Circle` it invokes `Circle::Area()`.

Virtual methods are employed as follows:

```c++
#include <cmath>

class Shape {
public:
    // Virtual destructor (VERY IMPORTANT, SEE NOTE BELOW)
    virtual ~Area() {}

    // Virtual area method
    virtual double Area() const {
        return 0.0;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double w, double l) : width(w), length(l) {}

    // Override the Shape::Area() method with an implementation specific to Rectangle
    double Area() const override {
        return length * width;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    explicit Circle(double t) : radius(r) {}

    // Override the Shape::Area() method with an implementation specific to Circle
    //
    // NOTE: there is an 'override' keyword that was introduced in C++11 and is optional: it is used
    // to enforce that the method is indeed an overriding method of a virtual base method at compile time
    // and is used as follows:
    double Area() const override {
        return M_PI * radius * radius; // pi*r^2
    }
};
```

> NOTE: It is very important that a default virtual destructor was included after adding the virtual `Area()` method to the base class. Whenever a base class includes even a single virtual method, it must include a virtual destructor so that the correct destructor(s) are called in the correct order when the object is eventually deleted.

This is called runtime polymorphism because the decision of which implementation of the `Area()` method to use is determined during program execution based on the type that the base is pointing at. It is implemented using [the virtual table](https://www.learncpp.com/cpp-tutorial/125-the-virtual-table/) mechanism. In a nutshell: it is a little more expensive to use but it can be immensely useful. There is also compile-time polymorphism. Here is more on the [differences between them](https://www.geeksforgeeks.org/polymorphism-in-c/).

In the example above, if a class extends from `Shape` but does not include an override of `Area()` then calling the `Area()` method will invoke the base class method which (in the implementation above) returns `0.0`.

In some cases, you may want to **enforce** that sub-classes implement this method. This is done by not providing a default implementation, thus making it what is called a _pure virtual_ method.

```c++
class Shape {
public:
    virtual ~Area() {}
    virtual double Area() const = 0;
};
```

In general a class with only pure virtual methods and a virtual destructor is called an _abstract class_ or _interface_ and is typically named as such (e.g. `ButtonInterface`, or similar). An interface class guarantees that all extending classes implement a specific method with a specific method signature.

### 1.4 Special Methods

#### 1.4.1 Constructor and Destructor

All classes have at least one constructor and a destructor, even if they are not explicitly defined. The constructor and destructor
assist in managing the lifetime of the object. The constructor is invoked when an object is created and the destructor is invoked
when an object is destroyed (either by going out of scope or explicitly using `delete`).

The constructor establishes a [class invariant](https://softwareengineering.stackexchange.com/a/32755), a set of assertions guaranteed to be true during the lifetime of the object, which is then removed when the destructor is called.

##### 1.4.1.1 Use of `explicit` in Constructors

The `explicit` keyword should be used in single-argument constructors to avoid a situation in which the constructor is implicitly invoked when a single argument is given in place of an object. Consider the following `Array` class:

```c++
class Array {
private:
    int size;

public:
    // Constructor
    Array(int size) {
        this->size = size;
    }

    // Destructor
    ~Array() {}

    // Print the contents of the array
    Print(const Array & array) {
        // ...
    }
};
```

The following is now legal but ambiguous:

```c++
Array array = 12345;
```

It ends up being the equivalent of this:

```c++
Array array = Array(12345);
```

Perhaps that's okay, but what about the following:

```c++
array.Print(12345);
```

Uh-oh. That's now legal, compileable code, but what does it mean? It is extremely unclear to the user.

To fix this, declare the single-argument `Array` constructor as `explicit`:

```c++
class Array {
    int size;
public:
    explicit Array(int size) {
        this->size = size;
    }

    // ...
};
```

Now you can only use the print method as follows:

```c++
array.Print(Array(12345));
```

and the previous `array.Print(12345)` is now a syntax error.

##### 1.4.1.2 Member Initializer Lists

Member initializer lists allow you to initialize member variables in the definition of a method. This turns out to provide
some performance benefits for class-type member variables, since a call to the default constructor is avoided. For POD (plain old data)
like ints and floats, though, it is the same as initializing them in the body of the method.

```c++
class Car {
private:
    int year;
    int miles;
    std::string make;

public:
    Car(const int year, const int miles, const std::string & make) : year(year), miles(miles), make(make) {}
};
```

Using the initializer list is basically the same as the following more verbose constructor implementation, notwithstanding the note above regarding performance:

```c++
Car(const int year, const int miles, const std::string & make) {
    this->year = year;
    this->miles = miles;
    this->make = make;
}
```

Since C++11 initializer lists have some added functionality and curly braces `{}` can be used instead of parentheses `()` in the
initializer list, but to maintain compatibility with older compilers you may want to use parentheses. The same applies in general
to initialization syntax when creating objects. Many people prefer braces, and in some cases it's necessary (e.g. vector containing [100, 1] or a vector of one hundred 1s?), but to support older compilers you may consider using parentheses.

#### 1.4.2 `new` and `delete`

The `new` and `delete` operators (and their array counterparts, `new[]` and `delete[]`) are operators used to dynamically allocate
memory for objects, much like C's `malloc()` and `free()`.

More on these operators can be found [here](https://www.geeksforgeeks.org/new-and-delete-operators-in-cpp-for-dynamic-memory/).

When manually allocating memory dynamically, it is the responsibility of the programmer to manage the memory and properly
delete objects that have been allocated.

#### 1.4.3 Copy Constructor and Copy Assignment

Copy constructors and copy assigment operators allow one object to be constructed or assigned a copy of another object directly:

```c++
Foo a(10);
Foo b(a);   // (1): Copy via constructor
Foo c = a;	// (2): Copy via assignment operator
```

This is accomplished by supplying a copy constructor and an assigment operator overload, both of which have a special syntax
where they accept a const reference to an object of their same type.

```c++
class Foo {
private:
    int data;

public:
    // Default (no argument) constructor
    Foo() : data(0) {}

    // Single argument constructor
    explicit Foo(const int v) : data(v) {}

    // Copy constructor
    Foo(const Foo & f) : data(f.data) {}

    // Copy assignment operator
    Foo & operator=(const Foo & f) {
        data = f.data;
        return *this;
    }
};
```

Note that the compiler will always provide a default constructor, a default copy constructor, and a default copy assignment operator, so for simple cases (like this trivial example) you will not have to implement them yourself. More info on this can be found [here](https://stackoverflow.com/questions/4172722/what-is-the-rule-of-three).

#### 1.4.4 Move Constructor and Move Assignment

Sometimes instead of performing a copy you instead wish to completely move data from one object to another. This requires the use
of a move constructor and move assignement operator.

```c++
class Movable {
private:
    Foo * data_ptr;

public:
    Movable(Foo data) : data_ptr(new Foo(data)) {}

    // Move constructor
    Movable(Movable && m) {
        // Point to the other object's data
        data_ptr = m.data_ptr;

        // Remove the other object's data pointer by
        // setting it to nullptr
        m.data_ptr = nullptr;
    }

    // Move assignment operator
    Movable & operator=(Movable && m) {
        data_ptr = m.data_ptr;
        m.data_ptr = nullptr;
        return *this;
    }

    ~Movable() {
        delete data_ptr;
    }
};
```

The move constructor and assignment operator can be used as follows:

```c++
Movable Bar() {
    // ...
}

int main() {
    Movable a(Bar());       // Using the move constructor
    Movable b = Bar();		// Using the move assignment operator
}
```

Since `Bar()` creates an object that won't be used elsewhere and is deleted after the call, we can use the move constructor or
move assignment operator to move the data to our object.

A programming idiom called ['copy and swap'](https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom) makes use of the move constructor and can be a useful idiom.

### 1.5 Operator Overloading

Operators such as `+`, `-`, `*`, etc. are familiar and ubiquitous when working with simple data types like integers and floating point
numbers. These operators as well as others can also be overloaded to provide a clear syntactic meaning to your own classes. For example,
when working with linear algebra you can overload the `+` operator to perform an element-wise addition of two vectors. Here's a brief
example using complex numbers that allows you to use the `+` and `-` operators to easily add and subtract two complex numbers.

There are two main ways to do operator overloading. The first is using normal member functions. The second uses the `friend` keyword and non-member methods that have access to the private member variables of the class.

Using normal member functions (requires a getter method for the member variables):

```c++
// File: complex.h

class Complex {
private:
    double r = 0.0; // Real part, defaults to 0.0
    double i = 0.0; // Imaginary part, defaults to 0.0

public:
    Complex(const double r, const double i) : r(r), i(i) {}

    // Accessor methods
    double GetReal(void) const { return r; }
    double GetImaginary(void) const { return i; }

    // + Operator
    Complex operator+(const Complex & a, const Complex & b) {
        return Complex(a.GetReal() + b.GetReal(), a.GetImaginary() + b.GetImaginary());
    }

    // - Operator
    Complex operator-(const Complex& a, const Complex& b) {
        return Complex(a.GetReal() - b.GetReal(), a.GetImaginary() - b.GetImaginary());
    }
};
```

Using `friend` methods:

```c++
// File: complex.h

class Complex {
private:
    double r = 0.0; // Real part, defaults to 0.0
    double i = 0.0; // Imaginary part, defaults to 0.0

public:
    Complex(const double r, const double i) : r(r), i(i) {}

    // + Operator (declaration only)
    friend Complex operator+(const Complex & a, const Complex & b);

    // - Operator (declaration only)
    friend Complex operator-(const Complex& a, const Complex& b);
};

// These are NOT member functions
// They can also be defined inside the class body but leaving them outside
// is a clearer reminder that they are not part of the class
Complex operator+(const Complex & a, const Complex & b) {
    return Complex(a.r + b.r, a.i + b.i);
}

Complex operator-(const Complex& a, const Complex& b) {
    return Complex(a.r - b.r, a.i - b.i);
}
```

In either case, the new operators can be used as follows:

```c++
int main() {
    Complex a(1, 2);    //  1 + 2i
    Complex b(5, 3);    //  5 + 3i

    Complex c = a + b;	//  6 + 5i
    Complex d = a - b;	// -4 - 1i
}
```

It's also often useful to overload the output stream operator to provide a custom output string displaying the object's
internal state in a human-readable format. This is done by overloading the `<<` operator and requires using the `<iostream>`
functionality.

```c++
#include <iostream>

class Complex {
private:
    // ...
public:
    // ...

    friend std::ostream & operator<<(std::ostream & os, const Complex & c);
};

// Definition
// Again, this is NOT a member function!
std::ostream & operator<<(std::ostream & os, const Complex & c) {
    os << c.r << " + " << c.i << "i";
    return os;
}

int main() {
    Complex a {1, 2};
    Complex b {5, 3};

    std::cout << a;     // Prints: 1 + 2i
    std::cout << a + b; // Prints: 6 + 5i
}
```

You can also similiarly overload the input stream operator (`>>`), and can read more about the various operators [here](http://en.cppreference.com/w/cpp/language/operators).

### 1.6 Templates

Templates are a very powerful abstraction allowing you to generate compile-time methods/classes/etc. for any number of types while
writing only one implementation.

Say you have a method that adds two floating point number together, and another to add two integers together:

```c++
double Add(const double a, const double b) {
    return a + b;
}

int Add(const int a, const int b) {
    return a + b;
}
```

That's great, but since both floating point numbers and integers implement the `+` operator you can use a template to instead
write one generic implementation of a method that can operate on doubles, ints, floats, and (in this case) any other type that
implements the `+` operator.

A simple templatized version of `Add` would look something like this:

```c++
template <typename T>   // T becomes whatever type is used at compile-time
T Add(const T & a, const T & b) {
    return a + b;   // The type T must support the + operator
}

// Usages
int main() {
    Add<int>(3, 5);		    // int version
    Add<double>(3.2, 5.8);  // double
    Add(3.45f, 5.0f);	    // implicit float version: we leave off the <float> here, since it can deduce the type from the context

    Complex a {1, 2};	    // Custom class
    Complex b {5, 3};
    Add(a, b);	            // Works because we added support for the + operator!
}
```

In this simple example the compiler would generate four different methods, one for each type. Templating allows you to write more
concise and modular code at the expense of generating a larger executable (code bloat).

Templates are especially useful to create class templates. Class templates must be completely defined in a single header file.

```c++
// File: storage.h

template <class T>      // <--- 'class' is synonymous with 'typename'
class Container {
private:
    T data;
public:
    explicit Container(const T & d) : data(d) {}
};

// Usage
int main() {
    Container<int> a(1);
    Container<float> b(10.0f);
    Container<Container<int>> c(a);
}
```

> NOTE: More coming soon on templates...

Read more about templates [here](https://www.geeksforgeeks.org/templates-cpp/) and [here](http://en.cppreference.com/w/cpp/language/templates).

## 2.0 General C++ Syntax

### 2.1 Namespaces

In a large production project you may have thousands of symbols for various types, variables, methods, and so on. To avoid symbol names conflicting
with one another you can use namespaces to logically separate symbol names in to broad categories. Namespaces are an inherent feature of C++; when you
create a class and refer to a method as `ClassName::Method()` you are essentially using a namespace feature intrinsic to classes.

For a brief namespace example, suppose that you have two data structures, both of which implement a `Node` class. In the following code, namespaces
are used to allow the compiler (and the programmer) to distinguish between the two types.

```c++
// File: list.h

namespace list {

template <typename T>
struct Node {
    Node * next;
    Node * prev;
    T data;
};

}; // namespace
```

```c++
// File: bst.h

namespace bst {

template <typename T>
struct Node {
    Node * left;
    Node * right;
    T data;
};

}; // namespace
```

```c++
// File: main.cpp
#include "list.h"
#include "bst.h"

int main() {
    list::Node<int> a;
    bst::Node<int> b;
};
```

The standard C++ library uses the namespace `std`, e.g. `std::cout`, `std::string`, `std::endl`, etc. While you can use a `using namespace foo;` directive to address
symbols directly in the `foo` namespace without prefixing the `foo::` qualifier, this is generally considered bad practice as it pollutes the global namespace and
sort of undermines the point of using namespaces in the first place.

```c++
#include <iostream>
using namespace std;

cout << "Hello, World" << endl;             // <--- BAD: pollutes the global namespace
```

```c++
#include <iostream>

std::cout << "Hello, World" << std::endl;   // <--- GOOD: It's clear that you're using symbols from the standard namespace
```

### 2.2 References and Pointers

Those familiar with C will be very intimately acquainted with pointers. C++ adds the concept of references, which is a powerful way to have _some_ of the features of
pointers while avoiding some of the pitfalls. Later versions of C++ also add [smart pointers](https://docs.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=vs-2019),
which allow for better memory management and scoping via `std::unique_ptr`, `std::shared_ptr`, and `std::weak_ptr`, as compared to traditional raw pointers.

Raw pointers in C++ behave exactly the same way as they do in C: a pointer variable stores the address of whatever it is pointing to. You can think of pointers as
essentially storing a link to another piece of data. You can access the data that the pointer points to with the `->` operator, or dereference it with the `*` operator.

References are more akin to an alias. References cannot be `NULL` or `nullptr`, and references cannot be reassigned to reference something else after they have been created.
Additionally, references do not take up extra memory; they share the same address as whatever they reference to. References cannot have multiple levels of indirection (pointers can),
and there is no reference arithmetic like there is for pointers. You can access the underlying data of a reference directly by using the reference itself: that is, if it's a reference
to an integer it can be used as an integer. If it's a reference to a class you can access the class members directly with the `.` operator.

Although pointers are incredibly powerful, references are generally much safer, especially when passing objects to methods using pass-by-reference. It is very common in
C++ code to pass an object as a `const` reference (if the data should be unmutable within the method) or a non-const reference rather than a raw pointer as is required in C.

More on [references vs pointers here](https://stackoverflow.com/a/57492).

In the following code, assume a 32-bit system, in which case the size of a pointer variable is 4 bytes, and that the stack grows towards higher memory addresses.

```c++
// Pointers
int a = 10;                     // Ends up at memory address '0x2A000084', for example
int b = 20;                     // Ends up at memory address '0x2A000088'

int * ptr = nullptr;            // ptr is a separate variable whose type is 'pointer to int' and whose value has been initialized to '0x00000000'
printf("ptr = %p\n");           // Prints: 0x0

ptr = &a;                       // The value of ptr is now the address of the variable 'a'
std::cout << p << std::endl;    // Prints: 0x2a000084
std::cout << *p << std::endl;   // Prints: 10

ptr = &b;                       // The value of ptr is now the address of the variable 'b'
std::cout << p << std::endl;    // Prints: 0x2a000088
std::cout << *p << std::endl;   // Prints: 20
```

```c++
// References
int a = 10;                         // Ends up at memory address '0x2A000084', for example
int b = 20;                         // Ends up at memory address '0x2A000088'

int & ref_a = a;                    // ref_a is an alias of (reference to) the variable a
int & ref_b = b;                    // ref_b is an alias of (reference to) the variable b

std::cout << ref_a << std::endl;    // Prints: 10
std::cout << ref_b << std::endl;    // Prints: 20

std::cout << &ref_a << std::endl;   // Prints: 0x2a000084
std::cout << &ref_b << std::endl;   // Prints: 0x2a000088

ref_a = b;                          // SETS THE VALUE OF 'a' TO THE VALUE OF 'b'!

std::cout << ref_a << std::endl;    // Prints: 20
std::cout << a << std::endl;        // ALSO PRINTS: 20 !

int & ref_c;                        // ERROR! References must be initialized at their declaration
```

Perhaps the most widely used aspect of references is to pass objects by reference (sometimes constant reference) to a method. To avoid hammering the stack with
large objects when you pass them by value it is nearly always preferrable to pass by reference, which is the term used when using either a reference _or_ a pointer.
Using a reference allows you to pass any size object by reference, while still allowing you to access the object directly.

```c++
// Pass by reference using a const reference
void Foo(const Bar & bar) {
    int a = bar.GetValue();

    if (bar.SomeMethod()) {
        // ...
    }

    bar.SetValue(10);   // ERROR! Cannot modify a const reference!
}

// Pass by reference using a non-const reference
void Foo(Bar & bar) {
    int a = bar.GetValue();

    if (bar.SomeMethod()) {
        // ...
    }

    bar.SetValue(10);   // Modifies 'bar' and thus whatever 'bar' references
}
```

By passing an object by reference using a reference instead of a pointer you:

- Don't need to check for `NULL` or `nullptr` since references cannot be null
- Can access the referenced object's data directly instead of using the `->` operator or dereferencing a pointer
- Make it clearer which parameters are meant to be _input_ parameters and which are meant to be _output_ parameters by using
  `const` to denote strictly input parameters
- Gain the benefits of both passing by value and passing by reference since you don't need to use a lot of memory on the stack for your object

Thus, passing by reference using a `const` reference is essentially the same as passing by value, but you avoid copying the object onto the stack. Passing by reference
using a non-const reference is essentially the same as passing by reference using a pointer, but you are guaranteed that it is not null and it's as if the pointer
is effectively dereferenced.

### 2.3 Keywords

[Reference](http://en.cppreference.com/w/cpp/keyword)

#### 2.3.1 General Keywords

[`asm`](http://en.cppreference.com/w/cpp/language/asm)
[`auto`](http://en.cppreference.com/w/cpp/language/auto)
[`const`](http://en.cppreference.com/w/cpp/language/cv)
[`constexpr` (_since C++11_)](http://en.cppreference.com/w/cpp/language/constexpr)
[`explicit`](http://en.cppreference.com/w/cpp/language/explicit)
[`export` (_until C++11_)](http://en.cppreference.com/w/cpp/keyword/export)
[`extern` (_language linkage_)](http://en.cppreference.com/w/cpp/language/language_linkage)
[`friend`](http://en.cppreference.com/w/cpp/language/friend)
[`inline`](http://en.cppreference.com/w/cpp/language/inline)
[`mutable`](http://en.cppreference.com/w/cpp/language/cv)
[`noexcept` (_operator_)](http://en.cppreference.com/w/cpp/language/noexcept)
[`noexcept` (_function specifier_)](http://en.cppreference.com/w/cpp/language/noexcept_spec)
[`nullptr`](http://en.cppreference.com/w/cpp/language/nullptr)
[`override`](http://en.cppreference.com/w/cpp/language/override)
[`static` (_class member specifier_)](http://en.cppreference.com/w/cpp/language/static)
[`template`](http://en.cppreference.com/w/cpp/language/templates)
[`this`](http://en.cppreference.com/w/cpp/language/this)
[`virtual` (_function specifier_)](http://en.cppreference.com/w/cpp/language/virtual)
[`virtual` (_base class specifier_)](http://en.cppreference.com/w/cpp/language/derived_class)
[`volatile`](http://en.cppreference.com/w/cpp/language/cv)

#### 2.3.2 Storage Class Specifiers

[Reference](http://en.cppreference.com/w/cpp/language/storage_duration)

- `auto` (_until C++11_)
- `register` (_until C++17_)
- `static`
- `extern`
- `thread_local` (_since C++11_)

#### 2.3.3 `const` and `dynamic` Cast Conversion

- [`const_cast`](http://en.cppreference.com/w/cpp/language/const_cast)
- [`dynamic_cast`](http://en.cppreference.com/w/cpp/language/dynamic_cast)

### 2.4 Preprocessor Tokens

- `#if`: Preprocessor version of `if(...)`
- `#elif`: Preprocessor version of `else if(...)`
- `#else`: Preprocessor version of `else`
- `#endif`: Used to end an `#if`, `#ifdef`, or `#ifndef`
- `defined()`: Returns true if the macro is defined
- `#ifdef`: Same as `#if defined(...)`
- `#ifndef`: Same as `#if !defined(...)`
- `#define`: Defines a text macro. See [here](http://en.cppreference.com/w/cpp/preprocessor/replace) for full explanation, including macro functions and predefined macros.
- `#undef`: Un-defines a text macro
- `#include`: Includes a source file
- `#line`: Changes the current file name and line number in the preprocessor
- `#error`: Prints an error message and stops compilation
- `#pragma`: Non-standard, can be used instead of header guards (`#ifndef HEADER_H` ...)

### 2.5 Strings (`std::string`)

[Reference](http://en.cppreference.com/w/cpp/string/basic_string)

### 2.6 Iterators (`std::iterator<...>`)

[Reference](http://en.cppreference.com/w/cpp/concept/Iterator)

### 2.7 Exceptions

[Reference](http://en.cppreference.com/w/cpp/error/exception)

### 2.8 Lambdas

[Reference](https://en.cppreference.com/w/cpp/language/lambda)
