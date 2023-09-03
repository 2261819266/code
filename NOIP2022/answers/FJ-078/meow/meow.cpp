#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<iterator>
#include<map>
using namespace std;
int m,n,a[1000001],c[301]={0},d[301]={0},b[1000001][3],g,f,t,p=0,q=0,u[1000001],l=0,r=0;
queue<int> ss[301];
inline int rd()
{
	int l=1,r=0;
	char s=getchar();
	while(s<'0'||s>'9')
	{
		if(s=='-')l=-1;
		s=getchar();
	}
	while(s>='0'&&s<='9')
	{
		r=r*10+s-'0';
		s=getchar();
	}
	return l*r;
}
inline void nsn(int k)
{
	//cout<<"op"<<endl;
	if(c[k]==0)return;
	for(int i=1;i<=p;i++)
	{
		if(i==k)continue;
		//cout<<ss[i].front()<<" "<<ss[k].front()<<endl;
		if(ss[i].front()==ss[k].front())
		{
			ss[i].pop();
			c[i]--;
			ss[k].pop();
			c[k]--;
			l++;
			b[l+r][0]=2;
			b[l+r][1]=d[min(i,k)];
			b[l+r][2]=d[max(i,k)];
			if(c[k]==0)
			{
				swap(ss[k],ss[p]);
				swap(c[k],c[p]);
				swap(d[k],d[p]);
				p--;
			}
			if(c[i]==0)
			{
				swap(ss[i],ss[p]);
				swap(c[i],c[p]);
				swap(d[i],d[p]);
				p--;
			}
			nsn(i);
			break;
		}
	}
}
inline void cwx(int k,int kk,queue<int>cc[])
{
	int v=p,ccc[301],dd[301];
	for(int i=1;i<=n;i++)
	ccc[i]=c[i],cc[i]=ss[i],dd[i]=d[i];
	if(k==m+1)
	{
		if(p==0)
		{
			g=1;
			printf("%d\n",kk-1);
			for(int i=1;i<=kk-1;i++)
			{
				if(b[i][0]==1)
				printf("%d %d\n",b[i][0],b[i][1]);
				if(b[i][0]==2)
				printf("%d %d %d\n",b[i][0],b[i][1],b[i][2]);
			}
			return;
		}
	}
	else
	for(int i=1;i<=min(p+1,n);i++)
	{
		if(i==p+1)
		{
			p++;
			ss[p].push(a[k]);
			//cout<<a[k]<<endl<<endl;
			b[kk][0]=1;
			b[kk][1]=d[p];
			c[p]++;
			l=0,r=kk;
			nsn(p);
			cwx(k+1,kk+1+l,ss);
			if(g==1)return;
			c[p]--;
			p=v;
			for(int i=1;i<=n;i++)
			c[i]=ccc[i],ss[i]=cc[i],d[i]=dd[i];
		}
		else
		{
			if(a[k]==ss[i].back())
			{
				c[i]--;
				for(int i=1;i<=c[i]+1;i++)
				{
					u[i]=ss[i].front();
					ss[i].pop();
				}
				for(int i=1;i<=c[i];i++)
				{
					ss[i].push(u[i]);
				}
				b[kk][0]=1;
				b[kk][1]=d[i];
				if(c[i]==0)
				{
					swap(ss[i],ss[p]);
					swap(c[i],c[p]);
					swap(d[i],d[p]);
					p--;
				}
			}
			else
			{
				c[i]++;
				ss[i].push(a[k]);
				b[kk][0]=1;
				b[kk][1]=d[i];
			}
			cwx(k+1,kk+1,ss);
			if(g==1)return;
			p=v;
			for(int i=1;i<=n;i++)
			c[i]=ccc[i],ss[i]=cc[i],d[i]=dd[i];
		}
	}
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	t=rd();
	while(t--)
	{
		g=0;
		n=rd();
		m=rd();
		f=rd();
		memset(c,0,sizeof(c));
		p=0;
		for(int i=1;i<=n;i++)
		d[i]=i;
		for(int i=1;i<=m;i++)
		{
			a[i]=rd();
		}
		cwx(1,1,ss);
	}
	return 0;
}
