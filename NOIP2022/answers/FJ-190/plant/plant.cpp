#include<bits/stdc++.h>

using namespace std;
const int Md=998244353;
const int N=1000+5;
int T,id;
int n,m;
char mp[N][N];
int C[N][N]={0};
long long ansc,tmp,ansf;
long long c,f;

void init(){
	memset(mp,0,sizeof(mp));
	memset(C,0,sizeof(C));
	ansc=0,ansf=0;
}

int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T>>id;
	while(T--){
		init();
		cin>>n>>m>>c>>f;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
			}
		for(int i=1;i<=n;i++){
			for(int j=m-1;j>=1;j--){
				if(mp[i][j+1]=='0'&&mp[i][j]=='0')
					C[i][j]=C[i][j+1]+1;
			}
		}
		if(c==0&&f==0){
			cout<<0<<" "<<0<<"\n";
			continue;
		}
		for(int i=3;i<=n;i++){
			for(int j=1;j<=m;j++){
				int gg=i;
				tmp=0;
				while(gg-1>=1&&mp[gg-1][j]=='0'){
					gg--;
					if(i-gg>1){
						ansc+=C[i][j]*C[gg][j];
						tmp+=C[i][j]*C[gg][j];
						ansc%=Md;
					}
				}
				int kk=i;
				while(kk+1<=n&&mp[kk+1][j]=='0')kk++;
				ansf+=(kk-i)*tmp;
				ansf%=Md;
			}
		}
		cout<<(ansc*c)%Md<<" "<<(ansf*f)%Md<<"\n";
	}
	
	return 0;
}
