//18.10.11 #No.15683 <감시> 0851-1017
//Coments : cctv 하나도 없는 경우도 고려 ~ 런타임에러는 보통 배열 인덱스 접근오류가 많아
//각 경우 꼼꼼히 나누고 공통되는 작업을 찾아서 함수화, 방향가지고 노는거 선언 주의
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string.h>
#define MAXNM 8+1
#define INF 0x7fffffff
using namespace std;
int ans, N, M;
typedef struct{
	int r, c, num;
}CCTV;
int map[MAXNM][MAXNM];
int visit[MAXNM][MAXNM];
vector<CCTV> vec;
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };

void calc(int visited[][MAXNM]){
	int cnt = 0;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (visited[i][j] == 0) cnt++;
			if (cnt > ans) return;
		}
	}
	if (cnt < ans) ans = cnt;
}

bool check(int rr, int cc){
	if (rr < 0 || rr >= N || cc < 0 || cc >= M) return false;
	else if (map[rr][cc] == 6) return false;
	else return true;
}

void look(int r, int c, int dir, int visited[][MAXNM]){
	int rr = r + dr[dir];
	int cc = c + dc[dir];
	while (check(rr, cc)){
		visited[rr][cc] = 7;
		rr += dr[dir];
		cc += dc[dir];
	}
}

void DFS(int cnt, int visited[][MAXNM], CCTV now_cctv){
	int temp_map[MAXNM][MAXNM];
	memcpy(temp_map, visited, sizeof(temp_map));

	if (cnt == vec.size()){
		calc(visited);
		return;
	}
	else{
		switch (now_cctv.num)
		{
		case 1://한방향4
			for (int i = 0; i < 4; i++){
				look(now_cctv.r, now_cctv.c, i, visited);
				if (vec.size() >cnt + 1){
					DFS(cnt + 1, visited, vec.at(cnt + 1));
					memcpy(visited, temp_map, sizeof(temp_map));
				}
				else{
					DFS(cnt + 1, visited, vec.at(cnt));
					memcpy(visited, temp_map, sizeof(temp_map));
				}
			}
			break;
		case 2://2방향 수평2
			for (int i = 0; i < 2; i++){
				look(now_cctv.r, now_cctv.c, i, visited);
				look(now_cctv.r, now_cctv.c, i + 2, visited);
				if (vec.size() >cnt + 1){
					DFS(cnt + 1, visited, vec.at(cnt + 1));
					memcpy(visited, temp_map, sizeof(temp_map));
				}
				else{
					DFS(cnt + 1, visited, vec.at(cnt));
					memcpy(visited, temp_map, sizeof(temp_map));
				}
			}
			break;
		case 3://2방향 직각4
			for (int i = 0; i < 4; i++){
				look(now_cctv.r, now_cctv.c, i, visited);
				look(now_cctv.r, now_cctv.c, (i + 1) % 4, visited);
				if (vec.size() >cnt + 1){
					DFS(cnt + 1, visited, vec.at(cnt + 1));
					memcpy(visited, temp_map, sizeof(temp_map));
				}
				else{
					DFS(cnt + 1, visited, vec.at(cnt));
					memcpy(visited, temp_map, sizeof(temp_map));
				}
			}
			break;
		case 4://3방향4
			for (int i = 0; i < 4; i++){
				look(now_cctv.r, now_cctv.c, i, visited);
				look(now_cctv.r, now_cctv.c, (i + 1) % 4, visited);
				look(now_cctv.r, now_cctv.c, (i + 2) % 4, visited);
				if (vec.size() >cnt + 1){
					DFS(cnt + 1, visited, vec.at(cnt + 1));
					memcpy(visited, temp_map, sizeof(temp_map));
				}
				else{
					DFS(cnt + 1, visited, vec.at(cnt));
					memcpy(visited, temp_map, sizeof(temp_map));
				}
			}
			break;
		case 5://4방향1
			for (int i = 0; i < 4; i++)	look(now_cctv.r, now_cctv.c, i, visited);
			if (vec.size() >cnt + 1){
				DFS(cnt + 1, visited, vec.at(cnt + 1));
				memcpy(visited, temp_map, sizeof(temp_map));
			}
			else{
				DFS(cnt + 1, visited, vec.at(cnt));
				memcpy(visited, temp_map, sizeof(temp_map));
			}
			break;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	setbuf(stdout, NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5){
				CCTV temp = { i, j, map[i][j] };
				vec.push_back(temp);
			}
		}
	}
	memcpy(visit, map, sizeof(map));
	ans = INF;
	if (vec.size()==0) calc(map);
	else DFS(0, visit, vec.front());

	cout << ans << endl;

	return 0;
}
