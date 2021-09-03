#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){
stack<char> st;
cout<<"Give me a string\n";
char str[30];
cin>>str;
char ch;
int i = 0;
int count = 0;

for(i = 0;i < sizeof(str);i++){
	ch = str[i];
	if((i == 0) && ((ch != '(') && (ch != '{') && (ch != '['))){
		cout<<"Error in "<<i<<" char!\n";
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
				cout<<"Error in "<<i<<" char!\n";
			}
			 if((ch == ']') && (st.top() != '[')){
                                cout<<"Error in "<<i<<" char!\n";
                        }
			 if((ch == '}') && (st.top() != '{')){
                                cout<<"Error in "<<i<<" char!\n";
                        }

		}
		
	}
	


}


}
