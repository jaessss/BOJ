//18.10.17 #No.2178 <미로탐색> 1550-1630
//Coments : DFS로 접근할 생각ㄴㄴ B인 이유 확인
//ios::sync_with_stdio(false); cin.tie(NULL); 이걸 쓸 때 scanf와 cin cout을 혼용하면 에러발생할 수 있음
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#define SIZE 100+1
#define INF 0x7fffffff
using namespace std;
long long ans;
int map[SIZE][SIZE];
long long visit[SIZE][SIZE];
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };
int N, M;

bool check(int rr, int cc){
	if (rr < 0 || rr >= N || cc < 0 || cc >= M) return false;
	if (map[rr][cc] == 0)return false;
	return true;
}

void BFS(){
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visit[0][0] = 1;
	while (!q.empty()){
		pair<int, int> now = q.front(); q.pop();
		for (int k = 0; k < 4; k++){
			int rr = now.first + dr[k];
			int cc = now.second + dc[k];
			if (check(rr, cc)){
				if (visit[rr][cc]){
					if (visit[rr][cc] <= visit[now.first][now.second] + 1) continue;
					else {
						q.push({ rr, cc });
						visit[rr][cc] = visit[now.first][now.second] + 1;
					}
				}
				else {
					q.push({ rr, cc });
					visit[rr][cc] = visit[now.first][now.second]+1;
				}
			}
		}
	}
	ans = visit[N - 1][M - 1];
}

int main(void)
{
	//ios::sync_with_stdio(false); cin.tie(NULL);
	setbuf(stdout, NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) scanf("%1d", &map[i][j]);
	BFS();

	cout << ans << endl;

	return 0;
}
