#ifndef __ARRAY__
#define __ARRAY__
#include <iostream>
#include <cstdlib>
using namespace std;
template<typename T>
class Array
{
	protected:
		T *data; 
		int len;
	public:
		Array(int size);
		~Array();
		
		int length();	
		T& operator[](int i);
		T operator[](int i) const;
		
		void print();
};
template<typename T>
Array<T>::Array(int size)
{
	if(size <= 0)
		cout << "Array bound error!" << endl;
	else
	{
		len = size;
		data = new T[len];
	}
}
template<typename T>
Array<T>::~Array()
{
	delete []data;
}
template<typename T>
int Array<T>::length()
{
	return len;
}
template<typename T>
T& Array<T>::operator[](int i)
{
	static T tmp;
	if(i >= 0 && i < len)
		return data[i];
	else{
		cout << "Array bound error!" <<endl;
		return tmp;
	}
}
template<typename T>
T Array<T>::operator[](int i) const
{
	if(i >= 0 && i < len)
		return data[i];
	else
		return 0;
}
template<typename T>
void Array<T>::print()
{
	int i;
	cout << "[";
	for(i = 0;i < len; i++)
	{
		cout << data[i];
		if(i < (len-1))
			cout << " ";
	}
	cout << "]" << endl;
}
#endif
