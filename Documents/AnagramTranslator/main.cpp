#include<iostream>
#include<map>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<vector>

void Error(int numEr){
	if(numEr == 1){
		std::cout<<"File opening error!\n";
	}
	if(numEr == 2){
		std::cout<<"There is no word like this!!\n";
	}
}

int main(int argc, char** argv){

	std::map<std::string, int> dict;
	std::vector<std::string> sentence;
	std::string line;
	std::string buff;
	
	std::string word;
	int maxMass;

	std::string resultWord;
	

	std::string key;
	int value;

	if(argc != 3){
		Error(1);
	}

	std::ifstream fin;
	fin.open(argv[1]);

	if(fin.is_open()){
	
		while(getline(fin, line)){
			line.erase(std::remove(line.begin(), line.end(), ','), line.end());
			auto pos = line.find(" ");
			key = line.substr(0, pos);
			value = stoi(line.substr(pos+1));
			dict[key] = value;
		}
		fin.close();
	}

	std::ifstream ffin;
	ffin.open(argv[2]);

	if(ffin.is_open()){
		
		while(getline(ffin, line)){
			sentence.clear();
			std::stringstream x;
			x << line;
			while(x >> word && x.good()){
				maxMass = 0;
				resultWord = "";
				for(auto elem: dict){
					if(std::is_permutation(word.begin(), word.end(), elem.first.begin())){
						if(maxMass <= elem.second){
							maxMass = elem.second;
							resultWord = elem.first;
						}
					}
					
				}
				if(resultWord.empty()){
					Error(2);
				}
				else{
					sentence.push_back(resultWord);
				}
			}

			do{
				for(int i = 0; i < sentence.size();i++){
					std::cout<<" "<<sentence[i]<<" ";
				}
				std::cout<<"\n";
			}while(std::next_permutation(sentence.begin(), sentence.end()));
		}
		ffin.close();
	}
	











}

