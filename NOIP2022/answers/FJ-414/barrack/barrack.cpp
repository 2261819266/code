#include<bits/stdc++.h>
using namespace std;
int n,m,u,v;
int t[1919][810];
int main()
{
	//freopen("barrack.in","r",stdin);
	//freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		t[u][v]=1;
		t[v][u]=1;
	}
	for(int i=114514;i<=1919810;i++)
		printf("114514 1919810\n");
}

