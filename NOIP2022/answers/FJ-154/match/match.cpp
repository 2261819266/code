#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<vector>
#include<bitset>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
const int MAXN=3050,INF=0x3f3f3f3f,MOD=998244353;

int read(){
	int flag=1,cnt=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') flag=-1;c=getchar();}
	while(c>='0'&&c<='9') cnt=(cnt<<1)+(cnt<<3)+(c^48),c=getchar();
	return flag*cnt;
}

//多测要清空！！！ 多测要清空！！！ 多测要清空！！！ 多测要清空！！！ 
//多测要清空！！！ 多测要清空！！！ 多测要清空！！！ 多测要清空！！！ 
//多测要清空！！！ 多测要清空！！！ 多测要清空！！！ 多测要清空！！！ 
//多测要清空！！！ 多测要清空！！！ 多测要清空！！！ 多测要清空！！！ 
//多测要清空！！！ 多测要清空！！！ 多测要清空！！！ 多测要清空！！！ 

int T,N,Q,a[MAXN],b[MAXN],maxxa[MAXN][MAXN],maxxb[MAXN][MAXN];
ULL sum[MAXN][MAXN];

void Init(){
	T=read();N=read();
	for(int i=1;i<=N;++i) a[i]=read();
	for(int i=1;i<=N;++i) b[i]=read();
	Q=read();
}

void Solve(){
	for(int i=N;i>=1;--i){
		maxxa[i][i]=a[i];maxxb[i][i]=b[i];
		for(int j=i-1;j>=1;--j) maxxa[j][i]=max(maxxa[j+1][i],a[j]),maxxb[j][i]=max(maxxb[j+1][i],b[j]);
	}
	for(int i=1;i<=N;++i){
		sum[i][i]=1ull*a[i]*b[i];
		for(int j=i+1;j<=N;++j) sum[i][j]=sum[i][j-1]+1ull*maxxa[i][j]*maxxb[i][j];
	}
	for(int j=1;j<=N;++j) for(int i=j-1;i>=1;--i) sum[i][j]+=sum[i+1][j];
}

void Print(){
	for(int i=1;i<=Q;++i){
		int l=read(),r=read();
		printf("%llu\n",sum[l][r]);
	}
}

int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	Init();
	Solve();	
	Print();
	return 0;
}
/*
0 2
2 1
1 2
1
1 2

*/
