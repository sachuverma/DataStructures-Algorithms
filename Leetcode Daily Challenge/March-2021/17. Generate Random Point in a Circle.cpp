/*
Generate Random Point in a Circle
===================================

Given the radius and x-y positions of the center of a circle, write a function randPoint which generates a uniform random point in the circle.

Note:
input and output values are in floating-point.
radius and x-y position of the center of the circle is passed into the class constructor.
a point on the circumference of the circle is considered to be in the circle.
randPoint returns a size 2 array containing x-position and y-position of the random point, in that order.

Example 1:
Input: 
["Solution","randPoint","randPoint","randPoint"]
[[1,0,0],[],[],[]]
Output: [null,[-0.72939,-0.65505],[-0.78502,-0.28626],[-0.83119,-0.19803]]

Example 2:
Input: 
["Solution","randPoint","randPoint","randPoint"]
[[10,5,-7.5],[],[],[]]
Output: [null,[11.52438,-8.33273],[2.46992,-16.21705],[11.13430,-12.42337]]

Explanation of Input Syntax:
The input is two lists: the subroutines called and their arguments. Solution's constructor has three arguments, the radius, x-position of the center, and y-position of the center of the circle. randPoint has no arguments. Arguments are always wrapped with a list, even if there aren't any.
*/

class Solution
{
public:
  const double PI = 2 * acos(0.0);
  double m_radius, m_x_center, m_y_center;
  double uniform()
  {
    return (double)rand() / RAND_MAX;
  }

  Solution(double radius, double x_center, double y_center)
  {
    srand(time(NULL));
    m_radius = radius;
    m_x_center = x_center;
    m_y_center = y_center;
  }

  vector<double> randPoint()
  {
    double theta = 2 * PI * uniform();
    double r = sqrt(uniform());
    return vector<double>{m_x_center + r * m_radius * cos(theta), m_y_center + r * m_radius * sin(theta)};
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
