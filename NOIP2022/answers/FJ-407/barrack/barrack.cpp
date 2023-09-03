#include<iostream>
using namespace std;

const int N = 3001;

bool a[N][N];
int n, m;

int main()
{
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);

	cin >> n >> m;

	for(int i = 1; i <= n; i ++ )
		for(int j = 1; j <= n; j ++)
		{
			a[i][j] = 0;
		}

	int x, y;
	for (int i = 1; i <= m; i ++ )
	{
		cin >> x >> y;
		a[x][y] = 1; a[y][x] = 1;
	}

	return 0;
}