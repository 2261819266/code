#include<bits/stdc++.h>
using namespace std;
const int N=1001,mod=998244353;
int T,ID,n,m,C,F,cnt[N][N],s[N][N],f[N],v[N];
int ansf,ansc;
//cnt[i][j]:line i from j(0) to 1 len
//tot[i][j]:row j from i(0) to 1 len
//s[i][j]:row j sum of cnt
//f[i][j]:ways to C
bool a[N][N];
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	T=read(),ID=read();
//	if(ID==1){for(int i=1;i<=T;i++)cout<<"0 0\n";return 0;}
//	if(ID);
	while(T--){
		memset(cnt,0,sizeof(cnt));
		memset(f,0,sizeof(f));
		memset(v,0,sizeof(v));
		ansf=ansc=0;
		n=read(),m=read(),C=read(),F=read();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				a[i][j]=(getchar()-'0');
			getchar();
		}
		for(int i=1;i<=n;i++){
			int j=1;
			while(j<=m){
				while(a[i][j]==1)j++;
				int res=0,last=j;
				while(a[i][j]==0&&j<=m)res++,j++;
				for(int k=last;k<j;k++)cnt[i][k]=res-(k-last);
			}
		}
		for(int j=1;j<=m;j++)
			for(int i=1;i<=n;i++)
				s[i][j]=s[i-1][j]+cnt[i][j];
		for(int j=1;j<=m;j++){
			int i=1;
			while(i<=n){
				while(a[i][j]==1)i++;
				int res=0,last=i;
				while(a[i][j]==0&&i<=n)res++,i++;
				for(int k=i-1;k>=last+2;k--){
					int tmp=cnt[k][j+1]*(s[k-2][j+1]-s[last-1][j+1])%mod;
					f[j]+=tmp;
					v[j]+=tmp*(i-1-k)%mod;
					f[j]%=mod;v[j]%=mod;
				}
			}
		}
		for(int i=1;i<=m;i++)ansc+=f[i],ansf+=v[i];
		printf("%d %d\n",(ansc*C)%mod,(ansf*F)%mod);
	}
	return 0;
}
