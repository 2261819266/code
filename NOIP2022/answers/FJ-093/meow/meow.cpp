#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int M=2e6+5;
int T,n,m,k,cnt;
int a[M],sz[310],bs[310],q[3][M],qf[3],qt[3];
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	if(T==1001)
	{
		while(T--)
		{
			memset(sz,0,sizeof(sz));
			memset(bs,0,sizeof(bs));
			scanf("%d%d%d",&n,&m,&k);
			for(int i=1;i<=m;i++) scanf("%d",&a[i]);
			cnt=0;
			for(int i=1;i<=m;i++)
			{
				cnt++;
				int p=((a[i]-1)%(n-1))+1;
				if(sz[p]==0) sz[p]++,bs[p]=a[i];
				else if(sz[p]==1)
				{
					if(bs[p]!=a[i]) sz[p]++;
					else sz[p]=0;
				}
				else if(sz[p]==2)
				{
					sz[p]=1;
					if(bs[p]==a[i])
					{
						cnt++;
						if(a[i]<=n-1) bs[p]=n-1+a[i];
						else bs[p]=a[i]-n+1;
					}
				}
			}
			printf("%d\n",cnt);
			memset(sz,0,sizeof(sz));
			for(int i=1;i<=m;i++)
			{
				int p=((a[i]-1)%(n-1))+1;
				if(sz[p]==0)
				{
					printf("1 %d\n",p);
					sz[p]++,bs[p]=a[i];	
				}
				else if(sz[p]==1)
				{
					printf("1 %d\n",p);
					if(bs[p]!=a[i]) sz[p]++;
					else sz[p]=0;
				}
				else if(sz[p]==2)
				{
					sz[p]=1;
					if(bs[p]==a[i])
					{
						printf("1 %d\n",n);
						printf("2 %d %d\n",p,n);
						cnt++;
						if(a[i]<=n-1) bs[p]=n-1+a[i];
						else bs[p]=a[i]-n+1;
					}
					else printf("1 %d\n",p);
				}
			}
		}
	}
	if(T!=1001)
	{
		while(T--)
		{
			memset(q,0,sizeof(q));
			qf[1]=1,qf[2]=1;
			qt[1]=0,qt[2]=0;
			scanf("%d%d%d",&n,&m,&k);
			for(int i=1;i<=m;i++) scanf("%d",&a[i]);
			cnt=0;
			for(int i=1;i<=m;i++)
			{
				cnt++;
				if(qt[1]<qf[1]) q[1][++qt[1]]=a[i];
				else
				{
					if(a[i]==q[1][qt[1]]) qt[1]--;
					else if(a[i]==q[1][qf[1]])
					{
						cnt++;
						qf[1]++;
					}
					else q[1][++qt[1]]=a[i];
				}
			}
			printf("%d\n",cnt);
			memset(q,0,sizeof(q));
			qf[1]=1,qf[2]=1;
			qt[1]=0,qt[2]=0;
			for(int i=1;i<=m;i++)
			{
				if(qt[1]<qf[1]) q[1][++qt[1]]=a[i],printf("1 1\n");
				else
				{
					if(a[i]==q[1][qt[1]]) qt[1]--,printf("1 1\n");
					else if(a[i]==q[1][qf[1]])
					{
						printf("1 2\n");
						printf("2 1 2\n");
						qf[1]++;
					}
					else q[1][++qt[1]]=a[i],printf("1 1\n");
				}
			}
		}
	}
	return 0;
}
