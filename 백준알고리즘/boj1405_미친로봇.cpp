#include <cstdio>
#include <vector>

#define MAXSIZE 30
using namespace std;

//µ¿¼­³²ºÏ
int dir_x[4] = { 0,0,1,-1 };
int dir_y[4] = { 1,-1,0,0 };

enum { EAST, WEST, SOUTH, NORTH };
vector <vector<int> > map(MAXSIZE, vector<int>(MAXSIZE, 0));
vector <double> probs(4, 0);
int N;
double sum;

/*
// ¾ø¾îµµ µÅ 
bool canGo(int x, int y)
{
	if (x <= 0 || y <= 0 || x >= MAXSIZE || y >= MAXSIZE) return false;
	else return true;
}
*/
void madRobot(int cnt, int x, int y, double prob)
{
	if (map[x][y] == 1)
		return;

	else if (cnt == N)
		sum += prob;

	else
	{
		map[x][y] = 1;
		madRobot(cnt + 1, x, y + dir_y[EAST], prob*probs[EAST]);
		madRobot(cnt + 1, x, y + dir_y[WEST], prob*probs[WEST]);
		madRobot(cnt + 1, x + dir_x[SOUTH], y, prob*probs[SOUTH]);
		madRobot(cnt + 1, x + dir_x[NORTH], y, prob*probs[NORTH]);
		map[x][y] = 0;
	}
	return;
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < 4; i++)
	{
		scanf("%.11lf", &probs[i]);
		probs[i] /= 100;
	}

	madRobot(0, 15, 15, 1);

	printf("%f", sum);
	return 0;
}
