#include<bits/stdc++.h>
#define For(i,a,b) for(int i(a);i<=b;++i)
#define foR(i,a,b) for(int i(a);i>=b;--i)
#define int long long
using namespace std;
const int Mod=998244353;
int n,m,T,idd,c,f,b[1008][1008],d[1008][1008];
int ansc,ansf;
bool a[1008][1008];
string s;
void dfsc(int x,int y){
	if(a[x+1][y]==1)return ;
	For(i,x+2,n){
		if(a[i][y]==1)return ;
		if(b[i][y]==1)continue;
//		cout<<i<<" "<<y<<"!\n";
		ansc=(ansc+(b[x][y]-1)*(b[i][y]-1)%Mod)%Mod;
	}
}
void dfsf(int x,int y){
	if(a[x+1][y]==1||a[x+2][y]==1)return ;
	For(i,x+2,n-1){
		if(a[i][y]==1||a[i+1][y]==1)return ;
		if(b[i][y]==1)continue;
		ansf=(ansf+(b[x][y]-1)*(b[i][y]-1)%Mod*d[i+1][y]%Mod)%Mod;
	}
}
signed main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>T>>idd;
	while(T--){
		ansc=0;ansf=0;
		cin>>n>>m>>c>>f;
		For(i,1,n){
			cin>>s;s="!"+s;
			For(j,1,m)a[i][j]= s[j]=='1';
		}
		For(i,1,n){
			b[i][m+1]=0;
			foR(j,m,1){
				if(a[i][j]==1)b[i][j]=0;
				else b[i][j]=b[i][j+1]+1;
			}
		}
		For(j,1,m){
			d[n+1][j]=0;
			foR(i,n,1){
				if(a[i][j]==1)d[i][j]=0;
				else d[i][j]=d[i+1][j]+1;
			}
		}
		if(c!=0)
		For(i,1,n-2){
			For(j,1,m){
				if(b[i][j]>=2)
//				cout<<i<<" "<<j<<"AAQ\n",
				dfsc(i,j);
			}
		}
		if(f!=0)
		For(i,1,n-3){
			For(j,1,m){
				if(b[i][j]>=2)
				dfsf(i,j);
			}
		}
		cout<<(c*ansc)%Mod<<" "<<(f*ansf)%Mod<<endl;
	}
}
