#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

const int N=250010;

int a[N],b[N],n;
int t1[N],t2[N];

int build(int no,int l,int r,int t[],int m[])
{
	if(l==r)
	{
		return t[no]=m[l];
	}
	int mid=(l+r)/2;
	return t[no]=max(build(no*2,l,mid,t,m),build(no*2+1,mid+1,r,t,m));
}
int query(int no,int l,int r,int lx,int rx,int t[],int m[])
{
	if(lx<=l&&r<=rx)return t[no];
	int mid=(l+r)/2,res=-1;
	if(lx<=mid)res=max(res,query(no*2,l,mid,lx,rx,t,m));
	if(rx>mid)res=max(res,query(no*2+1,mid+1,r,lx,rx,t,m));
	return res;
}
int qry(int op,int lx,int rx)
{
	if(op==1)return query(1,1,n,lx,rx,t1,a);
	if(op==2)return query(1,1,n,lx,rx,t2,b);
	return 114514;
}

int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	
	int T,Q;scanf("%d%d",&T,&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	scanf("%d",&Q);
	build(1,1,n,t1,a);build(1,1,n,t2,b);
	
	int l,r,p,q;long long ans;
	while(Q--)
	{
		scanf("%d%d",&l,&r);ans=0;
		for(p=l;p<=r;p++)
			for(q=p;q<=r;q++)
				ans+=(long long)qry(1,p,q)*qry(2,p,q);
		printf("%lld\n",ans);
	}
	
	fclose(stdin);fclose(stdout);
	return 0;
}
