#include <iostream>
#include <cstdio>
using namespace std;
int n,m,u[1000001],v[1000001];
int main() {
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
	}
	int s=1,cc=1000000007;
	for(int i=1;i<n;i++)
	{
		int a=2*i;
		s=(s+(a-1)*4)%cc;
	}
	printf("%d\n",s);
	fclose(stdin); fclose(stdout);
	return 0;
}

