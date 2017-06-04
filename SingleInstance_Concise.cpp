#include "iostream"

class SingleInstance
{
private:
  SingleInstance();
  // SingleInstance(const SingleInstance&);
  // SingleInstance& operator= (const SingleInstance&);
  ~SingleInstance();
  static SingleInstance* m_Instance;

public:
  static pthread_mutex_t mutex;
  static SingleInstance* getInstance();
  void simplePrint();
};

SingleInstance::SingleInstance()
{
  pthread_mutex_init(&mutex, NULL);
}

//拷贝构造函数
// SingleInstance::SingleInstance(const SingleInstance&)
// {}

// 赋值函数
// SingleInstance& SingleInstance::operator= (const SingleInstance&)
// {
//   return *this;
// }

//error: cannot declare member function ‘static SingleInstance* SingleInstance::getInstance()’ to have static linkage [-fpermissive]
// static SingleInstance* SingleInstance::getInstance()
// {
//   if (NULL == m_Instance)
//   {
//     m_Instance = new SingleInstance();
//   }
//   return m_Instance;
// }

pthread_mutex_t SingleInstance::mutex;

SingleInstance* SingleInstance::m_Instance = 0;

//线程安全
SingleInstance* SingleInstance::getInstance()
{
  if (NULL == m_Instance)
  {
    pthread_mutex_lock(&mutex);
    if (NULL == m_Instance)
    {
      //释放问题？
      m_Instance = new SingleInstance();
    }
    pthread_mutex_unlock(&mutex);
  }
  return m_Instance;
}

void SingleInstance::simplePrint()
{
  std::cout << "simple print~" << std::endl;
}

int main()
{
  //error: ‘SingleInstance::SingleInstance()’ is private
  //SingleInstance instance;

  SingleInstance* instance_try = SingleInstance::getInstance();
  instance_try->simplePrint();

  SingleInstance* instance_again = instance_try;
  // SingleInstance* instance_again = SingleInstance::getInstance();
  instance_again->simplePrint();

  if (instance_try == instance_again)
  {
    std::cout << "instance_try == instance_again" << std::endl;
  }

  return 0;
}
