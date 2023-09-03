#include<bits/stdc++.h>
using namespace std;
int t,id,n,m,c,f,mp[1005][1005],ansc=0,ansf=0;
const int mod=998244353;
char ch;

bool check_c(int x1,int x2,int y0,int y1,int y2){
	for(int y0_2=y0;y0_2<=y1;y0_2++)
		if(mp[x1][y0_2]==1) return 0;
	for(int y0_2=y0;y0_2<=y2;y0_2++)
		if(mp[x2][y0_2]==1) return 0;
	for(int x1_2=x1;x1_2<=x2;x1_2++)
		if(mp[x1_2][y0]==1) return 0;
	return 1;
}

bool check_f(int x1,int x2,int x3,int y0,int y1,int y2){
	for(int y0_2=y0;y0_2<=y1;y0_2++)
		if(mp[x1][y0_2]==1) return 0;
	for(int y0_2=y0;y0_2<=y2;y0_2++)
		if(mp[x2][y0_2]==1) return 0;
	for(int x1_2=x1;x1_2<=x3;x1_2++)
		if(mp[x1_2][y0]==1) return 0;
	return 1;
}

int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin>>t>>id;
	while(t--){
		ansc=ansf=0;
		cin>>n>>m>>c>>f;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				cin>>ch; mp[i][j]=ch-'0';
			}
		if(c==0&&f==0) cout<<0<<" "<<0<<endl;
		else{
			for(int x1=1;x1<=n;x1++)
				for(int x2=x1+2;x2<=n;x2++)
					for(int y0=1;y0<=m;y0++)
						for(int y1=y0+1;y1<=m;y1++)
							for(int y2=y0+1;y2<=m;y2++){
								if(check_c(x1,x2,y0,y1,y2)) ansc=(ansc+1)%mod;
								if(f!=0)
								for(int x3=x2+1;x3<=n;x3++)
									if(check_f(x1,x2,x3,y0,y1,y2)) ansf=(ansf+1)%mod;
							}
			cout<<((c*ansc)%mod)<<" ";
			if(f!=0) cout<<((f*ansf)%mod)<<endl;
			else cout<<0<<endl;
		}
	}
	return 0;
}
