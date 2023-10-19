#include <cstdio>
#include <stack>
#include <algorithm>

using namespace std;


long long arr[100001] = { 0, };
int left_arr[100001] = { 0, };
int right_arr[100001] = { 0, };


int main() {

	while (1) {
		int N = 0;
		scanf("%d", &N);

		if (N == 0) {
			break;
		}

		for (int idx = 0; idx < N; ++idx) {
			scanf("%lld", &arr[idx]);
		}

		stack<pair<int,int> > user_stack; 

		for (int idx = 0; idx < N; ++idx) {
			
			left_arr[idx] = idx;

			if (true == user_stack.empty()) {
				user_stack.push({idx, arr[idx]});
				continue;
			}

			while ((false == user_stack.empty()) &&
				(arr[idx] <= user_stack.top().second)) {
				pair <int,int> cur_elem = user_stack.top(); user_stack.pop();
				left_arr[idx] = left_arr[cur_elem.first];
			}
			
			user_stack.push({ idx, arr[idx] });
		}
		stack < pair <int, int> > new_stack;
		user_stack.swap(new_stack);

		for (int idx = N-1; idx >= 0; --idx) {

			right_arr[idx] = idx;

			if (true == user_stack.empty()) {
				user_stack.push({ idx, arr[idx] });
				continue;
			}

			while ((false == user_stack.empty()) &&
				(arr[idx] <= user_stack.top().second)) {
				pair <int, int> cur_elem = user_stack.top(); user_stack.pop();
				right_arr[idx] = right_arr[cur_elem.first];
			}

			user_stack.push({ idx, arr[idx] });
		}

		long long result = 0;
		for (int idx = 0; idx < N; ++idx) {
			int width = right_arr[idx] - left_arr[idx] + 1;
			long long cur_result = width * arr[idx];
			result = result > cur_result ? result : cur_result;
		}

		printf("%lld\n", result);

	}

	return 0;
}
