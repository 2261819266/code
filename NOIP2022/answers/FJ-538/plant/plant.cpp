#include<bits/stdc++.h>
using namespace std;
const long long N=1e3+5,P=998244353;
long long T,id,cn,fn,C,F;
long long n,m,a[N][N],f[N][N];
void init(){
	memset(a,0,sizeof a);
	memset(f,0,sizeof f);
	C=F=0;
	scanf("%lld%lld%lld%lld",&n,&m,&cn,&fn);
	for(long long i=1;i<=n;i++)
		for(long long j=1;j<=m;j++){
			char t=' ';
			while(t!='0'&&t!='1')	scanf("%c",&t);
			a[i][j]=t-'0';
		}
}
void get_f(){
	for(long long i=1;i<=n;i++){
		for(long long j=m;j>=1;j--){
			if(a[i][j]==1)	continue;
			if(j==m||a[i][j+1]==1)	f[i][j]=0;
			else	f[i][j]=f[i][j+1]+1;
		}
	}
}
void get_lie(long long y,long long xst,long long xed){
	if(xst+1>=xed)	return;
	long long sum[N];
	sum[xst-1]=0;
	for(long long i=xst;i<=xed;i++)	sum[i]=(sum[i-1]+f[i][y])%P;
	for(long long i=xst+2;i<=xed;i++)	C=(C+(long long)sum[i-2]*f[i][y]%P)%P;
	for(long long i=xst+2;i<=xed;i++)	F=(F+(long long)sum[i-2]*f[i][y]%P*(xed-i)%P)%P;
}
void Plant(){
	init();
	get_f();
	for(long long y=1;y<=m;y++){
		long long st,ed;
		for(long long i=1;i<=n;i++){
			if(a[i][y]==0&&(i==1||a[i-1][y]==1))	st=i;
			if(a[i][y]==0&&(i==n||a[i+1][y]==1)){ed=i;get_lie(y,st,ed);}
		}
	}
	printf("%lld %lld\n",C*cn,F*fn);
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>T>>id;
	while(T--)	Plant();
	return 0;
}
