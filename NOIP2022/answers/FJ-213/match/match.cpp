#include<bits/stdc++.h>
#define For(i,s,e) for(long long i = (s);i<=(e);i++)
#define rof(i,s,e) for(long long i = (e);i>=(s);i--)

using namespace std;

typedef unsigned long long ll;
const ll N = 1e6+10;
const ll mo = 9223372036854775808;

ll n,m,cnt,T,Q,l,r;
ll a[N],b[N];

ll Mod(ll x){
	ll s = x % mo ;
	return s;
}

int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);

	cin>>T>>n;
	For(i,1,n) cin>>a[i];
	For(i,1,n) cin>>b[i];
	cin>>Q;
	ll sum=0;
	while(Q--){
		sum = 0;
		cin>>l>>r;
		For(p,l,r){
			For(q,l,r){
				if(p > q) continue;
				ll maxa=0,maxb=0;
				For(i,p,q){
					maxa=max(maxa,a[i]);
					maxb=max(maxb,b[i]);
				}
				sum += Mod(maxa*maxb);
			}
		}
		cout<<Mod(sum)<<endl;
	}
	
	
	
	return 0;
}
