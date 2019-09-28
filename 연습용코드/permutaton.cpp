#include <cstdio>
#include <vector>

using namespace std;

void Permutation(int cnt, int idx, int num_choice, vector <bool> & permutation_vec)
{
	// base case  
	if (cnt > num_choice || idx > permutation_vec.size())
		return;
	else
	{
		if (cnt == num_choice)
		{
			for (int i = 0; i < permutation_vec.size(); i++)
			{
				if (permutation_vec[i])
				{
					printf("%d ", i + 1);
				}
			}
			printf("\n");
			return;
		}
		else
		{
			// 해당 idx 포함 -> cnt+1 
			permutation_vec[idx] = true;
			Permutation(cnt + 1, idx + 1, num_choice, permutation_vec);
			permutation_vec[idx] = false;
			Permutation(cnt + 1, idx + 1, num_choice, permutation_vec);
		}
	}
}


int main()
{
	vector <bool> per(5, false);
	Permutation(0, 0, 5, per);

	return 0;
}