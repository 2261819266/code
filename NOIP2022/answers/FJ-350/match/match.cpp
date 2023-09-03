#include <bits/stdc++.h>
using std::max;
typedef long long ll;
typedef unsigned long long ull;
const int N=2e5+15;

inline ll rd(){
	ll w=1,r=0;char c=getchar();
	while(!isdigit(c)) ((c=='-')&&(w=-1)),c=getchar();
	while(isdigit(c)) r=r*10+c-'0',c=getchar();
	return w*r;
}

int n,q,a[N],b[N],T;
ull ans;

inline void calc(int l,int r){
	int ma,mb;
	for(int i=l;i<=r;++i){
		ma=a[i],mb=b[i];
		for(int j=i;j<=r;++j){
			ma=max(ma,a[j]);
			mb=max(mb,b[j]);
			ans+=ma*mb;
		}
	}
}

int main(){
	freopen("match.in","r",stdin);freopen("match.out","w",stdout);
	T=rd(),n=rd();
	for(int i=1;i<=n;++i) a[i]=rd();
	for(int i=1;i<=n;++i) b[i]=rd();
	q=rd();
	for(int i=1,l,r;i<=q;++i){
		ans=0;
		l=rd(),r=rd();
		calc(l,r);
		std::cout<<ans<<'\n';
	}
	
	return 0;
}
