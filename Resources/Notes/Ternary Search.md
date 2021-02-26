## Ternary Search

Ternary search is a divide and conquer algorithm that can be used to find an element in an array. It is similar to binary search where we divide the array into two parts but in this algorithm, we divide the given array into three parts and determine which has the key (searched element). We can divide the array into three parts by taking mid1 and mid2 which can be calculated as shown below. Initially, l and r will be equal to 0 and n-1 respectively, where n is the length of the array.

`mid1 = l + (r-l)/3`
`mid2 = r – (r-l)/3`

Note: Array needs to be sorted to perform ternary search on it.

_Steps to perform Ternary Search:_
First, we compare the key with the element at mid1. If found equal, we return mid1.
If not, then we compare the key with the element at mid2. If found equal, we return mid2.
If not, then we check whether the key is less than the element at mid1. If yes, then recur to the first part.
If not, then we check whether the key is greater than the element at mid2. If yes, then recur to the third part.
If not, then we recur to the second (middle) part.

### Recursive Implementation of Ternary Search

```c++
// C++ program to illustrate
// recursive approach to ternary search
#include <bits/stdc++.h>
using namespace std;
// Function to perform Ternary Search
int ternarySearch(int l, int r, int key, int ar[])
{
  if (r >= l) {
    // Find the mid1 and mid2
    int mid1 = l + (r - l) / 3;
    int mid2 = r - (r - l) / 3;
    // Check if key is present at any mid
    if (ar[mid1] == key) {
        return mid1;
    }
    if (ar[mid2] == key) {
        return mid2;
    }
    // Since key is not present at mid,
    // check in which region it is present
    // then repeat the Search operation
    // in that region
    if (key < ar[mid1]) {
      // The key lies in between l and mid1
      return ternarySearch(l, mid1 - 1, key, ar);
    }
    else if (key > ar[mid2]) {
      // The key lies in between mid2 and r
      return ternarySearch(mid2 + 1, r, key, ar);
    }
    else {
      // The key lies in between mid1 and mid2
      return ternarySearch(mid1 + 1, mid2 - 1, key, ar);
    }
  }
  // Key not found
  return -1;
}

// Driver code
int main(){
  int l, r, p, key;
  // Get the array
  // Sort the array if not sorted
  int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  // Starting index
  l = 0;
  // length of array
  r = 9;
  // Checking for 5
  // Key to be searched in the array
  key = 5;
  // Search the key using ternarySearch
  p = ternarySearch(l, r, key, ar);
  // Print the result
  cout << "Index of " << key << " is " << p << endl;
  // Checking for 50
  // Key to be searched in the array
  key = 50;
  // Search the key using ternarySearch
  p = ternarySearch(l, r, key, ar);
  // Print the result
  cout << "Index of " << key << " is " << p << endl;
}
```

Output:

```
Index of 5 is 4
Index of 50 is -1
```

### Iterative Approach of Ternary Search

```c++
// C++ program to illustrate
// iterative approach to ternary search

#include <iostream>
using namespace std;
// Function to perform Ternary Search
int ternarySearch(int l, int r, int key, int ar[]){
  while (r >= l) {
    // Find the mid1 and mid2
    int mid1 = l + (r - l) / 3;
    int mid2 = r - (r - l) / 3;
    // Check if key is present at any mid
    if (ar[mid1] == key) {
      return mid1;
    }
    if (ar[mid2] == key) {
      return mid2;
    }
    // Since key is not present at mid,
    // check in which region it is present
    // then repeat the Search operation
    // in that region
    if (key < ar[mid1]) {
      // The key lies in between l and mid1
      r = mid1 - 1;
    }
    else if (key > ar[mid2]) {
      // The key lies in between mid2 and r
      l = mid2 + 1;
    }
    else {
      // The key lies in between mid1 and mid2
      l = mid1 + 1;
      r = mid2 - 1;
    }
  }
    // Key not found
    return -1;
}

// Driver code
int main()
{
  int l, r, p, key;
  // Get the array
  // Sort the array if not sorted
  int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  // Starting index
  l = 0;
  // length of array
  r = 9;
  // Checking for 5
  // Key to be searched in the array
  key = 5;
  // Search the key using ternarySearch
  p = ternarySearch(l, r, key, ar);
  // Print the result
  cout << "Index of "<<key<<" is " << p << endl;
  // Checking for 50
  // Key to be searched in the array
  key = 50;
  // Search the key using ternarySearch
  p = ternarySearch(l, r, key, ar);
  // Print the result
  cout << "Index of "<<key<<" is " << p;
}
```

Output:

```
Index of 5 is 4
Index of 50 is -1
```

Time Complexity: `O(log3(n))` ,where n is the size of the array.
Uses: In finding the maximum or minimum of a `unimodal` function.
