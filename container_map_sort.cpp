#include "iostream"
#include "map"
#include "algorithm"

//重载<<
std::ostream& operator<< (std::ostream& output, const std::pair<int, int>& mapValue)
{
  output << mapValue.first << " ==> " << mapValue.second;
  return output;
}

void map_normal()
{
  std::map<int, int> m_map;
  //初始化
  m_map[9] = 9;
  m_map[8] = 8;
  m_map[7] = 7;
  m_map.insert(std::pair<int, int>(4, 1));
  m_map.insert(std::pair<int, int>(4, 4));
  m_map.insert(std::pair<int, int>(3, 4));
  m_map.insert(std::pair<int, int>(1, 2));

  //遍历
  std::map<int, int>::iterator mapIter = m_map.begin();
  std::cout << "before operator<<: " << std::endl;
  for(; mapIter != m_map.end(); ++mapIter)
  {
    std::cout << "map element: " << mapIter->first << " ==> " << mapIter->second << std::endl;
  }

  std::cout << "after operator<<: " << std::endl;
  mapIter = m_map.begin();
  for(; mapIter != m_map.end(); ++mapIter)
  {
    std::cout << "map element: " << *mapIter << std::endl;
  }
}

void map_greater_sort()
{
  std::map<int, int, std::greater<int>> m_map;
  //初始化
  m_map[9] = 9;
  m_map[8] = 8;
  m_map[7] = 7;
  m_map.insert(std::pair<int, int>(4, 1));
  m_map.insert(std::pair<int, int>(4, 4));
  m_map.insert(std::pair<int, int>(3, 4));
  m_map.insert(std::pair<int, int>(1, 2));

  //遍历
  std::map<int, int>::iterator mapIter = m_map.begin();
  for(; mapIter != m_map.end(); ++mapIter)
  {
    std::cout << "map element: " << mapIter->first << " ==> " << mapIter->second << std::endl;
  }
}

struct CompSort
{
  //重载()
  bool operator() (const int& A, const int B)
  {
    // return A < B;
    return B < A;
  }
};

//map的自动去重 及 自定义排序。注意：map 不能使用 std::sort
void map_custom_sort()
{
  std::map<int, int, CompSort> m_map;
  //初始化
  m_map[9] = 9;
  m_map[8] = 8;
  m_map[7] = 7;
  m_map.insert(std::pair<int, int>(4, 1));
  m_map.insert(std::pair<int, int>(4, 4));
  m_map.insert(std::pair<int, int>(3, 4));
  m_map.insert(std::pair<int, int>(1, 2));

  //遍历
  std::map<int, int>::iterator mapIter = m_map.begin();
  for(; mapIter != m_map.end(); ++mapIter)
  {
    std::cout << "map element: " << mapIter->first << " ==> " << mapIter->second << std::endl;
  }
}

int main()
{
  map_normal();
  std::cout << "----------" << std::endl;
  map_greater_sort();
  std::cout << "----------" << std::endl;
  map_custom_sort();

  return 0;
}
