## Binary Search :banana:

## 문제
### [1300. K번째 수](boj.kr/1300)
<section id="description">
				<div class="headline">
				</div>
				<div style="font-size:medium; line-height:30px;" id="problem_description">
				<p>세준이는 N*N크기의 배열을 만들었다. (배열의 방 번호는 1부터 시작한다.)</p>

<p>그 배열을 A라고 했을 때, 배열에 들어가는 수는 A[i][j] = i*j 이다.</p>

<p>세준이는 이 수를 일차원 배열 B에 넣으려고 한다. 그렇게 되면, B의 크기는 N*N이 될 것이다. 그러고 난 후에, B를 오름차순 정렬해서 k번째 원소를 구하려고 한다.</p>

<p>N이 주어졌을 때, k번째 원소를 구하는 프로그램을 작성하시오.</p>

#### 아이디어 
1부터 K까지 이분 탐색을 한다. 
각 칸에 대입된 수는 `i*j`이므로 middle 값을 i로 나눈 값은 각 열의 몇 번째 칸인지를 나타내고, 이 값은 그 행에서 middle 값 보다 작은 수의 개수와 같다. 

middle 값 보다 작은 수의 개수를 세아리며 그 수가 주어진 K보다 크거나 같아지면 정답 후보가 된다. 

이분 탐색이 끝났을 때, 가장 마지막으로 확인한 정답 후보가 정답이 된다! 

```cpp

int binarySearch(const int & N, const int & K) {
	int start = 1, end = K;
	int mid = 0;
	int ans = 0;
	while (start <= end) {
		mid = (start + end) >> 1;
		int cnt = 0;
		for (int n = 1; n <= N; n++) {
			cnt += (mid/n < N) ? mid/n : N;
		}
		if (cnt < K) {
			start = mid + 1;
		}
		else {
			// 정답 후보들
			ans = mid;
			end = mid -1;
		}
	}
	return ans;
}
```