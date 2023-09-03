#include<bits/stdc++.h>
using namespace std;

int t,id,n,m,c,f,vc=0,vf=0,a[1010][1010];
string s[1010];
int hang(int x,int y,int yy){
	for(int i=y;i<=yy;i++){
		if(a[x][i]==1) return -1;
	}
	return 1;
}
int lie(int y,int x,int xx){
	for(int i=x;i<=xx;i++){
		if(a[i][y]==1) return -1;
	}
	return 1;
}

int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>t>>id;
	while(t--){
		vc=0,vf=0;
		cin>>n>>m>>c>>f;
		for(int i=1;i<=n;i++){
			cin>>s[i];
			for(int j=0;j<s[i].size();j++){
				a[i][j+1]=s[i][j]-'0';
			}
		} 
		if(c!=0){
			for(int x1=1;x1<=n-2;x1++){
				for(int x2=x1+2;x2<=n;x2++){
					for(int y0=1;y0<=m-1;y0++){
						if(a[x1][y0]==1||a[x2][y0]==1) break;
						if(lie(y0,x1,x2)==-1) break;
						for(int y1=y0+1;y1<=m;y1++){
							if(a[x1][y1]==1) break;
							if(hang(x1,y0,y1)==-1) break;
							for(int y2=y0+1;y2<=m;y2++){
								if(a[x2][y2]==1) break;
								if(hang(x2,y0,y2)==1){
									vc++;
								}
							}
						}
					}
				}
			}
		}
		cout<<(c*vc)%998244353<<" ";
		if(f!=0){
			for(int x1=1;x1<=n-3;x1++){
				for(int x2=x1+2;x2<=n-1;x2++){
					for(int x3=x2+1;x3<=n;x3++){
						for(int y0=1;y0<=m-1;y0++){
							if(a[x1][y0]==1||a[x2][y0]==1) break;
							if(lie(y0,x1,x3)==-1) break;
							for(int y1=y0+1;y1<=m;y1++){
								if(a[x1][y1]==1) break;
								if(hang(x1,y0,y1)==-1) break;
								for(int y2=y0+1;y2<=m;y2++){
									if(a[x2][y2]==1) break;
									if(hang(x2,y0,y2)==1){
										vf++;
									}
								}
							}
						} 
					}
				}
			} 
		}
		cout<<(f*vf)%998244353<<endl;
	}
	return 0;
} 
//998244353
