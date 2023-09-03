#include<cstdio>
#include<iostream>
using namespace std;
inline int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}
long long ans,mod=1000000007;
inline long long pow(int b){
	if(b==-1)return 1;
	long long ans=1,a=2;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int n,m,x[500005],y[500005];
long long sum1,sum2;
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read(),m=read();
	for(register int i = 1;i<=m;i++)x[i]=read(),y[i]=read();
	sum2=pow(m-1);
	for(register long long i = 0,res;i<n;i++){
		if(!i)res=n*sum2*2%mod;
		else res=(n-i)*sum2%mod;
		ans=(ans+res)%mod;
	}
	printf("%lld",ans);
	return 0;
}
