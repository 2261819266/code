#include<bits/stdc++.h>
#define ll long long 
#define MAXN 1005
#define mod 998244353
using namespace std;
int T,id,n,m,sr[MAXN][MAXN],sd[MAXN][MAXN];
char a[MAXN][MAXN];
int sum[MAXN][MAXN];
ll vc,vf,c,f;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||'9'<ch){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline ll llread(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||'9'<ch){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	T=read(),id=read();
	while(T--){
		//item!!
		n=read(),m=read(),c=read(),f=read();
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=m;j>=1;j--)
				a[i][j]=a[i][j-1];
		}
		for(int i=1;i<=n;i++){
			for(int j=m;j>=1;j--){
				if(a[i][j+1]=='0'){
					sr[i][j]=sr[i][j+1]+1;//cout<<i<<" "<<j<<" "<<sr[i][j]<<endl;
				}
			}
		}//cout<<endl;
		for(int i=1;i<=m;i++){
			for(int j=n;j>=1;j--){
				if(a[j+1][i]=='0'){
					sd[j][i]=sd[j+1][i]+1;//cout<<j<<" "<<i<<" "<<sd[j][i]<<endl;
				}
			}
		}//cout<<endl;
		for(int j=1;j<=m;j++){
			int lst=0;
			for(int i=1;i<=n;i++){
				sum[i][j]=sum[i-1][j]+sr[i][j];
				if(a[i][j]=='0'&&lst+3<=i){
					vc=(vc+sr[i][j]*1ll*(sum[i-2][j]-sum[lst][j])%mod)%mod;
					vf=(vf+(sr[i][j]*1ll*(sum[i-2][j]-sum[lst][j])%mod)*sd[i][j]%mod)%mod;//cout<<i<<" "<<j<<" "<<vc<<endl;
				}
				if(a[i][j]=='1') lst=i;
			}
		}
		printf("%lld %lld\n",1ll*c*vc%mod,1ll*f*vf%mod);
		vc=0;vf=0;
		for(int i=0;i<=n+1;i++)
		    for(int j=0;j<=m+1;j++){
		  		a[i][j]='\0';
		  		sum[i][j]=0;
		  		sr[i][j]=0;
		  		sd[i][j]=0;
		 	}
	}
	return 0 ;
}
