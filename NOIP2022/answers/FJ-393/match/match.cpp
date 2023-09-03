#include<bits/stdc++.h>
using namespace std;
#define L(x) x<<1
#define R(x) x<<1|1
int T,n,q;
__int128 mod=1;
long long sta[250005][21];
long long stb[250005][21];
__int128 st[250005][21];
__int128 ask(int l,int r){
	int k=log2(r-l+1);
	return max(st[l][k],st[r-(1<<k)+1][k]);
}struct tree{
	int l,r;
	long long sum;
}t[1000005];
void build(int p,int l,int r){
	t[p].l=l;
	t[p].r=r;
	if(l==r){
		t[p].sum=st[l][0];
		return;
	}int mid=(l+r)>>1;
	build(L(p),l,mid);
	build(R(p),mid+1,r);
	t[p].sum=(ask(l,r)+t[L(p)].sum+t[R(p)].sum)%mod;
}__int128 asksum(int p,int l,int r){
	if(t[p].l>r||t[p].r<l)	return 0;
	if(l<=t[p].l&&t[p].r<=r)	return t[p].sum;
	__int128 ans=0;
	if(t[L(p)].r>l)	ans=(ans+asksum(L(p),l,r))%mod;
	if(t[R(p)].l<r)	ans=(ans+asksum(R(p),l,r))%mod;
	return ans;
}void put(__int128 x){
	if(x>9)	put(x/10);
	putchar(x%10+48);
}int main(){
	mod<<=64;
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>T>>n;
	for(int i=1;i<=n;i++){
		cin>>sta[i][0];
	}for(int i=1;i<=n;i++){
		cin>>stb[i][0];
		st[i][0]=sta[i][0]*stb[i][0]%mod;
	}for(int k=1;k<=20;k++){
		for(int i=1;i+(1<<k)-1<=n;i++){
			sta[i][k]=max(sta[i][k-1],sta[i+(1<<(k-1))][k-1]);
			stb[i][k]=max(stb[i][k-1],stb[i+(1<<(k-1))][k-1]);
			st[i][k]=sta[i][k]*stb[i][k]%mod;
		}
	}cin>>q;
	build(1,1,n);
	while(q--){
		int l,r;
		cin>>l>>r;
		put(asksum(1,l,r));
		putchar('\n');
	}return 0;
}
