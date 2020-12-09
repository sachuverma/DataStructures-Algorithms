## **Split String on " "(spaces)**

### 1. **stringstream**

Code:

```
std::string s = "What is the right way to split a string into a vector of strings";
std::stringstream ss(s);
std::istream_iterator<std::string> begin(ss);
std::istream_iterator<std::string> end;
std::vector<std::string> vstrings(begin, end);
std::copy(vstrings.begin(), vstrings.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
```

Output:

```
What
is
the
right
way
to
split
a
string
into
a
vector
of
strings
```

### 2. **Using Boost Library**

```
#include <boost/algorithm/string.hpp>
std::vector<std::string> strs;
boost::split(strs, "string to split", boost::is_any_of("\t "));
```
