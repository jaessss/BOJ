//18.10.14 #No.13460 <구슬 탈출2> 1345-1630
//Coments : 방향은 2칸씩 띄워서 반대 방향이게끔 설정
//move 순서 부분에서 시간 왕창... 순서 판단에 있어서 R 이동방향선 전체에 B가 있는지 확인! 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define MAXNM 10+1
#define INF 0x7fffffff
using namespace std;
int N, M;
char map[MAXNM][MAXNM];
int ans;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };
pair<int, int> hole;

pair<int, int> move(pair<int, int> p, int dir, pair<int, int> before){
	int rr = p.first + dr[dir];
	int cc = p.second + dc[dir];
	while (map[rr][cc] == '.'){
		rr += dr[dir];
		cc += dc[dir];
	}
	if (map[rr][cc] == 'O') return make_pair(rr, cc);
	else{
		rr -= dr[dir];
		cc -= dc[dir];
		if (rr == before.first && cc == before.second){//공끼리 겹치는 경우
			rr -= dr[dir];
			cc -= dc[dir];
		}
		return make_pair(rr, cc);
	}
}

bool redfirst(pair<int, int> red, pair<int, int> blue, int dir){
	int rr = red.first + dr[dir];
	int cc = red.second + dc[dir];
	while (map[rr][cc] == '.'){
		if (rr == blue.first && cc == blue.second){
			return false;
		}
		rr += dr[dir];
		cc += dc[dir];
	}
	return true;
}

void DFS(pair<int, int> red, pair<int, int> blue, int cnt, int dir){
	if (cnt > 10){
		return;
	}
	else if (cnt < ans){
		//move
		pair<int, int> temp_red = red;
		pair<int, int> temp_blue = blue;
		if (redfirst(red,blue,dir)){
			temp_red = move(red, dir, temp_blue);
			temp_blue = move(blue, dir, temp_red);
		}
		else{
			temp_blue = move(blue, dir, temp_red);
			temp_red = move(red, dir, temp_blue);
		}
		//check & depth++
		if (temp_blue == hole){
			return;
		}
		else if (temp_red == hole){
			ans = min(ans, cnt); return;
		}
		else{
			for (int i = 0; i < 4; i++){
				if (i != ((dir + 2) % 4) && i != dir) DFS(temp_red, temp_blue, cnt + 1, i);
			}
		}
	}
	
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	setbuf(stdout, NULL);
	pair<int, int> R;
	pair<int, int> B;

	cin >> N >> M;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> map[i][j];
			if (map[i][j] == 'O') hole = make_pair(i, j);
			if (map[i][j] == 'R'){
				R = make_pair(i, j);
				map[i][j] = '.';
			}
			if (map[i][j] == 'B'){
				B = make_pair(i, j);
				map[i][j] = '.';
			}
		}
	}
	ans = INF;
	for (int i = 0; i < 4; i++) DFS(R, B, 1, i);
	if (ans == INF) ans = -1;
	cout << ans << endl;

	return 0;
}
