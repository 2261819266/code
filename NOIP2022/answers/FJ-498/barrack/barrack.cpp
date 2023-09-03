#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define mod 1000000007
using namespace std;
struct way
{
	int fr,to,hv;
}wy[114514]={0};
int f[114514][2]={0};
bool cmp(way a,way b)
{
	if(a.fr==b.fr)return a.to<b.to;
	return a.fr<b.fr;
}
int n,m,ans,a;
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		cin>>wy[i].fr>>wy[i].to;
	}
	sort(wy+1,wy+n+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(f[wy[i].fr][0]==0)f[wy[i].fr][0]=i;
		f[wy[i].to][1]=i;
	}
	while(wy[m+1].hv!=1)
	{
		wy[1].hv++;
		a=1;
		while(wy[a].hv!=2)
		{
			wy[a+1].hv+=1;
			wy[a].hv=0;;
			a++;
		}
	}
	return 0;
}
