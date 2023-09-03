#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
long long ans=0;//mod=18446744073709551616;
int t,n,Q;
long long a[250007],b[250007],treea[5000007],treeb[5000007];
int buildtreea(int ll,int rr,int deep)
{ int mid=(ll+rr-1)/2;
   //cout<<ll<<" "<<rr<<" "<<deep<<" "<<mid<<endl;
  if(ll==rr) 
   {treea[deep]=a[ll];
    return treea[deep];
   }
   else
   { treea[deep]=max(buildtreea(ll,mid,deep*2),buildtreea(mid+1,rr,deep*2+1));
     //cout<<ll<<" "<<rr<<" "<<treea[deep]<<" "<<deep<<endl;
     return treea[deep];
   	
   }
}
int buildtreeb(int ll,int rr,int deep)
{ int mid=(ll+rr-1)/2;
  if(ll==rr) 
   {treeb[deep]=b[ll];
    return treeb[deep];
   }
   else
   { treeb[deep]=max(buildtreeb(ll,mid,deep*2),buildtreeb(mid+1,rr,deep*2+1));
     return treeb[deep];
   	
   }
}
int finda(int nowl,int nowr,int nowd,int findl,int findr)
{    int mid=(nowl+nowr-1)/2;
    //  cout<<nowl<<" "<<nowr<<endl;   
      if(nowl>=findl&&nowr<=findr) {
	   //cout<<"flag";
	    return treea[nowd];

      }
     if(findr<=mid)
     {  //cout<<"flag2 ";
	    return finda(nowl,mid,nowd*2,findl,findr);
	 }
	 
	 if(mid<findl)
      { //cout<<"flag3 ";
	     return finda(mid+1,nowr,nowd*2+1,findl,findr);
	  }
	   
	   if(mid>=findl&&findr>=mid)
	      { //cout<<"flag4 ";
		  int left=finda(nowl,mid,nowd*2,findl,findr);
		  int right=finda(mid+1,nowr,nowd*2+1,findl,findr);
		  return max(left,right);
	     }
	      //else {
		 // return treea[nowd];
		  //cout<<"flag ";
	      //}
	     // cout<<nowl<<" "<<nowr<<" ";
	   
	 
	 //  cout<<nowl<<" "<<nowr<<endl;   
}
int findb(int nowl,int nowr,int nowd,int findl,int findr)
{    int mid=(nowl+nowr-1)/2;
    //  cout<<nowl<<" "<<nowr<<endl;   
      if(nowl>=findl&&nowr<=findr) {
	   //cout<<"flag";
	    return treeb[nowd];

      }
     if(findr<=mid)
     {  //cout<<"flag2 ";
	    return findb(nowl,mid,nowd*2,findl,findr);
	 }
	 
	 if(mid<findl)
      { //cout<<"flag3 ";
	     return findb(mid+1,nowr,nowd*2+1,findl,findr);
	  }
	   
	   if(mid>=findl&&findr>=mid)
	      { //cout<<"flag4 ";
		  int left=findb(nowl,mid,nowd*2,findl,findr);
		  int right=findb(mid+1,nowr,nowd*2+1,findl,findr);
		  return max(left,right);
	     }
	      //else {
		 // return treea[nowd];
		  //cout<<"flag ";
	      //}
	     // cout<<nowl<<" "<<nowr<<" ";
	   
	 
	 //  cout<<nowl<<" "<<nowr<<endl;   
}
void work1()
{
	long long maxa=-2e9,maxb=-2e9;
	for(int i=1;i<=Q;i++)
	{ int l,r;
	  scanf("%d%d",&l,&r);
	  for(int p=l;p<=r;p++)
	   for(int q=p;q<=r;q++)
	   { for(int k=p;k<=q;k++)
	      { maxa=max(maxa,a[k]);
		    maxb=max(maxb,b[k]);
		  }
		  ans+=maxa*maxb;
		  maxa=-2e9;
		  maxb=-2e9;
		//  cout<<p<<" "<<q<<" "<<ans<<endl;
		  
	   }
	   cout<<ans<<endl;
	}
}
void work2(){
	buildtreea(1,n,1);
	buildtreeb(1,n,1);
	long long maxa=0,maxb=0;
	for(int i=1;i<=Q;i++)
	{ int l,r;
	  scanf("%d%d",&l,&r);
	  for(int p=l;p<=r;p++)
	   for(int q=p;q<=r;q++)
	   { maxa=finda(1,n,1,p,q);
		 maxb=findb(1,n,1,p,q);
		// cout<<maxa<<" "<<maxb<<endl;
		 ans+=maxa*maxb;
	   }
      cout<<ans<<endl;
	}
// for(int i=1;i<=5;i++) cout<<treeb[i]<<" ";
	
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>t>>n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	cin>>Q;
    work2();
	
	return 0;
}
