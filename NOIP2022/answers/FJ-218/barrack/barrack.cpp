#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 5e5 + 10, M = 1e6 + 10, mod = 1e9 + 7;
int h[N], ne[M], e[M], idx; 
int n, m;
bool st[N];
int d[N];

void add(int a, int b)
{
	ne[idx] = h[a], e[idx] = b, h[a] = idx ++;
 } 

int doit(int x)
{
	
}

int main()
{
	int sum = 0;
	
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	scanf("%d%d", &n, &m);
	memset(h, -1, sizeof h);
	while(m --)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b), add(b, a);
		d[a] ++, d[b] ++; 
	}
	
	for (int i = 1; i <= n; i ++)
	{
		sum += doit(i);
	}
	
	cout << sum << endl;
	
	return 0;
}
