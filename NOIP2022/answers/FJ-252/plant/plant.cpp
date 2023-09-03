#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1e3+10;
const ll mod =998244353;
bool st;
int T,n,m,mlc,mlf,cz;
ll cdaan,fdaan;
char ch[MAXN][MAXN];//long long
ll dpC[MAXN][MAXN],dpF[MAXN][MAXN];
int hang[MAXN][MAXN];int lie[MAXN][MAXN];
bool ed;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&cz);
	while(T--){
		cdaan=0;fdaan=0;
		memset(ch,0,sizeof(ch));
		memset(dpC,0,sizeof(dpC));
		memset(dpF,0,sizeof(dpF));
		memset(hang,0,sizeof(hang));
		memset(lie,0,sizeof(lie));
		scanf("%d%d%d%d",&n,&m,&mlc,&mlf);
	for(int i=1;i<=n;i++){
		scanf("%s",ch[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=m-1;j>=0;j--){
			if(ch[i][j]=='0')hang[i][j]=hang[i][j+1]+1;
		}
	}
	for(int j=0;j<m;j++){
		for(int i=n;i>=1;i--){
			if(ch[i][j]=='0')lie[i][j]=lie[i+1][j]+1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=m-1;j>=0;j--){
			if(ch[i][j]=='0')dpC[i][j]=max(0ll,dpC[i-1][j]+hang[i-1][j]-1);
			dpC[i][j]=(dpC[i][j]+mod)%mod;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<m;j++)cout<<lie[i][j];
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			dpF[i][j]=max(dpC[i-1][j]*(hang[i][j]-1),0ll);
			dpF[i][j]=(dpF[i][j]+mod)%mod;
			cdaan=(cdaan+dpF[i][j]+mod)%mod;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<m;j++){
//			dpC[i][j]=dpF[i][j];
//		}
//	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			fdaan=(fdaan+max(dpF[i][j]*(lie[i+1][j]),0ll)+mod)%mod;
			//cout<<dpF[i][j]*lie[i+1][j];
		}
	//	cout<<endl;
	}
	fdaan=(fdaan+mod)%mod;
	cdaan=(cdaan+mod)%mod;
	printf("%lld %lld\n",cdaan*mlc,fdaan*mlf);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
