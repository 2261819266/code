#include<bits/stdc++.h>
using namespace std;
int T,n,a[250001],b[250001],q,l[250001],r[250001];
__int128_t ans,mod=1,maxa[3001][3001],maxb[3001][3001],suma[3001][3001],sumb[3001][3001];
void write(__int128_t g){
	if(g){
		write(g/10);
	}else{
		return;
	}
	putchar(g%10+'0');
}
__int128_t max(__int128_t a,__int128_t b){
	return a>b?a:b;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin >> T >> n;
	for(int i=1;i<=64;i++){
		mod*=2;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	cin >> q;
	for(int i=1;i<=q;i++){
		scanf("%d%d",&l[i],&r[i]);
	}
	for(int i=1;i<=n;i++){
		maxa[i][i]=a[i];
		maxb[i][i]=b[i];
		for(int j=i+1;j<=n;j++){
			maxa[i][j]=max(maxa[i][j-1],a[j]);
			maxb[i][j]=max(maxb[i][j-1],b[j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			suma[i][j]=suma[i][j-1]+maxa[i][j];
			sumb[i][j]=sumb[i][j-1]+maxb[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		ans=0;
		for(int p=l[i];p<=r[i];p++)	{
			for(int q=p;q<=r[i];q++){
				ans+=maxa[p][q]*maxb[p][q];
				ans%=mod;
			}
//			ans+=(sumb[p][r[i]]-sumb[p][p])*(suma[p][r[i]]-suma[p][p]);
//			ans%=mod;
		}
		write(ans);
		printf("\n");
	}
//	cout << ans;
	




	return 0;
}
//709551616
