#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_CNT 3
#define LIMIT_NUM 200000000

int answer = 0;
int N = 0;
std::vector < int > numVector;
std::vector < int > sumOfNumVector;

bool userBinarySearch(int low, int upper, int target)
{
	if (target > LIMIT_NUM)
	{
		return false;
	}

	while (low <= upper)
	{
		int mid = (low + upper) / 2;
		int checkNum = sumOfNumVector[mid];

		if (checkNum == target)
		{
			return true;
		}

		if (checkNum < target)
		{
			low = mid + 1;
		}
		else if (checkNum > target)
		{
			upper = mid - 1;
		}
	}

	return false;
}

int main()
{
	scanf("%d", &N);

	for (int idx = 0; idx < N; ++idx)
	{
		int curNum = 0;
		scanf("%d", &curNum);
		numVector.push_back(curNum);
	}
	
	for (int outIdx = 0; outIdx < N; ++outIdx)
	{
		for (int innerIdx = outIdx; innerIdx < N; ++innerIdx)
		{
			sumOfNumVector.push_back(numVector[outIdx] + numVector[innerIdx]);
		}
	}

	//findAnswer(N - 1, 0, 0);
	std::sort(numVector.begin(), numVector.end());
	std::sort(sumOfNumVector.begin(), sumOfNumVector.end());

	int sizeOfSumVec = static_cast <int> (sumOfNumVector.size()); 
	for (int outIdx = N - 1; outIdx >= 0; --outIdx)
	{
		int outNum = numVector[outIdx];

		for (int midIdx = outIdx; midIdx >= 0; --midIdx)
		{
			int curSub = numVector[outIdx] - numVector[midIdx];

			//if (true == userBinarySearch( 0, N-1, curSub))
			if (true == std::binary_search(sumOfNumVector.begin(), sumOfNumVector.end(), curSub))
			{
				printf("%d\n", numVector[outIdx]);
				return 0; 
			}
		}
	}
	

	return 0;
}