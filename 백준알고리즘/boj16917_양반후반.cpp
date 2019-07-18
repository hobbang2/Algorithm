#include <cstdio>
#include <vector>

using namespace std;
enum chicken {yang,hu,banban,num_Y,num_H};
int main()
{
	bool more_yang = false;
	bool expense_banban = false;
	int diff_num = 0;
	int price = 0;
	int input[5] = {0,};

		for (int i = 0; i < 5; i++)
		{
			scanf("%d", &input[i]);
		}

		if (input[num_Y] > input[num_H])
		{
			more_yang = true;
		}

		if ((input[yang] + input[hu]) > (2 * input[banban]))
		{
			if (more_yang)
			{
				diff_num = input[num_Y]-input[num_H];
				price += (2 * input[banban] * input[num_H]);
				if (input[yang] > 2 * input[banban])
				{
					price += (2 * input[banban] * diff_num);
				}
				else
				{
					price += input[yang] * diff_num;
				}
			}

			else
			{
				diff_num = input[num_H] - input[num_Y];
				price += (2 * input[banban] * input[num_Y]);
				if (input[hu] > 2 * input[banban])
				{
					price += (2 * input[banban] * diff_num);
				}
				else
				{
					price += input[hu] * diff_num;
				}
			}
		}

		else
		{
			if (input[yang] > 2 * input[banban])
			{
				price += (2 * input[banban] * input[num_Y] + input[hu] * input[num_H]);
			}
			else if (input[hu] > 2 * input[banban])
			{
				price += (2 * input[banban] * input[num_H] + input[yang] * input[num_Y]);
			}
			else
				price += input[yang] * input[num_Y] + input[hu] * input[num_H];
		}
		
		printf("%d", price);
	return 0;
}