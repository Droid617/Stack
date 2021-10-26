#include<iostream>
#include<cstdlib>
#include"IniFile.h"

int main(int argc, char** argv){

	IniFile a(argv[1]);
	a.Save();
	std::cout<<a.data["player"]["x"]<<"\n";

}

