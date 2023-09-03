#include<iostream>
#include<cstring>
using namespace std;
#define int long long

int read(){
	int w=0;bool f=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=0;c=getchar();
	}
	while(isdigit(c))w=(w<<3)+(w<<1)+(c^48),c=getchar();
	return f?w:-w;
}
void print(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
const int maxm=1e3+4;
const int mod=998244353;

int T,id;
int n,m,c1,c2;
int f[maxm][maxm];
int g[maxm][maxm];
char s[maxm];int ans;
inline int qqpow(int a,int b){
	int res=1;
	while(b){
		if(b&1)res*=a,res%=mod;
		a=a*a%mod;
		b>>=1;
	}
	return res%mod;
}
int sum;

signed main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	T=read(),id=read();
	while (T--){
		n=read(),m=read(),c1=read(),c2=read();
		if(c1==0&&c2==0){
			print(0);return 0;
		}
		int x,y;
		memset(g,0,sizeof(g));
		ans=0;sum=0;
//		if(m==2){
		for(int i=1;i<=n;++i){
			cin>>s+1;
			int l=strlen(s+1);
			for(int j=1;j<=l;++j){
				g[i][j]=s[j]-'0';	
			}
		}
		for(int q=1;q<=m;++q){
			
			for(int i=1;i<=n;++i){
				x=m,y=m;
				if(g[i][q]==1||g[i+1][q]==1)continue;
				for(int p=q+1;p<=m;++p)if(g[i][p]==1){x=p-1;break;}
				if(x==q)continue;
				for(int j=i+2;j<=n;++j){
					if(g[j][q]==1)break;
					y=m;
					for(int p=q+1;p<=m;++p)if(g[j][p]==1){
					y=p-1;break;	
					}
					if(y==q)continue;
					y-=q;
//					cout<<x<<y;
//					ans+=x+y;
					if(x>=1&&y>=1){
						ans=(ans+(x-q)*(y))%mod;
						int xx=0;
						for(int k=j+1;k<=n;++k){
							if(g[k][q]==0)xx++;if(g[k][q]==1)break;
						}	
						sum=(sum+xx*ans)%mod;
					}
				}
			}	
		}	
		print(ans*c1),putchar(' '),print(sum*c2);
	}
//	}
	return 0;
}
