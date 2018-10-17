//18.10.17 #No.1890 <점프>
//Coments : N이 100이기 때문에 DFS는 시간초과, 경로가 많아서 BFS는 메모리초과
//답은 DP로 찾아야 함 -> DFS보다 메모리는 더 먹지만 반복문으로 처리할 수 있어 시간단축
//visit체크를 한곳만 방문해서 확인한다는 컨셉
//사이즈가 클때는 int형 선언이 문제가 되지 않을지 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define MAXN 100+1
using namespace std;
long ans;
int N;
int map[MAXN][MAXN];
long DP_cnt[MAXN][MAXN];
bool visit[MAXN][MAXN];

void DP(){
	DP_cnt[0][0] = 1;
	visit[0][0] = true;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (visit[i][j]){
				if (i == N - 1 && j == N - 1) continue;
				int jump = map[i][j];
				int cc = j + jump;
				int rr = i + jump;
				if (cc <= N - 1){
					DP_cnt[i][cc] += DP_cnt[i][j];
					visit[i][cc] = true;
				}
				if (rr <= N - 1){
					DP_cnt[rr][j] += DP_cnt[i][j];
					visit[rr][j] = true;
				}
			}
		}
	}
	ans = DP_cnt[N - 1][N - 1];
}
int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	setbuf(stdout, NULL);
	cin >> N;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> map[i][j];
	DP();

	cout << ans << endl;

	return 0;
}
