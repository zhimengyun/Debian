#include "iostream"

template<typename T>
class common
{
public:
	void print(T p);
};

template<typename T>
void common<T>::print(T p)
{
	std::cout << "common::print(): " << p << std::endl;
}

template<typename T1, typename T2, typename T3>
class common_option
{
public:
	void print(T1 p);
};

template<typename T1, typename T2, typename T3>
void common_option<T1, T2, T3>::print(T1 p)
{
	std::cout << "common_option::print(): " << p << std::endl;
}

int main()
{
	common<int> c_int;
	c_int.print(1602);
	common<double> c_double;
	c_double.print(2333.6666);
	common<std::string> c_string;
	c_string.print("bilibili");

	common_option<int, double, std::string> co_int;
	co_int.print(1991);
	common_option<double, int, std::string> co_double;
	co_double.print(3.1415926);
	common_option<std::string, int, double> co_string;
	co_string.print("niconiconi");
	return 0;
}
