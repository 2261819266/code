#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,m,k,a[305],s1[605],s2[605],s3[605],cnt[605],tot1,tot2,tot3,p;
bool flag;
int Max(int u,int v)
{
	if(u<=v) u=v;
	return u;
}
void Check1()
{
	tot1=0,tot2=0,tot3=0,p=0;
	for(int i=1;i<=2*m;i++)
	{
		if(cnt[i]==0)
		{
			s1[++tot1]=a[++p];
			if(s1[tot1]==s1[tot1-1])
			{
				s1[tot1]=0;
				s1[tot1-1]=0;
				tot1-=2;
			}
			
		}
		if(cnt[i]==1)
		{
			s2[++tot2]=a[++p];
			if(s2[tot2]==s2[tot2-1])
			{
				s2[tot2]=0;
				s2[tot2-1]=0;
				tot2-=2;
			}
		}
		if(cnt[i]==2)
		{
			while(s1[1]==s2[1]&&s1[1]!=0)
			{
				s1[1]=0;
				s2[1]=0;
				for(int i=1;i<=Max(tot1,tot2);i++)
				{
					s1[i]=s1[i+1];
					s2[i]=s2[i+1];
				}
				tot1--;
				tot2--;
			}
	}
	if(tot1==0&&tot2==0&&p==m)
	{
		cout<<i<<endl;
	        for(int j=1;j<=i;j++)
	       {
		      if(cnt[j]<=1)
		      {
		      	cout<<1<<" "<<cnt[j]+1;
			  }
			  if(cnt[j]==2)
			  {
			  	cout<<2<<" "<<1<<" "<<2;
			  }
			  cout<<endl;
	       }
	        flag=1;
	        return ;
	}
   }
}
void dfs1(int sum)
{
	if(flag==1) return ;
	if(sum==2*m+1)
	{
		Check1();
		return ;
	}
	cnt[sum]=0;
	dfs1(sum+1);
	cnt[sum]=1;
	dfs1(sum+1);
	cnt[sum]=2;
	dfs1(sum+1);
}
void Check2()
{
	tot1=0,tot2=0,tot3=0,p=0;
	for(int i=1;i<=2*m;i++)
	{
		if(cnt[i]==0)
		{
			s1[++tot1]=a[++p];
			if(s1[tot1]==s1[tot1-1])
			{
				s1[tot1]=0;
				s1[tot1-1]=0;
				tot1-=2;
			}
			
		}
		if(cnt[i]==1)
		{
			s2[++tot2]=a[++p];
			if(s2[tot2]==s2[tot2-1])
			{
				s2[tot2]=0;
				s2[tot2-1]=0;
				tot2-=2;
			}
		}
		if(cnt[i]==2)
		{
			s3[++tot3]=a[++p];
			if(s3[tot3]==s3[tot3-1])
			{
				s3[tot3]=0;
				s3[tot3-1]=0;
				tot3-=2;
			}
		}
		if(cnt[i]==3)
		{
			while(s1[1]==s2[1]&&s1[1]!=0)
			{
				s1[1]=0;
				s2[1]=0;
				for(int i=1;i<=Max(tot1,tot2);i++)
				{
					s1[i]=s1[i+1];
					s2[i]=s2[i+1];
				}
				tot1--;
				tot2--;
			}
	    }
	    if(cnt[i]==4)
		{
			while(s1[1]==s3[1]&&s1[1]!=0)
			{
				s1[1]=0;
				s3[1]=0;
				for(int i=1;i<=Max(tot1,tot3);i++)
				{
					s1[i]=s1[i+1];
					s3[i]=s3[i+1];
				}
				tot1--;
				tot3--;
			}
	    }
	    if(cnt[i]==5)
	    {
	    	while(s2[1]==s3[1]&&s2[1]!=0)
			{
				s2[1]=0;
				s3[1]=0;
				for(int i=1;i<=Max(tot2,tot3);i++)
				{
					s2[i]=s2[i+1];
					s3[i]=s3[i+1];
				}
				tot2--;
				tot3--;
			}
		}
	if(tot1==0&&tot2==0&&tot3==0&&p==m)
	{
		cout<<i<<endl;
	        for(int j=1;j<=i;j++)
	       {
		      if(cnt[j]<=2)
		      {
		      	cout<<1<<" "<<cnt[j]+1;
			  }
			  if(cnt[j]==3)
			  {
			  	cout<<2<<""<<1<<" "<<2;
			  }
			  if(cnt[j]==4)
			  {
			  	cout<<2<<""<<1<<" "<<3;
			  }
			  if(cnt[j]==5)
			  {
			  	cout<<2<<""<<2<<" "<<3;
			  }
			  cout<<endl;
	       }
	        flag=1;
	        return ;
	}
   }
}
void dfs2(int sum)
{
	if(flag==1) return ;
	if(sum==2*m+1)
	{
		Check2();
		return ;
	}
	cnt[sum]=0;
	dfs2(sum+1);
	cnt[sum]=1;
	dfs2(sum+1);
	cnt[sum]=2;
	dfs2(sum+1);
	cnt[sum]=3;
	dfs2(sum+1);
	cnt[sum]=4;
	dfs2(sum+1);
	cnt[sum]=5;
	dfs2(sum+1);
}
signed main()
{
   freopen("meow.in","r",stdin);
   freopen("meow.out","w",stdout);
   cin>>t;
   for(int i=1;i<=t;i++)
   {
   	cin>>n>>m>>k;
   	for(int j=1;j<=m;j++)
   	{
   		cin>>a[j];
	   }
	   flag=0;
	   if(n==2) dfs1(1);
	   else dfs2(1);
   }
   return 0;
}


