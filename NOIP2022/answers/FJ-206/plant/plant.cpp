#include<bits/stdc++.h>
using namespace std;
const long long Mod=998244353;
int n,m;
int T,id;
int c,f;
long long ans_c;
long long ans_f;
char a; 
int mp[3000][3000];
long long d[3000][3000];
long long p[3000][3000];

void print(){
	
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				cout<<d[i][j]<<" ";
			}
			cout<<endl;
		}
		
		cout<<endl<<endl;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				cout<<p[i][j]<<" ";
			}
			cout<<endl;
		}
		return;
}
void deal(){
	int x1,x2,yt;
	long long g=0;
	ans_c=0;
	ans_f=0;
	for(x1=1;x1<=n;++x1){
		for(yt=1;yt<=m;++yt){
			if(mp[x1][yt]==1||d[x1][yt]==0)continue;
			//cout<<"X1: "<<x1<<"Y: "<<yt<<endl;
			for(x2=2;x2<=(p[x1][yt]-1);++x2){
			//	cout<<"X2: "<<x2+x1<<endl;
			//	cout<<"Cj: "<<((d[x1][yt]-1)*(d[x1+x2][yt]-1))%Mod<<" ";
				if(p[x1][yt]-1-x2<0)g=0;
				else g=p[x1][yt]-1-x2;
			//	cout<<"Fj: "<<((((d[x1][yt]-1)*(d[x1+x2][yt]-1))%Mod)*g)%Mod<<endl;
				ans_c+=((d[x1][yt]-1)*(d[x1+x2][yt]-1))%Mod;
				ans_c%=Mod;
				ans_f+=((((d[x1][yt]-1)*(d[x1+x2][yt]-1))%Mod)*g)%Mod;
				ans_f%=Mod;
			}
		}
	}
	return;
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>T>>id;
	for(int ti=1;ti<=T;++ti){
		cin>>n>>m>>c>>f;
		
		memset(mp,0,sizeof(mp));
		memset(d,0,sizeof(d));
		memset(p,0,sizeof(p));
		
	    for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>a;
			if(a=='1'){
				mp[i][j]=1;
			}
		}
	   }
		
		for(int i=1;i<=n;++i){
			for(int j=m;j>=0;--j){
				if(mp[i][j]==0)d[i][j]=d[i][j+1]+1;
				else d[i][j]=0;
			}
		}
		
		
		for(int i=n;i>=1;--i){
			for(int j=1;j<=m;++j){
				if(mp[i][j]==0)p[i][j]=p[i+1][j]+1;
				else p[i][j]=0;
			}
		}

		deal();
		cout<<(ans_c*c)%Mod<<" "<<(ans_f*f)%Mod<<endl;
	}
	return 0; 		 
}
