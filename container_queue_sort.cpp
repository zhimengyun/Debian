#include "iostream"
#include "queue"

//默认 - 降序
void priority_sort_descend()
{
  std::priority_queue<int> proQueue;
  proQueue.push(10);
  proQueue.push(2);
  proQueue.push(6);
  proQueue.push(8);
  int proQueue_len = proQueue.size();
  std::cout << "priority_queue length: " << proQueue_len << std::endl;
  for (int i = 0; i < proQueue_len; ++i)
  {
    std::cout << proQueue.top() << std::endl;
    proQueue.pop();
  }
}

//升序
void priority_sort_ascend()
{
  //invalid - std::list<int>
  std::priority_queue<int, std::vector<int>, std::greater<int> > proQueue;
  proQueue.push(10);
  proQueue.push(2);
  proQueue.push(6);
  proQueue.push(8);
  int proQueue_len = proQueue.size();
  std::cout << "priority_queue length: " << proQueue_len << std::endl;
  for (int i = 0; i < proQueue_len; ++i)
  {
    std::cout << proQueue.top() << std::endl;
    proQueue.pop();
  }
}

struct value{
  int anymore;
  friend bool operator< (value A, value B)
  {
    // return A.anymore < B.anymore;
    return B.anymore < A.anymore;
  }
};

//自定义排序
void priority_sort_custom()
{
  value verify_value;
  std::priority_queue<value> proQueue;
  for (int i = 0; i < 5; ++i)
  {
    verify_value.anymore = i;
    proQueue.push(verify_value);
  }
  int proQueue_len = proQueue.size();
  std::cout << "priority_queue length: " << proQueue_len << std::endl;
  for (int i = 0; i < proQueue_len; ++i)
  {
    std::cout << proQueue.top().anymore << std::endl;
    proQueue.pop();
  }
}

int main()
{
  priority_sort_descend();
  std::cout << "----------" << std::endl;
  priority_sort_ascend();
  std::cout << "----------" << std::endl;
  priority_sort_custom();
  std::cout << "----------" << std::endl;
  std::vector<int> verify_vec;
  verify_vec.push_back(79);
  std::cout << verify_vec[0] << std::endl;

  return 0;
}
