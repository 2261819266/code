#include<stdio.h>
const int N=1005,P=998244353;
int T,id,n,m,c,f;
int ansc,ansf,R[N][N];
char s[N][N];
void Add(int &x,int y){
	if((x+=y)>=P)x-=P;
}
void solveC(){
	ansc=0;
	if(!c)return;
	for(int j=1;j<m;++j){
		for(int i=n-2,k=0;i>0;--i){
			if(s[i+2][j]=='1')k=0;
			else Add(k,R[i+2][j]);
			if(s[i+1][j]!='1')Add(ansc,1ll*R[i][j]*k%P);
		}
	}
}
void solveF(){
	ansf=0;
	if(!f)return;
	for(int j=1;j<m;++j){
		for(int i=n-3,k=0,d=0;i>0;--i){
			if(s[i+3][j]=='1')d=0;
			else ++d;
			if(s[i+2][j]=='1')k=0;
			else Add(k,1ll*R[i+2][j]*d%P);
			if(s[i+1][j]!='1')Add(ansf,1ll*R[i][j]*k%P);
		}
	}
}
void solve(){
	scanf("%d%d%d%d",&n,&m,&c,&f);
	for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(int i=1;i<=n;++i){
		for(int j=m,k=0;j;--j){
			if(s[i][j]=='1')R[i][j]=k=0;
			else R[i][j]=k++;
		}
	}
	solveC();
	solveF();
	printf("%d %d\n",ansc,ansf);
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--)solve();
	return 0;
}
