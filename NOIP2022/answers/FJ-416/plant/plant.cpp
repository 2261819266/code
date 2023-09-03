#include <bits/stdc++.h>
using namespace std;
#define p 998244353
int T,id,n,m,c,f,vc=0,vf=0,a[1000][1000],lr[1000][1000],ld[1000][1000];
bool ff(int aa,int b,int c){
	for(int l=aa;l<=b;l++){
		if(a[l][c]==1)return false;
	}
	return true;
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
    scanf("%d%d",&T,&id);
    while(T--){
    	vc=0;
    	vf=0;
    	memset(lr,-1,sizeof(lr));
    	memset(ld,-1,sizeof(ld));
    	scanf("%d%d%d%d",&n,&m,&c,&f);
    	for(int i=0;i<n;i++){
    		string s;
        	cin>>s;
    		for(int j=0;j<m;j++){
    	    a[i][j]=s[j]-'0';
			}
		}
		for(int i=0;i<n;i++){
        	for(int j=0;j<m;j++){
    		    for(int k=j;k<m;k++){
    		    	if(a[i][k]==1){
    	 	    		lr[i][j]=k-j-1;
    		    		if(k==j)lr[i][j]=-1;
    	 	    		break;
					}
				}
				if(lr[i][j]==-1&&!a[i][j])lr[i][j]=m-j-1;
				for(int k=i;k<n;k++){
					if(a[k][j]==1){
						ld[i][j]=k-i-1;
						if(k==i)ld[i][j]=-1;
						break;
					}
				}
				if(ld[i][j]==-1&&!a[i][j])ld[i][j]=n-i-1;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j+1<m;j++){
				if(!a[i][j]){
					for(int k=i+2;k<n;k++){
						if(ff(i,k,j)){
							vc+=(lr[i][j]*lr[k][j])%p;
			        	    vc%=p;
			         	    vf+=(lr[i][j]*lr[k][j]*ld[k][j])%p;
		   	        	    vf%=p;
						}
			    	    
				    }
				}
			}
		}
		printf("%d %d\n",c*vc,f*vf);
	}
	return 0;
}