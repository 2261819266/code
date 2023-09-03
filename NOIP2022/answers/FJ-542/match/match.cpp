#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7;
int a[250100];
int b[250100];
int treea[1000100];
int treeb[1000100];
int l,r,id,n,q;
long long ans;
void pusha(int rt)
{
	treea[rt]=max(treea[rt<<1],treea[rt<<1|1]);
}
void pushb(int rt)
{
	treeb[rt]=max(treeb[rt<<1],treeb[rt<<1|1]);
}
void builda(int rt,int l,int r)
{
	if (l == r)
	{
		treea[rt] = a[l];
		return ;
	}
	int mid = (l+r)>>1;
	builda(rt*2,l,mid);
	builda(rt*2+1,mid+1,r);
	pusha(rt);
}
void buildb(int rt,int l,int r)
{
	if (l == r)
	{
		treeb[rt] = b[l];
		return ;
	}
	int mid = (l+r)>>1;
	buildb(rt*2,l,mid);
	buildb(rt*2+1,mid+1,r);
	pushb(rt);
}
int finda(int rt,int l,int r,int pos)
{
	if (l == r && treea[rt] == pos)
	    return l;
	if (l==r && treea[rt] != pos)    return -1;
	int mid = (l+r)>>1;
	return max(finda(rt*2,l,mid,pos),finda(rt*2+1,mid+1,r,pos));
}
int findb(int rt,int l,int r,int pos)
{
	if (l == r && treeb[rt] == pos)
	    return l;
	if (l==r && treeb[rt] != pos)    return -1;
	int mid = (l+r)>>1;
	return max(findb(rt*2,l,mid,pos),findb(rt*2+1,mid+1,r,pos));
}
void query(int rt,int l,int r,int x,int y)
{
	if (l>y || r < x)    return ;
	if (l>=x && r <= y)
	{
		if (l==r)
		{
			ans += treea[rt]*treeb[rt];
			return ;
		}
		int mid = (l+r)>>1;
		if (treea[rt<<1] > treea[rt<<1|1] && treeb[rt<<1] > treeb[rt<<1|1]){
			ans+=(treea[rt<<1]*treeb[rt<<1|1]%Mod)*(r-mid)%Mod;
			ans%=Mod;
		}
		else if (treea[rt<<1] < treea[rt<<1|1] && treeb[rt<<1] < treeb[rt<<1|1]){
			ans+=(treea[rt<<1|1]*treeb[rt<<1|1]%Mod)*(mid-l+1)%Mod;
			ans%=Mod;
		} else{
			query(rt*2,l,mid,x,y);
			query(rt*2+1,mid+1,r,x,y);
		}
		query(rt*2,l,mid,x,y);
		query(rt*2+1,mid+1,r,x,y);
		return ;
	}
	int mid = (l+r)>>1;
	query(rt*2,l,mid,x,y);
	query(rt*2+1,mid+1,r,x,y);
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&id,&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
	}
	builda(1,1,n);
	buildb(1,1,n);
	scanf("%d",&q);
	while (q--)
	{
		int l,r;
		ans = 0;
		scanf("%d%d",&l,&r);
		query(1,1,n,l,r);
		cout<<ans;
	}
	return 0;
}
/*
0 2
2 1
1 2
1
1 2
*/
