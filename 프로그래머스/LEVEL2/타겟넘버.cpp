#include <string>
#include <vector>

using namespace std;

vector <bool> toggleVec(21,false);
int answer = 0;

void findSolution2(const vector <int> & nums,int target,int idx, int sum){
    if(idx >= (int)nums.size()){
        if(sum == target){
            answer = answer +1;
        }
        return;
    }
    findSolution2(nums,target,idx+1,sum + nums[idx]);
    findSolution2(nums,target,idx+1,sum - nums[idx]);
}
void findSolution(const vector <int> & nums, const int & target,int idx, int cnt){
    if((idx > (int)nums.size())|| (cnt) > (int)nums.size()){
        return;
    }
    
    if(cnt == (int)nums.size()){
        int sum = 0;
        for(int _idx = 0; _idx < (int)nums.size();_idx++){
            if(toggleVec[_idx] == false){
                sum = sum - nums[_idx];
            }
            else{
                sum = sum + nums[_idx];
            }
        }
        
        if(sum == target){
            answer = answer + 1;
        }
        return;
    }
    toggleVec[idx]=true;
    findSolution(nums,target,idx+1,cnt+1);
    toggleVec[idx]=false;
    findSolution(nums,target,idx+1,cnt+1);
}

int solution(vector<int> numbers, int target) {
    //findSolution(numbers,target,0,0);
    findSolution2(numbers,target,1,numbers[0]);
    findSolution2(numbers,target,1,-numbers[0]);

    return answer;
}