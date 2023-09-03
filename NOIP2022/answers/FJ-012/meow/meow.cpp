#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2000005;
inline int rd()
{
	int x=0; bool f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())
		if(ch=='-') f=0;
	for(;ch>='0'&&ch<='9';ch=getchar())
		x=x*10+(ch^48);
	return f?x:-x;
}
int n,m,k;
int a[N];
int stk[305][2];
pair<int,int> emp[1005];
int tp;
pair<int,int> inw[1005];
int ans[N<<1][2],cans;
void solve1()
{
	cans=0;
	tp=0;
	for(int i=1;i<=k;i++)
		inw[i]=make_pair(0,0);
	for(int i=1;i<=n;i++)
		stk[i][0]=stk[i][1]=0;
	
	emp[++tp]=make_pair(n,0);
	for(int i=1;i<=n-1;i++)
		emp[++tp]=make_pair(i,1);
	for(int i=1;i<=n-1;i++)
		emp[++tp]=make_pair(i,0);
	for(int i=1;i<=m;i++)
	{
		if(!inw[a[i]].first)
		{
			ans[++cans][0]=1;
			ans[cans][1]=emp[tp].first;
			inw[a[i]]=emp[tp];
			tp--;
			stk[inw[a[i]].first][inw[a[i]].second]=a[i];
		}
		else
		{	
			ans[++cans][0]=1;
			ans[cans][1]=n;
			ans[++cans][0]=2;
			ans[cans][1]=inw[a[i]].first;
			stk[inw[a[i]].first][inw[a[i]].second]=0;
			if(!inw[a[i]].second&&stk[inw[a[i]].first][1])
			{
				int &k=stk[inw[a[i]].first][1];
				stk[inw[a[i]].first][0]=k;
				emp[++tp]=make_pair(inw[a[i]].first,1);
				k=0;
			}
			else
				emp[++tp]=inw[a[i]];
			inw[a[i]]=make_pair(0,0);
		}
	}
	printf("%d\n",cans);
	for(int i=1;i<=cans;i++)
	{
		if(ans[i][0]==1)
			printf("%d %d\n",1,ans[i][1]);
		else
			printf("%d %d %d\n",2,ans[i][1],n);
	}
		
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T=rd();
	while(T--)
	{
		n=rd(),m=rd(),k=rd();
		for(int i=1;i<=m;i++)
			a[i]=rd();
		solve1();
		
	}
	return 0;
}

