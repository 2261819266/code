#include<bits/stdc++.h>
#define Re register
using namespace std;

const int N=305,M=2000005;

int T,n,m,k,a[M];

int sta[N][20005],to[N],en[N];

int cnt,opt[M],ansa[M],ansb[M];

int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	srand(time(0));
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(Re int i=1;i<=m;i++)
		{
			scanf("%d",&a[i]);
		}
		cnt=0;
		memset(opt,0,sizeof opt);
		memset(ansa,0,sizeof ansa);
		memset(ansb,0,sizeof ansb);
		for(Re int i=1;i<=n;i++)
		{
			to[i]=1;
			en[i]=0;
		}
		if(k==2*n-2)
		{
			for(Re int i=1;i<=m;i++)
			{
				int tp=sta[(a[i]-1)/2+1][to[(a[i]-1)/2+1]],ed=sta[(a[i]-1)/2+1][en[(a[i]-1)/2+1]];
				if(ed==a[i])
				{
					opt[++cnt]=1,ansa[cnt]=(a[i]-1)/2+1;
					sta[(a[i]-1)/2+1][en[(a[i]-1)/2+1]]=0,en[(a[i]-1)/2+1]=(en[(a[i]-1)/2+1]-1+20003)%20003;
				}
				else if(tp==a[i])
				{
					opt[++cnt]=1,ansa[cnt]=n;
					opt[++cnt]=2,ansa[cnt]=(a[i]-1)/2+1,ansb[cnt]=n;
					sta[(a[i]-1)/2+1][to[(a[i]-1)/2+1]]=0,to[(a[i]-1)/2+1]=(to[(a[i]-1)/2+1]+1)%20003;
				}
				else 
				{
					opt[++cnt]=1,ansa[cnt]=(a[i]-1)/2+1;
					en[(a[i]-1)/2+1]=(en[(a[i]-1)/2+1]+1)%20003,sta[(a[i]-1)/2+1][en[(a[i]-1)/2+1]]=a[i];
				}
			}
			printf("%d\n",cnt);
			for(Re int i=1;i<=cnt;i++)
			{
				if(opt[i]==1)
				{
					printf("1 %d\n",ansa[i]);
				}
				else 
				{
					printf("2 %d %d\n",ansa[i],ansb[i]);
				}
			}
		}
		else 
		{
			int rnd=(1ll*rand()*rand()%k)+1;
			for(Re int i=1;i<=m;i++)
			{
				if(a[i]!=rnd)
				{
					int pos;
					if(a[i]>rnd) pos=(a[i]-2)/2+1;
					if(a[i]<rnd) pos=(a[i]-1)/2+1;
					
					int tp=sta[pos][to[pos]],ed=sta[pos][en[pos]];
					if(ed==a[i])
					{
						opt[++cnt]=1,ansa[cnt]=pos;
						sta[pos][en[pos]]=0,en[pos]=(en[pos]-1+20003)%20003;
					}
					else if(tp==a[i]&&en[n]==to[n]-1)
					{
						opt[++cnt]=1,ansa[cnt]=n;
						opt[++cnt]=2,ansa[cnt]=pos,ansb[cnt]=n;
						sta[pos][to[pos]]=0,to[pos]=(to[pos]+1)%20003;
					}
					else 
					{
						opt[++cnt]=1,ansa[cnt]=pos;
						en[pos]=(en[pos]+1)%20003,sta[pos][en[pos]]=a[i];
					}
				}
				else 
				{
					if(en[n]>=to[n])
					{
						opt[++cnt]=1,ansa[cnt]=n;
						sta[n][en[n]]=0,en[n]=(en[n]-1+20003)%20003;
					}
					else 
					{
						opt[++cnt]=1,ansa[cnt]=n;
						en[n]=(en[n]+1)%20003,sta[n][en[n]]=a[i];
					}
				}
			}
			printf("%d\n",cnt);
			for(Re int i=1;i<=cnt;i++)
			{
				if(opt[i]==1)
				{
					printf("1 %d\n",ansa[i]);
				}
				else 
				{
					printf("2 %d %d\n",ansa[i],ansb[i]);
				}
			}
		}
	}
	return 0;
}
