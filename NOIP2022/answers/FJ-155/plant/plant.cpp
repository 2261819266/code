#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX=1010,mod=998244353;
bool fi;
int T,id,n,m,c,f,ans1,ans2;
char a[MAX][MAX];
int dp1[MAX][MAX],dp2[MAX][MAX],sum[MAX][MAX],tot[MAX][MAX]; 
bool se;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-48; ch=getchar();}
	return x*f;
}
signed main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
//	cerr<<(&se-&fi)/1024.0/1024.0<<endl;
	T=read(),id=read();
	while(T--){
		memset(dp1,0,sizeof(dp1));
		memset(dp2,0,sizeof(dp2));
		memset(tot,0,sizeof(tot));
		memset(sum,0,sizeof(sum));
		ans1=0,ans2=0;
		n=read(),m=read(),c=read(),f=read();
		for(register int i=1; i<=n; i++)
		    scanf("%s",a[i]+1);
		for(register int i=1; i<=n; i++)
		    for(register int j=m; j>=1; j--)
			    dp1[i][j]=(a[i][j]=='1')?0:dp1[i][j+1]+1;
		for(register int i=1; i<=m; i++)
		    for(register int j=n; j>=1; j--)
			    dp2[j][i]=(a[j][i]=='1')?0:dp2[j+1][i]+1; 
        for(register int i=1; i<=m; i++){
        	for(register int j=n; j>=1; j--){
        		sum[j][i]=(a[j][i]=='1')?0:(sum[j+1][i]+dp1[j][i]-1)%mod;
			}
		}
		for(register int i=1; i<=m; i++){
        	for(register int j=n; j>=1; j--){
        		tot[j][i]=(a[j][i]=='1')?0:(tot[j+1][i]+(dp1[j][i]-1)*(dp2[j][i]-1)%mod)%mod;
			}
		}
//		for(register int i=1; i<=n; i++){
//		    for(register int j=1; j<=m; j++)
//		        cout<<sum[i][j]<<" ";
//		    puts("");
//		}
        if(c){
//        	cout<<"ok"<<endl;
            for(register int i=1; i<=m; i++){
        	    for(register int j=1; j<=n; j++){
        	    	    int k=j+2;
        	    		if(dp2[j][i]<k-j+1||dp1[j][i]<=1)
        	    		    continue;
        	    		if(sum[k][i]<=0)
        	    		    continue;
        	    		ans1=(ans1+(dp1[j][i]-1)*(sum[k][i])%mod)%mod;
					}
				}
		}
		if(f){
			for(register int i=1; i<=m; i++){
				for(register int j=1; j<=n; j++){
					    int k=j+2;
						if(dp2[j][i]<k-j+2||dp1[j][i]<=1||dp2[k][i]<=1)
						    continue;
						if(tot[k][i]<=0)
						    continue;
						ans2=(ans2+(dp1[j][i]-1)*(tot[k][i])%mod)%mod;
					}
				}
		}
		printf("%lld %lld\n",ans1%mod,ans2%mod);
	}
	return 0;
}
