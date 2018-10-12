//18.10.12 #No.15685 <드래곤 커브> 1010-1123
//Coments : 규칙파악이 관건인 문제.. 초기 시작점이 각 세대 마지막 점으로 이동하는 점!
//for (int j = now_size - 2; j >=0; j--){  -->> 감소식으로 반복문 돌릴때는 unsigined면 안됨(vector<int> ::size_type)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int ans;
int N;
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };

typedef struct{
	int x, y, dir, last_gen, now_gen;
	vector<pair<int, int>> vec;
}CURVE;
CURVE curve[21];
int map[101][101];

bool check(int x, int y){
	if (map[x + 1][y] && map[x][y + 1] && map[x + 1][y + 1]) return true;
	else return false;
}

void solve(){
	for (int i = 0; i < N; i++){
		while (curve[i].now_gen < curve[i].last_gen){
			int now_size = curve[i].vec.size();
			pair<int, int> last_point = curve[i].vec.back();
			for (int j = now_size - 2; j >=0; j--){
				pair<int, int> now_point = curve[i].vec.at(j);
				now_point.first -= last_point.first;
				now_point.second -= last_point.second;
				swap(now_point.first, now_point.second);
				now_point.first *= (-1);
				now_point.first += last_point.first;
				now_point.second += last_point.second;
				curve[i].vec.push_back(now_point);
			}
			curve[i].now_gen++;
		}
	}
	
	for (int i = 0; i < N; i++){
		for (vector<int> ::size_type j = 0; j < curve[i].vec.size(); j++){
			map[curve[i].vec.at(j).second][curve[i].vec.at(j).first] = 1;
		}
	}

	for (int i = 0; i <= 99; i++){
		for (int j = 0; j <= 99; j++){
			if (map[i][j] == 1 && check(i, j)) ans++;
		}
	}

}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	setbuf(stdout, NULL);
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> curve[i].x >> curve[i].y >> curve[i].dir >> curve[i].last_gen;
		curve[i].vec.push_back(make_pair(curve[i].x, curve[i].y));
		int yy = curve[i].y + dy[curve[i].dir];
		int xx = curve[i].x + dx[curve[i].dir];
		curve[i].vec.push_back(make_pair(xx, yy));
	}
	if(N>0) solve();

	cout << ans << endl;

	return 0;
}
