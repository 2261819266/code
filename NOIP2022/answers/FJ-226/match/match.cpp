#include <bits/stdc++.h>
#define maxn 250010
using namespace std;
unsigned long long ans;
int T,n,Q;
struct player{
	int w,p;
}a[maxn],b[maxn];
bool cmp(player a,player b){
	return a.w>b.w;
}
void solve(int l,int r){
	unsigned long long tmp,m1,m2;
	for(int i=1;i<=n;i++){
		if(a[i].p>=l&&a[i].p<=r){
			m1=a[i].w;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(b[i].p>=l&&b[i].p<=r){
			m2=b[i].w;
			break;
		}
	}
	tmp=m1*m2;
	ans+=tmp;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].w);
		a[i].p=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i].w);
		b[i].p=i;
	}
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp);
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++){
		int L,R;
		ans=0;
		scanf("%d%d",&L,&R);
		for(int l=L;l<=R;l++){
			for(int r=l;r<=R;r++){
				solve(l,r);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
