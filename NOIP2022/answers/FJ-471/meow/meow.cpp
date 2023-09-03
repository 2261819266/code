#include<bits/stdc++.h>
using namespace std;
struct ny
{
	int g,ks,js,nl[1000050];
};
int T,zd,n,m,k,p[1000050],kz,op,gs;
ny z[305];
void sc(int x)
{
	for(int i=x;i<z[zd].g;i++)z[zd].nl[x]=z[zd].nl[x+1];
}
bool xz2(int x)
{
	for(int i=1;i<=z[1].g;i++)
	{
		if(z[1].nl[i]==x)return true;
	}
	return false;
}
bool xz(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(p[x]==z[i].js||p[x]==z[i].ks)
		{
			zd=i;
			return true;
		}
	}
	return false;
}
void xz3()
{
	for(int i=1;i<=n;i++)
	{
		if(z[i].g==0)
		{
			gs=i;
			return;
		}
	}
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		memset(z,0,sizeof(z));
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++)cin>>p[i];
		z[1].nl[1]=p[1];
		z[1].ks=z[1].js=p[1];
		z[1].g=1;
		op=1;
		for(int i=2;i<=m;i++)
		{
			if(xz(p[i])==true)
			{
				if(p[i]==z[zd].js)
				{
					op++;
					z[zd].g--;
					continue;
				}
				if(p[i]==z[zd].ks)
				{
					z[zd].nl[zd]=1;
					sc(1);
					op+=2;
					continue;
				}
			}
			if(xz2(p[i])==false)
			{
				z[1].g++;
			}
			else
			{
				z[2].g++;
			}
		}
		cout<<op<<endl;
		cout<<"1 1"<<endl;
		for(int i=2;i<=m;i++)
		{
			if(xz(p[i])==true)
			{
				if(p[i]==z[zd].js)
				{
					cout<<"1 "<<zd<<endl;
					op++;
					z[zd].nl[g]=0;
					z[zd].g--;
					z[zd].js=z[zd].nl[g];
					continue;
				}
				if(p[i]==z[zd].ks)
				{
					xz3();
					cout<<"2 "<<zd<<" "<<gs<<endl;
					z[zd].nl[zd]=1;
					sc(1);
					op+=2;
					continue;
				}
			}
			if(xz2(p[i])==false)
			{
				cout<<"1 1"<<endl;
			}
			else
			{
				cout<<"1 2"<<endl;
			}
		}
	}
	
	return 0;
}
