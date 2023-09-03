#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#define x first
#define y second

using namespace std;
typedef pair<int, int> PII;
const int N = 1e3 + 10, mod = 998244353;
int T, id;
int n, m, c, f;
char g[N][N];
queue<PII> path1;// zuo¹Õµã
queue<PII> path2;//xia
queue<PII> heap;

int bfsc()
{

	for(int i = 0; i < n; i ++)
	{
		for (int j = 0; j < m; j ++)
		{
			if(g[i][j] == '0')
			{
				heap.push({i ,j});//tou
			}
		}
	}
	
	int res = 0;
	
	while(heap.size())
	{
		PII t1 = heap.front();
		heap.pop();
		int a1 = t1.x, b1 = t1.y - 1;
		if(g[a1][b1] == '1' || b1 < 0) continue;
		
		while(b1 >= 0 && g[a1][b1] == '0')
		{
			path1.push({a1, b1});
			b1 -= 1;
		}
		
		while(path1.size())
		{
			PII t2 = path1.front();
			path1.pop();
			
			int a2 = t2.x + 1, b2 = t2.y;
			if(a2 >= n || g[a2][b2] == '1' || g[a2 + 1][b2] == '1' || a2 + 1 >= n) continue;
			a2 ++;
			while(a2 < n && g[a2][b2] == '0')
			{
				path2.push({a2, b2});
				a2 += 1;
			}
		}
		
		while(path2.size())
		{
			PII t3 = path2.front();
			path2.pop();
		
			int a3 = t3.x, b3 = t3.y + 1;
			if(b3 >= m|| g[a3][b3] == '1') continue;
		
			while(b3 < m && g[a3][b3] == '0')
			{
				res ++;
				b3 += 1;
			}
			
		}
	}
	
	return res % mod;
}

int bfsf()
{
	queue<PII> heap;
	for (int i = 0; i < n; i ++)
	{
		for (int j = 0; j < m; j ++){
			if(g[i][j] == '0')
			{
				heap.push({i, j});
			}
		}
	}
	
	int res = 0;
	while(heap.size())
	{
		PII t1 = heap.front();
		heap.pop();
		
		int a1 = t1.x, b1 = t1.y - 1;
		if(g[a1][b1] == '1' || b1 < 0) continue;
		
		while(b1 >= 0 && g[a1][b1] == '0')
		{
			path1.push({a1, b1});
			b1 --;
		}
		
		while(path1.size())
		{
			PII t2 = path1.front();
			path1.pop();
			
			int a2 = t2.x + 1, b2 = t2.y;
			if(a2 >= n || g[a2][b2] == '1' || g[a2 + 1][b2] == '1' || a2 + 1 >= n || a2 + 2 >= n || g[a2 + 2][b2] == '1') continue;
			a2 ++;
			while(a2 < n && g[a2][b2] == '0' && g[a2 + 1][b2] == '0' )
			{
				path2.push({a2, b2});
				a2 ++;
			}
		}
		
		while(path2.size())
		{
			PII t3 = path2.front();
			path2.pop();
		
			int a3 = t3.x, b3 = t3.y + 1;
			int k = 1;
			if(g[a3][b3] == '1' || b3 >= m) continue;
			while(k + a3 < n && g[k + a3][t3.y] == '0')
			{
				k ++;
			}
			k --;
			while(b3 < m && g[a3][b3] == '0')
			{
				res += k;
				b3 ++;
			}
			
		}
	}
	
	return res  % mod;
}

int main()
{
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	
	scanf("%d%d", &T, &id);
	
	while(T --)
	{
		scanf("%d%d%d%d", &n, &m, &c, &f);
		
		for (int i = 0; i < n; i ++)
			cin >> g[i];
			
		cout << (bfsc() * c + mod) % mod <<" " << (bfsf() * f + mod) % mod << endl;
	}
	
	return 0;
}
