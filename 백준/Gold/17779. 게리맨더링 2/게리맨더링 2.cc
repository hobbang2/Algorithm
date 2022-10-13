#define ACTIVE_CODE 1
#if ACTIVE_CODE

#include <iostream>

int N = 0 , M = 0 ;

int map[21][21] = { 0 , };
int boundaryMap[21][21] = { 0 , };

void initBoundaryMap()
{
	for (int r = 1; r <= N; ++r)
	{
		for (int c = 1; c <= N; ++c)
		{
			boundaryMap[r][c] = 0;
		}
	}
}

void getDivider(int _x , int _y , int _d1 , int _d2)
{
	for (int idx = 0; idx <= _d1; ++idx)
	{
		boundaryMap[_x + idx][_y - idx] = 5;
		boundaryMap[_x + _d2 + idx][_y + _d2 - idx] = 5;
	}

	for (int idx = 0; idx <= _d2; ++idx)
	{
		boundaryMap[_x + idx][_y + idx] = 5;
		boundaryMap[_x + _d1 + idx][_y - _d1 + idx] = 5;

	}

	return; 
}

int numOfPeople = 0;

int getDiffBetArea( int _x , int _y , int _d1 , int _d2 )
{
	int areaPeoleArr[5] = { 0, };
	int maxPeople = 1; 
	int minPeople = 4002;

	// 1번 선거구 인구수 구하기
	int curPeople = 0;
	int restPeople = numOfPeople;
	for (int r = 1; r < _x + _d1; ++r)
	{
		for (int c = 1; c <= _y; ++c)
		{
			if (5 == boundaryMap[r][c])
			{
				break; 
			}
			curPeople += map[r][c]; 
		}
	}

	restPeople -= curPeople;
	maxPeople = (maxPeople < curPeople) ? curPeople : maxPeople ;
	minPeople = (minPeople > curPeople) ? curPeople : minPeople ;


	// 2번 선거구 인구수 구하기
	curPeople = 0;
	for (int r = 1; r <= _x + _d2; ++r)
	{
		for (int c = N; c > _y; --c)
		{
			if (5 == boundaryMap[r][c])
			{
				break;
			}
			curPeople += map[r][c];
		}
	}

	restPeople -= curPeople;
	maxPeople = (maxPeople < curPeople) ? curPeople : maxPeople;
	minPeople = (minPeople > curPeople) ? curPeople : minPeople;

	// 3번 선거구 인구수 구하기
	curPeople = 0;
	for (int r = _x + _d1 ; r <= N ; ++r)
	{
		for (int c = 1; c < _y - _d1 + _d2; ++c)
		{
			if (5 == boundaryMap[r][c])
			{
				break;
			}
			curPeople += map[r][c];
		}
	}

	restPeople -= curPeople;
	maxPeople = (maxPeople < curPeople) ? curPeople : maxPeople;
	minPeople = (minPeople > curPeople) ? curPeople : minPeople;

	// 4번 선거구 인구수 구하기
	curPeople = 0;
	for (int r = _x + _d2 + 1; r <= N; ++r)
	{
		for (int c = N ; c >= _y - _d1 + _d2; --c)
		{
			if (5 == boundaryMap[r][c])
			{
				break;
			}
			curPeople += map[r][c];
		}
	}

	restPeople -= curPeople;
	maxPeople = (maxPeople < curPeople) ? curPeople : maxPeople;
	minPeople = (minPeople > curPeople) ? curPeople : minPeople;

	maxPeople = (maxPeople < restPeople) ? restPeople : maxPeople;
	minPeople = (minPeople > restPeople) ? restPeople : minPeople;

	return maxPeople - minPeople;
}


int main()
{
	std::cin >> N ;


	for (int x = 1; x <= N; ++x)
	{
		for (int y = 1; y <= N; ++y)
		{
			std::cin >> map[x][y]; 
			numOfPeople += map[x][y];
		}
	}

	int ans = 4002; 
	// boundary 기준 고르기
	for (int x = 1; x <= N; ++x)
	{
		for (int y = 1; y <= N; ++y)
		{
			for (int d1 = 1; d1 <= N; ++d1)
			{
				for (int d2 = 1; d2 <= N; ++d2)
				{
					if (x + d1 + d2 > N)
					{
						continue; 
					}

					if (y - d1 < 1)
					{
						continue; 
					}

					if (y + d2 > N)
					{
						continue; 
					}
					initBoundaryMap();
					getDivider(x, y, d1, d2); 
					int curAns = getDiffBetArea(x, y, d1, d2);
					ans = (ans < curAns) ? (ans) : (curAns); 
				}
			}
		}
	}

	std::cout << ans; 

	return 0;

}

#endif 