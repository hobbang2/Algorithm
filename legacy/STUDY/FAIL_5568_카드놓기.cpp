#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int n , k ;
vector <int> cards;
set <string> nums;

void makeNum(int idx,int cnt, vector <bool> & _check) {
	 if (cnt == k) {
		string num = "";
		for (int i = 0; i < _check.size(); i++) {
			if (_check[i]) {
				num += to_string(cards[i]);
			}
		}
		if (!num.empty()) {
			cout << num<<" ";
			nums.insert(num);
		}
		return;
	}
	for (int i = 0; i < _check.size(); i++) {
		if (_check[i] == false)
		{
			_check[i] = true;
			makeNum(idx, cnt + 1, _check);
			_check[i] = false;
		}
	}
}


int main() {
	int card = 0;
	cin >> n >> k;
	
	vector <bool> check(n, false);

	while (n--) {
		cin >> card;
		cards.push_back(card);
	}
	makeNum(0, 0, check);
	cout << "\n"<<nums.size();
	return 0;
}