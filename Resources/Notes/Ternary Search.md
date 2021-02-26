## Ternary Search

Like linear search and binary search, ternary search is a searching technique that is used to determine the position of a specific value in an array. In binary search, the sorted array is divided into two parts while in ternary search, it is divided into parts and then you determine in which part the element exists.

Ternary search, like binary search, is a divide-and-conquer algorithm. It is mandatory for the array (in which you will search for an element) to be sorted before you begin the search. In this search, after each iteration it neglects 1/3 part of the array and repeats the same operations on the remaining 2/3

**Implementation**

```c++
int ternary_search(int l,int r, int x) {
  if(r >= l) {
    int mid1 = l + (r-l)/3;
    int mid2 = r -  (r-l)/3;
    if(ar[mid1] == x) return mid1;
    if(ar[mid2] == x) return mid2;
    if(x<ar[mid1]) return ternary_search(l,mid1-1,x);
    else if(x>ar[mid2]) return ternary_search(mid2+1,r,x);
    else return ternary_search(mid1+1,mid2-1,x);
  }
  return -1;
}
```

Let us consider the following example to understand the code.

Let the sorted array be `arr[] = {2,3,5,6,8,9,12,13,14}` with indices from 0 to 8. You are required to find the position of `x = 13` in this array.
Divide the sorted array into the following 3 parts by evaluating the values of `mid1` and `mid2`:

- {2,3,5}
- {6,8,9}
- {12,13,14}

Here `arr[mid1] = 5` and `arr[mid2] = 12 `. As 13 is not equal to 5 and 12 and it is also not smaller than 5, you can safely assume that it lies in the 3rd part of the array as it is greater than 12.

Run the ternary search again with `left = 7` and `right = 8`.

Now, `arr[mid1] = 13` and `arr[mid2] = 14`.

As `arr[mid1] = x`, `mid1` is the required answer.

If the value is not in the array, it returns `-1` as the answer.

_Complexity_
`O(log3(n))` , where `n` is the size of the array

**Use of ternary search:**
This concept is used in unimodal functions to determine the maximum or minimum value of that function. Unimodal functions are functions that, have a single highest value.

Let us consider a function `fn` in the interval `[a,b]` and you are required to determine the `x` for which `fn(x)` is maximized. The function `fn` is unimodal in nature, i.e. it strictly increases in the interval `[a,x]` and strictly decreases in the interval `[x,b]`.

This can be done by various other methods like double differentiation or by using a modified binary search. In the case when the function cannot be differentiated easily, ternary search is useful. It is less prone to errors and easy to implement when:

- Dealing with floating point integers
- Required maximum value is reached at the end of the interval.
