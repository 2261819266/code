#include<cstdio>//I boomed zero!
#include<cstring>
//#define meow(Kiana...) fprintf (stderr,Kiana)
int T,n,m,k,a[2000002];
int R()
{
	int x=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-48;
	return x;
}
//int vis[200002],;
//void sub1()
//{
//	for(reg int i=1;i<=m;++i)
//	{
//		vis[a[i]]=0;
//	}
//	for(reg int i=1;i<=m;++i)
//	{
//		if()
//	}
//}
int st[12][102],top[12],res[102][2],ans;
bool fd;
void check()
{
//	meow("check!\n");
//	for(int i=1;i<=3;++i) 
//	{
//		meow("%d ",top[i]);
//		for(int j=1;j<=top[i];++j)
//		{
//			meow("%d ",st[i][j]);
//		}
//		meow("\n");
//	}
	int pnt[12]={0};
	int now=ans;
	pnt[1]=pnt[2]=pnt[3]=1;
	while(pnt[1]<=top[1]||pnt[2]<=top[2]||pnt[3]<=top[3])
	{
		bool flag=0;
		for(int i=1;i<3;++i)
		for(int j=i+1;j<=3;++j)
		{
			if(pnt[i]>top[i]||pnt[j]>top[j]||flag) continue; 
			if(st[i][pnt[i]]==st[j][pnt[j]])
			{
				++now;
				res[now][0]=i,res[now][1]=j;
				++pnt[i];++pnt[j];
				flag=1;
			}
		}
		if(!flag) break;
	}
	if(pnt[1]>top[1]&&pnt[2]>top[2]&&pnt[3]>top[3])
	{
		for(int i=1;i<=ans;++i) printf("1 %d\n",res[i][0]);
		for(int i=ans+1;i<=now;++i) printf("2 %d %d\n",res[i][0],res[i][1]);
		fd=1;
	}
//	meow("check...\n");
}
void dfs(int u)
{
//	meow("!\n");
	if(u>m)
	{
		if(!fd) check();
		return;
	}
	for(int i=1;i<=3;++i)
	{
		int flag=0;
		st[i][++top[i]]=a[u];
		if(top[i]>1&&st[i][top[i]]==st[i][top[i]-1]) flag=a[u],top[i]-=2;
		res[++ans][0]=i;
		dfs(u+1);
		res[ans--][0]=0;
		if(flag) st[i][++top[i]]=flag,st[i][++top[i]]=flag;
		--top[i];
		if(fd) break;
	}
}
void sub2()
{
	memset(st,0,sizeof(st));
	memset(top,0,sizeof(top));
	memset(res,0,sizeof(res));
	fd=0;
	dfs(1);
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	T=R();
	while(T--)
	{
		n=R();m=R();k=R();
		for(int i=1;i<=m;++i) a[i]=R();
//		if(k==2*n-2)
//		{
//			sub1();
//		}
		if(n==3)
		{
			sub2();
		}
	}
	return 0;
}
/*
1
3 10 5
1 2 3 4 5 2 3 4 5 1
*/
