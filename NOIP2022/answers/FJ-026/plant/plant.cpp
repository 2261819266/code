#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int p=998244353;
int T,id;

int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d %d",&T,&id);
	while(T--){
		int n,m,c,f;
		scanf("%d %d %d %d",&n,&m,&c,&f);
		
		long long ansC=0,ansF=0;
		string a[1010];
		int add[1010][1010]={0},addf[1010][1010]={0};
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=m;j>=1;j--){
				if(a[i][j-1]=='0') add[i][j]=add[i][j+1]+1;
			}
		}
		for(int i=n;i>=1;i--){
			for(int j=1;j<=m;j++){
				if(a[i][j-1]=='0') addf[i][j]=addf[i+1][j]+1;
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=m;j++)
//				printf("%d ",addf[i][j]);
//			cout<<endl;
//		}
		for(int j=1;j<=m;j++){
			for(int l=1;l<=n-2;l++){
				if(add[l][j]==0 || add[l][j]==1 || add[l+1][j]==0) continue;
				for(int r=l+2;r<=n;r++){
					if(add[r][j]==0) break;
					if(add[r][j]==1) continue;
					int nadd=((add[r][j]-1)*(add[l][j]-1))%p;
					ansC+=nadd;
					ansC%=p;
					ansF+=(nadd*addf[r+1][j])%p;
					ansF%=p;
				}
			}
		}
		printf("%lld %lld\n",ansC*c,ansF*f);
	}
	return 0;
}
