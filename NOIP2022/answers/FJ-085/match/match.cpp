#include<bits/stdc++.h>
#define MAXN 250010
#define ll long long
using namespace std;
int T,n,Q,askl,askr;
ll a[MAXN],b[MAXN];
/*
int st1[MAXN],t1,st2[MAXN],t2;
ll sum1[MAXN],sum2[MAXN],ans;
*/
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||'9'<ch){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline ll llread(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||'9'<ch){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}

/*
struct tree{
	int l,r;
	ll la,ra,v,maxn;
}t1[MAXN],t2[MAXN];

void build(int x,int lb,int rb){
	t1[x].l=lb,t1[x].r=rb;
	t2[x].l=lb,t2[x].r=rb;
	if(lb==rb){
		t1[x].la=a[lb],t1[x].ra=a[rb],t1[x].maxn=a[lb];
		t2[x].la=b[lb],t2[x].ra=b[rb],t2[x].maxn=b[lb];
		return ;
	}
	build(ls,lb,mid);build(rs,mid+1,rb);
	t1[x].maxn=max(t1[ls].maxn,t1[rs].maxn);
	if(t1[ls].maxn<=a[mid+1]) t1[x].la=plus(t1[ls].la,t1[rs].la);
	else{
		int pos=mid+1;
		while(a[pos]<t1[ls].maxn) pos++;
		t1[x].la=plus(t1[ls].la,t1[rs].la);
	}
	if(a[mid]<=a[mid+1]) t1[x].la=plus(t1[ls].la,t1[rs].la);
	else{
		int pos=mid+1;
		while(a[pos]<a[mid]) pos++;
		
	}
	
	
	
	
}
*/
/*
ll pls(ll a,ll b){
	return (a+b)%(1<<64);
}

ll mul(ll a,ll b){
	return a*b%(1<<64);
}
*/
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	T=read(),n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) b[i]=read();
	//build(1,1,n);
	Q=read();
	while(Q--){
		askl=read(),askr=read();
		//printf("%lld\n",querry(1,1,n,askl,askr));
		/*
		for(int i=askl;i<=askr;i++){
			while(t1>0&&st1[t1]<=a[i]) t1--;
			if(t1>0){
				sum1[i]=sum1[st1[t1]]+a[i]*(i-st1[t1]);
				ans=ans+
			}
			else{
				sum1[i]=a[i]*(i-askl+1);
			}
			st1[++t1]=a[i];
			
			while(t2>0&&st2[t2]<=b[i]) t2--;
			if(t2>0) sum2[i]=sum2[st2[t2]]+b[i]*(i-st2[t2]);
			else sum2[i]=a[i]*(i-askl+1);
			st[++t1]=a[i];
			
		}
		//ans=mul(sum1[askr],sum2[askr]);
		for(int i=askl;i<=askr;i++) sum1[i]=0,sum2[i]=0;
		*/
		ll ans=0;
		for(int l=askl;l<=askr;l++){
			ll max1=0,max2=0;
			for(int r=l;r<=askr;r++){
				max1=max(max1,a[r]),max2=max(max2,b[r]);
				ans=ans+(max1*max2);
			}
		}
		printf("%lld\n",ans);
	}
	
	//È¡Ä££¡£¡£¡ 
	
	return 0 ;
}
