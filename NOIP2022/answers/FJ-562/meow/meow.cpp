#include<bits/stdc++.h>
#include<vector>
using namespace std;
const int N=2e6;
int n,m,k;
int pai[N];
vector<int> a[305];
vector<int> b[305];
int now[N];
struct s{
	int x,y;
}jl[N];
int p;
void xw(){
	bool ok=true;
	int cs=0;
	while(ok&&cs!=1){
		ok=false;
		cs=0;
		for(int i=1;i<=n;i++){
			if(b[i].empty()!=0){
				cs++;
				ok=true;
				for(int j=i+1;j<=n;j++){
					if(b[j].empty())continue;
					if(b[i][b[i].size()-1]==b[j][b[j].size()-1]){
						b[i].pop_back();
						b[j].pop_back();
						p++;
						jl[p].x=i;
						jl[p].y=j; 
					}
				}
			}
		}	
	}

}
void xiao(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<b[i].size();j++){
			if(b[i][j]==b[i][j-1]){
				for(int q=j-1;q+2<b[i].size();q++){
					b[i][q]=b[i][q+2];
				}
				b[i].pop_back();
				b[i].pop_back();
				j-=2;
			}
		}
	}
	xw();
}
void fz(){
	for(int i=1;i<=n;i++){
		b[i]=a[i];
	}
}
void cl(int i){
	for(int j=1;j<=n;j++){
		a[j].push_back(pai[i]);
		now[i]=j;
		cl(i+1);
		a[j].pop_back();
	}
	if(i==m){
		fz();
		xiao();
		bool o=true;
		for(int j=1;j<=n;j++){
			if(b[j].empty()!=0){
				o=false;
				break;
			}
		}
		if(o==true){
			for(int j=1;j<=m;j++){
				printf("1 %d\n",now[j]);
			}
			for(int j=1;j<=p;j++){
				printf("2 %d %d",jl[j].x,jl[j].y);
			}
			exit(0);
		}
	}
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		p=0;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++){
			a[i].clear();
		}
		for(int i=1;i<=m;i++)scanf("%d",&pai[i]);
		cl(1);
	}
	return 0;
}
