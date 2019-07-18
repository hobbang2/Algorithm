//#include <iostream>
//#include <string>
//#include <vector>
//#include <set>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	int N;
//	cin >> N;
//	getchar();
//
//	vector <vector <char> > word_dict(N);
//	char alpha = '0';
//	
//	for(int i = 0; i < N ; i++)
//	{
//		while (scanf("%c", &alpha), alpha != '\n')
//		{
//			word_dict[i].push_back(alpha);
//		}
//
//		sort(word_dict[i].begin(), word_dict[i].end());
//		do
//		{
//			for (auto it = word_dict[i].begin(); it != word_dict[i].end(); it++)
//			{
//				cout << *it;
//			}
//			cout << "\n";
//		} while (next_permutation(word_dict[i].begin(), word_dict[i].end()));
//	}
//
//	
//	return 0;
//}


#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	getchar();
	char alpha = '0';

	for (int i = 0; i < N; i++)
	{
		string word;
		cin >> word;
		sort(word.begin(), word.end());
		do
		{
			cout << word<<"\n";
		} while (next_permutation(word.begin(), word.end()));
	}


	return 0;
}