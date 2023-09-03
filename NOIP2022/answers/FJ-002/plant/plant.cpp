#include<bits/stdc++.h>
using namespace std;
string a[1005]={{1}};
bool b[1055][1055]={1};
bool cc[1055][1055]={1};
int ansc,ansf;
long long n,m,T,id,c,f;
int dfsc(int x,int y){
	int le,ll[1005]={0};
	if(a[x][y+1]!=1&&a[x+1][y]!=1&&a[x+2][y]!=1){
		le=1;
		for(int i=y+2;i<=m;i++){
			if(a[x][i]!=1){
				le++;
			}else{
				break;
			}
		}		
		for(int j=x+2;j<=n;j++){
			if(a[j][y]==0){
				for(int k=y+1;k<=m;k++){
					if(a[j][k]!=1){
						ll[j]++;
					}else{
						break;
					}
				}
			}else{
				break;
			}
		}
		b[x][y]=1;
		for(int i=1;i<=n;i++){
			if(ll[i]>0){
				ansc+=le*ll[i];
			}
		}
	}else{
		if(b[x+1][y]==0){
			dfsc(x+1,y);
		}else if(b[x-1][y]==0){
			dfsc(x+1,y);
		}else if(b[x][y+1]==0){
			dfsc(x,y+1);
		}else if(b[x][y-1]==0){
			dfsc(x,y-1);
		}else if(b[x+1][y]==1&&b[x-1][y]==1&&b[x][y+1]==1&&b[x][y-1]==1){
			return ansc;
		}
	}
}
int dfsf(int x,int y){
	long long le,ll[1005]={0},lll[1005]={0};
	if(a[x][y+1]!=1&&a[x+1][y]!=1&&a[x+2][y]!=1){
		le=1;
		for(int i=y+2;i<=m;i++){
			if(a[x][i]!=1){
				le++;
			}else{
				break;
			}
		}		
		for(int j=x+2;j<=n;j++){
			if(a[j][y]==0){
					for(int k=(y+1);k<=m;k++){
						if(a[j][k]!=1){
							ll[j]++;
						}else{
							break;
						}
					}
					if(a[j+1][y]!=1){
						for(int g=j+1;g<=n;g++){
							if(a[g][y]!=1){
								lll[j]++;
							}else{
								break;
							}
					}
					}
			}else{
				break;
			}
		}
		cc[x][y]=1;
		for(int i=1;i<=n;i++){
			if(ll[i]>0){
				ansf+=le*ll[i]*lll[i];
			}
		}
	}else{
		if(cc[x+1][y]==0){
			dfsf(x+1,y);
		}else if(cc[x-1][y]==0){
			dfsf(x+1,y);
		}else if(cc[x][y+1]==0){
			dfsf(x,y+1);
		}else if(cc[x][y-1]==0){
			dfsf(x,y-1);
		}else if(cc[x+1][y]==1&&cc[x-1][y]==1&&cc[x][y+1]==1&&cc[x][y-1]==1){
			return ansf;
		}
	}
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	std::cin>>T>>id;
	while(T!=0){
		std::cin>>n>>m>>c>>f;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				std::cin>>a[i][j];
				if(a[i][j]==0){
					b[i][j]=0;
					cc[i][j]=0;
				}
			}
		}
			std::cout<<(dfsc(1,1)*c)%998244353<<" "<<(dfsf(1,1)*f)%998244353<<endl;
			ansc=0;
			ansf=0;
			b[1005][1005]={1};
			cc[1005][1005]={1};
			T--;
	}
	return 0;
}
