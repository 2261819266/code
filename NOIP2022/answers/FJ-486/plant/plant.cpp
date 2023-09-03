#include<bits/stdc++.h>
using namespace std;
char c1;
bool ans[1005][1005];
long long mapp[1005][1005],id,T,n,m,c,f,cnthang,cntlie1,cntlie2,ansc,ansf;
void dfs(int x,int y)
{
	cnthang=x+1;
	for(int i=x+2;i<=n;i++)
	{
		if(ans[i][y]==false) break;
		cnthang++;
	}
	for(int i=y+1;i<=m;i++)
	{
		if(ans[x][i]==false) break;
		cntlie1++;
	}
	for(int i=x+2;i<=cnthang;i++)
	{
		for(int j=y+1;j<=m;j++)
		{
			if(ans[i][j]==false) break;
			cntlie2++;
		}
		ansc+=cntlie2*cntlie1;
		ansc%=998244353;
		ansf+=cntlie2*cntlie1*(cnthang-i);
		ansf%=998244353;
		cntlie2=0;
	}
	cntlie1=0;
	cntlie2=0;
	return;
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>T>>id;
	for(int z=1;z<=T;z++)
	{
		cin>>n>>m>>c>>f;
		for(int i=1;i<=n;i++) 
		{
			for(int j=1;j<=m;j++)
			{
				cin>>c1;
				mapp[i][j]=c1-48;
				if(mapp[i][j]==0) ans[i][j]=true;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(ans[i][j]==true&&ans[i][j+1]==true&&ans[i+1][j]==true&&ans[i+2][j]==true) dfs(i,j);
			}
		}
	}
	cout<<(ansc*c)<<' '<<(ansf*f);
	return 0;
}
/*
1 0
4 3 1 1
001
010
000
000

4 2
*/
/*
1 0
6 6 1 1
000010
011000
000110
010000
011000
000000

36 18
*/
/*
1 0
16 12 1 1
0000000000010111
1111111100000000
0011011111111111
0100111111110101
1110001101001110
1111011111100011
1111111111110000
1111111101111111
1111000000111111
0111110001110111
1101111101111100
0111011111011111

114 514
*/
