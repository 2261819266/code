#include<bits/stdc++.h>
using namespace std;
int n,m,k,T;
vector<int> b[302];
int s[302],t[302];
int a[2000006],op;
int flags[604],flagt[604];
struct node{int x,y;}ops[4000012];
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&a[i]);
			if(flags[a[i]])ops[++op].x=1,ops[op].y=flags[a[i]],flags[a[i]]=0;
		}
	}
	return 0;
}
