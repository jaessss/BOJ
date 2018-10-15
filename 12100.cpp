//18.10.15 #No.12100 <2048(easy)> 1905-2025
//Coments : 최대한 공통으로 할 수 있는 일을 함수화해서 케이스 나눠서 적절히 호출
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define MAXN 20+1
using namespace std;
int ans;
int N;

void calc(int map[][MAXN]){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (map[i][j] > ans) ans = map[i][j];
		}
	}
}

void move(int newmap[][MAXN], vector<int> vec, int dir, int num){
	int pos = 0;
	int size = vec.size();
	if (size == 0) return;
	else if (size == 1){
		switch (dir)
		{
		case 0:	newmap[pos++][num] = vec.at(0);	break;
		case 1:	newmap[num][N - 1 - (pos++)] = vec.at(0); break;
		case 2:	newmap[N - 1 - (pos++)][num] = vec.at(0); break;
		case 3:	newmap[num][pos++] = vec.at(0);	break;
		}
		return;
	}
	else{
		int temp = 0;
		int a, b;
		while (temp < size-1){
			a = vec.at(temp);
			b = vec.at(temp + 1);
			if (a == b){
				switch (dir)
				{
				case 0:	newmap[pos++][num] = a * 2;	break;
				case 1:	newmap[num][N - 1 - (pos++)] = a * 2; break;
				case 2:	newmap[N - 1 - (pos++)][num] = a * 2; break;
				case 3:	newmap[num][pos++] = a * 2;	break;
				}
				temp += 2;
			}
			else{
				switch (dir)
				{
				case 0:	newmap[pos++][num] = a; break;
				case 1:	newmap[num][N - 1 - (pos++)] = a; break;
				case 2:	newmap[N - 1 - (pos++)][num] = a; break;
				case 3:	newmap[num][pos++] = a;	break;
				}
				temp++;
			}
		}
		if (temp == size-1){
			switch (dir)
			{
			case 0:	newmap[pos++][num] = vec.at(size - 1); break;
			case 1:	newmap[num][N - 1 - (pos++)] = vec.at(size - 1); break;
			case 2:	newmap[N - 1 - (pos++)][num] = vec.at(size - 1); break;
			case 3:	newmap[num][pos++] = vec.at(size - 1); break;
			}
		}
	}
}

void DFS(int cnt, int dir, int map[][MAXN]){
	if (cnt > 5) { calc(map); return; }
	else{
		int newmap[MAXN][MAXN] = { 0, };
		if (dir == 0 || dir == 2){
			for (int j = 0; j < N; j++){
				vector<int> vec;
				if (dir == 0){
					for (int i = 0; i < N; i++)	if (map[i][j]) vec.push_back(map[i][j]);					
				}
				else if (dir == 2){
					for (int i = N-1; i >= 0; i--) if (map[i][j]) vec.push_back(map[i][j]);					
				}
				move(newmap, vec, dir, j);
			}
		}
		else if (dir == 1 || dir == 3){
			for (int i = 0; i < N; i++){
				vector<int> vec;
				if (dir == 3){
					for (int j = 0; j < N; j++) if (map[i][j]) vec.push_back(map[i][j]);
				}
				else if (dir == 1){
					for (int j = N - 1; j >= 0; j--) if (map[i][j]) vec.push_back(map[i][j]);
				}
				move(newmap, vec, dir, i);
			}
		}
		
		for (int i = 0; i < 4; i++) DFS(cnt + 1, i, newmap);		
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	setbuf(stdout, NULL);
	int map[MAXN][MAXN] = { 0, };
	cin >> N;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> map[i][j];

	ans = 0;
	for (int i = 0; i < 4; i++) DFS(1, i, map);

	cout << ans << endl;

	return 0;
}
