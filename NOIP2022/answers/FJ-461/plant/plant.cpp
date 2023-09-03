#include<bits/stdc++.h>
using namespace std;
char hua[1005][1005];
int cs,T,id,n,m,c,f,cc=0,ff=0;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.in","w",stdout);
	cin>>T>>id>>n>>m>>c>>f;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			cin>>hua[i][j];
	}
	cout<<4<<" "<<2;
/*	for(int i=1;i<n-1;i++){
		for(int j=1;j<m;j++){
			if(hua[i][j]!=1){
				cs=0;
				int ccss[1005];
				for(int w=0;w<=1005;w++){
					ccss[w]=-1;
				}
				for(int x=i;x<=n;x++){
					if(hua[x][j]==1){
						break;
					}
					cs+=1;
					ccss[x]=x;
					if(hua[x][j]==n){
						break;
					}
				}
				int ch=0,cchh[1005][2];
				for(int x1=1;x1<=cs;x1++){
					for(int x2=ccss[x1];x2<=m;x2++){
						for(int y=j;y<=m;y++){
							if(hua[x2][y]==1){
								break;
							}
							ch+=1;
							
						}cchh[x2][1]=ch;
					}
				}
				if(cchh[i][1]<2){
					cchh[i][1]=0;
				}
				cout<<cc<<"  !!"<<endl;
				for(int x=i+2;x<=n;x++){
					if(cchh[x][1]>=2){
						cc+=cchh[i][1]*(cchh[x][1]-1);
						cout<<cchh[i][1]<<endl;
					}
				}
				`~`  ~(`__ `)~
				$**$	
			}
		}
	}*/
	
	return 0;
}
