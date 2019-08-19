#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int n, k;
vector <int> cards;
set <string> nums;

void makeNum(int cnt, string num, vector <bool> & _check) {
	if (cnt == k) {
		nums.insert(num);
		return;
	}
	for (int idx = 0; idx < (int)_check.size(); idx++) {
		if (_check[idx] == false)
		{
			_check[idx] = true;
			makeNum(cnt + 1, num + to_string(cards[idx]), _check);
			_check[idx] = false;
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
	makeNum( 0, "", check);
	cout << nums.size() << "\n";
	return 0;
}