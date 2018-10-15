//18.10.15 #No.9882 <Balanced Teams> 1125-1139
//Coments : 가지치기 할 수 있는 부분고민?
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define INF 0x7fffffff
using namespace std;
int ans;
int input[12];
int teamNum[12];
int teamCnt[5];

void calc(){
	int maxval = -INF;
	int minval = INF;
	for (int i = 1; i <= 4; i++){
		int temp_sum = 0;
		for (int j = 0; j < 12; j++){
			if (teamNum[j] == i) temp_sum+=input[j];
		}
		maxval = max(maxval, temp_sum);
		minval = min(minval, temp_sum);
	}
	ans = min(ans, maxval - minval);
}

void DFS(int cnt){
	if (cnt == 12) {
		calc();
		return; 
	}
	else{
		for (int i = 1; i <= 4; i++){
			if (teamCnt[i] < 3){
				teamNum[cnt] = i;
				teamCnt[i]++;
				DFS(cnt + 1);
				teamCnt[i]--;
				teamNum[cnt] = 0;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	setbuf(stdout, NULL);
	for (int i = 0; i < 12; i++) cin >> input[i];
	ans = INF;
	DFS(0);

	cout << ans << endl;

	return 0;
}
