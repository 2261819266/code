#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
const int MAXN=1e3+5;
int T,id;
int n,m,c,f,ansc,ansf;
bool a[MAXN][MAXN];
int mph[MAXN][MAXN],mpl[MAXN][MAXN];
void calc_mph(int n,int m){
	for(int i(1);i<=n;++i){
		mph[i][m+1]=-1;
	}
	for(int i(1);i<=n;++i){
		for(int j(m);j>=1;--j){
			if(a[i][j]) mph[i][j]=-1;
			else mph[i][j]=mph[i][j+1]+1;
		}
	}
	return;
}
void calc_mpl(int n,int m){
	for(int j(1);j<=m;++j){
		mpl[n+1][j]=-1;
	}
	for(int j(1);j<=m;++j){
		for(int i(n);i>=1;--i){
			if(a[i][j]) mpl[i][j]=-1;
			else mpl[i][j]=mpl[i+1][j]+1;
		}
	}
	return;
}
int calc_c(int i,int j){
	if(i>=n-1||j>=n) return 0;
	if(mph[i][j]<=0) return 0;
	if(mpl[i][j]<=1) return 0;
	int ans=0;
	int ki=i+2;
	while(ki<=n&&(!a[ki][j])){
		ans+=mph[ki][j];
		ans%=MOD;
		++ki;
	}
	ans*=mph[i][j];ans%=MOD;
	return ans;
}
int calc_f(int i,int j){
	if(i>=n-2||j>=n) return 0;
	if(mph[i][j]<=0) return 0;
	if(mpl[i][j]<=2) return 0;
	int ans=0;
	int ki=i+2;
	while(ki+1<=n&&mpl[ki][j]>=1){
		ans+=(mph[ki][j]*(mpl[i][j]-ki+i))%MOD;
		ans%=MOD;
		++ki;
	}
	ans*=mph[i][j];ans%=MOD;
	return ans;
}
int main(){
//	freopen("E:\\NOIP2022\\plant\\plant3.in","r",stdin);
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--){
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i(1);i<=n;++i){
			char ch=getchar();
			while(ch<'0'||ch>'1') ch=getchar();
			for(int j(1);j<=m;++j){
				a[i][j]=ch-'0';
				ch=getchar();
			}
		}
		calc_mph(n,m);
		calc_mpl(n,m);
		ansc=ansf=0;
		if(c!=0){
			for(int i(1);i+2<=n;++i){
				for(int j(1);j<m;++j){
					ansc+=calc_c(i,j);
					ansc%=MOD;
				}
			}
		}else ansc=0;
		if(f!=0){
			for(int i(1);i+3<=n;++i){
				for(int j(1);j<m;++j){
					ansf+=calc_f(i,j);
					ansf%=MOD;
				}
			}
		}else ansf=0;
		printf("%d %d\n",(ansc*c)%MOD,(ansf*f)%MOD);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//Yang4 Li4 3 Zhe4 Yang4 Jia2 Dai4 Si1 Huo4 Zhen1 De Hao3 Ma
//样例3这样夹带私货真的好吗 
