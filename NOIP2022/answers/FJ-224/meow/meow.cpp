#include<iostream>
#include<cstring>
#include<cstdio>
int n,m,k;
int t[1000]={};
int z[1000][2]={};
int p[1000]={},g[1000]={};
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	
	int i,j;
	int Q,N,E;
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d %d %d",&n,&m,&k);
		memset(t,0,sizeof(t));
		for(i=1;i<=m;i++)
		{
			scanf("%d",&t[i]);
		}
		N=n;
		for(i=1;i<=m;i++)
		{
			k=t[i];
			if(p[k])
			{
				if(g[k])
				{
					printf("1 %d\n",p[k]);
					z[p[k]][1]=0;
				}
				else
				{
					printf("1 %d\n",N);
					printf("2 %d %d\n",N,p[k]);
					z[p[k]][0]=z[p[k]][1];
					z[p[k]][1]=0;
				}
				p[k]=0;
				continue;
			}
			E=0;
			for(j=1;j<=n;j++)
			{
				if(z[j][1]||j==N)
				{
					continue;
				}
				p[k]=j;
				printf("1 %d\n",j);
				if(z[j][0])
				{
					g[k]=1;
					z[j][1]=k;
				}
				else
				{
					g[k]=0;
					z[j][0]=k;
				}
				E=1;
				break;
			}
			if(E)
			{
				continue;
			}
			j=++i;
			if(k==t[j])
			{
				printf("1 %d\n",N);
				printf("1 %d\n",N);
				continue;
			}
			while(g[t[j]])
			{
				z[p[t[j]]][1]=0;
				j++;
			}
			if(z[p[t[j]]][1])
			{
				printf("1 %d\n",p[t[j]]);				
				while(i<j)
				{
					printf("1 %d\n",p[t[i]]);
					p[t[i]]=0;
					i++;
				}
				printf("1 %d\n",N);
				printf("2 %d %d\n",N,p[t[j]]);
				z[p[t[j]]][0]=z[p[t[j]]][1];
				z[p[t[j]]][1]=k;
				g[z[p[t[j]]][0]]=0;
				g[z[p[t[j]]][1]]=1;
				p[k]=p[t[j]];
				p[t[j]]=0;
			}
			else
			{
				printf("1 %d\n",N);
				p[k]=N;
				g[k]=0;
				i--;
				while(i<j)
				{
					i++;
					printf("1 %d\n",p[t[i]]);
					p[t[i]]=0;
				}
				z[p[t[j]]][0]=0;
				N=p[t[j]];
			}
		}
	} 
}
