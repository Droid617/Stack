#pragma once
#include<cstdlib>

template <class T>
class Stack{
private:
	T* ptr;
	int idx;
public:
	Stack(int n){
		ptr = new T[n];
		idx = -1;
	}

	T top();
	void pop();
	void push(T elem);
	void print();


	
	~Stack(){
		delete[] ptr;
	}
};

