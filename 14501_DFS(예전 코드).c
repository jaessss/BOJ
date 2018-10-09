#include <stdio.h>
#define MAXN 15+1
#define MAX(a, b) (a>b)?(a):(b)

int N;
int table[MAXN][2];
int ans;

void DFS(int index, int sum){

	if (index > N){
		ans = MAX(ans, sum);
		return;
	}

	for (int i = 0; i < 2; i++)
	{		
		if (i == 0 && index + table[index][0]<=N+1){//해당 상담 선택 o			
			DFS(index + table[index][0], sum + table[index][1]);
		}
		if (i == 1 && index + 1 <= N+1){//해당 상담 선택 x
			DFS(index + 1, sum);
		}
	}
}

int main(void)
{
	int T;

	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d %d", &table[i][0], &table[i][1]);
	ans = 0;
	DFS(1, 0);
	
	printf("%d", ans);

	return 0;
}
