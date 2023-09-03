#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

typedef long long LL;
typedef long double LD;

const int maxN=500010;
const int mod=1e9+7;

int _read()
{
	int _sign=1,_num=0;
	char _c=getchar();
	for(;!isdigit(_c);_c=getchar())
		if(_c=='-')
			_sign*=-1;
	for(;isdigit(_c);_c=getchar())
		_num=(_num<<3)+(_num<<1)+_c-'0';
	return _sign*_num;
}

void print(int _x)
{
	if(_x<0)
		putchar('-'),_x=-_x;
	if(_x>9)
		print(_x/10);
	putchar(_x%10+'0');
}

int n,m;
int _A=0,_Tree=0,_Qua=0;
//int f[maxN][2][2]={0};

int ksm(int a,int b)
{
	int cur=1;
	while(b)
	{
		if(b&1)
			cur=(cur*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return cur;
}

void solveA()
{
	int cur1=((n+1)*ksm(2,n-1))%mod,
	cur2=((n*(n-1)/2)%mod*ksm(2,n-2))%mod;
	print(cur1+cur2);
	putchar('\n');
}

int dfn[110]={0},low[110]={0};
int dfc=0,top=0;
int sta[110]={0};
int use[110]={0};
int vis[110]={0};
int cut[110][110]={0};
int g[100][100]={0};
int ans=0;

void tarjan(int u)
{
	vis[u]=1;
	low[u]=dfn[u]==++dfc;
	sta[++top]=u;
	for(int v=1;v<=n;v++)
	{
		if(g[u][v]==0||use[v]==0)
			continue;
		if(!vis[v])
			tarjan(v);
		low[u]=min(low[u],low[v]);
		if(dfn[u]<low[v])
			cut[u][v]=cut[v][u]=1;
	}
	if(low[u]==dfn[u])
	{
		while(sta[top]!=u)
			top--;
		top--;
	}
}

void dfs(int pos)
{
	if(pos>n)
	{
		int useCnt=0;
		for(int i=1;i<=n;i++)
			useCnt+=use[i];
		if(useCnt<=1)
		{
			ans=(ans+ksm(2,m))%mod;
			return ;
		}
		/*for(int i=1;i<=n;i++)
			cout<<use[i]<<" ";
		cout<<endl;*/
		for(int i=1;i<=n;i++)
			dfc=top=dfn[i]=low[i]=vis[i]=0;
		for(int i=1;i<=n;i++)
			if(!vis[i]&&use[i])
				tarjan(i);
		int cutCnt=0,edgeCnt=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				cutCnt+=cut[i][j],
				edgeCnt+=(use[i]&use[j]&g[i][j]);
		ans=(ans+ksm(2,edgeCnt-cutCnt))%mod;
		//cout<<edgeCnt<<" "<<cutCnt<<endl;
		return ;
	}
	use[pos]=0;
	dfs(pos+1);
	use[pos]=1;
	dfs(pos+1);
}

void solve1()
{
	dfs(1);
	print(ans);
	putchar('\n');
}

void judge()
{
	if(_A)
	{
		solveA();
		return ;
	}
	else
		solve1();
	/*if(n<=30)
	{
		solve1();
		
	}
	else
	{
		solveA();
	}*/
	/*if(_A)
	{
		solveA();
		return ;
	}
	else if(_Tree)
	{
		
	}
	else if(_Qua)
	{
		
	}
	else ;*/
}



signed main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	ios::sync_with_stdio(false);
//	cin.tie(0),cout.tie(0);
	n=_read(),m=_read();
	if(n==1)
	{
		printf("2\n");
		return 0;
	}
	else if(n==2)
	{
		if(m==1)
			printf("5\n");
		else
			printf("15\n");
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		int u,v;
		u=_read(),v=_read();
		g[u][v]=g[v][u]=1;
		if(m==n-1)
		{
			if(u!=i||v!=i+1)
				_Tree=1;
		}
	}
	if(!_Tree&&m==n-1)
		_A=1;
	if(m==n)
		_Qua=1;
	judge();
	/*f[1][0]=f[1][1]=1;
	for(int i=2;i<=n;i++)
	{
		f[i][0]=f[i-1][0]+f[i-1][1];
		f[i][1]=f[i-1][0]*2+f[i-1][1];
	}
	cout<<f[n][0]+f[n][1]<<endl;*/
	/*f[1][0][0]=f[1][1][1]=1;
	for(int i=2;i<=n;i++)
	{
		f[i][0][0]=f[i-1][0][0]*2;
		f[i][0][1]=f[i-1][0][1]+f[i-1][1][1];
		f[i][1][0]=0;
		f[i][1][1]=f[i-1][0][0]*2+f[i-1][0][1]+f[i-1][1][1];
	}
	for(int i=1;i<=n;i++)
		cout<<f[i][0][0]<<" "<<f[i][0][1]<<" "<<f[i][1][0]<<" "<<f[i][1][1]<<endl;
	cout<<f[n][0][0]+f[n][1][1]+f[n][0][1]<<endl;*/
	return 0;
}
