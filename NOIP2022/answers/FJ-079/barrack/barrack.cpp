#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include <algorithm>
using namespace std;
long long dan=1000000007;
long long ans;
long long n,m;
inline int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x;
}
long long erci(long long x){
	long long yu=2;
	while(--x){
		yu=(yu*2)%dan;
	}
	return yu;	
}
long long jiec(long long x){
	long long ans=1;
	for(long long yu=1;yu<=x;yu++){
		ans=(ans*yu)%dan;
	}
	return ans;
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	if(n>3000){
			ans=(jiec(n-1)*erci(m-1))%dan+(n*erci(m))%dan;
			printf("%lld",ans);
			return 0;
	}else{
		ans=((n-1)*(erci(n-1))*erci(n))%dan;
		printf("%lld",ans);
		return 0;
	}
	return 0;
}
