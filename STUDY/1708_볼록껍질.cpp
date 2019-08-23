#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/*
* Monotone Chain Algrorithm
*/

int convex_down[100001];
int convex_up[100001];


typedef struct Coord {
	long long x;
	long long y;

	Coord operator- (const Coord & c) const {
		return{ x - c.x,y - c.y };
	}
	bool operator< (const Coord & c)const {
		if (x == c.x) {
			return y < c.y;
		}
		else {
			return x < c.x;
		}
	}
}Coord;


long long getCCW(const Coord & v1, const Coord & v2) {
	return v1.x*v2.y - v1.y*v2.x;
}


int getCCW(const Coord & c1, const Coord & c2, const Coord & c3) {
	long long ccw = getCCW(c2 - c1, c3 - c1);
	if (ccw == 0) {
		return 0;
	}
	else if (ccw > 0) {
		return 1;
	}
	else {
		return -1;
	}
}

int main() {
	int N = 0;
	Coord point = { 0,0 };
	vector <Coord> points;
	
	scanf("%d", &N);


	for (int n = 1; n <= N; n++) {
		scanf("%lld %lld", &point.x, &point.y);
		points.push_back(point);
	}

	sort(points.begin(), points.end());

	int cnt_up = 0;
	// 윗쪽 볼록껍질 구하기 

	for (int idx = 0; idx < N; idx++) {
		// 볼록 껍질의 변에 점이 여러 개 있는 경우에는 가장 양 끝점만 개수에 포함
		while ((cnt_up >= 2) && (getCCW(points[convex_up[cnt_up - 2]],points[convex_up[cnt_up - 1]], points[idx])) >= 0){
			cnt_up--;
		}
		convex_up[cnt_up++] = idx;
	}

	int cnt_down = 0;

	for (int idx = N-1; idx >=0; idx--) {
		while ((cnt_down >= 2) && (getCCW(points[convex_down[cnt_down - 2]],points[convex_down[cnt_down - 1]], points[idx]))>= 0) {
			cnt_down--;
		}
		convex_down[cnt_down++] = idx;
	}

	printf("%d\n", cnt_up + cnt_down - 2);
	
	return 0;
}