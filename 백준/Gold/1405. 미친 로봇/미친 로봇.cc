#include <cstdio>
#include <vector>

#define MAXSIZE 30
using namespace std;

enum{EAST,WEST,SOUTH,NORTH};
vector <vector<int> > map(MAXSIZE, vector<int>(MAXSIZE, 0));
vector <double> probs(4, 0);
int N;
double sum;

void madRobot(int cnt, int x, int y,double prob)
{
    if (map[x][y] == 1)
        return;
	
    else if (cnt == N)
		sum += prob;

    else
	{
            map[x][y] = 1;
			madRobot(cnt + 1, x, y+1, prob*probs[EAST]);
            madRobot(cnt + 1, x, y-1, prob*probs[WEST]);
			madRobot(cnt + 1, x+1, y, prob*probs[SOUTH]);
			madRobot(cnt + 1, x-1, y, prob*probs[NORTH]);
			map[x][y] = 0;
	}
	return;
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < 4; i++)
	{
		scanf("%lf", &probs[i]);
		probs[i] /= 100;
	}

	madRobot(0, 15, 15, 1);

	printf("%.11f", sum);
	return 0;
}
