//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//vector<string> s;
//
//int main() {
//
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		string str;
//		cin >> str;
//		s.push_back(str);
//	}
//
//	sort(s.begin(), s.end());
//
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = i + 1; j < n; j++) {
//
//			if (s[i].size() > s[j].size()) {
//				string str;
//				str = s[i];
//				s[i] = s[j];
//				s[j] = str;
//			}
//
//		}
//	}
//
//	for (int i = 0; i < n; i++) {
//		if (i == 0) cout << s[i] << endl;
//		else {
//			if (s[i] != s[i - 1]) cout << s[i] << endl;
//		}
//	}
//
//}
