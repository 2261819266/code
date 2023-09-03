#include<bits/stdc++.h>
using namespace std;
#define mod  998244353
const int N=1e3+5;
int T,id,n,m,c,f,siz[N],sum[N];
long long ansc,ansf;
bool a[N][N];
struct Node{
	int x,y,size;
};
struct Node2{
	int l,r,len;
};
struct Node3{
	int size,x;
};
vector<Node>vec[N];
vector<Node2>vec2[N];
vector<Node3>vec3,vec4;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--){
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				char c;cin>>c;
				a[i][j]=c-'0';
			}
		if(c==0&&f==0){
			printf("%d %d\n",0);
			continue;
		}
		ansc=0;ansf=0;
		for(int i=1;i<=m+1;i++)a[n+1][i]=1;
		for(int i=1;i<=n+1;i++)a[i][m+1]=1;
		for(int j=1;j<m;j++){//Ñ°ÕÒÒ»Êú 
			int count=0,stx,sty;
			for(int i=1;i<=n+1;i++){
				if(a[i][j]==1){
					if(a[i-1][j]==0){
						if(count>2){
							vec[j].push_back((Node){stx,i-1,count});
						}
					}
					count=0;
					continue;
				}
				count++;
				if(count==1)stx=i;
			}
		}
		for(int i=1;i<=n;i++){//Ñ°ÕÒÒ»ºá 
			int count=0;
			for(int j=1;j<=m+1;j++){
				if(a[i][j]==1){
					if(a[i][j-1]==0){
						if(count>1)vec2[i].push_back((Node2){j-count,j-1,count});
					}
					count=0;
					continue;
				}
				count++;
			}
		}
		for(int j=1;j<m;j++){
			for(auto v:vec[j]){
				vec3.clear();
				vec4.clear();
				int tot=0;
				for(int k=v.x;k<=v.y;k++)
					for(auto x:vec2[k]){
						if(x.l<=j&&x.r>=j){
							vec3.push_back((Node3){x.r-j,k});
							if(k!=v.y)vec4.push_back((Node3){x.r-j,k});
							tot+=(x.r-j);
						}
					}
				for(auto k:vec3)
					for(auto jk:vec3){
						if(k.x>=jk.x)continue;
						if(jk.x-k.x==1)continue;
						ansc=(ansc+(k.size)*(jk.size)%mod)%mod;
						
					}
				for(auto k:vec4)	
					for(auto jk:vec4){
						if(k.x>=jk.x)continue;
						if(jk.x-k.x==1)continue;
						//printf("%d %d %d %d\n",k.x,k.size,jk.x,jk.size);
						ansf=(ansf+k.size*jk.size%mod*(v.y-jk.x)%mod)%mod;
					}
			}
		}
		printf("%lld %lld\n",ansc*c%mod,ansf*f%mod);
	}
	return 0;
}
