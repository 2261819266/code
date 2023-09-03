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
#define mp make_pair
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int MAXN=1050,MAXM=2e6+50,INF=0x3f3f3f3f,MOD=998244353;

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

struct node{
	int a,b,c;
};

int N,M,K,a[MAXM],stk[MAXN][3],siz[MAXN],Ans=0;
pii noww[MAXN];
node ans[MAXN*2];

void subtask1(){
	for(int i=1;i<=M;++i){
		int id=a[i];
		if(!noww[id].first){
			for(int j=1;j<N;++j) if(siz[j]==0){++siz[j];noww[id]=mp(j,siz[j]);stk[j][siz[j]]=id;break;}
			if(!noww[id].first) for(int j=1;j<N;++j) if(siz[j]==1){++siz[j];noww[id]=mp(j,siz[j]);stk[j][siz[j]]=id;break;}
			ans[++Ans]=(node){1,noww[id].first,0};
		}
		else{
			if(noww[id].second==2){
				ans[++Ans]=(node){1,noww[id].first,0};
				//printf("1 %d\n",noww[id].first);
				stk[noww[id].first][siz[noww[id].first]]=0;
				--siz[noww[id].first];
				noww[id]=mp(0,0);
			}
			else{
				ans[++Ans]=(node){1,N,0};
				ans[++Ans]=(node){2,noww[id].first,N};
				//printf("2 %d %d\n",noww[id].first,N);
				stk[noww[id].first][1]=stk[noww[id].first][2];
				noww[stk[noww[id].first][2]]=mp(noww[id].first,1);
				stk[noww[id].first][2]=0;
				--siz[noww[id].first];
				noww[id]=mp(0,0);
			}
		}
	}
}

void Init(){
	Ans=0;
	N=read();M=read();K=read();
	for(int i=1;i<=M;++i) a[i]=read();
}

void Solve(){
	if(K==2*N-2){subtask1();return;}
	
}

void Print(){
	printf("%d\n",Ans);
	for(int i=1;i<=Ans;++i){
		if(ans[i].a==1) printf("%d %d\n",ans[i].a,ans[i].b);
		else printf("%d %d %d\n",ans[i].a,ans[i].b,ans[i].c);
	}
}

int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int T=read();
	while(T--){
		Init();
		Solve();	
		Print();
	}
	return 0;
}
/*
1
2 4 2
1 2 1 2

*/
