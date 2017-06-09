#include "iostream"
//重载操作符
//内联函数，用空间换时间

class Overload
{
public:
	Overload(int getVerify);
	inline bool operator==(const Overload& o);
	inline int operator+(const Overload& i);

private:
	int verify;
};

Overload::Overload(int getVerify) : verify(getVerify)
{}

inline bool Overload::operator==(const Overload& o)
{
	if (this->verify == o.verify)
	{
		return true;
	}
	return false;
}

inline int Overload::operator+(const Overload& i)
{
	return this->verify + i.verify;
}

int main()
{
	Overload left(10), right(10);
	if (left == right)
	{
		std::cout << "left == right" << std::endl;
	}
	else
	{
		std::cout << "left != right" << std::endl;
	}
	int value = 0;
	value = left + right;
	std::cout << value << std::endl;

	return 0;
}
