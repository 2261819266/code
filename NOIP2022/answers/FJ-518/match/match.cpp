#include<bits/stdc++.h>
using namespace std;
int t,n;
int sta[31][250005];
int stb[31][250005];
int l[250005];
long long aska(int l,int r){
	int s=log(r-l+1)/log(2.0);
	return max(sta[s][l],sta[s][r-(1<<s)+1]);
}
long long askb(int l,int r){
	int s=log(r-l+1)/log(2.0);
	return max(stb[s][l],stb[s][r-(1<<s)+1]);
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&t,&n);
	for(int i=1;i<=n;++i)scanf("%d",&sta[0][i]);
	for(int i=1;i<=n;++i)scanf("%d",&stb[0][i]);
	for(int i=1;i<=30;++i){
		for(int j=1;j<=n;++j){
			if(j+(1<<i)-1>n)break;
			sta[i][j]=max(sta[i-1][j],sta[i-1][j+(1<<i)-1]);
		}
	}
	for(int i=1;i<=30;++i){
		for(int j=1;j<=n;++j){
			if(j+(1<<i)-1>n)break;
			stb[i][j]=max(stb[i-1][j],stb[i-1][j+(1<<i)-1]);
		}
	}
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;++i){
		int l,r;
		scanf("%d%d",&l,&r);
		unsigned long long ans=0;
		for(int k=l;k<=r;++k){
			for(int j=k;j<=r;++j)ans+=aska(k,j)*askb(k,j);
		}
		cout<<ans<<endl; 
	}
	return 0;
}
