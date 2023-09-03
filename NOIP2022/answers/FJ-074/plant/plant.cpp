#include<cstdio>
#define N 1005
#define P 998244353
using namespace std;
typedef long long i64;
int T,iid;
int n,m,c,f;
i64 R[N][N],D[N][N],ans1,ans2;
bool a[N][N];
inline int Fr(){
	int res=0;char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>47&&c<58){res=(res<<1)+(res<<3)+(c^48);c=getchar();}
	return res;
}
inline void FrS(int i){
	char c=getchar();int j=1;
	while(j<=m){
		while(c<48||c>49)c=getchar();
		while(c==48||c==49){R[i][j]=D[i][j]=0;a[i][j++]=c==48?false:true;c=getchar();}
	}
	return;
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int now;
	T=Fr();iid=Fr();
	while(T--){
		n=Fr();m=Fr();c=Fr();f=Fr();
		ans1=ans2=0;
		for(int i=1;i<=n;i++)FrS(i);
		for(int i=1;i<=n;i++)
			for(int j=m-1;j;j--){
				if(a[i][j]||a[i][j+1])R[i][j]=0;
				else R[i][j]=R[i][j+1]+1;
			}
		for(int j=1;j<=m;j++)
			for(int i=n;i;i--){
				if(a[i][j])continue;
				if(i==n||a[i+1][j])D[i][j]=R[i][j],now=i;
				else D[i][j]=D[i+1][j]+R[i][j];
				if(now-i>1)ans1+=(D[i+2][j]-D[now+1][j])*R[i][j],ans1%=P;
				if(now-i>2)ans2+=(D[i+2][j]-D[now][j])*R[i][j]*(now-i-2),ans2%=P;
			}
		printf("%lld %lld\n",ans1*c,ans2*f);
	}
	return 0;
}
