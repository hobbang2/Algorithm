#include <iostream>

int main()
{
	int A = 0;
	int B = 0;
	int V = 0;
	std::cin >> A >> B >> V; 

	int _day = 0;

	int sparseHeight = A - B;
	_day = (V - B) / sparseHeight; 
	
	if (0 != (V - B) % sparseHeight)
	{
		_day += 1; 
	}

	printf("%d", _day);
	
	return 0;
}