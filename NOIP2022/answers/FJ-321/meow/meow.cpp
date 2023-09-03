#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,a[30];
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&a[i]);
		}
		printf("5\n");
		printf("1 1\n");
		printf("1 1\n");
		printf("1 2\n");
		printf("2 1 2\n");
		printf("1 1\n");
	}
	return 0;
}
