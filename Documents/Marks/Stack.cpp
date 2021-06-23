#include<iostream>
#include<cstdlib>
#include"Stack.h"

template <class T>
T Stack<T>::top(){
	if(idx < 0){
		T g = ptr[0];
        	std::cout<<"The stack is empty now"<<"\n";
        	return g;
	}
	T k = ptr[idx];
	std::cout<<"The top is "<<k<<"\n";
	return k;
}

template <class T>
void Stack<T>::pop(){
	if(idx < 0){
		std::cout<<"ERROR! The stack is empty now"<<"\n";
	}
	if(idx >= 0){
		idx--;
	}
}
template <class T>
void Stack<T>::push(T elem){
	idx++;
	ptr[idx] = elem;
}

template <class T>
void Stack<T>::print(){
	if(idx >= 0){
		std::cout<<"From top to bottom"<<"\n";
		for(int i = idx;i >= 0;i--){
			std::cout<<"The "<<i<<" elem is "<<ptr[i]<<"\n";
		}
	}
	if(idx < 0){
		std::cout<<"Sorry, but stack is empty ):"<<"\n";
	}
}
