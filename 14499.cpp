//18.10.13 #No.14499 <주사위 굴리기>
//Coments : 초기 시뮬문제, 머릿속으로 생각하기보다 종이에 써서 도표화
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#define MAXNM 20+1
int ans,N,M,K,x,y;
int map[MAXNM][MAXNM];
int dr[5] = { 0, 0, 0, -1, 1 };
int dc[5] = { 0, 1, -1, 0, 0 };
vector<int> input;
typedef struct{
	int r, c;
	int top, bottom, left, right, up, down;
}DICE;
DICE dice;

bool check(int rr, int cc){
	if (rr < 0 || rr >= N || cc < 0 || cc >= M) return false;
	else return true;
}

void solve(){
	int temp;
	for (int i = 0; i < K; i++){
		int dir = input.at(i);
		int rr = dice.r + dr[dir];
		int cc = dice.c + dc[dir];
		if (check(rr, cc)){
			switch (dir)
			{
			case 1:
				temp = dice.bottom;
				dice.bottom = dice.right;
				dice.right = dice.top;
				dice.top = dice.left;
				dice.left = temp;
				break;
			case 2:
				temp = dice.bottom;
				dice.bottom = dice.left;
				dice.left = dice.top;
				dice.top = dice.right;
				dice.right = temp;
				break;
			case 3:
				temp = dice.bottom;
				dice.bottom = dice.up;
				dice.up = dice.top;
				dice.top = dice.down;
				dice.down = temp;
				break;
			case 4:
				temp = dice.bottom;
				dice.bottom = dice.down;
				dice.down = dice.top;
				dice.top = dice.up;
				dice.up = temp;
				break;
			}
			dice.r += dr[dir];
			dice.c += dc[dir];
			if (map[dice.r][dice.c] == 0){
				map[dice.r][dice.c] = dice.bottom;
			}
			else{
				dice.bottom = map[dice.r][dice.c];
				map[dice.r][dice.c] = 0;
			}
			cout << dice.top << endl;
		}		
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	setbuf(stdout, NULL);
	int temp;
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> map[i][j];
	for (int i = 0; i < K; i++){
		cin >> temp;
		input.push_back(temp);
	}
	dice.r = x; dice.c = y;
	solve();

	return 0;
}
