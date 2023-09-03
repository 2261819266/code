#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int T,id;
const int N=1e4+100;
const int Mo=998244353;
int tu[N][N],dp[N][N],dx[N][N],dy[N][N];
int xqc,xqf;
int n,m;
int resx=0,resy=0;
int you(int i,int j){
	int z=0;
	for(;j<=m;j++){
		if(tu[i][j]==1)break;
		
		z++;
	}
	return max(z-1,0);
}
int xia(int i,int j){
	int z=0;
	for(;i<=n;i++){
		if(tu[i][j]==1)break;
		z++;
	} 
	return max(z-1,0);
}
int czc(){
	//int res=0;
	//第k列 开始遍历 
	for(int k=1;k<=m;k++){
		for(int i=1;i<=n;i++){
		
			for(int j=i+2;j<=n;j++){
				int nx1=0,nx2=0,ny1=0;
			
					if(j-i!=dy[j][k]-dy[i][k])continue;
					
					nx1=you(i,k);
					nx2=you(j,k);
					ny1=xia(j,k);
					resx=(resx+nx1*nx2)%Mo;
					resy=(resy+(nx1*nx2*ny1)%Mo)%Mo;
					//cout<<"i j x1 x2 "<<i<<" "<<j<<" "<<nx1<<" "<<nx2<<endl;
					//cout<<"res="<<res<<endl;
				}	
			
			}	
	} 
	
	return 0;
	
} 

int main(){
	
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--){
		resx=0,resy=0;
		scanf("%d%d%d%d",&n,&m,&xqc,&xqf);
		if(xqc==0&&xqf==0){
			printf("0 0\n");
			continue; 
		} 
		for(int i=1;i<=n;i++){
			string s;
			cin>>s;
			for(int j=0;j<s.size();j++){
				if(s[j]=='1')
				tu[i][j+1]=1;
			}
		}		

		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(tu[i][j]==1)continue;
				dx[i][j]=dx[i][j-1]+1;
				dy[i][j]=dy[i-1][j]+1;
			}
		}
		/*cout<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<dx[i][j]<<" ";
			}
			cout<<endl;
		
		}cout<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<dy[i][j]<<" ";
			}
			cout<<endl;
		}*/
		czc();
		LL ans1=(resx*xqc)%Mo;
		LL ans2=(resy*xqf)%Mo;
		//cout<<ans1<<" "<<ans2;
		printf("%d %d\n",ans1,ans2);
		
	}
	
	return 0;
}
