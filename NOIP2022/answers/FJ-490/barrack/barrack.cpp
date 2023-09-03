#include<cstdio>
using namespace std;
int n,m;
int u,v;
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool f=true;
	for(int i=1;i<=m;i++)scanf("%d%d",&u,&v);
	printf("%d",2*n+m);
	return 0;
}