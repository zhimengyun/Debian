#include "iostream"

int main()
{
  //定义一个空指针
  int *p = 0;
  //对空指针解引用或赋值，产生一个段错误（SIGSEGV 信号）
  int num = *p;
  //*p = 10;

  std::cout << *p << std::endl;

  return 0;
}
