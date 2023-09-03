#include<cstdio>
#include<iostream>
using namespace std;
int T,n,m,k,a[2000005],sta[305][200005],top[305],flo[305],prin[4000005][3];
int main()
{
	freopen("meow","r",stdin);
	freopen("meow","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++)flo[i]=1;
		if(k==2*n-2)
		{
			for(int i=1;i<=m;i++)
			{
				int t=(a[i]+1)/2;
				if(sta[t][top[t]]==a[i])
				{
					top[t]--;
					prin[++prin[0][0]][0]=1;
					prin[prin[0][0]][1]=t;
				}
				else if(sta[t][flo[t]]==a[i])
				{
					prin[++prin[0][0]][0]=1;
					prin[prin[0][0]][1]=n;
					prin[++prin[0][0]][0]=2;
					prin[prin[0][0]][1]=t;
					prin[prin[0][0]][2]=n;
					flo[t]++;
				}
				else 
				{
					sta[t][++top[t]]=a[i];
					prin[++prin[0][0]][0]=1;
					prin[prin[0][0]][1]=t;
					
				}
			}
			printf("%d\n",prin[0][0]);
			for(int i=1;i<=prin[0][0];i++)
			{
				if(prin[i][0]==1)printf("%d %d\n",prin[i][0],prin[i][1]);
				else if(prin[i][0]==2)printf("%d %d %d\n",prin[i][0],prin[i][1],prin[i][2]);
			}
		}
	}
	return 0;
}
