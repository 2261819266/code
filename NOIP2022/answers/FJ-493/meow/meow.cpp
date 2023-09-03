#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,k,cnt1,cnt2;
int sit[605][2];
int a[2000005];
int s[4000005][2];
bool f[4000005];
int u[305],d[305];
bool f2[305][2];
void work1() {
	int op=0;
	for(int j=1; j<=m; j++) {
		int i=a[j];
		if(sit[i][0]==1) {
			f[++op]=0;
			s[op][0]=n;
			f[++op]=1;
			s[op][0]=n;
			s[op][1]=sit[i][1];
			if(f2[sit[i][1]][1])u[++cnt1]=sit[i][1],f2[sit[i][1]][1]=0;
			else d[++cnt2]=sit[i][1],f2[sit[i][1]][0]=0;
			sit[i][0]=0;
		} else if(sit[i][0]==2) {
			f[++op]=0;
			s[op][0]=sit[i][1];
			sit[i][0]=0;
			u[++cnt1]=sit[i][1];
			f2[sit[i][1]][1]=0;
		} else {
			if(cnt2>=1)sit[i][0]=1,sit[i][1]=d[cnt2--],f[++op]=0,s[op][0]=sit[i][1];
			else{
				sit[i][0]=2;
				sit[i][1]=u[cnt1--];
				f[++op]=0;
				s[op][0]=sit[i][1];
			}
		}
	}
	printf("%d\n",op);
	for(int i=1;i<=op;i++){
		printf("%d ",(int)f[i]+1);
		for(int j=0;j<(int)f[i]+1;j++)printf("%d ",s[i][j]);
		printf("\n");
	}
}
int main() {
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d",&n,&m,&k);
		memset(sit,0,sizeof(sit));
		for(int i=1; i<=m; i++) {
			scanf("%d",&a[i]);
		}
		memset(u,0,sizeof(u));
		memset(d,0,sizeof(d));
		cnt1=cnt2=0;
		for(int i=1; i<n; i++)u[++cnt1]=i,d[++cnt2]=i;
		if(k==2*n-2)work1();
	}
	return 0;
}
/*
1
2 4 2
1 2 1 2
*/
