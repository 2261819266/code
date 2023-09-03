#include<bits/stdc++.h>
using namespace std;
const long long aa=1e9+7;
long long n,m;
long long ans=1,tot=1;
int v[1000007],u[1000007];
inline long long read(){
	long long x=0;
	bool f=0;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(; isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
	if(f) x=-x;
	return x;
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read();
	m=read();
	for(long long i=1;i<=m;i++){
		v[i]=read();
		u[i]=read();
	}
	for(int i=1;i<=n;i++){
		ans=((ans%aa)*(i%aa))%aa;
	}
	for(int i=1;i<=m+1;i++){
		tot=((tot%aa)*(i%aa))%aa;
	}
	cout<<(tot+((m%aa)*(m%aa)*(m%aa)%aa))%aa;
	
	return 0;
}
