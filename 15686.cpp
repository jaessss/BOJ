//18.10.09 #No.15686 <치킨배달> 1601-1637
//Coments : 최대 M개이지만 M개 미만을 탐색할 필요는 없음
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define MAXN 50 + 1
#define MAXM 13 +1
#define INF 0x7fffffff
using namespace std;
int ans;
int N, M, input;
typedef struct HOME{
	int r, c, dis;
};

typedef struct CK{
	int r, c;
};

vector<HOME> home;
vector<CK> ck;

void init(){
	home.clear();
	ck.clear();
}

void search(int i){
	int total = 0;
	for (int j = 0; j < home.size(); j++) home.at(j).dis = INF;

	for (int j = 0; j < ck.size(); j++){
		if (i & (1 << j)){
			for (int k = 0; k < home.size(); k++){
				int temp_dis = abs(ck.at(j).r - home.at(k).r) + abs(ck.at(j).c - home.at(k).c);
				home.at(k).dis = min(home.at(k).dis, temp_dis);
			}
		}
	}

	for (int j = 0; j < home.size(); j++) total += home.at(j).dis;
	ans = min(ans, total);
}

void solve(){
	for (int i = 0; i < (1 << ck.size()); i++){
		int cnt = 0;
		for (int j = 0; j < ck.size(); j++)	if (i & (1 << j)) cnt++;
		if (cnt == M) search(i);			
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	setbuf(stdout, NULL);
		
	init();
	cin >> N >> M;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			cin >> input;
			if (input == 1){
				HOME temp = { i, j, INF };
				home.push_back(temp);
			}
			else if (input == 2){
				CK temp = { i, j };
				ck.push_back(temp);
			}
		}
	}
	ans = INF;
	solve();

	cout << ans << endl;
	
	return 0;
}
