//18.10.11 #No.13458 <시험감독>
//Coments : vector로 했을때 왜 안되는지 모르겠다...
//출력 자료형 범위 주의
#include <stdio.h>
#define MAXN 1000000+2

long long ans;
int N;
int student[MAXN];
int B,C;

void solve(){
	ans = N;
	for (int i = 1; i <= N; i++){
		student[i] -= B;
		if (student[i] > 0){
			if (student[i] % C == 0) ans += (student[i] / C);
			else ans += (student[i] / C) + 1;
		}
	}
}
int main(void)
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &student[i]);
	scanf("%d %d", &B, &C);
	solve();
	printf("%lld\n", ans);

	return 0;
}
