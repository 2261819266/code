#include<cstdio>
#include<iostream>
using namespace std;
inline int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}
int n,m,c,f,t,id,a[1005][1005],hang[1005][1005],lie[1005][1005];
long long ans1,ans2,mod=998244353;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	t=read(),id=read();
	while(t--){
		n=read(),m=read(),c=read(),f=read();
		ans1=0,ans2=0;
		char ch=getchar();
		for(register int i = 1;i<=n;i++){
			for(register int j = 1;j<=m;j++){
				while(ch<'0'||ch>'1')ch=getchar();
				a[i][j]=ch^48;
				ch=getchar();
			}
		}
		for(register int i = 1;i<=n;i++){
			hang[i][m+1]=m+1;
			for(register int j = m;j;j--){
				if(a[i][j])hang[i][j]=j;
				else hang[i][j]=hang[i][j+1];
			}
		}
		for(register int j = 1;j<=m;j++){
			lie[n+1][j]=n+1;
			for(register int i = n;i;i--){
				if(a[i][j])lie[i][j]=i;
				else lie[i][j]=lie[i+1][j];
			}
		}
		long long sum1,sum2,cheng;
		for(register int j = 1;j<=m;j++){
			for(register int i = 1;i<=n;i=lie[i][j]+1){
				sum1=0,sum2=0,cheng=0;
				for(register int k = i;k<lie[i][j];k++){
					sum1+=hang[k][j]-j-1;
					sum2+=(hang[k][j]-j-1)*(hang[k][j]-j-1);
					if(k!=i)cheng += (hang[k][j]-j-1)*(hang[k-1][j]-j-1);
				}
				sum1*=sum1;
				sum1-=sum2;
				sum1/=2;
				sum1-=cheng;
				ans1=(ans1+sum1)%mod;
			}
		}
		for(register int j = 1;j<=m;j++){
			for(register int i = 1;i<=n;i=lie[i][j]+1){
				sum1=hang[i][j]-j-1;
				for(register int k = i+2;k<lie[i][j];k++){
					ans2=(ans2+sum1*(hang[k][j]-j-1)*(lie[i][j]-k-1))%mod;
					sum1+=hang[k-1][j]-j-1;
				}
			}
		}
		printf("%lld %lld\n",c*ans1%mod,f*ans2%mod);
	}
	return 0;
}
