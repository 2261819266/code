#include<bits/stdc++.h>
using namespace std;

const int N=1001;

int T,n,m,k,x,l[N],st[N][N],a;
bool fl;

int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);//long long,zhushi,shuzu,duipai
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&x);
			fl=0;
			for(int j=1;j<=n;j++)
			{
				if(st[j][l[j]]==x)
				{
					printf("%d %d\n",1,j);
					fl=1;
					l[j]--;
					break;
				}

			}		
					if(!fl)
				{
					srand(time(0));
					a=rand()%n+1;
					printf("%d %d\n",1,a);
					l[a]++;st[a][l[a]]=x;
				}
		}
	}
	return 0;
}

