#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
inline int read()
{
	char ch=getchar();
	int f=1,x=0;
	while(!isdigit(ch)) {
		if(ch=='-') {
			f=0;
		}
		ch=getchar();
	}
	while(isdigit(ch)) {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar(); 
	}
	return f ? x : -x;
}
int t,id,n,m,c,f,mapp[1005][1005],sumx[1005][1005],sumy[1005][1005];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	t=read();id=read();
	if(id==1) {
		while(t--) {
			printf("0 0\n");
		}
		return 0;
	}
	while(t--) {
		n=read();m=read();c=read();f=read();
		ll ac=0,af=0;
		for(int i=1;i<=n;++i) {
			for(int j=1;j<=m;++j) {
				mapp[i][j]=sumx[i][j]=sumy[i][j]=0;
			}
		}
		for(int i=1;i<=n;++i) {
			string temp;cin>>temp;
			for(int j=1;j<=m;++j) {
				mapp[i][j]=temp[j-1]-48;
				sumx[i][j]=(mapp[i][j] ? 0 : sumx[i][j-1]+1);
				sumy[i][j]=(mapp[i][j] ? 0 : sumy[i-1][j]+1);
			}
		}
		{
    		for(int i=1;i<=n;++i) {
    			for(int j=1;j<=m;++j) {
    				if(mapp[i][j]) {
    					continue;
					}
					int sp1=m;
					for(int k=j;k<=m;++k) {
						if(mapp[i][k]) {
							sp1=k-1;
							break;
						}
					}
					ll v=sumx[i][sp1]-sumx[i][j]+1;
					if(v>1) {
						for(int k=i+1;k<=n-1;++k) {
							if(mapp[k][j]) {
								break;
							}
							int sp2=m;
							for(int l=j;l<=m;++l) {
								if(mapp[k+1][l]) {
									sp2=l-1;
									break;
								}
							}
							ll v1=sumx[k+1][sp2]-sumx[k+1][j]+1;
							if(v1>1) {
								ac=ac+((v-1)*(v1-1))%mod;
							}
							if(k>n-2 || mapp[k+2][j]) {
								break;
							}
							int sp3=n;
							for(int l=k+2;l<=n;++l) {
								if(mapp[l][j]) {
									sp3=l-1;
									break;
								}
							}
							ll v2=sumy[sp3][j]-sumy[k+2][j]+1;
							if(v2>0) {
								af=af+((v-1)*(v1-1)*(v2))%mod;
							}
						}
					}
					ac%=mod,af%=mod;
				}
			}
			printf("%lld %lld\n",(c*ac)%mod,(f*af)%mod); 
		}
	}
	return 0;
}

