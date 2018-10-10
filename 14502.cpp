//18.10.10 #No.14502 <연구소>
//Coments : 쉬프트 비트연산은 32비트까지만?
//벽3개 세우는 조합 경우의수 -> for문으로 처리...
//vector<int> ::size_type i
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string.h>//memcpy사용시

#define INF 0x7fffffff
#define MAXNM 8
using namespace std;
typedef struct {
	int r, c;
}POINT;
POINT point[3];
int ans;
int M, N;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int map[MAXNM][MAXNM];
int newmap[MAXNM][MAXNM];
vector<POINT> vec;

bool check(int rr, int cc){
	if (rr < 0 || rr >= N || cc < 0 || cc >= M) return false;
	if (newmap[rr][cc] != 1 && newmap[rr][cc] != 2) return true;
	else return false;
}

void search(int r, int c){
	newmap[r][c] = 2;
	for (int k = 0; k < 4; k++){
		int rr = r + dr[k];
		int cc = c + dc[k];
		if (check(rr, cc)) search(rr, cc);
	}
}

void expand(POINT point[]){
	int cnt = 0;
	int virus_num = 0;
	memcpy(newmap, map, sizeof(int) * 64);
	for (int i = 0; i < 3; i++) newmap[point[i].r][point[i].c] = 1;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (map[i][j] == 2){
				search(i, j);
			}
		}
	}
	//count
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (newmap[i][j] == 0) cnt++;
		}
	}

	ans = max(ans, cnt);
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	setbuf(stdout, NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++){
		cin >> map[i][j];
		if (map[i][j] == 0){
			POINT temp = { i, j };
			vec.push_back(temp);
		}
	}
	ans = 0;
	POINT temp_point[3];
	for (vector<int> ::size_type i = 0; i < vec.size(); i++){
		temp_point[0] = vec.at(i);
		for (vector<int> ::size_type j = i + 1; j < vec.size(); j++){
			temp_point[1] = vec.at(j);
			for (vector<int> ::size_type k = j + 1; k < vec.size(); k++){
				if (map[vec.at(i).r][vec.at(i).c] == 0 && map[vec.at(j).r][vec.at(j).c] == 0 && map[vec.at(k).r][vec.at(k).c] == 0){
					temp_point[2] = vec.at(k);
					expand(temp_point);
				}
			}
		}
	}   

	cout << ans;

	return 0;
}
