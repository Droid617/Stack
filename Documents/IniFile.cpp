#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<fstream>
#include<cstdlib>
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

std::string IniFile::Read(std::string section, std::string key, std::string defaultValue){//Здесь использую string, так как , по сути, все в файле - это строки
										//А при получении строки данных можно проверить через typeid  и явно привести.
	if(data[section][key] == ""){
		return defaultValue;
	}
	else{
		return data[section][key];
	}
				
}


template<typename T> void IniFile:: Write(std::string section, std::string key, T value){
		data[section][key] = value;
}

template void IniFile:: Write<std::string>(std::string section, std::string key, std::string value);
template void IniFile:: Write<bool>(std::string section, std::string key, bool value);
template void IniFile:: Write<int>(std::string section, std::string key, int value);
template void IniFile:: Write<float>(std::string section, std::string key, float value);

				
bool IniFile::SectionExists(std::string section){
		
	std::map<std::string, std::map<std::string, std::string>>:: iterator it;
	it = data.find(section);
	return (it == data.end()) ? false : true;
		
}
		

bool IniFile::KeyExists(std::string section, std::string key){
		
	std::map<std::string, std::string>:: iterator it;
        it = data[section].find(key);
        return (it == data[section].end()) ? false : true;
			
}




