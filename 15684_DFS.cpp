//18.10.15 #No.15684 <사다리조작>ver2 1550-1745
//DFS
//Coments : 최대 3개라는 조건!!! 조건확인잘해 B가아니라 D로 풀어야한다!
//탐색 대상 조건 줄이는 포인트! 쭉 줄을 세워놓고 선택하고 확인 안하고 다음진행 큰 줄기는 같다.
//DFS 공부좀 더하자....너무지저분
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
queue<vector<pair<int, int>>> q;
bool visit[MAXH][MAXN];
vector<pair<int, int>> now_vec;
vector<pair<int, int>> temp_vec;

void DFS(int cnt, vector<pair<int, int>> vec){
	if (cnt >= 3 && ans == 3) return;
	else{
		if (vec.size()){
			map[vec.at(vec.size() - 1).first][vec.at(vec.size() - 1).second] = 1;
		}
		int false_cnt = 0;
		for (int num = 1; num <= N; num++){
			int temp_num = num;
			for (int i = 1; i <= H; i++){
				if (map[i][temp_num] == 1) temp_num++;
				else if (temp_num > 1 && map[i][temp_num - 1] == 1) temp_num--;
			}
			if (temp_num != num) { false_cnt++; break; }
		}

		if (!false_cnt) {
			ans = min(ans, cnt); 
			if (vec.size())	map[vec.at(vec.size() - 1).first][vec.at(vec.size() - 1).second] = 0;
			return;
		}
		else if(cnt<3){
			int rr=1, cc=1;
			if (vec.size()){//백트래킹 포인트 탐색 대상의 범위를 좁혀가야 시간초과 안나
				rr = vec.at(vec.size() - 1).first;
				cc = vec.at(vec.size() - 1).second;
			}
			for (int i = rr; i <= H; i++, cc = 1){
				for (int j = cc; j <= N - 1; j++){
					if (!map[i][j] && !map[i][j + 1] ){
						if (j >= 2 && map[i][j - 1]) continue;
						else{
							temp_vec = vec;
							temp_vec.push_back({ i, j });
							DFS(cnt + 1, temp_vec);
						}						
					}
				}
			}
			if (vec.size())	map[vec.at(vec.size() - 1).first][vec.at(vec.size() - 1).second] = 0;
		}
		else {
			if (vec.size())	map[vec.at(vec.size() - 1).first][vec.at(vec.size() - 1).second] = 0;
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
	vector<pair<int, int>> v;
	DFS(0, v);
	if (ans == INF) ans = -1;
	cout << ans << endl;

	return 0;
}
