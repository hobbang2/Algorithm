#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <vector>

using namespace std;

int main()
{
	string braceStr = "";
	vector<char> braceVec;
	long long answer = 0;
	long long tmpValue = 1;

	cin >> braceStr;

	for (int idx = 0; idx < (int)braceStr.size(); idx++)
	{
		if ((braceStr[idx] == '('))
		{
			braceVec.push_back('(');
			tmpValue *= 2;
		}
		else if ((braceStr[idx] == ')'))
		{
			if ((braceVec.empty()) || (braceVec.back() != '('))
			{
				answer = 0;
				break;
			}
			else
			{
				if(braceStr[idx-1]=='('){
					answer += tmpValue;
				}
				braceVec.pop_back();
				tmpValue /= 2;
			}
		}
		else if ((braceStr[idx] == '['))
		{
			braceVec.push_back('[');
			tmpValue *= 3;
		}
		else if ((braceStr[idx] == ']'))
		{
			if ((braceVec.empty()) || (braceVec.back() != '['))
			{
				answer = 0;
				break;
			}
			else
			{
				if(braceStr[idx-1]=='['){
					answer += tmpValue;
				}
				braceVec.pop_back();
				tmpValue /= 3;
			}
		}
	}
	answer = (braceVec.empty() ? answer: 0);
	cout << answer << "\n";
	return 0;
}