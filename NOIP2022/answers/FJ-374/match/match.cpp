#include<bits/stdc++.h>
using namespace std;
int ta[1000010],tb[1000010];
int a[250010],b[250010],c[3010][3010];
void builda(int root,int l,int r){
	if(l==r){
		ta[root]=a[l];
		return;
	}
	builda(root*2,l,(l+r)/2);
	builda(root*2+1,(l+r)/2+1,r);
	ta[root]=max(ta[root*2],ta[root*2+1]);
}
void buildb(int root,int l,int r){
	if(l==r){
		tb[root]=b[l];
		return;
	}
	buildb(root*2,l,(l+r)/2);
	buildb(root*2+1,(l+r)/2+1,r);
	tb[root]=max(tb[root*2],tb[root*2+1]);
}
int getmaxa(int root,int l,int r,int s,int t){
	if(s<=l&&t>=r)return ta[root];
	int mid=(l+r)/2;
	int k=0;
	if(mid>=s)k=max(k,getmaxa(root*2,l,mid,s,t));
	if(mid+1<=t)k=max(k,getmaxa(root*2+1,mid+1,r,s,t));
	return k;
}
int getmaxb(int root,int l,int r,int s,int t){
	if(s<=l&&t>=r)return tb[root];
	int mid=(l+r)/2;
	int k=0;
	if(mid>=s)k=max(k,getmaxb(root*2,l,mid,s,t));
	if(mid+1<=t)k=max(k,getmaxb(root*2+1,mid+1,r,s,t));
	return k;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	ios::sync_with_stdio(0);
	int t,n;
	cin>>t>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	builda(1,1,n);
	buildb(1,1,n);
	int Q;
	cin>>Q;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			c[i][j]=getmaxa(1,1,n,i,j)*getmaxb(1,1,n,i,j);
		}
	}
	while(Q--){
		int l,r;
		cin>>l>>r;
		unsigned long long ans=0;
		for(int p=l;p<=r;p++){
			for(int q=p;q<=r;q++){
				ans+=c[p][q];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}            