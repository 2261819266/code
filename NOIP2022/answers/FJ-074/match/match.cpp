#include<cstdio>
#define N 3033
using namespace std;
typedef unsigned long long u64;
int n,Q;
int lg2[N];
u64 ST[2][13][N],ans;
inline int Fr(){
	int res=0;char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>47&&c<58){res=(res<<1)+(res<<3)+(c^48);c=getchar();}
	return res;
}
inline u64 Mx(u64 x,u64 y){return x>y?x:y;}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int _,__;
	n=Fr();n=Fr();lg2[0]=-1;
	for(int i=0;i<2;i++)
		for(int j=1;j<=n;j++){
			ST[i][0][j]=(u64)Fr();
			lg2[j]=lg2[j>>1]+1;
		}
	for(int i=0;i<2;i++)
		for(int k=1;k<13;k++)
			for(int j=1;j<=n;j++){
				ST[i][k][j]=Mx(ST[i][k-1][j],ST[i][k-1][j+(1<<(k-1))]);
			}
	Q=Fr();
	while(Q--){
		_=Fr();__=Fr();ans=0;
		for(int p=_;p<=__;p++)
			for(int q=p;q<=__;q++){
				int ___=lg2[q-p+1];
				ans+=Mx(ST[0][___][p],ST[0][___][q-(1<<___)+1])*Mx(ST[1][___][p],ST[1][___][q-(1<<___)+1]);
				//printf("%llu %llu\n",Mx(ST[0][___][p],ST[0][___][q-(1<<___)+1]),Mx(ST[1][___][p],ST[1][___][q-(1<<___)+1]));
			}
		printf("%llu\n",ans);
	}
	return 0;
}
