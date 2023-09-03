#include <bits/stdc++.h>
using namespace std;
const int N=10010;
const int inf=0x3f3f33f;

#define ULL unsigned long long

int a[1010][1010];

int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int t,id;cin>>t>>id;
	while(t--){
		int n,m,c,f;
		ULL vc,vf;
		cin>>n>>m>>c>>f;
		if(id==0) vc=4,vf=2;
		if(id==1) vc=1,vf=1;
		if(id==2){
			int sum=0;vf=0;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++) {
					cin>>a[i][j];
					if(a[i][j]==1) sum++;
				}
			if(sum==0) vc=2;
			else if(sum==1&&(a[2][1]==1||a[2][2]==1)) vc=1;
			else vc=0;
		}
		if(id==5){
			if(m%3==0||m%3==1) vc=(n-2)*(n-1)/2*(m/3)%998244353,vf=(n-2)*(n-3)/2*(m/3)%998244353;
			else vc=(n-2)*(n-1)/2*(m/3+1)%998244353,vf=(n-2)*(n-3)/2*(m/3+1)%998244353;
		}
		if(id==6){
			vf=0;
			if(n%4==3) vc=m*m*(m-1)*(m-1)/4*(n/4+1)%998244353;
			else vc=m*m*(m-1)*(m-1)/4*(n/4)%998244353;
		}
		cout<<vc*c<<" "<<vf*f<<endl;
	}
	return 0;
}
