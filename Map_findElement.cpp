#include "iostream"
#include "map"

void findElement(std::map<std::string, std::string>& a)
{
  std::map<std::string, std::string>::iterator m_map_iter;
  m_map_iter = a.find("hello");
  //iterator非空判断
  if (a.end() != m_map_iter)
  {
    std::cout << m_map_iter->second << std::endl;
  }

  m_map_iter = a.find("error");
  if (a.end() != m_map_iter)
  {
    std::string s = m_map_iter->second;
    std::cout << s << std::endl;
  }
}

void findElementSafe(const std::map<std::string, std::string>& a)
{
  //Tips: const_iterator
  std::map<std::string, std::string>::const_iterator m_map_iter;
  m_map_iter = a.find("hello");
  if (a.end() != m_map_iter)
  {
    std::cout << m_map_iter->second << std::endl;
  }

  m_map_iter = a.find("error");
  if (a.end() != m_map_iter)
  {
    std::string s = m_map_iter->second;
    std::cout << s << std::endl;
  }
}

int main()
{
  std::map<std::string, std::string> m_map;
  m_map["hello"] = "Map";
  findElement(m_map);

  m_map["hello"] = "Map Safe";
  findElementSafe(m_map);

  return 0;
}
