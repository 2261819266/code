#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
inline ll read(){
	ll s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+'0');
}
const int MAXX=1e6+5;
const int MAXN=250000;
struct tree{
	ll mx;
}trA[MAXX],trB[MAXX];
ll a[MAXN],b[MAXN];
void build_trA(ll k,ll l,ll r){
	if(l==r){
		trA[k].mx=a[l];
		return;
	}
	ll mid=(l+r)>>1;
	build_trA(2*k,l,mid);
	build_trA(2*k+1,mid+1,r);
	trA[k].mx=max(trA[2*k].mx,trA[2*k+1].mx);
}
void build_trB(ll k,ll l,ll r){
	if(l==r){
		trB[k].mx=b[l];
		return;
	}
	ll mid=(l+r)>>1;
	build_trB(2*k,l,mid);
	build_trB(2*k+1,mid+1,r);
	trB[k].mx=max(trB[2*k].mx,trB[2*k+1].mx);
}
ll queryA(ll k,ll l,ll r,ll tarl,ll tarr){
	if(l==tarl&&r==tarr){
		return trA[k].mx;
	}
	ll mid=(l+r)>>1;
	if(tarr<=mid){
		return queryA(2*k,l,mid,tarl,tarr);
	}
	else if(tarl>mid){
		return queryA(2*k+1,mid+1,r,tarl,tarr);
	}
	else{
		return max(queryA(2*k,l,mid,tarl,mid),queryA(2*k+1,mid+1,r,mid+1,tarr));
	}
}
ll queryB(ll k,ll l,ll r,ll tarl,ll tarr){
	if(l==tarl&&r==tarr){
		return trB[k].mx;
	}
	ll mid=(l+r)>>1;
	if(tarr<=mid){
		return queryB(2*k,l,mid,tarl,tarr);
	}
	else if(tarl>mid){
		return queryB(2*k+1,mid+1,r,tarl,tarr);
	}
	else{
		return max(queryB(2*k,l,mid,tarl,mid),queryB(2*k+1,mid+1,r,mid+1,tarr));
	}
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T=read(),n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=n;i++){
		b[i]=read();
	}
	if(T==1||T==2||T==0){
		build_trA(1,1,n);
		build_trB(1,1,n);
		ll ans=0;
		ll Q=read();
		while(Q--){
			ans=0;
			ll l=read(),r=read();
			for(ll i=l;i<=r;i++){
				for(ll j=i;j<=r;j++){
					if(i==j){
						ans+=a[i]*b[i];
						continue;
					}
					ll q1=queryA(1,1,n,i,j),q2=queryB(1,1,n,i,j);
					ans+=(q1*q2);
				}
			}
			write(ans);
			putchar('\n');
		}
	}
	return 0;
}
