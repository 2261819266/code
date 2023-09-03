#include <bits/stdc++.h> 
using namespace std;
//5pts???
#define int unsigned long long
const int maxn=1e6+10;
int a[maxn],b[maxn],n;
int dp[maxn][20][2],logg[maxn];
void init()
{
	logg[0]=-1;
	for(int i=1;i<=n;i++)
	dp[i][0][0]=a[i],logg[i]=logg[i/2]+1;
	for(int i=1;i<=n;i++) 
	for(int j=1;i+(1<<j)-1<=n;j++)
	dp[i][j][0]=max(dp[i][j-1][0],dp[i-(1<<j-1)][j-1][0]);
	for(int i=1;i<=n;i++)
	dp[i][0][1]=b[i],logg[i]=logg[i/2]+1;
	for(int i=1;i<=n;i++) 
	for(int j=1;i+(1<<j)-1<=n;j++)
	dp[i][j][1]=max(dp[i][j-1][1],dp[i-(1<<j-1)][j-1][1]);
}
int querymax_a(int l,int r)
{
	int maxn=0;
	for(int i=l;i<=r;i++)
	maxn=max(maxn,a[i]);
	return maxn;
}
int another(int op,int l,int r)
{
	int k=logg[r-l+1];
	return max(dp[k][l][op],dp[k][r-(1<<k)+1][op]);
}
int querymax_b(int l,int r)
{
	int maxn=0;
	for(int i=l;i<=r;i++)
	maxn=max(maxn,b[i]);
	return maxn;
}
signed main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T;
	cin>>T>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	cin>>b[i];
	int q;
	cin>>q;
	while(q--) 
	{
		int ll,rr;
		cin>>ll>>rr;
		int res=0;
		for(int l=ll;l<=rr;l++)
		for(int r=l;r<=rr;r++)
		res+=querymax_a(l,r)*querymax_b(l,r);
		cout<<res<<'\n';
	}
}
/*
0 30
9 30 25 18 7 3 29 15 12 16 14 26 24 5 1 8 13 28 6 17 2 22 4 23 27 10 11 19 20 21
27 24 11 26 7 3 8 15 25 10 1 4 18 14 20 23 9 22 29 30 13 28 19 17 2 21 6 12 5 16
30
1 30
1 30
6 30
3 26
4 26
6 28
1 24
4 30
7 29
3 24
7 30
3 26
4 26
2 29
4 30
6 21
8 29
11 14
15 19
19 20
7 30
25 30
7 9
19 30
7 26
13 26
5 30
15 24
18 21
23 29
*/
