#include<bits/stdc++.h>
#define N 250050
using namespace std;
int t,n,a[N],b[N],maxna[4*N],maxnb[4*N],q;
unsigned long long ans;/*
void builda(int k,int l,int r){
	if(l==r){
		maxna[k]=a[l];return;
	}
	int mid=(l+r)>>1;
	builda(k<<1,l,mid);builda(k<<1|1,mid+1,r);
	maxna[k]=max(maxna[k<<1],maxna[k<<1|1]);
}
void buildb(int k,int l,int r){
	if(l==r){
		maxnb[k]=b[l];return;
	}
	int mid=(l+r)>>1;
	buildb(k<<1,l,mid);buildb(k<<1|1,mid+1,r);
	maxnb[k]=max(maxnb[k<<1],maxnb[k<<1|1]);
}*/
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&t,&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
//	builda(1,1,n);buildb(1,1,n);
	scanf("%d",&q);
	for(int k=1;k<=q;k++){
		ans=0;
		int l,r;scanf("%d%d",&l,&r);
		for(int u=l;u<=r;u++){
		    int mnb=-1,mna=-1;
			for(int v=u;v<=r;v++){
				if(b[v]>mnb) mnb=b[v];
				if(a[v]>mna) mna=a[v];
				ans+=mna*mnb;
			}	
		}
		cout<<ans;printf("\n");
	}
	return 0;
}
