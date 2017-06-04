#include "iostream"
#include "sstream"
#include "boost/lexical_cast.hpp"

//string to int
int StringToInt(std::string ss)
{
  int destInt = 0;
  std::stringstream sourceString("");
  sourceString << ss;
  sourceString >> destInt;
  return destInt;
}

int main()
{
  std::cout << StringToInt("123") << std::endl;
  //c++11 std::stoi
  std::cout << std::stoi("1231231239") << std::endl;
  //boost::lexical_cast
  std::cout << boost::lexical_cast<double>("123.019") << std::endl;
  std::cout << boost::lexical_cast<int>("233") << std::endl;

  //int to string
  std::string str = "123";
  std::string toStr = std::to_string(100);
  std::cout << str << std::endl;
  std::cout << toStr << std::endl;

  std::string strTemp = str + toStr;
  std::cout << strTemp << std::endl;

  return 0;
}
