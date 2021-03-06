#include<iostream>
#include<stack>
#include<string>

void Error(int ii){
	std::cout<<"Error in "<<ii<<" index!\n";
}

int main(){
	std::stack<char> st;

	std::cout<<"Give me a string\n";
	char str[30];
	std::cin>>str;

	char ch;
	int i = 0;
	int count = 0;

	for(i = 0;i < sizeof(str);i++){
		ch = str[i];
		if((i == 0) && ((ch != '(') && (ch != '{') && (ch != '['))){
			Error(i);
			continue;
		}
		else{
			if((ch == '(') || (ch == '{') || (ch == '[')){
				st.push(ch);
				count++;
				continue;
			}
			else{
				if((ch == ')') && (st.top() != '(')){
					Error(i);
				}
			 	if((ch == ']') && (st.top() != '[')){
                                	Error(i);
                        	}
			 	if((ch == '}') && (st.top() != '{')){
                                	Error(i);
                        	}
			}
		}
	}
}
