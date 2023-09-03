#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T,n,m,k,a,z[4][1000],ans=0,s[50][3];
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		memset(z,0,sizeof(z));
		printf("%d\n",m);
		for(int i=0;i<m;i++){
			scanf("%d",&a);
			printf("%d %d\n",1,i%2+1);
		}
	}
	return 0;
}

