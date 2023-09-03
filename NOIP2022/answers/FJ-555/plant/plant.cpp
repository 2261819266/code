#include<bits/stdc++.h>//0xnnb2ndsb
using namespace std;
#define ll long long
#define db double
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10-'0'+ch;
		ch=getchar();
	}
	return x*f;
}
const int mod=998244353;
int T,id,n,m,c,f,ans1,ans2;
bool a[1005][1005];
char ch[1005];
int r[1005][1005],d[1005][1005],sum1[1005][1005],sum2[1005][1005];
void init(){
	ans1=ans2=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			r[i][j]=d[i][j]=sum1[i][j]=sum2[i][j]=0;
		}
	}
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	T=read(),id=read();
	while(T--){
		init();
		int n=read(),m=read(),c=read(),f=read();
		for(int i=1;i<=n;i++){
			scanf("%s",ch+1);
			for(int j=1;j<=m;j++){
				a[i][j]=ch[j]-'0';
				a[i][j]=!a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=m;j;j--){
				r[i][j]=j;
				if(a[i][j+1]){
					r[i][j]=r[i][j+1];
				}
			}
		}
		for(int i=n;i;i--){
			for(int j=1;j<=m;j++){
				d[i][j]=i;
				if(a[i+1][j]){
					d[i][j]=d[i+1][j];
				}
			}
		}
		for(int i=n;i;i--){
			for(int j=1;j<=m;j++){
				sum1[i][j]=r[i][j]-j;
				sum2[i][j]=(ll)(r[i][j]-j)*(d[i][j]-i)%mod;
				if(a[i+1][j]){
					sum1[i][j]+=sum1[i+1][j];
					sum2[i][j]+=sum2[i+1][j];
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(!a[i][j])continue;
				if(d[i][j]-i<2)continue;
				ans1+=(ll)(r[i][j]-j)*sum1[i+2][j]%mod;
				ans1%=mod;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(!a[i][j])continue;
				if(d[i][j]-i<3)continue;
				ans2+=(ll)(r[i][j]-j)*sum2[i+2][j]%mod;
				ans2%=mod;
			}
		}
		printf("%d %d\n",c*ans1,f*ans2);
	}
	return 0;
}
