#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string alpha_word;
	cin >> alpha_word;
	for (char i = 'a'; i <= 'z'; i++)
	{
		int result = alpha_word.find(i);
		if (result == alpha_word.npos)
			result = -1;
		cout << result<<" ";
	}

	return 0;
}