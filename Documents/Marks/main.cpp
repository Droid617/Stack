#include<cstdlib>
#include"Stack.h"
#include"Stack.cpp"
#include<iostream>
int main(){

	Stack<int> stInt(5);
	stInt.push(20);
	stInt.push(30);
	stInt.push(40);
	stInt.push(50);
	stInt.pop();
	stInt.print();

}

