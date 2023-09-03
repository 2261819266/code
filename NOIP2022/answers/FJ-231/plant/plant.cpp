#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
const int M=998244353;
int T,id,a[1001][1001],n,m,c,f;
int H(int x,int y)
{
	for(int i=y+1;i<=m;i++) 
		if(a[x][i]) return i-y-1;
	return m-y;
}
void Sc(int c)
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
}
int main()
{
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	scanf("%d%d",&T,&id);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&m,&c,&f);
		string s;
		for(int i=1;i<=n;i++)
		{
			cin>>s;
			for(int j=0;j<s.size();j++)a[i][j+1]=s[j]-48;
		}
		Sc(c); Sf(f);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
	
