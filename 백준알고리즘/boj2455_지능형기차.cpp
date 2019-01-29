#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector <int> train(5, 0);
	int enter_people=0;
	int out_people = 0;
	int num = 0;

	for (int i = 1; i < 5; i++)
	{
		scanf("%d %d", &out_people, &enter_people);
		num += enter_people;
		num -= out_people;
		train[i] = num;
	}

	printf("%d", *max_element(train.begin(), train.end()));
	
	return 0;
}