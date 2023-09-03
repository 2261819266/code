#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353, MAXN = 1010;

bool a[MAXN][MAXN];
int numX[MAXN][MAXN]; // [i, j] 处向下最远无坑长度 
int numY[MAXN][MAXN]; // [i, j] 处向后最远无坑长度 
int T, id;
int n, m, c, f; 
vector< int > canbeX[MAXN];

inline void getnum() // 计算 num[][]
{
	memset(numX, 0, sizeof(numX));
	memset(numY, 0, sizeof(numY));
	for (register int i = n; i >= 1; i--)
	{
		for (register int j = 1; j <= m; j++)
		{
			if (a[i][j]) numX[i][j] = 0;
			else numX[i][j] = numX[i + 1][j] + 1;
		}
	}
	for (register int i = 1; i <= n; i++)
	{
		for (register int j = m; j >= 1; j--)
		{
			if (a[i][j]) numY[i][j] = 0;
			else numY[i][j] = numY[i][j + 1] + 1;
		}
	}
	
	/*
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			printf("%d ", numX[i][j]);
		printf("\n");
	}
	*/
			
} 

inline void getans()
{
	if (c == 0 && f == 0)
	{
		printf("0 0\n");
		return;
	}
	int ansC = 0, ansF = 0;
	for (register int y0 = 1; y0 <= m; y0++) // x1~x2 到 y 的距离 
	{
		for (register int x1 = 1; x1 <= n; x1++)
		{
			if (a[x1][y0]) continue;
			for (register int x2 = x1 + 1; x2 <= n; x2++)
			{
				if (a[x2][y0]) break; // 保证 x1~x2 无坑 
				if (x1 + 1 >= x2) continue;
				if (numY[x1][y0] <= 1 || numY[x2][y0] <= 1) continue; // 不构成条件 
//				printf("y0:%d x1:%d x2:%d maxy1:%d maxy2:%d\n", y0, x1, x2, numY[x1][y0], numY[x2][y0]);
				// 'C'直接加 
				ansC += (numY[x1][y0] - 1) * (numY[x2][y0] - 1);
				ansC = ansC % MOD;
				// 'F'加上尾的数量
				if (f == 0) continue;
				if (numX[x2][y0] <= 1) continue;
				ansF += (numY[x1][y0] - 1) * (numY[x2][y0] - 1) * (numX[x2][y0] - 1);
				ansF = ansF % MOD;
			}
		}
	}
	printf("%d %d\n", ansC, ansF);
}

int main()
{
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	
	scanf("%d %d", &T, &id);
	string tmp;
	for (register int t1 = 0; t1 < T; t1++)
	{
//		printf("%d ", t1);
		scanf("%d %d %d %d", &n, &m, &c, &f);
		for (register int i = 1; i <= n; i++)
		{
			cin >> tmp;
			for (register int j = 1; j <= m; j++)
			{
				a[i][j] = tmp[j - 1] == '1' ? true : false;
			}
		}
		getnum();
		getans(); 
	}
	return 0;
}
