// GDX AK NOIP!!!
#include<bits/stdc++.h>
using namespace std;
const int N=1006;
typedef long long ll;
int T,id,n,m,fst[N],a[N][N],mx[N][N][12],nxt[N][N][2];
ll c,f,x,y,ansc,ansf,mod=998244353;
char ch[N];
int ask(int num,int l,int r)
{
	int k=(int)(log(r-l+1)/log(2));
	return max(mx[num][l][k],mx[num][r-(1<<k)+1][k]);
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--)
	{
		scanf("%d%d%lld%lld",&n,&m,&c,&f);
		if(!c&&!f){puts("0 0");continue;}
		ansc=ansf=0ll;
		bool flag=true,ff=true;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",ch+1);
			for(int j=1;j<=m;j++)
			{
				a[i][j]=(int)(ch[j]-'0');
				if(j<=m/3&&!a[i][j]) flag=false;
				if(i<=n/4&&!a[i][j]) ff=false;
			}
		}
		for(int i=1;i<=m;i++)
		{
			int t=(int)(log(n)/log(2));
			for(int j=1;j<=n;j++) mx[i][j][0]=a[j][i];
			for(int j=1;j<=t;j++)
			{
				for(int k=1;k<=n-(1<<j)+1;k++) mx[i][k][j]=max(mx[i][k][j-1],mx[i][k+(1<<(j-1))][j-1]);
			}
		}
		for(int i=1;i<=n;i++)
		{
			nxt[i][m+1][0]=m+1;
			for(int j=m;j>=1;j--)
			{
				if(a[i][j]) nxt[i][j][0]=j;
				else nxt[i][j][0]=nxt[i][j+1][0];
			}
		}
		for(int j=1;j<=m;j++)
		{
			nxt[n+1][j][1]=n+1;
			for(int i=n;i>=1;i--)
			{
				if(a[i][j]) nxt[i][j][1]=i;
				else nxt[i][j][1]=nxt[i+1][j][1];
			}
		}
		int t=1,p=1;
		if(flag) t+=m/4;
		if(ff) p+=n/3;
		for(int l=p;l<=n-2;l++)
		{
			for(int r=l+2;r<=n;r++)
			{
			    for(int i=t;i<=m;i++)
			    {
			    	if(ask(i,l,r)) continue;
			    	ansc=(ansc+(ll)((nxt[l][i][0]-i-1)*(nxt[r][i][0]-i-1)))%mod;
			    	ansf=(ansf+(ll)((nxt[l][i][0]-i-1)*(nxt[r][i][0]-i-1)*(nxt[r][i][1]-r-1)))%mod;
				}
			}
		}
		printf("%lld %lld\n",(ansc*c)%mod,(ansf*f)%mod);
	}
	return 0;
}
