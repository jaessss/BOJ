//18.10.19 #No.10026 <적록색약>
//Coments : D,B 상관없지만 D나 B를 호출하는데 있어 메인문에서 visit을 활용해 모든 경우를 탐색할 수 있도록 호출해주어야함
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <string.h>
#define MAXN 100+5
using namespace std;
int ans1, ans2;
char map[MAXN][MAXN];
bool visit[MAXN][MAXN];

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

int N;

bool check(int rr, int cc){
	return rr >= 0 && rr <= N - 1 && cc >= 0 && cc <= N - 1;
}

void BFS(int r,int c){
	queue<pair<int, int>> q;
	q.push({ r, c });
	visit[r][c] = true;
	while (!q.empty()){
		pair<int, int> now = q.front(); q.pop();
		for (int k = 0; k < 4; k++){
			int rr = now.first + dr[k];
			int cc = now.second + dc[k];
			if (check(rr, cc)){
				if (!visit[rr][cc]){
					if (map[rr][cc] == map[now.first][now.second]){
						visit[rr][cc] = true;
						q.push({ rr, cc });
					}
					else continue;	
				}
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	setbuf(stdout, NULL);
	cin >> N;
	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++) cin >> map[i][j];

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (!visit[i][j]){
				BFS(i, j);
				ans1++;
			}
		}
	}
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (map[i][j] == 'R') map[i][j] = 'G';
		}
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (!visit[i][j]){
				BFS(i, j);
				ans2++;
			}
		}
	}
	cout << ans1 << " " << ans2 << '\n';

	return 0;
}
