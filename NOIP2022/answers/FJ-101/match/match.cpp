#include<bits/stdc++.h>
#define maxn 250005
using namespace std;

typedef unsigned long long ull;

void FR(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
}

int a[maxn],b[maxn];

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	FR();
	int T,n,Q;
	//scanf("%d%d",&T,&n);
	cin>>T>>n;
//	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
//	for(int i=1;i<=n;++i) scanf("%d",&b[i]);
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i) cin>>b[i];
	//scanf("%d",&Q);
	cin>>Q;
	int l,r;
	while(Q--){
		//scanf("%d%d",&l,&r);
		cin>>l>>r;
		ull ans=0;
		for(int p=l;p<=r;++p){
			for(int q=p;q<=r;++q){
				int maxa=0,maxb=0;
				for(int i=p;i<=q;++i){
					maxa=max(maxa,a[i]);
					maxb=max(maxb,b[i]);
				}
				ans+=(ull)maxa*maxb;
			}
		}
		//printf("%d\n",ans);
		cout<<ans<<endl;
	}
	return 0;
}

