#include<bits/stdc++.h>
using namespace std;
long long t,n,m,k;
long long a[2000001];
int apr[601];
int s[301][100001],top[301],tail[301],cnt,q;
bool op[4000001];
int op1[4000001],op2[4000001];
int cntop;
void solve1()
{
	for(int i=1;i<=n;i++)
	tail[i]=1;
	for(int i=1;i<=m;i++)
	{
		if(apr[a[i]])
		{
			--apr[a[i]];
			for(int j=1;j<=n;j++)
			{
				if(s[j][top[j]]==a[i]&&top[j]>=tail[j])
				{
					//cout<<1<<' '<<j<<'\n';
					op[++cntop]=0;
					op1[cntop]=j;
					--top[j];
					if(j==cnt&&top[j]<tail[j])--cnt;
					break;
				}
				if(s[j][tail[j]]==a[i]&&top[j]>=tail[j])
				{
					//cout<<1<<' '<<cnt+1<<'\n';
					op[++cntop]=0;
					op1[cntop]=cnt+1;
					//cout<<2<<' '<<j<<' '<<cnt+1<<'\n';
					op[++cntop]=1;
					op1[cntop]=j;
					op2[cntop]=cnt+1;
					++tail[j];
					if(j==cnt&&top[j]<tail[j])--cnt;
					break;
				}
			}
		}
		else
		{
		   
			for(int j=1;j<=n-1;j++)
			{
				if(top[j]<=tail[j])
				{
					++apr[a[i]];
					++top[j];
					s[j][top[j]]=a[i];
					//cout<<1<<' '<<j<<'\n';
					op[++cntop]=0;
					op1[cntop]=j;
					if(top[j]==tail[j])++cnt;
					break;
				}
				
			}
		}
		//cout<<cnt<<' ';
	}
	cout<<cntop<<'\n';
	for(int i=1;i<=cntop;i++)
	{
		cout<<op[i]+1<<' ';
		if(!op[i])cout<<op1[i]<<'\n';
		else cout<<op1[i]<<' '<<op2[i]<<'\n';
	}
}
void solve2()
{
	bool flag;
	for(int i=1;i<=n;i++)
	tail[i]=1;
	for(int i=1;i<=m;i++)
	{
		if(apr[a[i]])
		{
			flag=0;
			--apr[a[i]];
			for(int j=1;j<=n-1;j++)
			{
				if(s[j][top[j]]==a[i]&&top[j]>=tail[j])
				{
					//cout<<1<<' '<<j<<'\n';
					op[++cntop]=0;
					op1[cntop]=j;
					--top[j];
					if(j==cnt&&top[j]<tail[j])--cnt;
					flag=1;
					break;
				}
				if(s[j][tail[j]]==a[i]&&top[j]>=tail[j])
				{
					//cout<<1<<' '<<cnt+1<<'\n';
					op[++cntop]=0;
					op1[cntop]=cnt+1;
					//cout<<2<<' '<<j<<' '<<cnt+1<<'\n';
					op[++cntop]=1;
					op1[cntop]=j;
					op2[cntop]=cnt+1;
					++tail[j];
					if(j==cnt&&top[j]<tail[j])--cnt;
					flag=1;
					break;
				}
			}
			if(!flag)
			{
				for(int j=1;j<=n-1;j++)
		     	{
				if(s[j][top[j]]==a[n-q]&&top[j]>=tail[j])
				{
					++q;
					++apr[a[i]];
					++top[j];
					s[j][top[j]]=a[i];
					//cout<<1<<' '<<j<<'\n';
					op[++cntop]=0;
					op1[cntop]=j;
					if(top[j]==tail[j])++cnt;
					break;
				}
	    		}
			}
		}
		else
		if(cnt<n-1||top[n-1]<=tail[n-1])
		{
			for(int j=1;j<=n-1;j++)
			{
				if(top[j]<=tail[j])
				{
					++apr[a[i]];
					++top[j];
					s[j][top[j]]=a[i];
					//cout<<1<<' '<<j<<'\n';
					op[++cntop]=0;
					op1[cntop]=j;
					if(top[j]==tail[j])++cnt;
					break;
				}
			}
		}
		else
		{
			flag=0;
			while(!flag)
			{
				

			for(int j=1;j<=n-1;j++)
			{
				if(top[j]<=tail[j]+q)
				{
					++apr[a[i]];
					++top[j];
					s[j][top[j]]=a[i];
					//cout<<1<<' '<<j<<'\n';
					op[++cntop]=0;
					op1[cntop]=j;
					if(top[j]==tail[j])++cnt;
					flag=1;
					break;
				}
			}
			if(!flag)++q;
		}
		}
		//cout<<cnt<<' ';
	}
	cout<<cntop<<'\n';
	for(int i=1;i<=cntop;i++)
	{
		cout<<op[i]+1<<' ';
		if(!op[i])cout<<op1[i]<<'\n';
		else cout<<op1[i]<<' '<<op2[i]<<'\n';
	}
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++)
		{
			cin>>a[i];
		}
		if(k==n*2-2)
		solve1();
		else
		solve2();
	}
}
/*
1 
2 4 2
1 2 1 2
*/
