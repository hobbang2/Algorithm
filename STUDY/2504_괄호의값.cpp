#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector <char> braceVec;
	vector <char> valueVec;
	string target;
	cin >> target;
	for (int idx = 0; idx < target.size(); idx++) {
		if (braceVec.size() == 0) {
			if (target[idx] == '(' || target[idx] == '[') {
				braceVec.push_back(target[idx]);
			}
			else {
				printf("0\n");
				return 0;
			}
		}
		else {

			}
		}
	}
	return 0;
}