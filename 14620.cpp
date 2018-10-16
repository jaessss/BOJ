//18.10.16 #No.14620 <꽃길> 1029-1054
//Coments : DFS 탐색범위 - 다음 순서에 해당하는 것만 탐색, 현재까지의 답과 비교해서 가지치기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define INF 0x7fffffff
#define MAXN 10+1
using namespace std;
int ans;
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };
int map[MAXN][MAXN];
int cost[MAXN][MAXN];
int visit[MAXN][MAXN];
int N;

void cal_cost(){
	for (int i = 2; i <= N - 1; i++){
		for (int j = 2; j <= N - 1; j++){
			int temp_sum = map[i][j];
			for (int k = 0; k < 4; k++) temp_sum += map[i + dr[k]][j + dc[k]];
			cost[i][j] = temp_sum;
		}
	}
}

void visit_calc(int r, int c, int option){
	visit[r][c] = option;
	for (int k = 0; k < 4; k++){
		visit[r + dr[k]][c + dc[k]] = option;
	}
}

bool visit_check(int r, int c){
	for (int k = 0; k < 4; k++){
		if (visit[r + dr[k]][c + dc[k]]) return false;
	}
	return true;
}

void DFS(int depth, int r, int c, int nowsum){
	if (depth == 3) {
		ans = min(ans, nowsum);
		return;
	}
	else if (ans < nowsum) return;
	else{
		for (int i = r; i <= N - 1; i++, c = 2){
			for (int j = c; j <= N - 1; j++){
				if (visit_check(i, j)){
					visit_calc(i, j, 1);
					DFS(depth + 1, i, j + 1, nowsum + cost[i][j]);
					visit_calc(i, j, 0);
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
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) cin >> map[i][j];
	cal_cost();

	ans = INF;
	DFS(0, 2, 2, 0);

	cout << ans << endl;

	return 0;
}
