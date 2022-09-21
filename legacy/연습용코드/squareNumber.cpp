#include <iostream>
#include <vector>

#define MAX_VALUE 11
using namespace std;

typedef struct NumPair{
    int a,b,c;
    NumPair(int _a,int _b, int _c):a(_a),b(_b),c(_c){}
}NumPair;

int main(){
    vector <int> squareNum(MAX_VALUE,0);
    vector <NumPair> pairSet[MAX_VALUE];
    for(int idx = 1; idx < MAX_VALUE; idx++){
        squareNum[idx] = idx * idx;
    }
    
    for(int i = 1; i <MAX_VALUE;i++){
        for(int j = i; j <MAX_VALUE;j++){
            for(int k = j; k < MAX_VALUE; k++){
                int curNum = i*i + j *j +k *k;
                for(int l = 1; l < MAX_VALUE; l++){
                    if(squareNum[l] == curNum){
                        NumPair curPair(i,j,k);
                        pairSet[l].push_back(curPair);
                    }
                }
            }
        }
    }

    for(int idx = 1; idx < MAX_VALUE;idx++){
        int curSize = (int)pairSet[idx].size();
        for(int pair = 0 ; pair < curSize; pair++){
            cout << "equation : "<< pairSet[idx][pair].a <<"^2 + " <<pairSet[idx][pair].b <<"^2 + "<< pairSet[idx][pair].c <<"^2 = ";
            cout << idx << "^2 \n";
            cout << "result : "<< pairSet[idx][pair].a * pairSet[idx][pair].a << " + ";
            cout << pairSet[idx][pair].b * pairSet[idx][pair].b << " + ";
            cout << pairSet[idx][pair].c * pairSet[idx][pair].c << " = ";
            cout << idx * idx <<"\n\n";
        }
    }

    return 0;
}