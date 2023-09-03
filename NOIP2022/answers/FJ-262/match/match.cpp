#include<bits/stdc++.h>
using namespace std;
int T,n,Q;
int N[100010],O[100010];
int trn[400500];int tro[400500];
unsigned long long MOD=9223372036854775807;

void build(int k,int l,int r){	//线段树维护最大值； 
	if(l==r){
		trn[k]=N[l];
		tro[k]=O[l];
		return;
	}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build((k<<1)+1,mid+1,r);
	trn[k]=max(trn[k<<1],trn[(k<<1)+1]);
	tro[k]=max(tro[k<<1],tro[(k<<1)+1]);
	return;
}
int find1(int k,int l,int r,int p,int q){//找最值 
	if(l>=p&&r<=q){
		return trn[k];
	}
	int mid=(l+r)>>1;
	int max1=-1,max2=-1;
	if(p<=mid) max1=find1(k<<1,l,mid,p,q);
	if(q>=mid+1) max2=find1((k<<1)+1,mid+1,r,p,q);
	if(max1>max2) return max1;
	else return max2;
}
int find2(int k,int l,int r,int p,int q){
	if(l>=p&&r<=q){
		return tro[k];
	}
	int mid=(l+r)>>1;
	int max1=-1,max2=-1;
    if(p<=mid) max1=find2(k<<1,l,mid,p,q);
	if(q>=mid+1) max2=find2((k<<1)+1,mid+1,r,p,q);
	if(max1>max2) return max1;
	else return max2;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>T>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&N[i]);//输入 
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&O[i]);
	}
	build(1,1,n);//建树 
	/*for(int i=1;i<=2*n;i++){
		cout<<trn[i]<<" "<<tro[i]<<endl;
	}*/
	cin>>Q;
	unsigned long long ans=0;
	for(int i=1;i<=Q;i++){
		ans=0;
		int li,ri;
		scanf("%d%d",&li,&ri);
		for(int q=li;q<=ri;q++){
			for(int p=li;p<=q;p++){
				ans+=((find1(1,1,n,p,q)%MOD)*(find2(1,1,n,p,q)%MOD));
				//cout<<find1(1,1,n,p,q)<<" "<<find2(1,1,n,p,q)<<" "<<ans<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
