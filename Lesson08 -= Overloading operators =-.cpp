#include <iostream>

class Array
{
private:
	int* arr;
	int size;

public:
	Array(int size_, int value)
		: Array(size_)
	{
		std::cout << " Array(int size_, int value)\n ";
		for (int i = 0; i < size; ++i)
			arr[i] = value;
	}

	Array(int size_)
		: arr{ new int[size_] }, size{ size_ }
	{
		std::cout << "Array(int size_)\n ";
	}

	Array(int* array_, int size_)
		: Array(size_)
	{
		for (int i = 0; i < size; ++i)
			arr[i] = array_[i];
	}

	Array(const Array& obj)
		: Array(obj.size)
	{
		for (int i = 0; i < size; ++i)
		{
			arr[i] = obj.Index(i);
			obj.Index(i) = 0;
		}
		//obj.setElement(1, 10);
	}

	void setElement(int index_, int value)
	{
		if (index_ < 0 || index_ >= size)
		{
			std::cout << "Invalid index: " << index_ << ". Return last element." << std::endl;
		}
		else
		{
			arr[index_] = value;
		}
	}

	int& Index(int index) const
	{
		if (index < 0 || index >= size)
		{
			std::cout << "Invalid index: " << index << ". Return last element." << std::endl;
			return arr[size - 1];
		}
		return arr[index];
	}

	int getSize() const
	{
		return size;
	}

	Array getCopy() const
	{
		return *this;
	}

	int& operator[] (int index_) const
	{
		return Index(index_);
	}

	~Array()
	{
		std::cout << "~Array()\n ";
		delete[] arr;
	}

	friend Array operator+ (const Array&, const Array&);

	const Array& operator= (const Array& obj)
	{
		if (this != &obj)
		{
		delete[] arr;
		arr = new int[obj.size];
		size = obj.size;
		for (int i = 0; i < size; ++i)
			arr[i] = obj.arr[i];
		}
		return *this;
	}
};

Array funk(Array a_)
{
	return Array(2);
}

Array operator+ (const Array& obj, const Array& obj2)
{
	Array result(obj.size + obj2.size);
	for (int i = 0; i < obj.size; ++i)
		result[i] = obj.arr[i];
	for (int i = obj.size; i < result.size; ++i)
		result[i] = obj2.arr[i - obj.size];
	return result;
}

std::ostream& operator<<(std::ostream& oss, const Array& arr)
{
	for (int i = 0; i < arr.getSize(); ++i)
		oss << arr[i] << " ";
	return oss;
}

std::istream& operator>>(std::istream& iss, Array& arr)
{
	for (int i = 0; i < arr.getSize(); ++i)
		iss >> arr[i];
	return iss;
}

int main()
{
	int array[] = { 5, 2, 6, 7, 8 };
	int array2[] = { 5, 6, 6, 8, 8, 7 };
	Array arr(array2, 6);
	Array arr2 = (array, 5);
	arr2 = arr;
	//Array result = arr + arr2;
	arr2 = arr2;

	//std::cin >> result;
	std::cout << arr << " ";
	std::cout << std::endl;
	std::cout << arr2 << " ";

	return 0;
}