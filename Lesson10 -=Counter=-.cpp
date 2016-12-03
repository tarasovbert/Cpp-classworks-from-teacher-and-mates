#include <iostream>
#include <cstring>
using namespace std;


class Counter
{
private:
	int value;
public:
	Counter(int val = 0)
		: value{ val }
	{}

	Counter(const Counter& a) = default;
	Counter& operator=(const Counter& a) = default;
	~Counter() = default;

	int& count()
	{
		return value;
	}

	Counter operator+(const Counter& a)
	{
		return Counter(value + a.value);
	}

	Counter operator-(const Counter& a)
	{
		return Counter(value - a.value);
	}

	const Counter& operator+=(const Counter& a)
	{
		value += a.value;
		return *this;
	}

	const Counter& operator-=(const Counter& a)
	{
		value -= a.value;
		return *this;
	}

	bool operator==(const Counter& a)
	{
		return value == a.value;
	}

	bool operator!=(const Counter& a)
	{
		return !operator==(a.value);
	}

	Counter& operator++()
	{
		 ++value;
		 return *this;
	}

	Counter& operator--()
	{
		--value;
		return *this;
	}
	
	Counter operator++(int)
	{
		return Counter(value++);
	}

	Counter operator--(int)
	{
		return Counter(value--);
	}

	friend ostream& operator<< (ostream& os, const Counter& a);


};



ostream& operator<< (ostream& os, const Counter& a)
{
	os << a.value;
	return os;
}



void main()
{
	Counter a(5), b(5);
	Counter c = a + b;
	cout << c << endl;
	cout << (a == b) << endl;
	cout << (a != b) << endl;
	Counter d(a);
	cout << d << endl;
	cout << ++d << endl; //префиксная
	cout << d++ << endl; //постфиксная
}