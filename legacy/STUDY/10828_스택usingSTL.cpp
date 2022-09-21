// 구현X stl사용
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <int> stack;

void push(int target) {
	stack.push_back(target);
	return;
}

bool isEmpty() {
	if (stack.empty()) {
		return true;
	}
	else {
		return false;
	}
}

int pop() {
	int value = -1;
	if (!isEmpty()) {
		value = stack[stack.size() - 1];
		stack.pop_back();
	}
	return value;
}

int size() {
	return stack.size();
}

int top() {
	int value = -1;
	if (!isEmpty()) {
		value = stack[stack.size()-1];
	}
	return value;
}


int main() {
	int N = 0;
	int target = 0;
	string order = "";

	scanf("%d", &N);

	while (N--) {
		cin >> order;
		if (order == "push") {
			cin >> target;
			push(target);
		}
		else if (order==("top")) {
			cout << top() << "\n";
		}
		else if (order == "size") {
			cout << size() << "\n";
		}
		else if (order == "pop") {
			cout << pop() << "\n";
		}
		else if (order == "empty") {
			cout << isEmpty() << "\n";
		}
	}
	return 0;
}