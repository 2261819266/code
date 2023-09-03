#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int res=0,flag=1;
	char ch=getchar();
	while(!('0'<=ch&&ch<='9'))
		flag=(ch=='-')?-1:1,ch=getchar();
	while('0'<=ch&&ch<='9')
		res=res*10+ch-'0',ch=getchar();
	return res*flag;
}
namespace work1
{
	deque<int> q[310];
	void solve()
	{
		int n=read(),m=read(),k=read();
		for(int i=1;i<=m;i++)
		{
			int a=read(),id=(a+1)/2;
			if(q[id].size()==0)
			{
				printf("1 %d\n",id);
				q[id].push_back(a);
			}
			else if(q[id].front()==a)
			{
				
				printf("1 %d\n",n);
				printf("2 %d %d\n",id,n);
			}
			else if(q[id].back()==a)
				printf("1 %d\n",id);
			else
			{
				q[id].push_back(a);
				printf("1 %d\n",id);
			}
		}
	}
};
namespace work2
{
//	int n,m,k;
//	deque<int> q[310];
//	int val[2000010];
//	int tag[610];
//	int cnt=0;
//	int ans[2000010][3];
//	void dfs(int k)
//	{
//		if(k==m)
//		{
//			for(int i=1; ;i++)
//			{
//				if(ans[i][0]==0)
//					break;
//				printf("%d %d",ans[i][0],ans[i][1]);
//				if(ans[i][0]==2)
//					printf("%d",ans[i][2]);
//				putchar('\n');
//			}
//			return ;
//		}
//		if(tag[val[i]][0]==0)
//		{
//			if(q[tag[val[i]][0]].back()==val[i])
//			{
//				q[tag[val[i]][0]].pop_back();
//				ans[++ans[0]][0]=1;
//				ans[ans[0]][1]=tag[val[i]][0];
//				tag[val[i]][0]=0;
//				dfs(k+1);
//			}
//			else if(q[tag[val[i]][0]].front()==val[i])
//			{
//				int flag=0;
//				for(int i=1;i<=n;i++)
//					if(q[id].size()==)
//				q[tag[val[i]][0]].pop_front();
//				ans[++ans[0]][0]=1;
//				ans[ans[0]][1]=tag[val[i]][0];
//				tag[val[i]][0]=0;
//				dfs(k+1);
//			}
//			else 
//			{
//				for(int i=1;i<=)
//				dfs(k+1)
//				
//			}
//		}
//		else 
//		{
//			
//		}
//	}
	void solve()
	{
		int n=read(),m=read(),k=read();
		for(int i=1;i<=m;i++)
		{
			int val=read();
			printf("1 1\n");
		}
	}
};
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T=read();
	if(T%10==1)
	{
		while(T--)
			work1::solve();
	}
	else work2::solve();
	return 0;
}
