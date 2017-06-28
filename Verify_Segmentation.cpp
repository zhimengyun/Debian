#include "iostream"

//数组越界测试 - 不一定会导致 segmentation fault
void ArrayBound()
{
  int num[10] = {0};
  std::cout << num[11] << std::endl;

  num[12] = 9;
  std::cout << num[12] << std::endl;
}

void ArrayBoundMore()
{
  int *boom = new int[10];
  std::cout << boom[0] << std::endl;

  //segmentation fault不是标准异常，故无法捕捉
  try
  {
    boom[11] = 10;
    std::cout << boom[11] << std::endl;
    //std::cout << boom[-5] << std::endl;
  }
  catch(std::exception)
  {
    std::cout << "boom fetch ERROR!" << std::endl;
  }
  catch(...)
  {
    std::cout << "Invalid memory reference!" << std::endl;
  }
}

//产生一个 segmentation fault
void SIGSEGV()
{
  //定义一个空指针
  int *p = 0;
  //对空指针解引用或赋值，产生一个段错误（SIGSEGV 信号）
  int num = *p;
  //*p = 10;
}

void NotSIGSEGV()
{
  int num = 0;
  //debug
  std::cout << &num << std::endl;
  int *p = &num;
  //debug
  std::cout << p << std::endl;
  *p = 10;
  int temp = *p;
  std::cout << *p << std::endl;
  std::cout << temp << std::endl;
}

int main()
{
  ArrayBound();
  ArrayBoundMore();
  //SIGSEGV();
  NotSIGSEGV();

  return 0;
}
