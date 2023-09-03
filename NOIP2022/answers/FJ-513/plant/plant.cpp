#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1010;
const ll mod=998244353;
int T,id,n,m,c,f,s[N][N],lst;
bool a[N][N];
char z;
ll vc,vf,sum;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--){
		vc=vf=0;
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=1;i<=n;i++){
			getchar();
			for(int j=1;j<=m;j++){
				cin>>z;
				if(z=='1') a[i][j]=1;
				else a[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			s[i][m]=0;
			for(int j=m-1;j;j--){
				if(a[i][j+1]==0) s[i][j]=s[i][j+1]+1;
				else s[i][j]=0;
			}
			/*for(int j=1;j<=m;j++) cout<<s[i][j]<<" ";
			cout<<endl;*/
		}
		for(int j=1;j<=m;j++){//C
			lst=0;sum=0;
			for(int i=n;i;i--){
				if(a[i][j]==1){
					lst=0;
					sum=0;
				}
				else{
					if(!lst){
						lst=i;
						sum=s[i][j];
					}
					else{
						if(lst>i+1) vc=(vc+s[i][j]*(sum-s[i+1][j])%mod)%mod;
						sum+=s[i][j];
					}
				}
			}
		}
		for(int j=1;j<=m;j++){//F
			lst=0;sum=0;
			for(int i=n;i;i--){
				if(a[i][j]==1){
					lst=0;
					sum=0;
				}
				else{
					if(!lst){
						lst=i;
						sum=0;
					}
					else{
						if(lst>i+2) vf=(vf+s[i][j]*(sum-s[i+1][j]*(lst-i-1)%mod+mod)%mod)%mod;
						sum=(sum+s[i][j]*(lst-i)%mod)%mod;
					}
				}
			}
		}
		printf("%lld %lld\n",vc*c%mod,vf*f%mod);
	}
	return 0;
}