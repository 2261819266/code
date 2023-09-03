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
const int MAXN=1050,INF=0x3f3f3f3f,MOD=998244353;

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

char s[MAXN][MAXN];
bool can_plant[MAXN][MAXN];
int N,M,C,F,you[MAXN][MAXN],xia[MAXN][MAXN];
LL valC[MAXN][MAXN],valF[MAXN][MAXN],AnsC=0,AnsF=0;

void Init(){
	AnsC=AnsF=0;
	memset(you,0,sizeof(you));
	memset(xia,0,sizeof(xia));
	memset(valC,0,sizeof(valC));
	memset(valF,0,sizeof(valF));
	N=read();M=read();C=read();F=read();
	for(int i=1;i<=N;++i) scanf("%s",s[i]+1);
	for(int i=1;i<=N;++i) for(int j=1;j<=M;++j) can_plant[i][j]=((s[i][j]-'0')^1);
}

void Solve(){
	for(int i=1;i<=N;++i){
		you[i][M]=(can_plant[i][M]?M:0);
		for(int j=M-1;j>=1;--j) you[i][j]=(can_plant[i][j]?max(j,you[i][j+1]):0);
	}
	for(int j=1;j<=M;++j){
		xia[N][j]=(can_plant[N][j]?N:0);
		for(int i=N-1;i>=1;--i) xia[i][j]=(can_plant[i][j]?max(i,xia[i+1][j]):0);
	}
	for(int j=1;j<=M;++j){
		if(can_plant[N][j]) valC[N][j]=you[N][j]-j,valF[N][j]=0;
		else valC[N][j]=valF[N][j]=0;
		for(int i=N-1;i>=1;--i){
			if(!can_plant[i][j]){valC[i][j]=valF[i][j]=0;continue;}
			valC[i][j]=(you[i][j]-j+valC[i+1][j])%MOD;
			valF[i][j]=((you[i][j]-j)*(xia[i][j]-i)%MOD+valF[i+1][j])%MOD;
		}
	}
	for(int i=1;i<=N-2;++i)
		for(int j=1;j<=M-1;++j){
			if(!can_plant[i][j]||!can_plant[i+1][j]) continue;
			AnsC=(AnsC+valC[i+2][j]*(you[i][j]-j)%MOD)%MOD;
			AnsF=(AnsF+valF[i+2][j]*(you[i][j]-j)%MOD)%MOD;
		}
}

void Print(){
	printf("%lld %lld\n",C*AnsC,F*AnsF);
	/*for(int i=1;i<=N;++i){
		for(int j=1;j<=M;++j) printf("%d ",valC[i][j]);
		printf("\n");
	}*/
}

int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T=read(),id=read();
	while(T--){
		Init();
		Solve();	
		Print();
	}
	return 0;
}
/*
1 0
6 6 1 1
000010
011000
000110
010000
011000
000000
*/
