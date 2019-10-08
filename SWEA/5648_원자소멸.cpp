#include <cstdio>
#include <vector>

using namespace std;

vector <vector <int> > map(4001,vector <int> (4001,0));
typedef struct Atom {
	int y, x; 
	int dir;
	int energy;
	bool collision;
	Atom(int _y = 0, int _x = 0, int _d = 0, int _e = 0, int _c = false)
		:y(_y), x(_x), dir(_d),energy(_e), collision(_c) {
	}
}Atom;

int dir_y[4] = { 1,-1,0,0 };
int dir_x[4] = { 0,0,-1,1 };
vector <Atom> atoms;

void mapCleaning(){
    for(int idx = 0; idx < (int)atoms.size();idx++){
        if(map[atoms[idx].y][atoms[idx].x]!=0){
            map[atoms[idx].y][atoms[idx].x]=0;
        }
    }
}
int getEnergy( int & numOfAtom) {
	int N = (int)atoms.size();
	int energy = 0;
	for (int n = 0; n < N; n++) {
		Atom curAtom = atoms[n];
		if (curAtom.collision == true) {
			continue;
		}
		if (map[curAtom.y][curAtom.x] > 1) {
			for (int idx = 0; idx < N; idx++) {
				if ((n==idx)||(atoms[idx].collision == true)) {
					continue;
				}
				if ((curAtom.y == atoms[idx].y) &&(curAtom.x == atoms[idx].x)) {
					atoms[idx].collision = true;
					numOfAtom -= 1;
					energy += atoms[idx].energy;
				}
			}
			numOfAtom -= 1;
			map[curAtom.y][curAtom.x] = 0;
			energy += curAtom.energy;
			atoms[n].collision = true;
		}
	}
	return energy;
}

void startCollision(int numOfAtom,int & answer) {
	int N = (int)atoms.size();
	for (;;) {
		if (numOfAtom <= 1) {
            mapCleaning();
			break;
		}
		for (int idx = 0; idx < N; idx++) {
			// 이미 붕괴했으면 다음거 보기
			if (atoms[idx].collision == true) {
				continue;
			}
			Atom curAtom = atoms[idx];
			map[curAtom.y][curAtom.x] = 0;
			int next_y = curAtom.y + dir_y[curAtom.dir];
			int next_x = curAtom.x + dir_x[curAtom.dir];
			// 범위 벗어났으면 ㅂ2
			if (next_y < 0 || next_x < 0 || next_y > 4000 || next_x > 4000) {
				atoms[idx].collision = true;
				numOfAtom -= 1;
			}
			else {
				map[next_y][next_x]+=1;
				atoms[idx].y = next_y;
				atoms[idx].x = next_x;
			}
		}
		// map 돌면서 2 보다 크면 원자 돌면서 에너지 방출해야함
		int tmpEnergy = getEnergy(numOfAtom);
		answer += tmpEnergy;
	}
	return;
}

int main() {
	int T = 0;
	int N = 0;
	int answer = 0;
	int cpyN = 0;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		atoms.clear();
		answer = 0;
		scanf("%d", &N);
		cpyN = N;
		for (int n = 0; n < N; n++) {
			Atom curAtom;
			scanf("%d %d %d %d", &curAtom.x, &curAtom.y, &curAtom.dir, &curAtom.energy);
			curAtom.y = (curAtom.y + 1000) * 2;
			curAtom.x = (curAtom.x + 1000) * 2;
			atoms.push_back(curAtom);
		}

		// cpyN이 0이 될 때 까지 
		startCollision(cpyN,answer);
		printf("#%d %d\n", tc, answer);
	}
	return 0;
}