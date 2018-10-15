//18.10.15 #No.15684 <사다리조작>ver2 1550-1745
//DFS
//Coments : 최대 3개라는 조건!!! 조건확인잘해 B가아니라 D로 풀어야한다!
//탐색 대상 조건 줄이는 포인트! 쭉 줄을 세워놓고 선택하고 확인 안하고 다음진행 큰 줄기는 같다.
//DFS 공부좀 더하자....너무지저분
//for문 사용시 세번째 인자로 증감연산과 함께 다른 수행사항 추가할 수 있음!(for (int i = rr; i <= H; i++, cc = 1))
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <string.h>
#define MAXN 10 + 1
#define MAXH 30 + 1
#define INF 0x7fffffff
using namespace std;
int ans;
int N, M, H;
int map[MAXH][MAXN];
vector<pair<int, int>> temp_vec;

bool end_check(){
	int false_cnt = 0;
	for (int num = 1; num <= N; num++){
		int temp_num = num;
		for (int i = 1; i <= H; i++){
			if (map[i][temp_num] == 1) temp_num++;
			else if (temp_num > 1 && map[i][temp_num - 1] == 1) temp_num--;
		}
		if (temp_num != num) { false_cnt++; break; }
	}
	if (false_cnt) return false;
	else return true;
}

void DFS(int cnt, pair<int, int> pos){
	if (cnt >= 3 && ans == 3) return;
	else{
		if (end_check()) {
			ans = min(ans, cnt);
			return;
		}
		else if (cnt<3){
			int rr = pos.first, cc = pos.second;//백트래킹 포인트 탐색 대상의 범위를 좁혀가야 시간초과 안나
			for (int i = rr; i <= H; i++, cc = 1){
				for (int j = cc; j <= N - 1; j++){
					if (!map[i][j] && !map[i][j + 1]){
						if (j >= 2 && map[i][j - 1]) continue;
						else{
							map[i][j] = 1;
							DFS(cnt + 1, { i, j });
							map[i][j] = 0;
						}
					}
				}
			}
		}
		else {
			return;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	setbuf(stdout, NULL);
	cin >> N >> M >> H;
	int temph, tempc;
	for (int i = 1; i <= M; i++){
		cin >> temph >> tempc;
		map[temph][tempc] = 1;
	}
	ans = INF;
	DFS(0, { 1, 1 });
	if (ans == INF) ans = -1;
	cout << ans << endl;

	return 0;
}
