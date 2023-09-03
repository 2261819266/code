#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
struct l{
	int m,n,o;
}p[2000000];
int e[300],r[300];
deque<int> f[300];
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int a,b,c,d,g,h,i,j,k,q,s,t;
	scanf("%d",&a);
	for (i=0;i<a;i++)
	{
		scanf("%d%d%d",&b,&c,&d);
		if (1)
		{
			for (t=0;t<(b<<1)-2;t++) e[t]=t>>1;
			for (j=0;j<b;j++) f[j].clear();
			for (q=0;q<d;q++)
			{
				r[q]=q;
				swap(r[q],r[rand()%(q+1)]);
			}
			h=0;
			for (k=0;k<c;k++)
			{
				scanf("%d",&g);
				g=r[g-1]+1;
				if (g<=(b<<1)-2)
				if (f[e[g]].empty())
				{
					f[e[g]].push_back(g);
					p[h].m=1;
					p[h].n=e[g]+1;
					h++;
				}
				else if (f[e[g]].back()==g)
				{
					f[e[g]].pop_back();
					p[h].m=1;
					p[h].n=e[g]+1;
					h++;
				}
				else if (f[e[g]].front()==g&&f[b-1].empty())
				{
					f[e[g]].pop_front();
					p[h].m=1;
					p[h].n=b;
					h++;
					p[h].m=2;
					p[h].n=e[g]+1;
					p[h].o=b;
					h++;
				}
				else
				{
					f[e[g]].push_back(g);
					p[h].m=1;
					p[h].n=e[g]+1;
					h++;
				}
				else
				{
					if (!(f[b-1].size()&1)) f[b-1].push_back(g);
					else f[b-1].pop_back();
					p[h].m=1;
					p[h].n=b;
					h++;
				}
			}
			printf("%d\n",h);
			for (s=0;s<h;s++)
			if (p[s].m==1) printf("1 %d\n",p[s].n);
			else printf("2 %d %d\n",p[s].n,p[s].o);
		}
	}
	return 0;
}
