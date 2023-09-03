#include<bits/stdc++.h>
#include<chrono>
using namespace std;
const int MAXN=250010;
int sum[4*MAXN],sum1[4*MAXN];
int aa[MAXN],bb[MAXN];
int T,n;
long long ans;
void build(int l,int r,int rt){
	if(l==r){
		sum[rt]=aa[l];
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,rt*2);
	build(mid+1,r,rt*2+1);
	sum[rt]=max(sum[rt*2],sum[rt*2+1]);
}
void build1(int l,int r,int rt){
	if(l==r){
		sum1[rt]=bb[l];
		return;
	}
	int mid=(l+r)/2;
	build1(l,mid,rt*2);
	build1(mid+1,r,rt*2+1);
	sum1[rt]=max(sum1[rt*2],sum1[rt*2+1]);
}
int query(int l,int r,int a,int b,int rt){
	if(l>=a&&r<b)return sum[rt];
	int mid=(l+r)/2;
	if(mid<=a)return query(l,mid,a,b,rt*2);
	if(mid>b)return query(mid+1,r,a,b,rt*2+1);
	return max(query(mid+1,r,a,b,rt*2+1),query(l,mid,a,b,rt*2));
}
int query1(int l,int r,int a,int b,int rt){
	if(l>=a&&r<b)return sum1[rt];
	int mid=(l+r)/2;
	if(mid<=a)return query1(l,mid,a,b,rt*2);
	if(mid>b)return query1(mid+1,r,a,b,rt*2+1);
	return max(query1(mid+1,r,a,b,rt*2+1),query1(l,mid,a,b,rt*2));
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0),cout.tie(0);
	cin>>T>>n;
	for(int i=1;i<=n;i++){
		cin>>aa[i];
	}
	for(int i=1;i<=n;i++){
		cin>>bb[i];
	}
	build(1,n,1);
	build1(1,n,1);
	int q;
	cin>>q;
	for(int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;
		for(int j=l;j<=r;j++){
			for(int k=j;k<=r;k++){
				int xx=query(1,n,j,k,1);
				int yy=query1(1,n,j,k,1);
				ans+=xx+yy;
			}
		}
	}
	long long aad=1;
	for(int i=2;i<=64;i++){
		aad*=2;
	}
	cout<<ans%aad;
	return 0;
}