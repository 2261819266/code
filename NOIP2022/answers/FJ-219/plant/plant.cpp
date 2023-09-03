#include<bits/stdc++.h>
#define f(i,n,m) for(int i=n;i<=m;i++)
using namespace std;
typedef pair<int,int> PII;
const int N = 1010;
const long long mods = 998244353;
int g[N][N];
int T,id;
int C,F; 
int n,m;
vector<PII>edge[N];
long long ans,ans2;

int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--){
		ans = ans2 = 0;
		for(int i=1;i<=n;i++) edge[i].clear();
		memset(g,0,sizeof g);
		scanf("%d%d%d%d",&n,&m,&C,&F);
		
		f(i,1,n){
		 char s[m+10];
		 scanf("%s",s);
		 for(int j=0;j<m;j++){
		 	g[i][j+1] = s[j] - '0';
		 }
		 for(int j=0;j<=m;j++){
				int k = j;
				while(!g[i][k+1] && k < m) k++;
				if(k == j || k == j + 1) continue;
				edge[i].push_back({j+1,k});
				//cout<<j+1<<" "<<k<<endl; 
				j = k;
			}
	}
	
	f(i,1,n-2){
		for(int j=0;j<edge[i].size();j++){        
			int y1 = edge[i][j].first, y2 = edge[i][j].second; 
			for(int k = i+2;k<=n;k++){
				for(int u=0;u<edge[k].size();u++){
					int y3 = edge[k][u].first,y4 = edge[k][u].second;
					if(y3 > y2-1) break;
					int yx = max(y1,y3);
					int yy = min(y2,y4);
					
					for(int i1=yx;i1<=yy-1;i1++){
						bool blag = false;
						for(int z = i+1;z<=k-1;z++){
							if(g[z][i1]){
								blag = true;
								break;
							}
						}
						if(blag == false){
							//cout<<"1"<<"---"<<i<<" "<<y1<<" "<<y2<<endl;
							//cout<<"2"<<"---"<<k<<" "<<y3<<" "<<y4<<endl;
							//cout<<endl;
							ans += (y2-i1)*(y4-i1);
							for(int p=k+1;p<=n;p++){
								if(!g[p][i1]) ans2 += (y2-i1)*(y4-i1);
								//cout<<i<<" "<<k<<endl;
								if(g[p][i1])break;
							}
						}
					}
				}
			}
		}	
	}
	printf("%lld %lld\n",((ans%mods)*C)%mods,((ans2%mods)*F)%mods);
}
	return 0;
}
