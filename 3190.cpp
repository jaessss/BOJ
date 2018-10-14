//18.10.14 #No.3190 <뱀> 2157-2314
//Coments : 좌표계 시작점 주의 1부터인지 0부터인지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;
#define MAXN 100+10
#define MAXK 100+10
int ans;
int N, K, L;
pair<int, int> apple[MAXN];
bool apple_used[MAXK];
queue<pair<int, char>> turn;
vector<pair<int, int>> baaaaaam;
int dir = 0;//오0아1왼2위3
int dirLchange[] = { 3, 0, 1, 2 };
int dirRchange[] = { 1, 2, 3, 0 };
int dr[] = { 0, 1, 0, -1 };
int dc[] = { 1, 0, -1, 0 };

bool check(int r, int c){
	for (vector<pair<int, int>> ::iterator itr = baaaaaam.begin(); itr < baaaaaam.end(); itr++){
		if ((*itr).first == r && (*itr).second == c) return false;
	}
	if (r >= 1 && r <= N && c >= 1 && c <= N) return true;
	else return false;
}

bool turning_check(int time){
	if (turn.front().first == time) return true;
	else return false;
}

void solve(){
	int time = 0;
	int apple_location;
	pair<int, int> head;
	while (true){
		head = baaaaaam.at(baaaaaam.size() - 1);
		time++;
		apple_location = K;
		int rr = head.first + dr[dir];
		int cc = head.second + dc[dir];
		if (check(rr, cc)){//자기몸에 닿는 조건 추가
			for (int i = 0; i < K; i++){//사과확인
				if (!apple_used[i] && apple[i].first == rr && apple[i].second == cc){
					apple_location = i;
					apple_used[i] = true;
					break;
				}
			}
			if (apple_location < K){//사과있을때
				baaaaaam.push_back(make_pair(rr, cc));
			}
			else{//사과 없을때
				baaaaaam.erase(baaaaaam.begin());
				baaaaaam.push_back(make_pair(rr, cc));
			}
			if (!turn.empty() && turning_check(time)){//방향변경확인
				if (turn.front().second == 'L')	dir = dirLchange[dir];
				else if (turn.front().second == 'D') dir = dirRchange[dir];
				turn.pop();
			}
		}
		else break;
	}
	ans = time;
	return;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	setbuf(stdout, NULL);
	cin >> N >> K;
	for (int i = 0; i < K; i++) cin >> apple[i].first >> apple[i].second;
	cin >> L;
	pair<int, char> temp;
	for (int i = 0; i < L; i++) {
		cin >> temp.first >> temp.second;
		turn.push(temp);
	}
	pair<int, int> start = { 1, 1 };
	baaaaaam.push_back(start);
	ans = 0;
	solve();

	cout << ans << endl;

	return 0;
}
