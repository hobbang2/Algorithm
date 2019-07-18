#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int main()
{
	int N = 0;
	cin >> N;
	vector <pair <int, int > > days_info(N + 1);

	for (int day = 1; day <= N; day++)
	{
		int duration, pay;
		cin >> duration >> pay;
		pair <int, int> day_info = { duration, pay };
		days_info[day] = (day_info);
	}

	int max_result = 0;

	queue < pair <int, int> > pays_q;
	
	for (int start_idx = 1; start_idx <= N; start_idx++)
	{
		
		int tmp_result = 0;
		pair<int, int> start_info = { days_info[start_idx].first + start_idx, days_info[start_idx].second };
		pays_q.push(start_info);

		while (!pays_q.empty())
		{
			pair <int, int> element = pays_q.front();
			pays_q.pop();
			//cout << "debugging : " << element.first << " " << element.second<<endl;

			if (element.first == N + 1)
			{
				max_result = max(max_result, element.second);
				continue;
			}

			for (int idx = element.first; idx <= N; idx++) 
			{
				
				int cur_day = element.first + days_info[idx].first +(idx - element.first);
				int cur_pay = element.second + days_info[idx].second;
				
				
				if (cur_day <= N+1)
				{
					pair<int, int> tmp = { cur_day, cur_pay };
					pays_q.push(tmp);
					
				}
				else
				{
					max_result = max(max_result, element.second);
				}
			}
		}
	}
	cout << max_result;
	getchar();
	return 0;
}