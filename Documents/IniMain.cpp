#include<iostream>
#include<cstdlib>
#include"IniFile.h"
#include<string>
#include<map>

int main(int argc, char** argv){

	IniFile a(argv[1]);
	a.Save();
	std::string c = a.Read("player", "x");
	std::string cc = a.Read("player", "y");
	std::cout<<"First"<<c<<"/ second"<<cc<<"/\n";
	std::string e = "eeeeeeeee";
	a.Write("player", "y", e);
	std::string g = a.Read("player", "y");
	std::cout<<"NEW VALUE IS "<<g<<"\n";
	if(a.SectionExists("player")){
		std::cout<<"Section exists\n";
	}
	if(!a.KeyExists("player", "oops!")){
		std::cout<<"This key doesnt exist\n";
	}
	
	
	return 0;
}

