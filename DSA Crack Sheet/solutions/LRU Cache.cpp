/*
LRU Cache
=========

The task is to design and implement methods of an LRU cache. The class has two methods get() and set() which are defined as follows.
get(x)   : Returns the value of the key x if the key exists in the cache otherwise returns -1.
set(x,y) : inserts the value if the key x is not already present. If the cache reaches its capacity it should invalidate the least recently used item before inserting the new item.
In the constructor of the class the size of the cache should be intitialized.

Example 1:
Input:
N = 2
Q = 2
Queries = SET 1 2 GET 1
Output: 2
Explanation: Cache Size = 2
SET 1 2 GET 1
SET 1 2 : 1 -> 2
GET 1 : Print the value corresponding
to Key 1, ie 2.

Example 2:
Input:
N = 2
Q = 7
Queries = SET 1 2 SET 2 3 SET 1 5
SET 4 5 SET 6 7 GET 4 SET 1 2 GET 3
Output: 5 -1
Explanation: Cache Size = 2
SET 1 2 SET 2 3 SET 1 5 SET 4 5
SET 6 7 GET 4 SET 1 2 GET 1
SET 1 2 : 1 -> 2
SET 2 3 : 1 -> 2, 2 -> 3 (the most
recently used one is kept at the
rightmost position) 
SET 1 5 : 2 -> 3, 1 -> 5
SET 4 5 : 1 -> 5, 4 -> 5 (Cache size
is 2, hence we delete the least
recently used key-value pair)
SET 6 7 : 4 -> 5, 6 -> 7 
GET 4 : Prints 5 
(The cache now looks like
6 -> 7, 4->5)
SET 1 2 : 4 -> 5, 1 -> 2 
(Cache size is 2, hence we delete 
the least recently used key-value 
pair)
GET 1 : No key value pair having 
key = 3. Hence, -1 is printed.

Your Task:
You only need to complete the provided functions get() and set(). 

Expected Time Complexity: O(1) for both get() and set().
Expected Auxiliary Space: O(1) for both get() and set(). (though, you may use extra space for cache storage and implementation purposes).

Constraints:
1 <= N <= 1000
1 <= Q <= 100000
1 <= x, y <= 1000
*/

class LRUCache
{
public:
  unordered_map<int, pair<int, list<int>::iterator>> Cache;
  list<int> order;
  int size;

  //Constructor for initializing the cache capacity with the given value.
  LRUCache(int cap)
  {
    size = cap;
  }

  //Function to return value corresponding to the key.
  int get(int key)
  {
    if (Cache.find(key) == Cache.end())
      return -1;
    int ans = Cache[key].first;
    auto itr = Cache[key].second;

    order.erase(itr);
    order.push_front(key);
    Cache[key].second = order.begin();
    return ans;
  }

  //Function for storing key-value pair.
  void set(int key, int value)
  {
    if (Cache.find(key) == Cache.end())
    {
      if (order.size() == size)
      {
        auto oldest = order.back();
        Cache.erase(oldest);
        order.pop_back();
      }
      order.push_front(key);
      Cache[key] = {value, order.begin()};
    }
    else
    {
      order.erase(Cache[key].second);
      order.push_front(key);
      Cache[key] = {value, order.begin()};
    }
  }
};