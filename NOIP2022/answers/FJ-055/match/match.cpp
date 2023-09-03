#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int res=0,flag=1;
	char ch=getchar();
	while(!('0'<=ch&&ch<='9'))
		flag=(ch=='-')?-1:1,ch=getchar();
	while('0'<=ch&&ch<='9')
		res=res*10+ch-'0',ch=getchar();
	return res*flag;
}
struct SegmentTree
{
	struct node
	{
		int data;
	};
	struct node nd[1000010];
	int val[250010];
	void build(int left,int right,int id)
	{
		if(left==right)
		{
			nd[id].data=val[left];
			return;
		}
		int mid=(left+right)>>1;
		build(left,mid,id<<1);
		build(mid+1,right,id<<1|1);
		nd[id].data=max(nd[id<<1].data,nd[id<<1|1].data);
		return ;
	}
	int query(int left,int right,int id,int start,int end)
	{
		if(end<left||right<start)
			return 0;
		if(start<=left&&right<=end)
			return nd[id].data;
		int mid=(left+right)>>1;
		return max(query(left,mid,id<<1,start,end),query(mid+1,right,id<<1|1,start,end));
	}
};
struct SegmentTree a,b;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T=read(),n=read();
	for(int i=1;i<=n;i++)
		a.val[i]=read();
	for(int i=1;i<=n;i++)
		b.val[i]=read();
	a.build(1,n,1);
	b.build(1,n,1);
	int q=read();
	for(int i=1;i<=q;i++)
	{
		unsigned long long ans=0;
		int left=read(),right=read();
		for(int j=left;j<=right;j++)
			for(int k=j;k<=right;k++)
				ans+=(unsigned long long)a.query(1,n,1,j,k)*b.query(1,n,1,j,k);
		printf("%llu\n",ans);
	}
	return 0;
}
