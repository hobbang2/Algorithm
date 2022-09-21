#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int R;
		scanf("%d", &R);
		char c;
		while (scanf("%c", &c), c!='\0')
		{
			for (int r = 0; r < R; r++)
			{
				printf("%c", c);
			}
		}
		printf("\n");
	}
	return 0; 
}