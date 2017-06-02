#include "iostream"
#include "memory"

//智能指针
class SmartPoint
{
public:
  SmartPoint();
  void print();

private:
  int itself;
};

SmartPoint::SmartPoint()
{
  itself = 7;
}

void SmartPoint::print()
{
  std::cout << "SmartPoint mamber variable: " << itself << std::endl;
}

int main()
{
  SmartPoint* smart = new SmartPoint;
  smart->print();

  std::shared_ptr<SmartPoint> sp(new SmartPoint);
  sp->print();

  typedef std::shared_ptr<SmartPoint> smartPtr;
  smartPtr(new SmartPoint);

  int smartSize = sizeof(SmartPoint);
  std::cout << "smartSize: " << smartSize << std::endl;

  return 0;
}
