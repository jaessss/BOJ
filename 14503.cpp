//18.10.10 #No.14503 <로봇청소기> 1710-1852
//Coments : while문 혹은 DFS
//DFS에서 왜 무한뤂...?
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define MAXNM 50+1
using namespace std;
int ans, N, M;
int map[MAXNM][MAXNM];
typedef struct{
	int r, c;
	int dir;
}ROBOT;
ROBOT robot;
int dr[4] = { 0, -1, 0, 1 };
int dc[4] = { -1, 0, 1, 0 };

void DFS(int r, int c, int dir, int rotate_cnt){
	if (ans) return;/////////////////////////////
	if (rotate_cnt >= 4 && !ans){
		int rr = r + dr[(dir + 3) % 4];
		int cc = c + dc[(dir + 3) % 4];
		if (map[rr][cc]==2) DFS(rr, cc, dir, 0);
		else if (map[rr][cc] == 1){
			for (int i = 0; i < N; i++){ for (int j = 0; j < M; j++){ if (map[i][j] == 2)ans++; }}
			return;
		}
	}

	map[r][c] = 2;
	int rr = r + dr[dir];
	int cc = c + dc[dir];
	if (map[rr][cc] == 0) DFS(rr, cc, (dir + 3) % 4, 0);
	else DFS(r, c, (dir + 3) % 4, rotate_cnt + 1);

}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	setbuf(stdout, NULL);

	cin >> N >> M;
	cin >> robot.r >> robot.c >> robot.dir;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> map[i][j];
		}
	}

	ans = 0;
	DFS(robot.r, robot.c, robot.dir, 0);

	cout << ans << endl;

	return 0;
}
