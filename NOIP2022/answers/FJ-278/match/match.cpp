#include<bits/stdc++.h>
#define F(i,j,n)for(register int i=j;i<=n;i++)
#define D(i,j,n)for(register int i=j;i>-n;i--)
#define N 3005
#define ull unsigned long long
ull a[N],b[N],p[N][N];
int main(){
	freopen("match.in","r",stdin);freopen("match.out","w",stdout);
	int T,n;scanf("%d%d",&T,&n);
	F(i,1,n)scanf("%llu",a+i);F(i,1,n)scanf("%llu",b+i);
	ull m1,m2;F(i,1,n){
		m1=a[i],m2=b[i];F(j,i,n){
			m1=std::max(m1,a[j]);m2=std::max(m2,b[j]);
			p[i][j]=m1*m2;
		}
	}
	F(i,1,n)F(j,i+1,n)p[i][j]+=p[i][j-1];
	int q;scanf("%d",&q);while(q--){
		int l,r;ull ans=0;scanf("%d%d",&l,&r);
		F(i,l,r){
			ans+=p[i][r]-p[i][i-1];
		}printf("%llu\n",ans);
	}return 0;
}
