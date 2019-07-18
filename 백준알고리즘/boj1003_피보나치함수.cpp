#include <cstdio>
#include <vector>

using namespace std;


class myFibo
{
private:
	int zero;
	int one;
public:
	myFibo(int u_zero = 0, int u_one = 0)
	{
		zero = u_zero;
		one = u_one;
	}
	bool isEmpty()
	{
		if ((zero == 0) && (one == 0))
			return true;
		else return false;
	}

	void idxZero()
	{
		zero = 1;
		one = 0;
	}
	void idxOne()
	{
		zero = 0;
		one = 1;
	}

	void printAnswer()
	{
		printf("%d %d\n", zero, one);
	}
	// Overload + operator to add two myFibo objects.
	myFibo operator+(const myFibo& b) {
		myFibo result;
		result.zero = this->zero + b.zero;
		result.one = this->one + b.one;
		return result;
	}


};
myFibo map[41];

myFibo fibo(int n)
{
	if (map[n].isEmpty())
	{
		map[n] = fibo(n - 1) + fibo(n - 2);
	}
	return map[n];
}

int main()
{
	map[0].idxZero();
	map[1].idxOne();

	int N;
	scanf("%d", &N);
	while (N--)
	{
		int num;
		scanf("%d", &num);
		fibo(num);
		map[num].printAnswer();
	}
	return 0;
}