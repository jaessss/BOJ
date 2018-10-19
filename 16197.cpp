//18.10.19 #No.16197 <두 동전>
//Coments : BFS로 접근하는 경우 큐에 넣을때 가능성있는 것만 넣는 걸로, 정답조건을 큐에 넣기 전에 확인!
//불필요한 큐삽입ㄴㄴ, 두 동전이 움직였을 떄 생길 수 있는 케이스를 보다 활용하기 좋게 나누는 법
//4차원 비짓 활용[][][][]
//탐색의 기본은 visit 체크!
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#define MAXNM 20+1
#define INF 0x7fffffff
using namespace std;
int ans;
int N, M;
char map[MAXNM][MAXNM];
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };
bool visit[MAXNM][MAXNM][MAXNM][MAXNM];

struct eachcoin{
	int r, c;
};
struct COINS{
	pair < eachcoin, eachcoin > coins;
	int cnt;//움직인횟수
};
COINS coins;

int check(int rr, int cc){//동
	if (rr<0 || rr>N - 1 || cc<0 || cc>M - 1) return 0;//낙
	else return 1;
}

void BFS(){
	queue<COINS> q;
	coins.cnt = 0;
	visit[coins.coins.first.r][coins.coins.first.c][coins.coins.second.r][coins.coins.second.c] = true;
	q.push(coins);


	while (!q.empty()){
		COINS now = q.front(); q.pop();
		if (now.cnt >= ans) continue;
		if (now.cnt >= 10) continue;
		//move
		for (int k = 0; k < 4; k++){
			COINS next = now;
			int fr = now.coins.first.r + dr[k];
			int fc = now.coins.first.c + dc[k];
			int sr = now.coins.second.r + dr[k];
			int sc = now.coins.second.c + dc[k];
			int f_chk = check(fr, fc);
			int s_chk = check(sr, sc);

			if (f_chk + s_chk == 0) continue;//둘다 낙
			else if (f_chk + s_chk == 1){//하나만 낙
				ans = min(ans, now.cnt + 1);
				continue;
			}
			else{//둘다 낙x
				if (map[fr][fc] != '#'){
					next.coins.first.r = fr;
					next.coins.first.c = fc;
				}
				if (map[sr][sc] != '#'){
					next.coins.second.r = sr;
					next.coins.second.c = sc;
				}
			}
			if (next.coins.first.r == next.coins.second.r && next.coins.first.c == next.coins.second.c) continue;
			if (!visit[next.coins.first.r][next.coins.first.c][next.coins.second.r][next.coins.second.c]){
				visit[next.coins.first.r][next.coins.first.c][next.coins.second.r][next.coins.second.c] = true;
				next.cnt = now.cnt + 1;
				q.push(next);
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	setbuf(stdout, NULL);
	cin >> N >> M;

	int coin_cnt = 0;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> map[i][j];
			if (map[i][j] == 'o'){//각코인정보 저장
				if (coin_cnt == 0){
					coins.coins.first.r = i;
					coins.coins.first.c = j;
					coin_cnt++;
				}
				else if (coin_cnt == 1){
					coins.coins.second.r = i;
					coins.coins.second.c = j;
				}
			}
		}
	}
	ans = INF;
	BFS();
	if (ans == INF) ans = -1;
	cout << ans << endl;

	return 0;
}
