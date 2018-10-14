//18.10.14 #No.10711 <모래성>
//Coments : 단순 완탐 시간초과날 것이라는거부터 파악(맵사이즈1000x1000)
//BFS를 쓸수밖에 없는이유확인
//없어질 격자를 대상으로 주변을 확인해서 큐에 넣는 식으로
//!visit[rr][cc] 중복되는 탐색 대상을 쳐내는 스킬...
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#define SIZE 1001
using namespace std;
int ans;
int H, W;
char map[SIZE][SIZE];
int visit[SIZE][SIZE];
int dr[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
queue<pair<int, int>> q;

bool check(int r, int c){
	return r >= 0 && r < H && c >= 0 && c < W;
}

bool isErode(int r, int c){
	int rr, cc;
	int cnt = 0;
	for (int i = 0; i < 8; i++){
		rr = r + dr[i];
		cc = c + dc[i];
		if (check(rr, cc) && map[rr][cc] == '.') cnt++;
		if (cnt >= map[r][c] - '0') return true;
		else continue;
	}
	return false;
}

void BFS(){
	while (!q.empty()){
		pair<int, int> temp = q.front(); q.pop();
		map[temp.first][temp.second] = '.';
		int rr, cc;
		for (int i = 0; i < 8; i++){
			rr = temp.first + dr[i];
			cc = temp.second + dc[i];
			if (map[rr][cc] != '.' && !visit[rr][cc] && isErode(rr, cc)){
				q.push({ rr, cc });
				visit[rr][cc] = visit[temp.first][temp.second] + 1;
			}
		}
	}
	for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) ans = max(ans, visit[i][j]);
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	setbuf(stdout, NULL);
	cin >> H >> W;
	for (int i = 0; i < H; i++)	for (int j = 0; j < W; j++) cin >> map[i][j];
	for (int i = 0; i < H; i++){
		for (int j = 0; j < W; j++){
			if (map[i][j] >= '1' && map[i][j] <= '8' && isErode(i, j)) {
				q.push({ i, j });
				visit[i][j] = 1;
			}
		}
	}
	ans = -1;
	BFS();

	cout << ans << endl;

	return 0;
}
