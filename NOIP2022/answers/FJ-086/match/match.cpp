#include<iostream>
#include<cstdio>
using namespace std;
int n,T,Q,cnt,maxa,maxb;
int a[2000000],b[2000000];
struct dy
{
	int v;
	int left;
	int right;
};
dy eda[8000000],edb[8000000];
int jsa(int u,int v,int p)
{
	eda[p].left=u;
	eda[p].right=v;
	if (u==v)
	{
		eda[p].v=a[u];
		return a[u];
	}
	eda[p].v=max(jsa(u,(u+v)/2,p*2),jsa((u+v+1)/2,v,p*2+1));
}
int jsb(int u,int v,int p)
{
	edb[p].left=u;
	edb[p].right=v;
	if (u==v)
	{
		edb[p].v=b[u];
		return b[u];
	}
	edb[p].v=max(jsb(u,(u+v)/2,p*2),jsb((u+v+1)/2,v,p*2+1));
}
int find_a(int u,int v,int p,int fhz)
{
	if (eda[p].left==u&&eda[p].right==v)
		return eda[p].v;
	int mid1=(eda[p].left+eda[p].right)/2,mid2=(eda[p].left+eda[p].right+1)/2;
	if (eda[p].left<u)
		fhz=min(find_a(eda[p].left,u,p*2,fhz),fhz);
	if (u<=eda[p].left)
		fhz=max(find_a(u,eda[p].left,p*2,fhz),fhz);
	if (eda[p].left>mid1)
		fhz=max(find_a(eda[p].left,mid1,p*2+1,fhz),fhz);
	if (eda[p].right>v)
		fhz=min(find_a(v,eda[p].right,p*2+1,fhz),fhz);
	if (v>=eda[p].right)
		fhz=max(find_a(eda[p].right,v,p*2+1,fhz),fhz);
	if (mid2>=eda[p].right)
		fhz=max(find_a(eda[p].right,mid2,p*2,fhz),fhz);
	return fhz;
}
int find_b(int u,int v,int p,int fhz)
{
	if (edb[p].left==u&&edb[p].right==v)
		return edb[p].v;
	int mid1=(edb[p].left+edb[p].right)/2,mid2=(edb[p].left+edb[p].right+1)/2;
	if (edb[p].left<u)
		fhz=min(find_b(edb[p].left,u,p*2,fhz),fhz);
	if (u<=edb[p].left)
		fhz=max(find_b(u,edb[p].left,p*2,fhz),fhz);
	if (edb[p].left>mid1)
		fhz=max(find_b(edb[p].left,mid1,p*2+1,fhz),fhz);
	if (edb[p].right>v)
		fhz=min(find_b(v,edb[p].right,p*2+1,fhz),fhz);
	if (v>=edb[p].right)
		fhz=max(find_b(edb[p].right,v,p*2+1,fhz),fhz);
	if (mid2>=edb[p].right)
		fhz=max(find_b(edb[p].right,mid2,p*2,fhz),fhz);
	return fhz;
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>T>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++)
		cin>>b[i];
	cin>>Q;
	if (Q>30)
	{
		jsa(1,n,1);
		jsb(1,n,1);
	}
	for (int i=1;i<=Q;i++)
	{
		int x,y;
		cin>>x>>y;
		maxa=0;maxb=0;
		if (Q>30)
		{
			maxa=find_a(x,y,1,eda[1].v);
			maxb=find_b(x,y,1,edb[1].v);
		}
		else
			for (int j=x;j<=y;j++)
			{
				maxa=max(a[j],maxa);
				maxb=max(b[j],maxb);
			}
		cout<<(maxa*maxb)%8589934592<<endl;
	}
}
