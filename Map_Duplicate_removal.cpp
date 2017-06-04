#include "iostream"
#include "vector"
#include "map"

//map的自动去重
int basic(std::vector<unsigned int> &v, std::map<unsigned int, std::string> &m)
{
  std::vector<unsigned int>::iterator it;
  for(it = v.begin(); it != v.end(); ++it)
  {
    m[*it] = "x";
  }

  std::cout << v.size() << std::endl;
  std::cout << m.size() << std::endl;

  if(v.size() != m.size())
  {
    return -1;
  }

  return 0;
}


int main()
{
  std::vector<unsigned int> v;
  std::map<unsigned int, std::string> m;
  v.push_back(1);
  v.push_back(1);

  // basic(v, m);
  std::cout << basic(v, m) << std::endl; // -1，说明 vector 和 map 大小不相等。

  return 0;
}
