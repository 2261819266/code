#include<bits/stdc++.h>
using namespace std;
int main(){
	
	std::ios::sync_with_stdio(false);
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,di,n,m,c,d,e,f;
	int  ans1=0,bns=0;
	char a[1010][1010];
	cin>>T>>di>>n>>m>>c>>f;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			d=j;
			e=i;
			if(a[e][d]=='0' and a[e+1][d]=='0' and a[e][d+1]=='0' and a[e][d+2]=='0') {
				int right1=0,right2=0,down=0,pl=0;
				for(int k=e;k<=n;k++){if(a[k][d]=='0')right1++;
											else break;
				}
				for(int k=d;k<=m;k++){if(a[e][k]=='0')down++;
				else break;
				}
				for(int k=d+2;k<=down;k++){
					
					if(a[e+1][k]=='0'){for(int l=e;l<=n;l++){
						if(a[l][k]=='0')right2++;
						else break;
					}
					if(a[e][k+1]=='0' and a[e+1][k]=='0'){
						pl=down-k;
						}
						bns=bns+(pl)*(right1)*(right2);
					}
					ans1+=(right1)*(right2);
					
				}
				
			}									
			}
		}
	
	cout<<c*ans1%998244353<<" "<<c*ans1/2%998244353;
	return 0;
}
