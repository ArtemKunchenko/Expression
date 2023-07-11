#pragma once
#include <iostream>
using namespace std;

template<class T>
class Stack
{
public:
	Stack(int capacity); // constructor default
	Stack(const Stack& other); //constructor copy
	Stack(Stack&& other); // constructor moving
	~Stack(); // destructor
	Stack<T>& operator= (const Stack& other); // operator copy
	Stack<T>& operator= (Stack&& other); //operator moving
	friend ostream& operator<<<T> (ostream& out, const Stack& stack); //operator cout
	bool empty(); //check
	void push(T item); //add to stack a new element
	void pop(); // remove from stack top element
	T& top(); // get top element without deleting
	
private:
	T* _data; // data
	int _size; // size
	int _capacity; // capacity
	int _index;

};


