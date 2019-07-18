//  다시해라 ㅡ.ㅡ 
//  testcase 3개 time out 
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int formationTeam(const deque<int> &dq, int n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;

	set <int> size_of_team;
	{
		deque<deque<int>> teams(1, deque<int>(1, dq[0]));

		for (int idx = 1; idx < dq.size(); idx++) {
			bool flag = false;
			int t_size = teams.size();

			for (int i = 0; i < t_size; i++) {
				int diff = dq[idx] - teams[i].back();

				if (diff > 1) {
					if (i == (t_size - 1)) {
						deque<int> team(1, dq[idx]);
						teams.push_back(team);
						while (teams.size() != 1) {
							size_of_team.insert(teams[0].size());
							teams.pop_front();
						}
						/*
						for (int j = 0; j < i; j++)
						{
							size_of_team.push_back(teams[j].size());
						}
						for (int j = 0; j < i; j++)
						{
							teams.pop_front();
						}
						*/
					}
					continue;
				}
				else if (diff == 1) {
					int j = i;
					while (j != (t_size - 1) && teams[j + 1].back() == teams[i].back()) {
						j++;
					}
					teams[j].push_back(dq[idx]);
					break;
				}
				else if (diff == 0) {
					if (i == (t_size - 1)) {
						deque<int> team(1, dq[idx]);
						teams.push_back(team);
					}
					else
						continue;
				}
			}
		}

		for (int idx = 0; idx < teams.size(); idx++) {
			size_of_team.insert(teams[idx].size());
		}
	}
	return *min_element(size_of_team.begin(), size_of_team.end());
}

int main() {
	// input data
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		deque<int> skills(n, 0);
		for (int i = 0; i < n; i++)
			cin >> skills[i];

		sort(skills.begin(), skills.end());

		int result = formationTeam(skills, n);

		/*
		1) n == 0 이면 result = 0
		2) n == 1 이면 result = 1

		3)
		*/
		// 결과 출력
		cout << result << endl;
	}

	return 0;
}