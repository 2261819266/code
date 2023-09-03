#include <bits/stdc++.h>
#define ps(x) puts(#x)
#define gc getchar
#define pc putchar
#define R register
#define foru(i,j,k) for(register int i=j;i<=k;++i)
#define ford(i,j,k) for(register int i=j;i>=k;--i)
#define ll long long
#define M 2000005
using namespace std;
inline ll rd(){R char ch=gc();R ll s=0,f=1;while(!isdigit(ch)){if(ch=='-')f=-1;ch=gc();}while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48);ch=gc();}return s*f;}
inline void print(ll x){if(x<0)pc('-'),x=-x;if(x>9)print(x/10);pc(x%10+48);}
bool ed;
int t;
bool cg;
int n,m,k;
int s[M];
int l[M],r[M];//每个队列底，顶
int up[M];//每个队列顶的牌是哪种 
int down[M];//同上，队列底 
int down2[M];
int op[M],a[M],b[M];
int cnt;//现在开了几个队列 
int now;
inline void sc()
{
	print(now),ps();
	foru(i,1,now)
	{
		putchar(op[i]+48),pc(' ');
		if(op[i]==1)print(a[i]),ps();
		else print(a[i]),pc(' '),print(b[i]),ps();
	}
}
inline bool pd()
{
	bool emmm=true;
	foru(i,1,cnt)
	{
		if(l[i]!=r[i])
		{emmm=false;break;}
	}
	return emmm;
}
void dfs(int top)
{
	if(now>m*2)return; 
	if(ed)return;
	if(top==m+1&&pd())
	{
		cg=1;
		ed=1;
		sc();
		return;
	}
	if(top==1)//第一个丢进去 
	{
		cnt++;
		now++;
		op[1]=1,a[1]=1;
		r[1]++;
		up[1]=s[1];
		down[1]=s[1];
		dfs(top+1);
	}
	foru(i,1,cnt)//选个栈丢进去（如果有相同的优先） 
	{
		if(down[i]==s[top]&&cnt<n)
		{
			int aa=up[i],bb=down[i];
			l[i]++;
			if(l[i]==r[i])up[i]=down[i]=0;
			op[++now]=1,a[now]=cnt+1;
			op[++now]=2,a[now]=i,b[now]=cnt+1;
			dfs(top+1);
			l[i]--;
			up[i]=aa,down[i]=bb;
			now-=2;
		}
		if(up[i]==s[top])
		{
			int aa=up[i],bb=down[i];
			r[i]--;
			if(l[i]==r[i])up[i]=down[i]=0;
			op[++now]=1,a[now]=i;
			dfs(top+1);
			r[i]++;
			up[i]=aa,down[i]=bb;
			now--;
		}
	}
	//所以有相同就消掉是最优吗。。。
	if(cnt+1<=n)//没爆
	{
		cnt++;
		r[cnt]++;
		op[++now]=1,a[now]=cnt;
		up[cnt]=s[top];
		dfs(top+1);
		r[cnt]--;
		up[cnt]=0;
		now--;
		cnt--;
	}
	if(cnt+1>n)
	{
		ford(i,cnt,1)
		{
			int aa=up[i];
			r[i]++;
			op[++now]=1,a[now]=i;
			up[i]=s[top];
			dfs(top+1);
			r[i]--;
			up[i]=aa;
			now--;
		}
	}
}
void dfs2(int top)
{
	if(now>m*2)return; 
	if(ed)return;
	if(top==m+1&&pd())
	{
		cg=1;
		ed=1;
		sc();
		return;
	}
	if(top==1)//第一个丢进去 
	{
		cnt++;
		now++;
		op[1]=1,a[1]=1;
		r[1]++;
		up[1]=s[1];
		down[1]=s[1];
		dfs(top+1);
	}
	int vis[4];
	vis[1]=vis[2]=vis[3]=0;
	foru(lk,1,3)
	{
	int sj=rand()%3+1;
	while(vis[sj]==1)
	{
		if(sj==3)sj=0;
		sj++;
	}
	vis[sj]=1;
	if(sj==1)
	{
	foru(i,1,cnt)//选个栈丢进去（如果有相同的优先） 
	{
		if(down[i]==s[top]&&cnt<n)
		{
			int aa=up[i],bb=down[i];
			l[i]++;
			if(l[i]==r[i])up[i]=down[i]=0;
			op[++now]=1,a[now]=cnt+1;
			op[++now]=2,a[now]=i,b[now]=cnt+1;
			dfs(top+1);
			l[i]--;
			up[i]=aa,down[i]=bb;
			now-=2;
		}
		if(up[i]==s[top])
		{
			int aa=up[i],bb=down[i];
			r[i]--;
			if(l[i]==r[i])up[i]=down[i]=0;
			op[++now]=1,a[now]=i;
			dfs(top+1);
			r[i]++;
			up[i]=aa,down[i]=bb;
			now--;
		}
	}
	}
	//所以有相同就消掉是最优吗。。。
	if(sj==2)
	{
	if(cnt+1<=n)//没爆
	{
		cnt++;
		r[cnt]++;
		op[++now]=1,a[now]=cnt;
		up[cnt]=s[top];
		dfs(top+1);
		r[cnt]--;
		up[cnt]=0;
		now--;
		cnt--;
	}
	}
	if(sj==3)
	{
	if(cnt+1>n)
	{
		ford(i,cnt,1)
		{
			int aa=up[i];
			r[i]++;
			op[++now]=1,a[now]=i;
			up[i]=s[top];
			dfs(top+1);
			r[i]--;
			up[i]=aa;
			now--;
		}
	}
	}
	}
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	t=rd();
	while(t--)
	{
		srand((unsigned)time(NULL));
		n=rd(),m=rd(),k=rd();
		foru(i,1,m)s[i]=rd(),up[i]=down[i]=l[i]=r[i]=0;
		ed=0;
		now=0;
		cg=false;
		cnt=0;
		dfs(1);
		if(!cg)
		{
			foru(i,1,m)up[i]=down[i]=l[i]=r[i]=0;
			ed=0;
			now=0;
			cg=false;
			cnt=0;
			dfs2(1);
		}
	}
	return 0;
}
