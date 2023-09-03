#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
struct c{
	bool d;
	int e,f,g,h;
	int gg;
}j[500000];
struct l{
	int m,n;
}o[1000000];
struct w{
	int x,y,z,aa,bb,cc;
	bool dd;
}ee[500000];
int a,b,s,t[500000],u,ff,jj[1500002],qq;
void p(int q,int r)
{
	int v;
	j[q].d=1;
	j[q].f=s;
	j[q].g=s;
	s++;
	t[u++]=q;
	for (v=j[q].e;v<b<<1;v=o[v].n) if (v!=(r^1))
	if (!j[o[v].m-1].d)
	{
		p(o[v].m-1,v);
		j[q].f=min(j[q].f,j[o[v].m-1].f);
	}
	else j[q].f=min(j[q].f,j[o[v].m-1].g);
	if (j[q].f==j[q].g)
	{
		j[q].h=ff;
		j[q].gg=a;
		ee[ff].x=q;
		ee[ff].y=1;
		for (;t[u-1]!=q;u--)
		{
			j[t[u-1]].h=ff;
			j[t[u-1]].gg=a;
			j[ee[ff].x].gg=t[u-1];
			ee[ff].x=t[u-1];
			ee[ff].y++;
		}
		u--;
		ff++;
	}
}
void ll(int mm)
{
	int nn,oo,pp;
	ee[mm].aa=jj[ee[mm].y+(ee[mm].z>>1)];
	ee[mm].bb=ee[mm].z>>1;
	ee[mm].cc=0;
	ee[mm].dd=1;
	for (oo=ee[mm].x;oo<a;oo=j[oo].gg) for (pp=j[oo].e;pp<b<<1;pp=o[pp].n) if (!ee[j[o[pp].m-1].h].dd)
	{
		ll(j[o[pp].m-1].h);
		ee[mm].aa=(long long int)(ee[mm].aa)*((ee[j[o[pp].m-1].h].cc+jj[ee[j[o[pp].m-1].h].bb+1])%1000000007)%1000000007;
		ee[mm].bb+=ee[j[o[pp].m-1].h].bb+1;
		ee[mm].cc=(ee[mm].cc+ee[j[o[pp].m-1].h].cc)%1000000007;
	}
	ee[mm].cc=(ee[mm].cc+ee[mm].aa-jj[ee[mm].bb]+1000000007)%1000000007;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int i,k,hh,ii,kk;
	scanf("%d%d",&a,&b);
	for (i=0;i<a;i++) j[i].e=b<<1;
	for (k=0;k<b;k++)
	{
		scanf("%d%d",&o[k<<1].m,&o[k<<1|1].m);
		o[k<<1].n=j[o[k<<1|1].m-1].e;
		j[o[k<<1|1].m-1].e=k<<1;
		o[k<<1|1].n=j[o[k<<1].m-1].e;
		j[o[k<<1].m-1].e=k<<1|1;
	}
	p(0,b<<1);
	for (hh=0;hh<a;hh++) for (ii=j[hh].e;ii<b<<1;ii=o[ii].n) if (j[hh].h==j[o[ii].m-1].h) ee[j[hh].h].z++;
	jj[0]=1;
	for (kk=1;kk<=a+b+1;kk++) jj[kk]=(jj[kk-1]<<1)%1000000007;
	ll(0);
	printf("%d",ee[0].cc);
	return 0;
}
/*
8 7
1 2
2 3
3 4
3 5
2 6
6 7
7 8
*/
