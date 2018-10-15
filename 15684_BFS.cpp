//18.10.15 #No.15684 <사다리조작>1122~
//BFS 메모리초과
//Coments : 최대 3개라는 조건!!! 조건확인잘해 B가아니라 D로 풀어야한다!
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
bool map[MAXH][MAXN];
queue<vector<pair<int, int>>> q;
bool visit[MAXH][MAXN];
vector<pair<int, int>> now_vec;
vector<pair<int, int>> temp_vec;

bool num_check(int num, vector<pair<int, int>> &vec){
	
	int start_num = num;
	int size = vec.size();
	if (vec.size()){
		for (int i = 0; i < size; i++){
			map[vec.at(i).first][vec.at(i).second] = 1;
		}
	}
	
	for (int i = 1; i <= H; i++){
		if (map[i][num] == 1) num++;
		else if (num > 1 && map[i][num - 1] == 1) num--;
		else if (size < 3){
			if (num <= N - 1 && map[i][num + 1] == 0 && !visit[i][num]){
				temp_vec = vec;
				temp_vec.push_back({ i, num });
				q.push(temp_vec);
				visit[i][num] = 1;
			}
			if (num > 1 && !visit[i][num - 1]){
				if (num > 2 && map[i][num - 2] == 1 ) continue;
				else{
					temp_vec = vec;
					temp_vec.push_back({ i, num -1 });\
					q.push(temp_vec);
					visit[i][num - 1] = 1;
				}
			}
		}
	}

	if (vec.size()){
		for (int i = 0; i < size; i++){
			map[vec.at(i).first][vec.at(i).second] = 0;
		}
	}
	if (num == start_num) return true;
	else return false;
}

void BFS(){
	int false_cnt = 0;
	memset(visit, 0, sizeof(visit));
	for (int i = 1; i <= N; i++){
		if (!num_check(i, now_vec)) false_cnt++;
	}
	if (!false_cnt) { ans = 0; return; }

	while (!q.empty()){
		now_vec = q.front(); q.pop();
		memset(visit, 0, sizeof(visit));
		false_cnt = 0;
		for (int i = 1; i <= N; i++){
			if (!num_check(i, now_vec)) false_cnt++;
		}
		if (!false_cnt) {
			ans = now_vec.size();
			break;			
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
	BFS();
	if (ans == INF) ans = -1;
	cout << ans << endl;

	return 0;
}
