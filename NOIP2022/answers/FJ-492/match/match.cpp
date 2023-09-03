#include<bits/stdc++.h>
#define lp (p<<1)
#define rp (p<<1|1)
#define mid ((l+r)>>1)
using namespace std;
const int N=250000+10;
typedef unsigned long long ull;
ull mod=pow(2,64),ans=0;
ull maxa[N<<2],a[N],maxb[N],b[N],q,t,n;

void build(ull p,ull l,ull r){
	if(l==r){
		maxa[p]=a[l];
		maxb[p]=b[l];
		return;
	}
	build(lp,l,mid),build(rp,mid+1,r);
	maxa[p]=max(maxa[lp],maxa[rp]);
	maxb[p]=max(maxb[lp],maxb[rp]);
}

ull query(ull s,ull e,ull l,ull r,ull p,int k){
	if(s<=l&&r<=e){
		if(k==1) return maxa[p];
		else return maxb[p];
	}
	ull res=0;
	if(s<=mid) res=query(s,e,l,mid,lp,k);
	if(mid<e) res=max(res,query(s,e,mid+1,r,rp,k));  
	return res;
} 

int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin>>t>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	build(1,1,n);
	cin>>q;
	for(int i=1,ll,rr;i<=q;i++){
		ans=0;
		cin>>ll>>rr;
		for(int x=ll;x<=rr;x++){
			for(int y=x,ma,mb;y<=rr;y++){
				ma=query(x,y,1,n,1,1);
				mb=query(x,y,1,n,1,2);
				ans=(ans+ma*mb);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

