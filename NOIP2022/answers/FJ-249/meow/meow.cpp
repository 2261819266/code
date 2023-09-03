#include<bits/stdc++.h>
using namespace std;
const int M=3e6+100;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	x=(x<<3)+(x<<1)+ch-48,ch=getchar();
	return f*x;
}
struct node
{
	int pos,c;
}t[1000];
int n,T,m,k,a[M],c[M*4],d[M][2],cc[M*4],cnt,f[M],pre,ans[M][4],tot;
void build(int k,int l,int r)
{
	if(l==r)
	{
		c[k]=d[l][0]=d[r][0]=0;cc[k]=1;
		return;
	}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	cc[k]=cc[k<<1]+cc[k<<1|1];c[k]=0;
}
void change(int k,int l,int r,int x,int y)
{
	if(l==r)
	{
		if(d[l][0]==y&&d[l][1])d[l][0]=d[l][1],d[l][1]=0,c[k]=1,cc[k]=0;
		else if(d[l][0]==y&&!d[l][1])c[k]=0,cc[k]=1,d[l][0]=0,c[k]=0;
		else if(d[l][1]==y)c[k]=1,cc[k]=0,d[l][1]=0;
		else if(!d[l][1]&&d[l][0]&&d[l][0]!=y)c[k]=0,cc[k]=0,d[l][1]=y;
		else if(!d[l][0])c[k]=1,cc[k]=0,d[l][0]=y;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)change(k<<1,l,mid,x,y);
	else change(k<<1|1,mid+1,r,x,y);
	c[k]=c[k<<1]+c[k<<1|1];
	cc[k]=cc[k<<1]+cc[k<<1|1];
}
int query(int k,int l,int r,int x)
{
	if(l==r)return l;
	int mid=(l+r)>>1;
	if(x==0&&cc[k<<1])return query(k<<1,l,mid,x);
	else if(x==0)return query(k<<1|1,mid+1,r,x);
	if(x==1&&c[k<<1])return query(k<<1,l,mid,x);
	else if(x==1)return query(k<<1|1,mid+1,r,x);
	return 0;
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();m=read();k=read();
		for(int i=1;i<=m;++i)
		a[i]=read();
		for(int i=1;i<=k;++i)
		t[i].c=t[i].pos=0;
		build(1,1,n);tot=0;cnt=0;pre=0;
		
		for(int i=1,x,y;i<=m;++i)
		{
			if(!cnt)
			{
				if(!t[a[i]].pos)
				{
					if(c[1])
					{
						t[a[i]].pos=query(1,1,n,1);
						f[i]=t[a[i]].pos;
						t[a[i]].c=1;
						change(1,1,n,t[a[i]].pos,a[i]);
					}
					else if(cc[1]>1)
					{
						t[a[i]].pos=query(1,1,n,0);
						f[i]=t[a[i]].pos;
						t[a[i]].c=0;
						change(1,1,n,t[a[i]].pos,a[i]);
					}
					else if(!c[1]&&cc[1]==1)cnt=a[i],pre=i;
				}
				else if(t[a[i]].pos)
				{
					if(t[a[i]].c==0)
					{
						x=query(1,1,n,0);
						t[d[t[a[i]].pos][1]].c=0;
						f[i]=x;
					}
					else f[i]=t[a[i]].pos;
					change(1,1,n,t[a[i]].pos,a[i]);
					t[a[i]].pos=0;
				}
			}
			else if(cnt)
			{
				y=t[a[i]].pos;
				if(a[i]!=cnt&&y)
				{
					if(!t[a[i]].c&&d[y][1])
					{
						f[pre]=y;
						t[cnt].pos=y;t[cnt].c=1;t[d[y][1]].c=0;
						x=query(1,1,n,0);
						f[i]=x;
						change(1,1,n,y,a[i]);
						change(1,1,n,y,cnt);
						cnt=0;
					}
					else if(!t[a[i]].c&&!d[y][1])
					{
						x=query(1,1,n,0);
						f[pre]=x;
						f[i]=y;
						t[a[i]].pos=0;
						t[cnt].pos=x;t[cnt].c=0;
						change(1,1,n,y,a[i]);
						change(1,1,n,x,cnt);
						cnt=0;
					}
					else if(t[a[i]].c)
					{
						f[i]=y;t[a[i]].pos=0;
						change(1,1,n,y,a[i]);
					}
				}
				else if(a[i]!=cnt&&!y)
				{
					x=query(1,1,n,1);
					f[i]=x;
					t[a[i]].c=1;t[a[i]].pos=x;
					change(1,1,n,x,a[i]);
				}
				else if(a[i]==cnt)
				{
					x=query(1,1,n,0);
					f[pre]=f[i]=x;
					cnt=0;
				}
			}
		}
		build(1,1,n);
		for(int i=1;i<=k;++i)
		t[i].c=t[i].pos=0;
		
		for(int i=1;i<=m;++i)
		{
			ans[++tot][0]=1;ans[tot][1]=f[i];
			if(!t[a[i]].pos)
			{
				if(d[f[i]][0])t[a[i]].c=1;
				else t[a[i]].c=0;
				t[a[i]].pos=f[i];
				change(1,1,n,f[i],a[i]);
			}
			else if(t[a[i]].pos)
			{
				if(t[a[i]].pos==f[i])
				{
					change(1,1,n,f[i],a[i]);
					t[a[i]].pos=0;
				}
				else
				{
					ans[++tot][0]=2;
					ans[tot][1]=t[a[i]].pos;
					ans[tot][2]=f[i];
					change(1,1,n,t[a[i]].pos,a[i]);
				}
			}
		}
		printf("%d\n",tot);
		for(int i=1;i<=tot;++i)
		{
			if(ans[i][0]==1)printf("1 %d\n",ans[i][1]);
			else printf("2 %d %d\n",ans[i][1],ans[i][2]);
		}
		for(int i=1;i<=m;++i)f[i]=0;
	}
	return 0;
}
