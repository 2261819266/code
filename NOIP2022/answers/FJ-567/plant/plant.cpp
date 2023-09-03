#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
const int MAXN=1010;
bool map_[MAXN][MAXN];
bool flag[MAXN][MAXN];
int jishu[MAXN][MAXN][2];//0-->heng,1-->shu
int n,m,c,f;
long long ans,ans1;
void suanc(int x,int y){
	if(x>=n-1||y>=m)return;
	if(flag[x][y]==1||map_[x][y]==1)return;
	flag[x][y]=1;
	int cnt=0;
	for(int i=x+2;i<x+jishu[x][y][1];i++){
		if(map_[x][y]==1)break;
		cnt+=jishu[i][y][0]-1;
		cnt%=mod;
	}
	for(int i=1;i<=cnt;i++){
		ans+=jishu[x][y][0]-1;
		ans%=mod;
	}
}



void suanf(int x,int y){
	if(x>=n-1||y>=m)return;
	if(flag[x][y]==1||map_[x][y]==1)return;
	flag[x][y]=1;
	int cnt=0;
	for(int i=x+2;i<x+jishu[x][y][1];i++){
		if(map_[x][y]==1)break;
		if(jishu[i][y][1]==1)break;
		cnt+=(jishu[i][y][0]-1)*(jishu[i][y][1]-1);
		cnt%=mod;
	}
	for(int i=1;i<=cnt;i++){
		ans1+=jishu[x][y][0]-1;
		ans1%=mod;
	}
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0),cout.tie(0);
	int t,id;
	cin>>t>>id;
	cin>>n>>m>>c>>f;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char x;
			cin>>x;
			map_[i][j]=x-'0';
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=m;j>=1;j--){
			if(map_[i][j]==1){
				jishu[i][j][0]=0;
			}
			else{
				jishu[i][j][0]=jishu[i][j+1][0]+1;
			}
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=m;j>=1;j--){
			if(map_[i][j]==1){
				jishu[i][j][1]=0;
			}
			else{
				jishu[i][j][1]=jishu[i+1][j][1]+1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			suanc(i,j);
		}
	}
	cout<<ans*c<<" ";
	memset(flag,0,sizeof(flag));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			suanf(i,j);
		}
	}
	cout<<ans1*f;
	return 0;
}