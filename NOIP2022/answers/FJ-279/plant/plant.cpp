#include<bits/stdc++.h>
#define mod  (long long) 998244353
using namespace std;
struct nb{
	char s[1005];
}st[1005];
int t,id,n,m,r[1005][1005],d[1005][1005];
long long anc,anf,c,f;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&t,&id);
	for(int k=1;k<=t;k++){
		anc=0;anf=0;
		memset(d,0,sizeof(d));
		memset(r,0,sizeof(r));
		scanf("%d%d%lld%lld",&n,&m,&c,&f);
		for(int i=1;i<=n;i++)  	scanf("%s",st[i].s+1);
		for(int i=1;i<=n;i++){
			r[i][m]=0;
			for(int j=m-1;j>=1;j--){
				if(st[i].s[j+1]=='1'||st[i].s[j]=='1') r[i][j]=0;
				else r[i][j]=r[i][j+1]+1;
			}
		}  
		for(int j=1;j<=m;j++){
		    d[n][j]=0;
		    for(int i=n-1;i>=1;i--){
		    	if(st[i+1].s[j]=='1'||st[i].s[j]=='1') d[i][j]=0;
		    	else d[i][j]=d[i+1][j]+1;
			}
		}
		for(int i=1;i<n;i++){
			for(int j=1;j<n;j++){
				if(st[i].s[j]=='1') continue;
				for(int q=i+2;q-i<=d[i][j];q++){
					anc+=r[i][j]*r[q][j];anc=anc%mod;
					if(q-i<d[i][j]){
						anf+=r[i][j]*r[q][j]*(d[i][j]-(q-i));anf=anf%mod;
					} 
				}
			}
		}
		printf("%lld %lld\n",c*anc,f*anf);
	}
	return 0;
}
