#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
long long Mod=998244353;
long long t,id,n,m,c,f,r[2000][2000],k,tail;
long long sc,ansc,sf,ansf;
char ch;
bool a[2000][2000];
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>t>>id;
	while(t--){
		cin>>n>>m>>c>>f;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>ch;
				a[i][j]=(ch=='0');
			}
		}
		if(!c&&!f){
			cout<<0<<' '<<0<<endl;
			continue;
		}
		memset(r,-1,sizeof(r));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(r[i][j]!=-1)continue;
				if(a[i][j]){
					for(k=j+1;k<=m&&a[i][k];k++){}
					r[i][--k]=0;
					k--;
					for(;k>=j;k--){
						r[i][k]=r[i][k+1]+1;
					}
				}
			}
		}
		/*for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<r[i][j]<<' ';
			}
			cout<<endl;
		}*/
		ansc=sc=0;
		if(c){
			for(int j=1;j<=m;j++){
				for(int i=n;i>=1;i--){
					if(a[i][j]){
						if(a[i+1][j]){
							ansc+=sc*r[i][j]%Mod;
							ansc%=Mod;
							//if(sc*r[i][j])cout<<i<<' '<<j<<' '<<sc<<' '<<ansc<<endl;
							sc+=r[i+1][j];
							sc%=Mod;
						}
					}
					else{
						sc=0;
					}
				}
				sc=0;
			}
		}
		cout<<ansc<<' ';
		ansf=sf=0;
		tail=-1;
		if(f){
			for(int j=1;j<=m;j++){
				for(int i=n;i>=1;i--){
					if(a[i][j]){
						if(tail==-1)tail=i;
						if(a[i+1][j]){
							ansf+=sf*r[i][j]%Mod;
							ansf%=Mod;
							//if(sf*r[i][j])cout<<i<<' '<<j<<' '<<sf<<' '<<ansf<<endl;
							sf+=r[i+1][j]*(tail-i-1)%Mod;
							sf%=Mod;
						}
					}
					else{
						sf=0;
						tail=-1;
					}
				}
				sf=0;
				tail=-1;
			}
		}
		cout<<ansf<<endl;
	}
	return 0;
}
/*
2 0
16 12 0 1
000000000001
011111111111
000000000011
011111111111
010011111111
010111100011
010011101111
011111100011
111111111111
000011111111
011111111111
000000111111
011111000111
011111011111
011111000111
011111011111
6 6 1 1
000010
011000
000110
010000
011000
000000
*/
