#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read(){
	ll ans=0,f=1;
	char x;
	x=getchar();
	while(!(('0'<=x&&x<='9')||x!='-')){
		x=getchar();
	}
	if(x=='-'){
		f=-1;
		x=getchar();
	}
	while('0'<=x&&x<='9'){
		ans*=10;
		ans+=x-'0';
		x=getchar();
	}
	return ans*f;
}
int id;
int n,m,c,f;
int mp[1010][1010];
ll sum1=0;
ll sum2=0;
int dfsc(int a1,int b1){
	if(mp[a1][b1]||mp[a1+1][b1]||mp[a1][b1+1]){
		return 0;
	}
	int b2=0;
	for(int i=b1+1;i<=m;i++){
		if(mp[a1][i]){
			break;
		}
		b2++;
	}
	
	int b3=0;
	for(int i=a1+2;i<=n;i++){
		if(mp[i][b1]==1){
			return 0;
		}
		for(int j=b1+1;j<=m;j++){
			if(mp[i][j]){
				break;
			}
			b3++;
		}
		sum1+=b3*b2;
		b3=0;
	}
	return 0;
}
int dfsf(int a1,int b1){
	if(mp[a1][b1]||mp[a1+1][b1]||mp[a1][b1+1]){
		return 0;
	}
	int b2=0;
	for(int i=b1+1;i<=m;i++){
		if(mp[a1][i]){
			break;
		}
		b2++;
	}
	int b3=0;
	for(int i=a1+2;i<=n;i++){
		if(mp[i][b1]==1){
			break;
		}
		b3++;
	}
	int b4=0,js=0;
	for(int i=a1+2;i<=a1+1+b3;i++){
		b4=0;
		js++;
		for(int j=b1+1;j<=m;j++){
			if(mp[i][j]){
				break;
			}
			b4++;
		}
		sum2+=b4*(b3-js)*b2;
	}
	return 0;
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T;
	char x;
	scanf("%d%d",&T,&id);
	for(int xsxs=0;xsxs<T;xsxs++){
		sum1=0;sum2=0;
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>x;
				mp[i][j]=x-'0';
			}
		}
		for(int i=1;i<=n-2;i++){
			for(int j=1;j<=m-1;j++){
				dfsc(i,j);
			}
			sum1%=998244353;
		}
		for(int i=1;i<=n-2;i++){
			for(int j=1;j<=m-2;j++){
				dfsf(i,j);
			}
			sum2%=998244353;
		}
		printf("%lld %lld\n",sum1*c%998244353,sum2*f%998244353);
	}
	return 0;
}
/*
1 0
4 3 1 1
001
010
000
000
40953511 162107233

*/

