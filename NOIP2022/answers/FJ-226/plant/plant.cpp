#include <bits/stdc++.h>
#define maxn 1010
#define MOD 998244353
using namespace std;
int Tt,id;
int n,m,c,f;
char mapp[maxn][maxn];
int T[maxn][maxn],L[maxn][maxn];
long long ansc,ansf;
int task(int j,int q){
	int tmp=1;
	while(1){
		if(T[q][tmp]>=j){
			return tmp;
		}
		tmp++;	
	}
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&Tt,&id);
	while(Tt--){
		scanf("%d%d%d%d",&n,&m,&c,&f);
		getchar();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%c",&mapp[i][j]);
			}
			getchar();
		}
		if(c==0&&f==0){
			cout<<0<<" "<<0;
			continue;
		}
		for(int i=1;i<=n;i++){
			int tmp=0;
			for(int j=1;j<=m;j++){
				if(mapp[i][j]=='1'){
					T[i][++tmp]=j-1;
				}
			}
			T[i][tmp+1]=m;
		}
		for(int j=1;j<=n;j++){
			int tmp=0;
			for(int i=1;i<=n;i++){
				if(mapp[i][j]=='1'){
					L[j][++tmp]=i-1;
				}
			}
			L[j][tmp+1]=n;
		}
		for(int j=1;j<m;j++){
			int e=1,tmp=1;
			while(L[j][tmp]-e<=1){
				e=L[j][tmp++]+2;
			}
			for(int tt=e;tt<=L[j][tmp]-2;tt++){
				long long sum=0;
				e=tt+2;
				for(;e<=L[j][tmp];e++){
					sum+=(T[e][task(j,e)]-j)%MOD;
				}
				ansc+=(sum*(T[tt][task(j,tt)]-j))%MOD;
				ansc%=MOD;
			}
		}
		cout<<ansc<<" "<<0<<endl;
	}
	return 0;
}
