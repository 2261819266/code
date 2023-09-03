#include<bits/stdc++.h>
using namespace std;
const int Maxn=3e5+7;
int T,n,a[Maxn]={},b[Maxn]={},Q,l,r;
int Max[Maxn<<2]={},Max1[Maxn<<2];
void PushUp(int rt){
	Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);
	Max1[rt]=max(Max1[rt<<1],Max1[rt<<1|1]);
}
void build(int l,int r,int rt){
	if(l==r){
		Max[rt]=a[l];
		Max1[rt]=b[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	PushUp(rt);
}
int query(int L,int R,int l,int r,int rt){
	if(L<=l&&r<=R){
		return Max[rt];
	}
	int mid=(l+r)>>1;
	int Maxm=-INT_MAX;
	if(L<=mid)
	Maxm=max(Maxm,query(L,R,l,mid,rt<<1));
	if(R>mid)
		Maxm=max(Maxm,query(L,R,mid+1,r,rt<<1|1));
	return Maxm;
}
int query1(int L,int R,int l,int r,int rt){
	if(L<=l&&r<=R){
		return Max1[rt];
	}
	int mid=(l+r)>>1;
	int Maxm=-INT_MAX;
	if(L<=mid)
	Maxm=max(Maxm,query1(L,R,l,mid,rt<<1));
	if(R>mid)
		Maxm=max(Maxm,query1(L,R,mid+1,r,rt<<1|1));
	return Maxm;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	std::ios::sync_with_stdio(false);
	
	cin>>T>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	build(1,n,1);
	cin>>Q;	
	for(int i=1;i<=Q;i++){
		cin>>l>>r;
		unsigned long long ans=0;
		for(int j=l;j<=r;j++){
			for(int k=j;k<=r;k++){
				long long finda=query(j,k,1,n,1),findb=query1(j,k,1,n,1);
				ans+=finda*findb;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}