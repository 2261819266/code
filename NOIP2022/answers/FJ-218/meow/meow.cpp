#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef pair<int, int> PII;
const int N = 310;
int T, n, m, k;
int a[N];
int top[N];
int s[N][N];
PII pre[N];

void move1()
{
	
}

PII deletes()
{
	for (int i = 0; i < n; i ++)
	{
		for (int j = 0; j < n; j ++)
		{
			if(i != j && s[i][0] == s[j][0])  
			{
				s[i][0] = s[i][top[i]];
				s[j][0] = s[j][top[j]];
				top[i] --;
				top[j] --;
				PII t = {i, j};
				return t;
			}
		}
	}
	return {-1, -1};
}

int main()
{
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	scanf("%d", &T);
	memset(s, -1, sizeof s);
	
	while(T --)
	{
		int res = 0;
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i < m; i ++)
		{
			scanf("%d", &a[i]);
		}
		
		int hh = 0;
		while(hh < m)
		{
			int t = a[hh ++];
			int flag = false;
			int x;
			for (int i = 1; i <= n; i ++)
			{
				if(t == s[i][top[i]]) {
					flag = true;
					x = i;
				}
			}
			if(flag == true)
			{
				move1();
			}
			else 
			{
			}
			
		}
	}
	
	return 0;
}
