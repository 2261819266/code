#include<cstdio>
int T,id,n,m,c,f,a[1010][1010];
char C[1010];
long long s[1010],ansc,ansf,s1,ss1,s2;
const long long MOD=998244353;
long long Add(long long a,long long b)
{
	return (a+b<MOD)?(a+b):a+b-MOD;
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--){
		ansc=ansf=0;
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=1;i<=n;i++){
			scanf("%s",C),s[i]=0;
			for(int j=1;j<=m;j++) a[i][j]='1'-C[j-1];
		}
		for(int j=m;j;j--){
			s1=ss1=s2=0;
			for(int i=1;i<=n;i++){
				if(a[i][j]) ansf=Add(ansf,Add(ss1,MOD-s2));
				if((!a[i][j])&&a[i-1][j]) ansc=Add(ansc,Add(ss1,MOD-s2)),s1=ss1=s2=0;
//				if(a[i][j]&&(!a[i-1][j])) s1=ss1=s2=0;
				if(a[i][j]) ss1=Add(ss1,s1*s[i]%MOD),s1=Add(s1,s[i]);
				if(a[i][j]&&a[i-1][j]&&i>1) s2=Add(s2,s[i]*s[i-1]%MOD);
//				printf("%d %d:%lld %lld %lld %lld %lld\n",i,j,s1,ss1,s2,ansc,ansf);
			}
			for(int i=1;i<=n;i++)
				if(a[i][j]) s[i]++;
				else s[i]=0;
			if(a[n][j]) ansc=Add(ansc,Add(ss1,MOD-s2));
		}
		printf("%lld %lld\n",ansc*c,ansf*f);
	}
}
