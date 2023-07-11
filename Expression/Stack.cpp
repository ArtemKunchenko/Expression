#include "Stack.h"
template<class T>
inline Stack<T>::Stack(int capacity)
{
	_capacity = capacity;
	_size = 0;
	_data = new T[_capacity]{ 0 };
	_index = _capacity;
	if (_capacity <= 0)
	{
		_capacity = 0;
		_data = nullptr;
		_index = 0;
	}
}
template<class T>
Stack<T>::Stack(const Stack& other)
{
	if (this == &other)
		return *this;
	_index = other._index;
	_capacity = other._capacity;
	_size = other._size;
	_data = new T[_size];
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = other._data[i];
	}
	cout << "copy constructor:\t" << this << endl;
}

template<class T>
Stack<T>::Stack(Stack&& other) : _data{ nullptr }, _size{ 0 }
{
	_index = other._index;
	_capacity = other._capacity;
	_data = other._data;
	_size = other._size;
	other._data = nullptr;
	other._size = 0;
	other._capacity = 0;
	other._index = 0;
	cout << "constructor moving:\t" << endl;
}

template<class T>
Stack<T>::~Stack()
{
	if (_data != nullptr)
		delete[] _data;
	cout << "destructor:\t" << this << endl;
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack& other)
{
	if (this == &other)
		return *this;
	_index = other._index;
	_capacity = other._capacity;
	_size = other._size;
	_data = new T[_size];
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = other._data[i];
	}
	cout << "copy constructor:\t" << this << endl;
	return *this;
}

template<class T>
Stack<T>& Stack<T>::operator= (Stack&& other)
{
	_index = other._index;
	_capacity = other._capacity;
	_data = other._data;
	_size = other._size;
	other._data = nullptr;
	other._size = 0;
	other._capacity = 0;
	other._index = 0;
	cout << "operator moving:\t" << endl;
}

template<class T>
bool Stack<T>::empty()
{
	if (_data == nullptr) return true;
	return false;
}

template<class T>
void Stack<T>::push(T item)
{
	if (_capacity <= _size)
	{
		cout << "Stack overflow:\t" << item << endl;
		//exit(0);
		return;
	}
	_data[--_index] = item;
	_size++;
}

template<class T>
void Stack<T>::pop()
{
	if (_size != 0)
	{
		_data[_index++] = 0;
		_size--;
	}
}

template<class T>
T& Stack<T>::top()
{
	return _data[_index];
}


template<class T>
ostream& operator<< (ostream& out, const Stack<T>& stack)
{
	for (size_t i = stack._capacity - 1; i >= stack._index; i--)
	{
		out << stack._data[i] << "\n";
	}
	return out;
}