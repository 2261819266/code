#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn=1e6+100,maxm=1e3+10,N=300000;
unsigned long long mod=1;

inline int read(int x=0){
	int c,f(1);
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-f;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-0x30;
	return x*f;
}

long long T,n,a[maxn],b[maxn],f1[N][20],f2[N][20],Q,l,r,ans1,ans2;
unsigned long long ans=0;

int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	T=read(),n=read();
	for(int i=1;i<=63;i++)mod*=2;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=1;i<=n;i++)f1[i][0]=a[i],f2[i][0]=b[i];
	int k=log(n)/log(2);
	for(int i=1;i<=k;i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			if(f1[j][i-1]>f1[j+(1<<(i-1))][i-1])f1[j][i]=f1[j][i-1];
			else f1[j][i]=f1[j+(1<<(i-1))][i-1];
			if(f2[j][i-1]>f2[j+(1<<(i-1))][i-1])f2[j][i]=f2[j][i-1];
			else f2[j][i]=f2[j+(1<<(i-1))][i-1];
		}
	}
	Q=read();
	while(Q--){
		ans=0;
		l=read(),r=read();
		for(int i=l;i<=r;i++){
			for(int j=i;j<=r;j++){
				k=log(j-i+1)/log(2);
				if(f1[i][k]>f1[j-(1<<k)+1][k])ans1=f1[i][k];
				else ans1=f1[j-(1<<k)+1][k];
				if(f2[i][k]>f2[j-(1<<k)+1][k])ans2=f2[i][k];
				else ans2=f2[j-(1<<k)+1][k];
				ans+=ans1*ans2;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
