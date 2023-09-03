#include<bits/stdc++.h>
using namespace std;
int t,id,m,n,c,f,vc,vf;
int gt[1005][1005];

int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>t>>id;
	for(;t>0;t--){
		vc=vf=0;
		cin>>n>>m>>c>>f;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				char ingt;
				cin>>ingt;
				gt[i][j]=ingt-'0';
			}
		}
		if(c)for(int j=0;j<m-1;j++){
			for(int i=0;i<n;i++){
				for(int k=i+2;k<n;k++){
					int cc=j,ff=j;
					if(gt[i+1][j]||gt[k][j]||gt[i][j+1]||gt[i][j]){
						break;
					}
						while((!gt[i][cc])&&cc<m)cc++;
						while((!gt[k][ff])&&ff<m)ff++;
						vc+=(cc-j-1)*(ff-j-1);
				}
				vc%=998244353;
			}
		}
		if(f)for(int j=0;j<m-1;j++){
			for(int i=0;i<n;i++){
				for(int k=i+2;k<n;k++){
					int cc=j,ff=j,ll=k;
					if(gt[i+1][j]||gt[k][j]||gt[i][j+1]||gt[i][j]){
						break;
					}
						while((!gt[i][cc])&&cc<m)cc++;
						while((!gt[k][ff])&&ff<m)ff++;
						while((!gt[ll][j])&&ll<n)ll++;
						vf+=(cc-j-1)*(ff-j-1)*(ll-k-1);
				}
				vc%=998244353;
			}
		}
	cout<<vc<<" "<<vf<<endl;
	}
	return 0;
}
