#include <cstdio>
#include <vector>

using namespace std;

void Permutation(int cnt, int idx, int num_choice, vector <bool> & permutation_vec)
{
	// base case  
	if (cnt > num_choice || idx >=permutation_vec.size())
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
			// permutation_vec[idx] = true;
			// Permutation(cnt + 1, idx + 1, num_choice, permutation_vec);
			// permutation_vec[idx] = false;
			// Permutation(cnt, idx+1, num_choice, permutation_vec);
			
			for(int curIdx = idx ; curIdx < permutation_vec.size()-1;curIdx++){
				permutation_vec[curIdx] = true;
				Permutation(cnt + 1, curIdx + 1, num_choice, permutation_vec);
				permutation_vec[curIdx] = false;
			}
		}
	}
}


int main()
{
	vector <bool> per(4, false);
	Permutation(0, 0, 2, per);

	return 0;
}