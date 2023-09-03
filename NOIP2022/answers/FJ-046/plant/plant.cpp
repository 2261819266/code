#include<bits/stdc++.h>
#define R register
using namespace std;
bool soil[1005][1005];
const int P=998244353;
char a;
int l,n,m,c,f,T,id;
int ansc,ansf,nowt,nowf;
inline void sear(int x,int y){
	if(soil[x][y]==1||soil[x+1][y]==1||soil[x][y+1]==1){
		if(y<m) sear(x,y+1);
		else sear(x+1,1);
	}
	for(R int i=n-x;i>=2;i--){
		if(l==1){l=0;continue;}
	    for(R int j=m-y;j>=1;j--){
	    	if(l==1) break;
	    	if(l==2) {l=0;continue;}
	        for(R int p=0;p<=i;p++){
	  	        if(l==1||l==2) break;
	 	        for(R int q=0;q<=j;q++){
	 		        if(soil[x+p][y+q]==1&&(q==0||(p==0&&q<j))){
	 		        	if(q==0||(p==0&&q<=1)) l=1;
	 		        	else l=2;
			        }
	 		        if(l==1||l==2) break;
	 		        if(soil[x+p][y+q]==0)
					 if(p==i&&q==j){
	 		        	nowt++;
	 		        	if(soil[x][y+q]==0&&j>=2) nowt++;
	 		        	ansc=(ansc+nowt)+P%P;
	 		        	if(x+p+1<=n&&soil[x+p+1][y]==0){
	 		        		for(R int u=1;x+p+u<=n;u++){
	 		        			if(soil[x+p+u][y]==0) nowf++;
							 }
	 		        		ansf=(ansf+nowt*nowf+P)%P;
						 }
						nowt=0;nowf=0;
					 }
	            }
            }
        }
    }
    if(x+1==n) return;
    if(y==m-1) sear(x+1,1);
    else if(y<m-1&&x+1<n) sear(x,y+1);
	return;
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>T>>id;
	for(R int z=1;z<=T;z++){
		ansc=0,ansf=0;
		cin>>n>>m>>c>>f;
		for(R int i=1;i<=n;i++)
		 for(R int j=1;j<=m;j++){
		 	cin>>a;
		 	if(a=='0') soil[i][j]=0;
		 	if(a=='1') soil[i][j]=1;
		 }
		sear(1,1);
		ansc=(ansc*c+P)%P;ansf=(ansf*f+P)%P;
		cout<<ansc<<" "<<ansf<<"\n";
	}
	return 0;
}
