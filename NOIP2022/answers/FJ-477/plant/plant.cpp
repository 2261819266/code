#include<bits/stdc++.h>

using namespace std;

int t,id,n,m,c,f,CAN[1005][1005],CAN1[1005][1005];
long long ans1,ans2;
string s[1005];
int main() {
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>t>>id;
	while(t--) {
		ans1=ans2=0;
		cin>>n>>m>>c>>f;
		for(int i=1;i<=n;i++) cin>>s[i];
		if(c==0&&f==0) {
			cout<<"0 0\n";
			continue;
		}
		for(int i=1;i<=n;i++) for(int j=m;j>=1;j--) {
			if(s[i][j-1]=='1') CAN[i][j]=0;
			else CAN[i][j]=CAN[i][j+1]+1;
		}
		for(int i=n;i>=1;i--) for(int j=1;j<=m;j++) {
			if(s[i][j-1]=='1') CAN[i][j]=0;
			else CAN1[i][j]=CAN1[i+1][j]+1;
		}
		for(int k=1;k<=m;k++) for(int i=1;i<=n;i++) {
			if(s[i][k-1]=='1') continue;
			for(int j=i+1;j<=n;j++) {
				if(s[j][k-1]=='1') break;
				if(j<i+2) continue;
				long long cnt=(CAN[i][k]-1)*(CAN[j][k]-1);
				ans1=ans1+cnt;
				ans2=ans2+cnt*(CAN1[j][k]-1);
				if(ans1>=998244353) ans1-=998244353;
				if(ans2>=998244353) ans2-=998244353;
			}
		}
		cout<<ans1*c<<" "<<ans2*f<<"\n";
	}
	return 0;
}
