#include<string>
#include<map>
#include<vector>
#include<cassert>
class IniFile{
	std::map<std::string, std::map<std::string, std::string>> data;
	std::string path;
public:	
	IniFile(std::string pathh){
		path = pathh;
	}

	void Save();//for adding in map	

	template<typename T> T Read(std::string section, std::string key,
		T defaultValue = T{}) const;//output key one
	template<typename T> void Write(std::string section, std::string key,
		T value);//write second value
	bool SectionExists(std::string section) const;
	
	bool KeyExists(std::string section, std::string key) const;//second key exist

	std::vector<std::string> sections() const;
	
	std::vector<std::string> keys(std::string section) const;//key keys


	~IniFile(){}
};
