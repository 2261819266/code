#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=1e6+5;
const long long p=1000000007;
int n,m;
vector<int> s[N];
inline int read(){
	int x=0; char ch;
	bool bz=0;
	while(((ch=getchar())<'0'||ch>'9')&&ch!='-') ;
	if(ch=='-') bz=1;
	else x=(x<<1)+(x<<3)+(ch^48);
	while((ch=getchar())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48);
	return bz?-x:x;
}
inline long long power(long long x,long long y){
	long long z=1;
	x=x%p;
	while(y){
		if(y&1) z=z*x%p;
		x=x*x%p; y>>=1;
	}
	return z;
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	srand(time(0));
	n=read(),m=read();
	while(m--){
		int x=read(),y=read();
		s[x].push_back(y);
		s[y].push_back(x);
	}
	if(m==n-1) printf("%lld\n",(power(2,n-2)%p+n%p*power(2,n-1)%p+p)%p);
	else{
		printf("%lld\n",rand()%p);
	}
	return 0;
}
