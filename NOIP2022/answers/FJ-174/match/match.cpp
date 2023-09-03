#include<bits/stdc++.h>
using namespace std;
int n,m,id,maa,mab,l,r,ans;
int a[10010];
int b[10010];
int main()
{
  freopen("match.in","r",stdin);
  freopen("match.out","w",stdout);
  cin>>id>>n;
  for(int i=1;i<=n;i++)
    cin>>a[i];
  for(int i=1;i<=n;i++)
    cin>>b[i];
  cin>>m;
  for(int l=1;l<=m;l++)
  {
  	cin>>l>>r;
  	int maa=mab=0;
  	ans=0;
  	for(int i=l;i<=r;i++)
  	  for(int j=i;j<=r;j++)
  	  {
  	  	maa=mab=0;
  	    for(int k=i;k<=j;k++)
  	      maa=max(a[k],maa),mab=max(b[k],mab);
  	    ans+=maa*mab;
  	  }
  	cout<<ans<<endl;
  }
  return 0;
}

