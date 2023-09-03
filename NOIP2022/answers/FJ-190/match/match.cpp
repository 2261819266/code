#include<bits/stdc++.h>

using namespace std;
const int N=3e5+5;
int T,Q;
int n,a[N],b[N],sta[N][30],stb[N][30]={0},LG[N];
unsigned long long ans=0,f[3005][3005]={0};

int qrya(int l,int r){
	int k=LG[r-l+1];
	return max(sta[l][k],sta[r-(1<<k)+1][k]);
}

int qryb(int l,int r){
	int k=LG[r-l+1];
	return max(stb[l][k],stb[r-(1<<k)+1][k]);
}

int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T>>n;
	for(int i=1;i<=n;i++)cin>>sta[i][0];
	for(int i=1;i<=n;i++)cin>>stb[i][0];
	for(int i=2;i<=3e5;i++){
		if((i&(i-1))==0)LG[i]=LG[i-1]+1;
		else LG[i]=LG[i-1];
	}
	for(int j=1;j<=29;j++)
		for(int i=1;i+(1<<(j-1))<=n;i++){
			sta[i][j]=max(sta[i][j-1],sta[i+(1<<(j-1))][j-1]);
			stb[i][j]=max(stb[i][j-1],stb[i+(1<<(j-1))][j-1]);
		}
	
	cin>>Q;
	for(int i=1,p,q;i<=Q;i++){
		ans=0;
		cin>>p>>q;
		for(int l=p;l<=q;l++)
			for(int r=l;r<=q;r++)
				ans+=(1ll*qrya(l,r))*(1ll*qryb(l,r));
		cout<<ans<<"\n";
	}
	return 0;
}
