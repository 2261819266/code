#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
typedef unsigned long long ull;
const int N=250000+5;
struct tree{
	int L,R,x,sz;
}ta[N],tb[N];
int T,n,m,top,rta,rtb,a[N],b[N],lg[N],st[2][N][21];
ull ans,suma,sumb;
int mymax(int x,int y,int opt)
{	if(opt==0)return (a[x]>a[y])?(x):(y);
	else return (b[x]>b[y])?(x):(y);
}
int query(int l,int r,int opt)
{	int k=lg[r-l+1];
	return mymax(st[opt][l][k],st[opt][r-(1<<k)+1][k],opt);
}
int buildt(int l,int r,int opt)
{	if(l>r)return 0;
	if(l==r)
	{	if(opt==0)ta[l]=(tree){0,0,a[l],1};
		else tb[l]=(tree){0,0,b[l],1};
		return l;
	}
	int k=query(l,r,opt);
	if(opt==0)
	{	ta[k].L=buildt(l,k-1,opt),ta[k].R=buildt(k+1,r,opt),ta[k].x=a[k];
		ta[k].sz=1+ta[ta[k].L].sz+ta[ta[k].R].sz;
	}
	else{
		tb[k].L=buildt(l,k-1,opt),tb[k].R=buildt(k+1,r,opt),tb[k].x=b[k];
		tb[k].sz=1+tb[tb[k].L].sz+tb[tb[k].R].sz;
	}
	return k;
}
void dfs1(int u)
{	suma+=(ull)(ta[ta[u].L].sz+1)*(ta[ta[u].R].sz+1)*ta[u].x;
	if(ta[u].L)dfs1(ta[u].L);
	if(ta[u].R)dfs1(ta[u].R);
}
void dfs2(int u)
{	sumb+=(ull)(tb[tb[u].L].sz+1)*(tb[tb[u].R].sz+1)*tb[u].x;
	if(tb[u].L)dfs2(tb[u].L);
	if(tb[u].R)dfs2(tb[u].R);
}
int main()
{	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	lg[0]=-1,ta[0].sz=tb[0].sz=0;
	for(int i=1;i<=n;i++)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),st[0][i][0]=i;	
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),st[1][i][0]=i;
	for(int u=0;u<2;u++)
		for(int j=1;j<=20;j++)
			for(int i=1;i+(1<<j)-1<=n;i++)
				st[u][i][j]=mymax(st[u][i][j-1],st[u][i+(1<<(j-1))][j-1],u);
	scanf("%d",&m);
	while(m--)
	{	int l,r;
		scanf("%d%d",&l,&r);
		ans=0;
		for(int i=l;i<=r;i++)
			for(int j=i;j<=r;j++)ans+=(ull)a[query(i,j,0)]*b[query(i,j,1)];
		printf("%llu\n",ans);
	}
	return 0;
}
