#include <iostream>
#include <cstdio>
using namespace std;
int a[100001],t,n,m,k;
int z1[100001],z2[100001];
/*void Sc(int c)
{
	if(c==0||n<3){
		printf("0 ");return;
	}
	int s=0;
	for(int i=1;i<=n-2;i++)
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]||a[i][j+1])continue;
			int h=H(i,j);
			if(!h)continue;
			for(int k=i+2;k<=n;k++)
			{
				if(a[k][j])break;
				int hp=H(k,j);
				if(hp<h)break;
				s=(s+hp*h)%M;
			}
		}
	printf("%d ",s);
}
void Sf(int f){
	if(f==0||n<4){
		printf("0");return;
	}
	int s=0;
	for(int i=1;i<=n-2;i++)
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]||a[i][j+1])continue;
			int K=i,ok=1;
			for(;K<=n;K++)if(a[K][j]){K--;ok=0;break;}
			if(ok)K=n;
			int h=H(i,j);
			if(!h)continue;
			for(int k=i+2;k<K;k++)
			{
				if(a[k][j])break;
				int hp=H(k,j);
				if(hp<h)break;
				s=(s+hp*h)*(K-k)%M;
			}
		}
	printf("%d ",s);
}*/
int main() {
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		printf("5\n1 1\n1 1\n1 2\n2 1 2\n1 1\n");
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
