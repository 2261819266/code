#include<bits/stdc++.h>
using namespace std;
long long n,l,r,q,ans,a[20][100005],b[20][100005],lg[100005];
long long mxa(int x,int y){
	int lgk=lg[y-x+1];
	return max(a[lgk][x],a[lgk][y-(1<<lgk)+1]);
}
long long mxb(int x,int y){
	int lgk=lg[y-x+1];
	return max(b[lgk][x],b[lgk][y-(1<<lgk)+1]);
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>n>>n;
	for(int i=1;i<=n;i++) cin>>a[0][i];
	for(int i=1;i<=n;i++) cin>>b[0][i];
	for(int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	for(int i=1;i<=20;i++)
		for(int j=1;j+(1<<i)-1<=n;j++){
			a[i][j]=max(a[i-1][j],a[i-1][j+(1<<(i-1))]);
			b[i][j]=max(b[i-1][j],b[i-1][j+(1<<(i-1))]);
		}
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>l>>r;ans=0;
		for(int j=l;j<=r;j++)
			for(int k=j;k<=r;k++)
				ans+=mxa(j,k)*mxb(j,k);
		cout<<ans<<'\n';
	}
	return 0;
}                          
