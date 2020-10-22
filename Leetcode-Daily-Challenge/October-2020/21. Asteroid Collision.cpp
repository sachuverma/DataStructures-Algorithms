/*
Asteroid Collision
==================

We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.


Example 1:
Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10.  The 5 and 10 never collide.

Example 2:
Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.

Example 3:
Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.

Example 4:
Input: asteroids = [-2,-1,1,2]
Output: [-2,-1,1,2]
Explanation: The -2 and -1 are moving left, while the 1 and 2 are moving right. Asteroids moving the same direction never meet, so no asteroids will meet each other.


Constraints:
1 <= asteroids <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0

Hint #1  
Say a row of asteroids is stable. What happens when a new asteroid is added on the right?
*/

class Solution
{
public:
  vector<int> asteroidCollision(vector<int> &asteroids)
  {
    stack<int> s;

    for (auto asteroid : asteroids)
    {
      if (s.empty() || asteroid > 0)
        s.push(asteroid);
      else
      {
        while (true)
        {
          auto el = s.top();
          if (el < 0)
          {
            s.push(asteroid);
            break;
          }
          else if (el == -asteroid)
          {
            s.pop();
            break;
          }
          else if (el > -asteroid)
            break;
          else
          {
            s.pop();
            if (s.empty())
            {
              s.push(asteroid);
              break;
            }
          }
        }
      }
    }

    vector<int> ans;
    while (s.size())
    {
      ans.push_back(s.top());
      s.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};
