#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=2e6+10;
inline int read()
{
	int n=0,f=1;
	char ch;
	ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')
		  f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=(n<<3)+(n<<1)+(ch-'0');
		ch=getchar();
	}
	return n*f;
}
struct node
{
	int opt,s1,s2;
}ans[M];
int cnt;
int q[M*2][5];
int a[M];
int n,m,k;
int head[M],tail[M];
void work()
{
	for(int i=1;i<=n;i++)
	   head[i]=1,tail[i]=0;
	   
	for(int i=1;i<=m;i++)
	{
		int id=(a[i]+1)/2;
		if(head[id]>tail[id])
		{
			ans[++cnt].opt =1;
			ans[cnt].s1 =id;
			tail[id]++;	q[id][tail[id]]=a[i];
			continue;
		}
		if(q[id][tail[id]]==a[i])
		{
			ans[++cnt].opt =1;	ans[cnt].s1 =id;
			tail[id]--;
			continue;
		}
		if(q[id][head[id]]==a[i])
		{
			ans[++cnt].opt =1;	ans[cnt].s1 =n;
			
			ans[++cnt].opt =2;
			ans[cnt].s1 =id;	ans[cnt].s2 =n;
			head[id]++;
			
			continue;
		}
		tail[id]++;
		q[id][tail[id]]=a[i];
		ans[++cnt].opt =1;  ans[cnt].s1 =id;
	}
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T=read();
	while(T--)
	{
		cnt=0;
		n=read(),m=read(),k=read();
		for(int i=1;i<=m;i++)
		   a[i]=read();
		work();
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;i++)
		{
			printf("%d %d ",ans[i].opt ,ans[i].s1 );
			if(ans[i].opt ==2)
			    printf("%d",ans[i].s2 );
			printf("\n");
		}
	}
}
/*
1 
2 4 2
1 2 1 2
*/ 
