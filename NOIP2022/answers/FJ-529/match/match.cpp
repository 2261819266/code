#include<bits/stdc++.h>
#define MAXN (250010)
#define fon(n,i) for(int i=1;i<=n;i++)
#define fen(k,n,i) for(int i=k;i<=n;i++)
//#define mo(i) i%18446744073709551616
using namespace std;
int T,Q,n,a[2][MAXN];
long long ans;
//int m[MAXN][MAXN];
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	fon(n,i) scanf("%d",&a[0][i]);
	fon(n,i) scanf("%d",&a[1][i]);
	scanf("%d",&Q);
	int l,r;long long maxn[2];
	fon(Q,i){
		ans=0; 
		scanf("%d%d",&l,&r);
		fen(l,r,j){
			fen(j,r,k){
				maxn[0]=0,maxn[1]=0;
				fen(j,k,o){
					if(a[0][o]>maxn[0]) maxn[0]=a[0][o];
					if(a[1][o]>maxn[1]) maxn[1]=a[1][o];
				}
				ans+=maxn[0]*maxn[1];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

