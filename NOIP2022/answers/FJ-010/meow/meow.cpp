#include<cstdio>
#include<queue> 
using namespace std;
const int N=310;
const int M=2e6+10;
int read()
{
	int s=0,b=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') b=-1; c=getchar();}
	while(c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
	return s*b;
}
struct step
{
	int opt,x,y;
}ans[M*2],blank;
deque<int> stack[N];
int T,n,m,k,cnt,a[M];
bool f;
void init()
{
	blank.opt=blank.x=blank.y=0;
	for(int i=1;i<=n;i++) stack[i].clear();
	for(int i=1;i<=cnt;i++) ans[i]=blank;
	cnt=0; f=0;
	
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) a[i]=read();
	return ;
}
void print()
{
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
		if(ans[i].opt==1) printf("%d %d\n",ans[i].opt,ans[i].x);
		else if(ans[i].opt==2) printf("%d %d %d\n",ans[i].opt,ans[i].x,ans[i].y);
	return ;
}
//void test(int d)
//{
//	printf("d=%d cnt=%d\n",d,cnt);
//	for(int i=1;i<=n;puts(""),i++)
//		for(int j=0;j<stack[i].size();j++)
//			printf("%d ",stack[i][j]);
//	puts("");
//}
void dfs(int d)
{
	if(f) return ;
	if(d>m)
	{
		for(int i=1;i<=n;i++)
			if(stack[i].size()) return ;
		print(); f=1; return ;
	}
//	test(d);
	for(int i=1;i<=n;i++)
	{
		if(stack[i].size()==0)
			for(int j=1;j<=n;j++)
				if(i!=j&&stack[j].size()>0&&a[d]==stack[j].front())
				{
					int tmpj=stack[j].front();
					step tmp1,tmp2;
					tmp1.opt=1,tmp1.x=i; tmp2.opt=2,tmp2.x=i,tmp2.y=j;
					stack[j].pop_front();
					ans[++cnt]=tmp1,ans[++cnt]=tmp2;
					dfs(d+1); if(f) return ;
					stack[j].push_front(tmpj);
					ans[cnt]=blank,cnt--; ans[cnt]=blank,cnt--;
				}
		stack[i].push_back(a[d]);
		int s=stack[i].size();
		step tmp1; tmp1.opt=1,tmp1.x=i;
		ans[++cnt]=tmp1;
		bool pd=0;
		if(s>=2&&stack[i][s-1]==stack[i][s-2])
			stack[i].pop_back(),stack[i].pop_back(),pd=1;
		dfs(d+1); if(f) return ;
		ans[cnt]=blank,cnt--;
		if(pd==1) stack[i].push_back(a[d]);
		else stack[i].pop_back();
	}
	return ;
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);

	T=read();
	while(T--)
	{
		init();
		dfs(1);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

