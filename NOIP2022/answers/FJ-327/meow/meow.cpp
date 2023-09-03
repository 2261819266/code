#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=305,M=305,Ss=1e6+5;
int n,m,k,T;
int sz[N],dn[N],a[N];

void init()
{
	memset(dn,0,sizeof dn);
	memset(a,0,sizeof a);
	memset(sz,0,sizeof sz);
}
int main()
{
	freopen("meow.in","r",stdin);//!!
	freopen("meow.out","w",stdout);//!!
	scanf("%d",&T);
	while(T--)
	{
		init();
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++)
			scanf("%d",&a[i]),a[i]++;
		for(int i=1;i<=m;i++)
		{
			if(sz[a[i]/2]==0)
			{
				sz[a[i]/2]++;
				dn[a[i]/2]=a[i]%2;
				printf("1 %d\n",a[i]/2);
			}
			else if(dn[a[i]/2]==a[i]%2)
			{
				sz[a[i]/2]--;
				printf("1 %d\n",n);
				printf("2 %d %d\n",a[i]/2,n);
			}
			else if(sz[a[i]/2]==1&&dn[a[i]/2]!=a[i]%2)
			{
				sz[a[i]/2]++;
				printf("1 %d\n",a[i]/2);
			}
			else if(sz[a[i]/2]==2&&dn[a[i]/2]!=a[i]%2)
			{
				sz[a[i]/2]--;
				printf("1 %d\n",a[i]/2);
			}
		}
	}

	return 0;
}


