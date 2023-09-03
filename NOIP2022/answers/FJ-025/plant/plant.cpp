#include<cstdio>
#include<cstring>
#define reg register
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
const int M=998244353;
const int MAXN=1050;
int n,m,c,f,flag=0;
long long ans1=0,ans2=0;
char s[MAXN];
int sum[MAXN][MAXN],suv[MAXN][MAXN];
int fg[MAXN][MAXN],gf[MAXN][MAXN];
int mp[MAXN][MAXN];
int read(){
	reg int s=0,f=1;
	reg char ch;
	for(;(ch=getchar())<'0'||ch>'9';ch=='-'?f=-f:0);
	for(;ch>='0'&&ch<='9';s=(s<<3)+(s<<1)+ch-'0',ch=getchar());
	return s*f;
}
void kotori(){
	n=read(),m=read();c=read(),f=read();
	ans1=ans2=0;
	memset(sum,0,sizeof(sum));
	memset(suv,0,sizeof(suv));
	for(reg int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(reg int j=1;j<=m;j++){
			mp[i][j]=s[j]-'0';
		}
	}
	
	for(reg int i=1;i<=n;i++){
		for(reg int j=m;j;j--){
			if(mp[i][j])sum[i][j]=0;
			else sum[i][j]=sum[i][j+1]+1;
		}
	}
	for(reg int j=1;j<=m;j++){
		flag=0;
		for(reg int i=1;i<=n;i++){
			if(mp[i][j])suv[i][j]=0,flag=i;
			else suv[i][j]=suv[i-1][j]+sum[i][j];
			fg[i][j]=flag;
		}
		flag=n+1;
		for(reg int i=n;i;i--){
			if(mp[i][j])flag=i;
			gf[i][j]=flag;
		}
	}
	int l,r;
	for(reg int i=3;i<=n;i++){
		for(reg int j=1;j<m;j++)if(fg[i][j]<i-2){
			r=i-2,l=fg[i][j];
			ans1=(ans1+1ll*sum[i][j+1]*(suv[r][j]-r+l)%M)%M;
		}
	}
	for(reg int i=3;i<=n;i++){
		for(reg int j=1;j<m;j++)if(fg[i][j]<i-2){
			r=i-2,l=fg[i][j];
			ans2=(ans2+1ll*sum[i][j+1]*(suv[r][j]-r+l)%M*(gf[i][j]-i-1)%M)%M;
		}
	}
	printf("%lld %lld\n",ans1*c,ans2*f);
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int _,idid;
	_=read(),idid=read();
	while(_--)kotori();
}
