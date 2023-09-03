#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,id,n,m,c,f,a[1001][1001],cntc=0,cntf=0;
	cin>>T;
	for(int k=0;k<T;k++){
		cin>>n>>m>>c>>f;
	    for(int i=0;i<n;i++){
	    	for(int j=0;j<m;j++){
		        cin>>a[i][j];
			}
	    }
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]==0&&a[i][j]){
				for(int k=j;k<=m;k++){
					if(a[i][k]==1){
						break;
					}
					for(int l=i+2;l<=n-2;l++){
						if(a[l-2][0]==1||a[l-1][0]==1){
							break;
						}
						for(int o=1;o<=m;o++){
							if(a[l][o]==0){
								cntc++;
							}else{
								break;
							}
						}
					}
					for(int u=i+3;u<n;u++){
					    for(int l=i+2;l<=u-1;l++){
						    for(int o=1;o<=m;o++){
							    if(a[l][o]==0){
							    	cntf++;
							    }else{
							    	break;
								}
						    }
					    }
					}
				}
			}
		}
	}
	cout<<cntc<<" "<<cntf;
	return 0;
}
