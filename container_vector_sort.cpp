#include "iostream"
#include "vector"
#include "algorithm"

//不排序
void vector_normal()
{
  std::vector<int> vec(2);
  std::cout << "vec size: " << vec.size() << std::endl;
  //初始化
  vec[0] = 0;
  vec[1] = 1;
  vec.push_back(5);
  vec.push_back(6);
  vec.push_back(7);
  vec.push_back(8);
  //vector的好处就是可以动态增加长度
  std::cout << "vec size: " << vec.size() << std::endl;

  std::cout << "first element: " << vec[0] << std::endl;
  std::cout << "second element: " << vec[1] << std::endl;
  std::vector<int>::iterator vecIter = vec.begin();
  //error: iterator 没有重载<<
  // std::cout << "vec begin(): " << vecIter << std::endl;
  for (; vecIter != vec.end(); ++vecIter)
  {
    std::cout << "element: " << *vecIter << std::endl;
  }
}

bool CompSort(const int &a,const int &b)
{
  return a>b;
}

//自定义排序
void vector_greater_sort()
{
  std::vector<int> vec(2);
  //初始化
  vec[0] = 0;
  vec[1] = 1;
  vec.push_back(5);
  vec.push_back(6);
  vec.push_back(7);
  vec.push_back(8);

  sort(vec.begin(), vec.end(), CompSort);

  std::cout << "first element: " << vec[0] << std::endl;
  std::cout << "second element: " << vec[1] << std::endl;
  std::vector<int>::iterator vecIter = vec.begin();
  for (; vecIter != vec.end(); ++vecIter)
  {
    std::cout << "element: " << *vecIter << std::endl;
  }
}

void vector_greater_sort_s()
{
  int salePath[4][4] = {0};

  salePath[0][1] = 2;
  salePath[0][2] = 6;
  salePath[0][3] = 5;
  salePath[1][2] = 4;
  salePath[1][3] = 4;
  salePath[1][0] = salePath[0][1];
  salePath[2][3] = 2;
  salePath[2][1] = salePath[1][2];
  salePath[2][0] = salePath[0][2];
  salePath[3][0] = salePath[3][0];
  salePath[3][1] = salePath[1][3];
  salePath[3][2] = salePath[2][3];

  std::vector<int> sales;
  for (int i = 0; i < 4; ++i)
  {
    for(int j = 0; j < 4; ++j)
    {
      sales.push_back(salePath[i][j]);
      std::cout << salePath[i][j] << " ";
    }
    std::cout << std::endl;
  }

  std::cout << "-----" << std::endl;
  sort(sales.begin(), sales.end(), CompSort);

  std::vector<int>::iterator Iter = sales.begin();
  int h = 0;
  for(; Iter != sales.end(); ++Iter)
  {
    std::cout << *Iter << " ";
    if ( (++h)%4 == 0)
      std::cout << std::endl;
  }
}

struct vecValue
{
  int value;
  //重载<
  friend bool operator< (vecValue A, vecValue B)
  {
    return B.value < A.value;
    // return A.value < B.value;
  }
  //重载<<
  friend std::ostream& operator<< (std::ostream& output, const vecValue& vec)
  {
    output << vec.value;
    return output;
  }
};

//自定义排序
void vector_custom_sort()
{
  std::vector<vecValue> vec;
  //初始化
  vecValue vecSort;
  for (int i = 0; i < 5; ++i)
  {
    vecSort.value = i;
    vec.push_back(vecSort);
  }

  std::vector<vecValue>::iterator vecIter = vec.begin();
  std::cout << "before sort: " << std::endl;
  for (; vecIter != vec.end(); ++vecIter)
  {
    std::cout << "element: " << vecIter->value << std::endl;
  }

  std::cout << "after sort: " << std::endl;
  sort(vec.begin(), vec.end());
  vecIter = vec.begin();
  for (; vecIter != vec.end(); ++vecIter)
  {
    std::cout << "element: " << vecIter->value << std::endl;
  }

  std::cout << "operator<<: " <<std::endl;
  vecIter = vec.begin();
  for (; vecIter != vec.end(); ++vecIter)
  {
    std::cout << "element: " << *vecIter << std::endl;
  }
}

int main()
{
  vector_normal();
  std::cout << "----------" << std::endl;
  vector_greater_sort();
  std::cout << "----------" << std::endl;
  vector_greater_sort_s();
  std::cout << "----------" << std::endl;
  vector_custom_sort();

  return 0;
}
