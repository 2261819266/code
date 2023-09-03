#include<bits/stdc++.h>
using namespace std;
const int N=305,M=2e6+5;
int t,n,m,k,op,a[M],cnt[N<<1],res[3][M];
queue<int> q[N],qs;
queue<pair<int,int> > wat,wat2;
void insert1(int x)
{
	if(cnt[x])
	{
		res[0][++op]=1;
		res[1][op]=cnt[x];
		q[cnt[x]].pop();
		qs.push(cnt[x]);
		return ;
	}
	res[0][++op]=1;
	res[1][op]=qs.front();
	cnt[x]=qs.front();
	q[qs.front()].push(x);
	qs.pop();
}
void insert2(int x,int y)
{
	if(cnt[x])
	{
		wat2.push({x,y});
		if(wat.size())
		{
			res[0][++op]=1;
			res[1][op]=cnt[x];
			q[cnt[x]].push(wat.front().first);
			cnt[wat.front().first]=cnt[x];
			q[cnt[x]].pop();
			wat.pop();
		}
		int t=y;
		if(wat.size()) t=wat.front().second;
		while(wat2.size()&&wat2.front().second<=t)
		{
			res[0][++op]=1;
			res[1][op]=n;
			res[0][++op]=2;
			res[1][op]=cnt[wat2.front().first];
			res[2][op]=n;
			wat2.pop();
		}
		return ;
	}
	wat.push({x,y});
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		op=0;
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=m;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<n;i++)
			qs.push(i);
		int i=1;
		for(;qs.size();i++)
			insert1(a[i]);
		for(;i<=m;i++)
			insert2(a[i],i);
		cout<<op<<endl;
		for(int i=1;i<=op;i++)
		{
			printf("%d %d",res[0][i],res[1][i]);
			if(res[0][i]==2) printf(" %d",res[2][i]);
			putchar('\n');
		}
	}
	return 0;
}
