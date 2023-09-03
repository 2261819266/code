#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
string s;
int n,m,c,f,t,id,i,j,k,flower[1005][1005],x1[2],x2,x3,y,y2;
long long ansc=0,ansf=0;
int main() {
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>t>>id;
	for(i=1; i<=t; i++) {
		cin>>n>>m>>c>>f;
		if(c==0&&f==0) {
			cout<<"0 0"<<endl;
		} else {
			for(j=1; j<=n; j++) {
				cin>>s;
				for(k=0; k<m; k++) {
					flower[k+1][j]=s[k]-'0';
				}
			}
			x1[1]=x1[2]=1;
			while(flower[x1[1]][x1[2]]==1&&x1[1]<m) {
				x1[1]++;
				if(x1[1]>=n) {
					x1[1]=1;
					x1[2]++;
				}
			}
			while(x1[2]<=n-2) {
				y=x1[1];
				while(flower[y+1][x1[2]]==0&&y<m) {
					y++;
				}
				x3=x1[2];
				while(flower[x1[1]][x3+1]==0&&x3<n) {
					x3++;
				}
				for(j=x1[2]+2; j<x3; j++) {
					y2=x1[1];
					while(flower[y2+1][j]==0&&y2<m) {
						y2++;
					}
					ansc+=(y-x1[1])*(y2-x1[1]);
					ansf+=(y-x1[1])*(y2-x1[1])*(x3-j);
				}
				y2=x1[1];
				while(flower[y2+1][x3]==0&&y2<m) {
					y2++;
				}
				ansc+=(y-x1[1])*(y2-x1[1]);
				ansc=ansc%mod;
				ansf=ansf%mod;
				x1[1]=y+2;
				if(x1[1]>=n) {
					x1[1]=1;
					x1[2]++;
				}
				while(flower[x1[1]][x1[2]]==1&&x1[1]<m) {
					x1[1]++;
					if(x1[1]>=n) {
						x1[1]=1;
						x1[2]++;
					}
				}
			}
			cout<<c*ansc<<" "<<f*ansf<<endl;
		}
	}
	return 0;
}
