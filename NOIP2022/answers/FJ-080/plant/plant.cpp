#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
int t,id,n,m;
ll ansc,ansf,l[1010][1010],r[1010][1010],c,f;
char s[1010][1010];
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>t>>id;
	while(t--){
		scanf("%d%d%lld%lld",&n,&m,&c,&f);
		ansc=0; ansf=0;
		for(int i=1;i<=n;i++){
			cin>>(s[i]+1);
		}
		memset(l,0,sizeof l);
		memset(r,0,sizeof r);
		for(int i=1;i<=n;i++){
			for(int j=m;j>=1;j--){
				if(s[i][j]=='0') l[i][j]=l[i][j+1]+1;
			}
		}
		for(int j=1;j<=m;j++){
			for(int i=n;i>=1;i--){
				if(s[i][j]=='0') r[i][j]=r[i+1][j]+1;
			}
		}
		/*for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<l[i][j]<<" ";
			} cout<<endl;
		}*/
		for(int j=1;j<=m-1;j++){
			ll o=0;
			for(int i=2;i<=n;i++){
				if(l[i][j]){
					ll u=((l[i][j]-1+mod)%mod)*o%mod;
					ansc=(ansc+u)%mod;
					ll p=(r[i][j]-1+mod)%mod;
					ansf=(ansf+u*p%mod)%mod;
					if(l[i-1][j]) o=(o+l[i-1][j]-1+mod)%mod;
				}
				else o=0;
			}
		}
		printf("%lld %lld\n",ansc*c%mod,ansf*f%mod);
	}
}
/*
2 1
4 3 1 1
111
111
111
111
16 12 1 1
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
*/

