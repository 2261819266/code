#include<bits/stdc++.h>
using namespace std;
const int N=6000005;
deque<int>que[305];
int T,n,m,k,fl,s,f[N][5],bs,flag,flaw,flas;
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		bs=0,flag=flaw=flas=0;
		for(int i=1;i<=n;i++)
			while(!que[i].empty())
				que[i].pop_back();
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&s);
			fl=0;
			for(int j=1;j<=n;j++)
				if(!que[j].empty()&&que[j].back()==s)
					{
						que[j].pop_back();
						++bs;
						f[bs][1]=1,f[bs][2]=j,f[bs][3]=0;
						fl=1;
						break ;
					}
			if(fl)
				continue ;
			for(int j=1;j<=n;j++)
				if(!que[j].empty()&&que[j].front()==s)
					{
						if(flag==0)
						{
							que[j].pop_front();
							++bs;
							f[bs][1]=1,f[bs][2]=n,f[bs][3]=0;
							++bs;
							f[bs][1]=2,f[bs][2]=j,f[bs][3]=n;
							fl=1;
							break ;
						}
						else
						{
							f[flaw][2]=j;
							++bs;
							que[j].push_back(flas);
							que[j].pop_front();
							f[bs][1]=1,f[bs][2]=n,f[bs][3]=0;
							++bs;
							f[bs][1]=2,f[bs][2]=j,f[bs][3]=n;
							flag=0;
						}
						fl=1;
					}
			if(fl)
				continue ;
			for(int j=1;j<n;j++)
				if(que[j].size()<=1)
				{
					que[j].push_back(s);
					++bs;
					f[bs][1]=1,f[bs][2]=j,f[bs][3]=0;
					fl=1;
					break ;
				}
			if(fl)
				continue ;
			++bs;
			f[bs][1]=1;
			f[bs][2]=n;
			f[bs][3]=0;
			flag=1;
			flas=s;
			flaw=bs;
		}
		printf("%d\n",bs);
		for(int i=1;i<=bs;i++)
		{
			printf("%d %d",f[i][1],f[i][2]);
			if(f[i][3]!=0)
				printf(" %d",f[i][3]);
			printf("\n");
		}
	}
	return 0;
}
