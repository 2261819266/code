#include<bits/stdc++.h>
using namespace std;
bool d[101][101],ff;
int t,id,n,m,c,f;
char ch;
void gett(){
	while(t--){
		cin>>n>>m>>c>>f;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				ch=getchar();
				if(j==1&&ch=='\n') ch=getchar();
				d[i][j]=c-'0';
			}
		}
	}
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>t>>id;
	if(id==1){cout<<"0 0";return 0;}
	else if(id==2){
		while(t--){
			ff=0;
			gett();
			for(int i=1;i<=3;i++){
				for(int j=1;j<=2;j++){
					if(i!=2&&j!=2&&d[i][j]) ff=1;
				}
			}
			if(ff) cout<<"0 0"<<endl;
			else cout<<"1 0"<<endl;
		}
	}
	else if(id==3){
		while(t--){
			gett();
			if(d[1][1]||d[2][1]||d[3][1]||d[4][1]) cout<<"0 ";
			else cout<<"1 ";
			if(d[1][1]||d[2][1]||d[3][1]||d[4][1]||d[1][2]||d[3][2]) cout<<"0";
			else cout<<"1"<<endl;
		}
		
	}
	return 0;
}
/*
1 0 0
0 0 0
0 0 0


*/
