#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
inline int read()
{
	int w=0, f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f = (~f+1);
		c = getchar();
	}
	while(c>='0'&&c<='9')
	{
		w = (w<<1)+(w<<3)+(c^48);
		c = getchar();
	}
	return w*f;
}
int vc, vf, M=998244353;
bool a[1001][1001];
int n, m, c, f;
void work()
{
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++) if(a[i][j]&&a[i+1][j]&&a[i+2][j])
		{
			if(a[i][j+1])
			{
				int k=i+2, s, u=0, v, y=j, x;
				while(a[i][y+1]) {	y += 1; u += 1; }
				while(a[k][j])
				{
					s = 0; v = 0; y = j, x = k;
					while(a[k][y+1]) {  y += 1; v += 1; }
					vc += (u*v);
					
					while(a[x+1][j]) {	x += 1; s += 1; }
					vf += (u*v*s);

					vc %= M; vf %= M;
					k += 1;
				}
			}
		}
	}
}
int main()
{
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	
	int T, id;
	char r;
	scanf("%d%d", &T, &id);
	while(T--)
	{
		vc = 0; vf = 0;
		memset(a, 0, sizeof(a));
		n = read(); m = read();	c = read(); f = read();
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=m; j++)
			{
				cin>>r;
				if(r=='0')	a[i][j] = 1;
			}
		}
		if(c==0&&f==0)
			printf("0 0\n");
		else
		{
			work();
			printf("%d %d\n", (c*vc), (f*vf));		
		}
	}
	return 0;
	fclose(stdin);	fclose(stdout);
}
