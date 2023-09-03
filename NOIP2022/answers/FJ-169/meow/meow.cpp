#include<bits/stdc++.h>
const int M=2e3+99;
using namespace std;
int T,n,k,m,a[M],ans[M],sum[M];
int s[666],head[666],wei[666];
bool vis[666][M];
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	if(T%10==2)
	{
		int stack1[M],stack2[M];
		bool vis1[M],vis2[M];
		while(T--)
		{
			memset(vis1,false,sizeof(vis1));
			memset(vis2,false,sizeof(vis2));
			scanf("%d%d%d",&n,&m,&k);
			for(int i=1;i<=m;i++)
				scanf("%d",&a[i]);
			int head1=0,head2=0;
			for(int i=1;i<=m;i++)
			{
				if(!vis1[a[i]])
				{
					stack1[++head1]=a[i];
					ans[i]=1;sum[i]=1;
					vis1[a[i]]=true;
				}
				else {
					if(stack1[head1]==a[i])
					{
						vis1[a[i]]=false;
						head1--;
						ans[i]=1;sum[i]=1;
					}
					else {
						ans[i]=1;sum[i]=2;
						if(stack2[head2]==a[i])
							head2--;
						else stack2[++head2]=a[i];
					}
				}
			}
			int tot=m+head1;
			printf("%d\n",tot);
			for(int i=1;i<=m;i++)
				printf("%d %d\n",ans[i],sum[i]);
			for(int i=0;i<=head1;i++)
				printf("2 1 2\n");
		}
	}
	else {
		while(T--)
		{
			memset(vis,false,sizeof(vis));
			memset(s,0,sizeof(s));
			memset(head,0,sizeof(head));
			memset(wei,1,sizeof(wei));
			memset(ans,0,sizeof(ans));
			memset(sum,0,sizeof(sum));
			scanf("%d%d%d",&n,&m,&k);
			for(int i=1;i<=m;i++)
				scanf("%d",&a[i]);
			for(int i=1;i<=m;i++)
			{
				bool f=false;
				for(int j=1;j<=n;j++)
					if(s[head[j]]==a[i])
					{
						head[j]--;f=true;
						ans[i]=1,sum[i]=j;
					}
				if(!f){
					for(int j=1;j<=n;j++)
						if(!vis[j][a[i]])
						{
							s[++head[j]]=a[i];
							ans[i]=1;sum[i]=j;
							vis[j][a[i]]=true;
						}
					}
			}
			int tot=m,t=0;
			for(int i=1;i<=n;i++)
				t+=head[i];
			tot=tot+t/2;
			printf("%d\n",tot);
			for(int i=1;i<=m;i++)
				printf("%d %d\n",ans[i],sum[i]);
			for(int i=1;i<n;i++)
				for(int j=i+1;j<=n;j++)
					if(s[wei[i]]==s[wei[j]])
					{
						printf("2 %d %d\n",i,j);
						wei[i]++;wei[j]++;
					}
		}
	}
	return 0;
}
/*2 14 3
1 3 2 2 3 1 1 2 2 3 1 2 2 3*/
