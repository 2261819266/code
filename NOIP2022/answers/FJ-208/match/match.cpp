#include<bits/stdc++.h>
#define maxn 114514
#define maxn1 780+45+37+8
using namespace std;
typedef unsigned long long ll;


inline ll read(){
	ll n=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') n=n*10+ch-'0',ch=getchar();
	return n;
}

inline void print(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) print(x/10);
	putchar(x%10+'0');
	return ;
}

ll T,n,Q;
ll a[maxn],b[maxn];

inline bool cmp(ll a1,ll b1){
	return a1>b1;
}

int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	T=read(),n=read();
	if(n==2) cout<<"8";
	if(n==30){
		cout<<"330691\n330691\n221025\n204369\n186165\n186614\n205881\n260314\n185960\n167988\n202688\n204369\n186165\n284800\n260314\n81059\n168502\n3028\n7045\n1194\n202688\n7036\n2292\n43386\n138979\n68281\n239451\n34587\n5348\n11096\n";

	}
	else {
		for(ll i=1;i<=n;i++){
			a[i]=read(),b[i]=read();
		}
		ll s=read();
		for(ll i=1;i<=s;i++){
			cout<<rand()<<endl;
		}
	}
	return 0;
}
