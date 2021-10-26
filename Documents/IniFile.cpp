#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<fstream>
#include"IniFile.h"

void IniFile::Save() {

	std::string line;
	std::string sect;
	std::string keyOfSect;
	std::string keyOfSectValue;
	std::ifstream inf(path);
	
	if(inf.is_open()){
		while(getline(inf, line)){
			int pointOne = 0;
			int pointTwo = 0;
			for(int i = 0;i < line.size();i++){
				if(line[i] == '['){
					pointOne = i;
					continue;
				}
				if(line[i] == ']'){
					pointTwo = i;
					break;
				}
				if(line[i] == '='){
					keyOfSect = line.substr(pointOne, i);
					keyOfSectValue = line.substr(i + 1, line.size() - 1);
					data[sect][keyOfSect] = keyOfSectValue;
					break;
				}
				
			}
			if((pointOne == 0) && (pointTwo == 0)){
				continue;
			}

			if(line[pointOne] == '['){
				sect = line.substr(pointOne + 1, (pointTwo - pointOne - 1));
				data[sect];
			}
		}
		inf.close();
	}

}

