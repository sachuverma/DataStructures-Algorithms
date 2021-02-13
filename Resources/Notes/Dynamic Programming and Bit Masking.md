# Dynamic Programming and Bit Masking

First thing to make sure before using bitmasks for solving a problem is that it must be having small constraints, as solutions which use bitmasking generally take up exponential time and memory.   

Let's first try to understand what Bitmask means. Mask in Bitmask means hiding something. Bitmask is nothing but a binary number that represents something. Let's take an example. Consider the set `A={1,2,3,4,5}`. We can represent any subset of `A` using a bitmask of length `5` , with an assumption that if `ith (0<=i<=4)` bit is set then it means `ith` element is present in subset. So the bitmask `01010` represents the subset `{2,4}`   

Now the benefit of using bitmask. We can set the `ith` bit, unset the `ith` bit, check if `ith` bit is set in just one step each. Let's say the bitmask,`b=01010` .   

Set the `ith` bit: `b|(1<<i)`. Let `i=0`, so,   
```C++
  (1 << i) = 00001
  01010 | 00001 = 01011
```
So now the subset includes the `0th` element also, so the subset is `{1,2,4}`.   

Unset the `ith` bit: `b&!(1<<i)`. Let `i=1`, so,    
```C++
  (1 << i) = 00010
  !(1 << i) = 11101
  01010 & 11101 = 01000
```
Now the subset does not include the `1st` element, so the subset is `{4}`.   

Check if `ith` bit is set: `b&(1<<i)`, doing this operation, if `ith` bit is set, we get a non zero integer otherwise, we get zero. Let `i=3`   
```C++
  (1 << i) = 01000
  01010 & 01000 = 01000
```

Clearly the result is non-zero, so that means `3rd` element is present in the subset.   

Let's take a problem, given a set, count how many subsets have sum of elements greater than or equal to a given value.   

Algorithm is simple:   
```C++
solve(set, set_size, val)
    count = 0
    for x = 0 to power(2, set_size)
        sum = 0
        for k = 0 to set_size        
            if kth bit is set in x
                sum = sum + set[k]
        if sum >= val
             count = count + 1
    return count
```   
To iterate over all the subsets we are going to each number from 0 to (2^set_size)-1   
The above problem simply uses bitmask and complexity is O((2^n)n).   

Now, let's take another problem that uses dynamic programming along with bitmasks.   

**Assignment Problem:**      
There are N persons and N tasks, each task is to be alloted to a single person. We are also given a matrix `cost` of size `NxN`, where `cost[i][j]` denotes, how much person `i` is going to charge for task `j`. Now we need to assign each task to a person in such a way that the total cost is minimum. Note that each task is to be alloted to a single person, and each person will be alloted only one task.   

The brute force approach here is to try every possible assignment. Algorithm is given below:   
```C++
assign(N,  cost)
    for i = 0 to N
        assignment[i] = i            //assigning task i to person i
    res = INFINITY
    for j = 0 to factorial(N)
        total_cost = 0
        for i = 0 to N
            total_cost = total_cost + cost[i][assignment[i]]
        res = min(res, total_cost)
        generate_next_greater_permutation(assignment)
    return res
```

The complexity of above algorithm is `O(N!)`, well that's clearly not good.   
Let's try to improve it using dynamic programming. Suppose the state of `dp` is `(k,mask)`, where `k` represents that person `0` to `k-1` have been assigned a task, and `mask` is a binary number, whose `ith` bit represents if the `ith` task has been assigned or not.   
Now, suppose, we have `answer(k,mask)`, we can assign a task `i` to person `k`, iff `ith` task is not yet assigned to any peron i.e. `mask&(1<<i) = 0` then, `answer(k+1, mask|(1<<i))` will be given as:  
```C++
answer(k+1, mask|(1<<i)) = min(answer(k+1, mask|(1<<i)),answer(k, mask)+cost[k][i])
```

One thing to note here is `k` is always equal to the number set bits in `mask`, so we can remove that. So the dp state now is just `(mask)`, and if we have `answer(mask)`, then  
```C++
answer(mask|(1<<i)) = min(answer(mask|(1<<i)),answer(mask)+cost[x][i])
```

here `x = number of set bits` in `mask`.  
Complete algorithm is given below:
```C++
assign(N, cost)
    for i = 0 to power(2,N)
        dp[i] = INFINITY
    dp[0] = 0
    for mask = 0 to power(2, N)
        x = count_set_bits(mask)
        for j = 0 to N
            if jth bit is not set in i
                dp[mask|(1<<j)] = min(dp[mask|(1<<j)], dp[mask]+cost[x][j])
    return dp[power(2,N)-1]  
```

Time complexity of above algorithm is `O((2^n)n)` and space complexity is `O(2^n)`.
This is just one problem that can be solved using DP+bitmasking. There's a whole lot.
Let's go to another problem, suppose we are given a graph and we want to find out if it contains a Hamiltonian Path. This problem can also be solved using DP+bitmasking in `O((2^n)(n^2))` time complexity and `O((2^n)n)` space complexity. 