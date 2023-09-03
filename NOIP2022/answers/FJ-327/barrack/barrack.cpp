#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e4+5,M=2e5+5;
const ll mod=1e9+7;
int fst[N],nxt[M],to[M],h=2;
int chk[M],chv[N],vis[N];
bool adda[2<<20];
int n,m;
long long ans;
void add(int x,int y)
{
	nxt[h]=fst[x],fst[x]=h,to[h]=y,h++;
}
bool check()
{
	int id=0;
	for(int i=2;i<=m*2+1;i++)
	{
		if(chk[i]) id|=(1<<(i/2));
	}
	for(int i=1;i<=n;i++)
	{
		if(chv[i]) id|=(1<<((i/2)+m*2+2));
	}
	if(adda[id]) return false;
	memset(vis,0,sizeof vis);
	queue<int> q;
	for(int i=1;i<=n;i++)	
		if(chv[i])
		{
			q.push(i);
			break;
		}
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		vis[t]=1;
		for(int i=fst[t];i;i=nxt[i])
		{
			int j=to[i];
			if(vis[j]||chk[i]==0) continue;
			q.push(j);
		}
	}
	for(int i=1;i<=n;i++)
		if(chv[i]&&!vis[i])
			return false;
		adda[id]=1;
	return true;
}
void vdfs(int x,int cnt)
{
	if(x==n+1)
	{
		if(cnt>=1) ans+=check(),ans%=mod;
		return;
	}
	chv[x]=1;
	vdfs(x+1,cnt+1);
	chv[x]=0;
	vdfs(x+1,cnt);
}
void edfs(int x)
{
	if(x==m*2+2)
	{
		vdfs(1,0);
		return;
	}
	chk[x]=1;
	edfs(x+1);
	chk[x]=0;
	edfs(x+1);
}
int main()
{
	freopen("barrack.in","r",stdin);//!!
	freopen("barrack.out","w",stdout);//!!
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y),add(y,x);
	}
	edfs(2);
	printf("%lld",ans);

	return 0;
}

