#include<bits/stdc++.h>
using namespace std;
int n,a[3010],b[3010],ma[3010][3010],mb[3010][3010];
long long ans=0;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	memset(ma,0,sizeof(ma));
	memset(mb,0,sizeof(mb));
	int T,Q;
	cin>>T>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	for(int i=1;i<=n;i++)
	  for(int j=i;j<=n;j++)
	    for(int t=i;t<=j;t++){
	    	ma[i][j]=max(ma[i][j],a[t]);
			mb[i][j]=max(mb[i][j],b[t]); 
		}
	cin>>Q;
	int l,r;
	while(Q--){
		ans=0;
		scanf("%d%d",&l,&r);
		for(int i=l;i<=r;i++)
		  for(int j=i;j<=r;j++)
		    ans+=ma[i][j]*mb[i][j];
		printf("%lld\n",ans);
	}
	return 0;
}
