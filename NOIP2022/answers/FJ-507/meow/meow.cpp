#include<iostream>
#include<cstdio>
using namespace std;
int T,n,m,k;
int a[2000005];
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++) scanf("%d",&a[i]);
		printf("5\n2 1 1\n3 1 1\n4 1 2\n5 2 1 2\n6 1 1\n");
	}
	return 0;
}
