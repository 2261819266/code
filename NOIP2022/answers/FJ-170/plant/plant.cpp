#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn=1e6+100,maxm=1e3+10,mod=998244353;

inline int read(int x=0){
	int c,f(1);
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-f;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-0x30;
	return x*f;
}

string s;
int T,id,n,m,c,f,a[maxm][maxm]={0},hang[maxm][maxm]={0},lie[maxm][maxm]={0},ccc[maxn]={0},ccf[maxn]={0},cntl=0,cnth=0;
int headh[maxn]={0},endh[maxn]={0},headl[maxn]={0},endll[maxn]={0};
long long ansc=0,ansf=0;

inline void find_c(){
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(lie[i][j]>0&&ccc[lie[i][j]]==0){
				for(int k=i+2;k<=endll[lie[i][j]];k++){
					ansc+=(endh[hang[i][j]]-j)*(endh[hang[k][j]]-j);
					ansc%=mod;
				}
			}
		}
	}
}

inline void find_f(){
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(lie[i][j]>0&&ccf[lie[i][j]]==0){
				for(int k=i+2;k<endll[lie[i][j]];k++){
					ansf+=(endh[hang[i][j]]-j)*(endh[hang[k][j]]-j)*(endll[lie[i][j]]-k);
					ansf%=mod;
				}
			}
		}
	}
}

int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	T=read(),id=read();
	while(T--){
		memset(a,0,sizeof(a));
		memset(hang,0,sizeof(hang));
		memset(lie,0,sizeof(lie));
		memset(ccc,0,sizeof(ccc));
		memset(ccf,0,sizeof(ccf));
		memset(headh,0,sizeof(headh));
		memset(headl,0,sizeof(headl));
		memset(endh,0,sizeof(endh));
		memset(endll,0,sizeof(endll));
		cntl=0,cnth=0,ansc=0,ansf=0;
		n=read(),m=read(),c=read(),f=read();
		for(int i=1;i<=n;i++){
			cin>>s;
			for(int j=0;j<m;j++){
				if(s[j]=='1')a[i][j+1]=1;
			}
		}//turn to normal
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]==1)continue;
				if(j==1||a[i][j-1]==1){
					cnth++;
					hang[i][j]=cnth;
					headh[cnth]=j;
					endh[cnth]=j;
				}//块状记录 
				else hang[i][j]=cnth,endh[cnth]++;
			}
		}//处理hang的连续0
		for(int j=1;j<=m;j++){
			for(int i=1;i<=n;i++){
				if(a[i][j]==1)continue;
				if(i==1||a[i-1][j]==1){
					if(endll[cntl]-headl[cntl]<2)ccc[cntl]=1;
					if(endll[cntl]-headl[cntl]<3)ccf[cntl]=1;//no way to plant
					cntl++;
					lie[i][j]=cntl;
					headl[cntl]=i;
					endll[cntl]=i;
				}
				else lie[i][j]=cntl,endll[cntl]++;
			}
		}
		if(c!=0)find_c();
		if(f!=0)find_f();
		cout<<ansc<<" "<<ansf<<"\n";
	}
	return 0;
}
