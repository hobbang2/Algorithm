#include <iostream>
#include <string>

#define MAX_SIZE 10002

using namespace std;	

class user_queue
{
private:
	int que[MAX_SIZE];
	int top;
	
public:
	user_queue()
	{
		que[MAX_SIZE] = { 0, };
		top = -1;
	}

	void push(int atom)
	{
		que[++top] = atom;
	}

	int pop()
	{
		if (empty())
			return -1;

		int tmp = que[0];

		for (int i = 0; i < top; i++)
		{
			que[i] = que[i + 1];
		}
		/*
		for (int i = top; i > 0; i--)
		{
			que[i - 1] = que[i];
		}
		*/
		top--;
		return tmp;
	}

	int size()
	{
		return top + 1;
	}

	int empty()
	{
		if (top == -1)
			return 1;
		else return 0;
	}

	int front()
	{
		if (empty())
			return -1;
		else return que[0];
	}

	int back()
	{
		if (empty())
			return -1;
		return que[top];
	}
};

int main()
{
	user_queue Q;
	int N = 0;
	int num;
	string order;
	
	scanf("%d", &N);
	
	while (N--)
	{
		cin >> order;
		if (order == "push")
		{
			int num;
			cin >> num;
			Q.push(num);
		}
		else if (order == "pop")
		{
			printf("%d\n", Q.pop());
		}
		else if (order == "size")
		{
			printf("%d\n", Q.size());
		}
		else if (order == "empty")
		{
			printf("%d\n", Q.empty());
		}
		else if (order == "front")
		{
			printf("%d\n", Q.front());
		}
		else if (order == "back")
		{
			printf("%d\n", Q.back());
		}
	}
	return 0;
}