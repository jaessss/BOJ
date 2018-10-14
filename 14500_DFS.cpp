//18.10.14 #No.14500 <테트로미노> 1210-1256
//Coments : dfs 작성시에는 return 조건 절대 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#define MAXNM 500+10
int N, M;
int map[MAXNM][MAXNM];
bool visit[MAXNM][MAXNM];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int ans;

bool check(int r, int c){
	return r >= 0 && r < N && c >= 0 && c < M;
}

void DFS(int r, int c, int cnt, int sum){
	if (cnt == 3 ){
		if (ans < sum) ans = sum;
		return;
	}
	else{
		visit[r][c] = true;
		for (int i = 0; i < 4; i++){
			int rr = r + dr[i];
			int cc = c + dc[i];
			if (check(rr, cc) && !visit[rr][cc]){
				DFS(rr, cc, cnt + 1, sum + map[rr][cc]);
			}
			else continue;
		}
		visit[r][c] = false;
	}
}

void calc(int r, int c){
	int sum = map[r][c];
	int min_val = 1000000;
	int cnt = 0;
	for (int i = 0; i < 4; i++){
		int rr = r + dr[i];
		int cc = c + dc[i];
		if (check(rr, cc)){
			sum += map[rr][cc];
			min_val = min(min_val, map[rr][cc]);
		}
		else cnt++;

		if (cnt >= 2) return;
	}
	if (cnt == 1){
		if (ans < sum) ans = sum;
	}
	else{
		sum -= min_val;
		if (ans < sum) ans = sum;
	}
}

void solve(){
	for (int i = 0; i < N; i++)	for (int j = 0; j < M; j++) DFS(i, j, 0, map[i][j]);

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			calc(i, j);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	setbuf(stdout, NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> map[i][j];
	ans = 0;
	solve();

	cout << ans << endl;

	return 0;
}
