#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <vector>

using namespace std;
bool flag = false;
int answer = 0;
string braceStr = "";

int calcBrace(int idx, vector <char> & braceV){
	if(idx >= braceStr.size()){
		if(braceV.empty()==false){
			return -20000000;
		}
		else{
			return 0;
		}
	}

	if(braceStr[idx] == '('){
		braceV.push_back(braceStr[idx]);
		return 2*calcBrace(idx+1,braceV);
	}

	else if(braceStr[idx] == ')'){
		if((braceV.empty()== true)||(braceV.back()!= '(')){
			return -20000000;
		}
		else{
			braceV.pop_back();
			return 1*calcBrace(idx+1,braceV);
		}
	}
	else if (braceStr[idx] == '['){
		braceV.push_back(braceV[idx]);
		return 3*calcBrace(idx+1,braceV);
	}else if(braceStr[idx] == ']'){
		if((braceV.empty()== true)||(braceV.back()!= '(')){
			return -20000000;
		}
		else{
			braceV.pop_back();
			return 1*calcBrace(idx+1,braceV);
		}
	}
}

int main(){
	vector <char> braceVec;
	cin >> braceStr;
	int answer = calcBrace(0,braceVec);
	answer = answer < 0 ? 0 : answer;
	cout << answer<<"\n";
	return 0;
}