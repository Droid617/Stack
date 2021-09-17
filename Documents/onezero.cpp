#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>

bool isZero(int i){
	return(i == 0);
}
bool isOne(int i){
	return(i == 1);
}

int main(int argc, char** argv){

	if(argc != 3){
		std::cout<<"Error! Required only 2 files in command line";
		return 0;
	}

	int buff;
	int i = 0;
	int zeroCount = 0;
	int oneCount = 0;

	std::vector<int> vin;
	std::vector<int>::iterator it;

	std::ifstream fin(argv[1]);
	if(fin.is_open()){
		while(!fin.eof()){
			fin>>buff;
			vin.push_back(buff);
		}
		fin.close();
	}
	
	it = std::unique(vin.begin(), vin.end());
	vin.resize(std::distance(vin.begin(), it));
	
	zeroCount = std::count_if(vin.begin(), vin.end(), isZero);
	oneCount = std::count_if(vin.begin(), vin.end(), isOne);

	std::ofstream fout(argv[2]);
	if(fout.is_open()){
		fout<<oneCount<<" "<<zeroCount;
		fout.close();
	}

	return 0;
}
