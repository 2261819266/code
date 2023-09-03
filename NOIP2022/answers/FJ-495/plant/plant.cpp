#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,id,n,m,v1,v2;
ll mod=998244353,c1[1005][1005],c2[1005][1005],sum1,sum2,ans1,ans2;
char s[1005][1005];
bool a[1005][1005];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&t,&id);
	while(t--)
	{
		memset(a,0,sizeof a);
		memset(c1,0,sizeof c1);
		memset(c2,0,sizeof c2);
		sum1=sum2=ans1=ans2=0;
		scanf("%d%d%d%d",&n,&m,&v1,&v2);
		for(int i=1;i<=n;i++)
			scanf("%s",s[i]+1);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(s[i][j]=='0')
					a[i][j]=1;
		if((!v1)&&(!v2))
		{
			printf("0 0\n");
			continue;
		}
		for(int i=n;i;i--)
			for(int j=m;j;j--)
				if(a[i][j])
					c1[i][j]=c1[i][j+1]+1,c2[i][j]=c2[i+1][j]+1;
		for(int i=n;i;i--)
			for(int j=m;j;j--)
				if(a[i][j])
					c1[i][j]--,c2[i][j]--;
		for(int j=m;j;j--)
		{
			for(int i=n;i;i--)
				if(a[i][j])
				{
					ans1=(ans1+(c1[i][j]*sum1)%mod)%mod;
					ans2=(ans2+(c1[i][j]*sum2)%mod)%mod;
					if(a[i+1][j])
						sum1=(sum1+c1[i+1][j])%mod,sum2=(sum2+(c1[i+1][j]*c2[i+1][j])%mod)%mod;
				}
				else
					sum1=0,sum2=0;
			sum1=0,sum2=0;
		}
		printf("%lld %lld\n",(ans1*v1)%mod,(ans2*v2)%mod);
	}
}
/*
2 0
4 3 1 1
001
010
000
000
4 3 1 1
001
010
000
000

2 1 
5 4 1 1
0001
0111
0001
0000
0000
5 4 1 1
0001
0111
0001
0000
0000

4 0
4 3 1 1
001
010
000
000
4 3 1 1
001
010
000
000
5 4 1 1
0001
0111
0001
0000
0000
4 4 0 0
0001
0111
0001
0000
*/
