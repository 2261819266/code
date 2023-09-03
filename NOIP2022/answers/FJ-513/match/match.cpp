#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int T,n,a[3010],b[3010],Q,l,r;
int fa[3010][3010],fb[3010][3010];
ull s[3010][3010],f[3010][3010],ans;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			fa[i][j]=max(a[j],fa[i][j-1]);
			fb[i][j]=max(b[j],fb[i][j-1]);
			f[i][j]=1ull*fa[i][j]*fb[i][j];
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=n;j>=i;j--)
			s[i][j]=s[i][j+1]+f[i][j];
	scanf("%d",&Q);
	while(Q--){
		scanf("%d%d",&l,&r);
		ans=0;
		for(int i=l;i<=r;i++)
			ans+=1ull*(s[i][i]-s[i][r+1]);
		printf("%llu\n",ans);
	}
	return 0;
}
