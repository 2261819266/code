#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+'0');
}
const int MOD=998244353;
ll a[1003][1003];
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	ll T=read(),id=read();
	while(T--){
		ll n=read(),m=read(),c=read(),f=read();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char ch=getchar();
				while(ch<'0'||ch>'9'){
					ch=getchar();
				}
				int t=ch-'0';
				a[i][j]=(t==0?1:0);
			}
		}
		if(id==1){
			write(0);
			putchar(' ');
			write(0);
			putchar('\n');
			continue;
		}
		for(int i=n;i>=1;i--){
			for(int j=m-1;j>=1;j--){
				if(a[i][j]==1){
					a[i][j]+=a[i][j+1];
				}
			}
		}
		ll ansC=0,ansF=0;
		for(int j=1;j<m;j++){
			int t=1;
			for(int i=1;i<=n;i++){
				if(a[i][j]==0){
					t=i+1;
					continue;
				}
				if((i==n||a[i+1][j]==0)&&t+2<=i){
					for(int k=t;k<=i-2;k++){
						for(int l=k+2;l<=i;l++){
							if(a[k][j]>=2&&a[l][j]>=2){
								ansC+=(a[k][j]-1)*(a[l][j]-1)%MOD;
								if(l<=i-1&&f!=0){
									ansF+=(a[k][j]-1)*(a[l][j]-1)%MOD*(i-l)%MOD;
								}
							}
						}
					}
				}
			}
		}
		write(ansC*c%MOD);
		putchar(' ');
		write(ansF*f%MOD);
		putchar('\n');
	}
	return 0;
}
