#include<bits/stdc++.h>
//#define int long long
#define reg register
using namespace std;
inline int cmin(reg int x,reg int y){return x<y?x:y;}
const int N=4e6+10,mod=1e9+7;
int cnt,n,m,k;
int a[N],b1[N],b2[N];
struct Node{int id,x,y;}ans[N];
inline void work(){
	for (reg int i=1;i<=m;i++){
		reg int id=(a[i]+1)>>1;
		if (!b1[id]) b1[id]=a[i],ans[++cnt]=(Node){1,id,0};
		else if (!b2[id]&&a[i]!=b1[id]) b2[id]=a[i],ans[++cnt]=(Node){1,id,0};
		else{
			if (b1[id]==a[i]){
				ans[++cnt]=(Node){1,n,0};
				ans[++cnt]=(Node){2,n,id};
				b1[id]=b2[id],b2[id]=0;
			}else{
				ans[++cnt]=(Node){1,id,0},b2[id]=0;
			}
		}
	}
	printf("%d\n",cnt);
	for (reg int i=1;i<=cnt;i++) 
		if (ans[i].id==1) printf("%d %d\n",ans[i].id,ans[i].x); 
		else printf("%d %d %d\n",ans[i].id,ans[i].x,ans[i].y);
}
signed main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int _; scanf("%d",&_);
	while (_--){
		scanf("%d%d%d",&n,&m,&k); cnt=0;// cout<<n<<" "<<m<<" "<<k<<endl;
		for (reg int i=1;i<=n;i++) b1[i]=b2[i]=0;
		for (reg int i=1;i<=m;i++) scanf("%d",&a[i]);//,cout<<a[i]<<" ";cout<<endl;
		if (k==2*n-2) work();
	}
	return 0;
}
/*
4 20 6
1 3 4 1 2 2 6 3 6 2 1 3 2 4 6 3 6 1 5 5
*/