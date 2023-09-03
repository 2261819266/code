#include<iostream>
#include<cstring>
#include<cstdio>
int n,m;
int CC,FF;
char S[1010]={};
int t[1010][1010]={};
long long int o=998244353;
long long int x[1010][1010]={},y[1010][1010]={};
long long int s[1010][1010]={};
int l[1010][1010]={};
long long int C,F;
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	
	int Q,id;
	scanf("%d %d",&Q,&id);
	int k,v;
	long long int w;
	while(Q--)
	{
		scanf("%d %d %d %d",&n,&m,&CC,&FF);
		memset(t,0,sizeof(t));
		for(int i=1;i<=n;i++)
		{
			scanf("%s",S+1);
			for(int j=1;j<=m;j++)
			{
				t[i][j]=(S[j]-'0')^1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m+1;j++)
			{
				if(t[i][j])
				{
					continue;
				}
				k=j-1;
				while(t[i][k])
				{
					x[i][k]=j-k-1;
					k--;
				}
			}
		}
		for(int j=1;j<=m;j++)
		{
			for(int i=1;i<=n+1;i++)
			{
				if(t[i][j])
				{
					continue;
				}
				k=i-1;
				while(t[k][j])
				{
					y[k][j]=i-k-1;
					k--;
				}
				v=k++;
				while(t[k][j])
				{
					l[k][j]=v;
					k++;
				}
			}
		}
		for(int j=1;j<=m;j++)
		{
			for(int i=1;i<=n;i++)
			{
				s[i][j]=s[i-1][j]+x[i][j];
			}
		}
		C=F=0;
		for(int j=1;j<=m;j++)
		{
			for(int i=3;i<=n;i++)
			{
				if(t[i][j]&&t[i-1][j])
				{
					w=(s[i-2][j]-s[l[i][j]][j]+o)*x[i][j];
					C+=w;
					C%=o;
					w%=o;
					F+=w*y[i][j];
					F%=o;
				}
			}
		}
		printf("%lld %lld\n",C*CC,F*FF);
	}
}
