//18.10.14 #No.14500 <테트로미노> 1210-1256
//Coments : 
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
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int ans;

bool check(pair<int, int> p[3]){
	for (int i = 0; i < 3; i++){
		if (p[i].first < 0 || p[i].first >= N || p[i].second < 0 || p[i].second >= M) return false;
		else continue;
	}
	return true;
}

void calcsum(int r, int c, pair<int, int> p[3]){
	int temp_sum = map[r][c];
	for (int i = 0; i < 3; i++){
		temp_sum += map[p[i].first][p[i].second];
	}
	if (temp_sum > ans) ans = temp_sum;
}

void solve(){
	int temp_sum;
	pair<int, int> p[3];
	//네모 & 지그재그
	for (int i = 0; i < N - 1; i++){
		for (int j = 0; j < M - 1; j++){
			for (int k = 0; k < 5; k++){
				if (k == 0){
					p[0] = make_pair(i + dr[0], j + dc[0]);
					p[1] = make_pair(i + dr[3], j + dc[3]);
					p[2] = make_pair(i + dr[3] + dr[1], j + dc[3] + dc[1]);
				}
				else if (k == 1){
					p[0] = make_pair(i + dr[1], j + dc[1]);
					p[1] = make_pair(i + dr[3], j + dc[3]);
					p[2] = make_pair(i + dr[3] + dr[0], j + dc[3] + dc[0]);
				}
				else if (k == 2){
					p[0] = make_pair(i + dr[1], j + dc[1]);
					p[1] = make_pair(i + dr[3], j + dc[3]);
					p[2] = make_pair(i + dr[1] + dr[2], j + dc[1] + dc[2]);
				}
				else if (k==3){
					p[0] = make_pair(i + dr[1], j + dc[1]);
					p[1] = make_pair(i + dr[2], j + dc[2]);
					p[2] = make_pair(i + dr[1] + dr[3], j + dc[1] + dc[3]);
				}
				else{
					p[0] = make_pair(i + dr[1], j + dc[1]);
					p[1] = make_pair(i + dr[3], j + dc[3]);
					p[2] = make_pair(i + dr[1] + dr[3], j + dc[1] + dc[3]);
				}
				if (check(p)) calcsum(i, j, p);
			}
		}
	}
	//가로3이상
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M - 2; j++){
			for (int k = 0; k < 7; k++){
				if (k == 0){//ㅡ
					p[0] = make_pair(i + dr[3], j + dc[3]);
					p[1] = make_pair(i + dr[3] + dr[3], j + dc[3] + dc[3]);
					p[2] = make_pair(i + dr[3] + dr[3] + dr[3], j + dc[3] + dc[3] + dc[3]);
				}
				else if (k == 1){//ㅗ
					p[0] = make_pair(i + dr[3], j + dc[3]);
					p[1] = make_pair(i + dr[3] + dr[3], j + dc[3] + dc[3]);
					p[2] = make_pair(i + dr[3] + dr[0], j + dc[3] + dc[0]);
				}
				else if (k == 2){//ㅜ
					p[0] = make_pair(i + dr[3], j + dc[3]);
					p[1] = make_pair(i + dr[3] + dr[3], j + dc[3] + dc[3]);
					p[2] = make_pair(i + dr[3] + dr[1], j + dc[3] + dc[1]);
				}
				else if (k == 3){//ㄴ1
					p[0] = make_pair(i + dr[3], j + dc[3]);
					p[1] = make_pair(i + dr[3] + dr[3], j + dc[3] + dc[3]);
					p[2] = make_pair(i + dr[0], j + dc[0]);
				}
				else if (k == 4){//ㄴ2
					p[0] = make_pair(i + dr[3], j + dc[3]);
					p[1] = make_pair(i + dr[3] + dr[3], j + dc[3] + dc[3]);
					p[2] = make_pair(i + dr[3] + dr[3] + dr[0], j + dc[3] + dc[3] + dc[0]);
				}
				else if (k == 5){//ㄱ1
					p[0] = make_pair(i + dr[3], j + dc[3]);
					p[1] = make_pair(i + dr[3] + dr[3], j + dc[3] + dc[3]);
					p[2] = make_pair(i + dr[3] + dr[3] + dr[1], j + dc[3] + dc[3] + dc[1]);
				}
				else{//ㄱ2
					p[0] = make_pair(i + dr[3], j + dc[3]);
					p[1] = make_pair(i + dr[3] + dr[3], j + dc[3] + dc[3]);
					p[2] = make_pair(i + dr[1], j + dc[1]);
				}
				if (check(p)) calcsum(i, j, p);
			}
		}
	}
	//세로3이상
	for (int i = 0; i < N-2; i++){
		for (int j = 0; j < M; j++){
			for (int k = 0; k < 7; k++){
				if (k == 0){//ㅣ
					p[0] = make_pair(i + dr[1], j + dc[1]);
					p[1] = make_pair(i + dr[1] + dr[1], j + dc[1] + dc[1]);
					p[2] = make_pair(i + dr[1] + dr[1] + dr[1], j + dc[1] + dc[1] + dc[1]);
				}
				else if (k == 1){//ㅏ
					p[0] = make_pair(i + dr[1], j + dc[1]);
					p[1] = make_pair(i + dr[1] + dr[1], j + dc[1] + dc[1]);
					p[2] = make_pair(i + dr[1] + dr[3], j + dc[1] + dc[3]);
				}
				else if (k == 2){//ㅓ
					p[0] = make_pair(i + dr[1], j + dc[1]);
					p[1] = make_pair(i + dr[1] + dr[1], j + dc[1] + dc[1]);
					p[2] = make_pair(i + dr[1] + dr[2], j + dc[1] + dc[2]);
				}
				else if (k == 3){//ㄴ1
					p[0] = make_pair(i + dr[1], j + dc[1]);
					p[1] = make_pair(i + dr[1] + dr[1], j + dc[1] + dc[1]);
					p[2] = make_pair(i + dr[1] + dr[1] + dr[3], j + dc[1] + dc[1] + dc[3]);
				}
				else if (k == 4){//ㄴ2
					p[0] = make_pair(i + dr[1], j + dc[1]);
					p[1] = make_pair(i + dr[1] + dr[1], j + dc[1] + dc[1]);
					p[2] = make_pair(i + dr[1] + dr[1] + dr[2], j + dc[1] + dc[1] + dc[2]);
				}
				else if (k == 5){//ㄱ1
					p[0] = make_pair(i + dr[1], j + dc[1]);
					p[1] = make_pair(i + dr[1] + dr[1], j + dc[1] + dc[1]);
					p[2] = make_pair(i + dr[2], j + dc[2]);
				}
				else{//ㄱ2
					p[0] = make_pair(i + dr[1], j + dc[1]);
					p[1] = make_pair(i + dr[1] + dr[1], j + dc[1] + dc[1]);
					p[2] = make_pair(i + dr[3], j + dc[3]);
				}
				if (check(p)) calcsum(i, j, p);
			}
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
