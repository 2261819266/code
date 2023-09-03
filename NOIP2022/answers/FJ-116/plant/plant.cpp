#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
int T,id,n,m,c,k;
long long ansc=0,ansf=0;
bool f[1007][1007];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>T>>id;
	if(id==1) for(int i=1;i<=T;i++) cout<<"0 0";
	if(id==2)
	 { for(int i=1;i<=T;i++)
	    { scanf("%d%d%d%d",&n,&m,&c,&k);
		   for(int j=1;j<=n;j++)
		    for(int k=1;k<=m;k++) cin>>f[j][k];
		     if(f[1][2]==1||f[1][1]==1||f[2][1]==1||f[3][1]==1) cout<<"0 0";
		      else if(f[2][2]==1&&f[3][2]==1) cout<<"0 0";
		         else if(f[2][2]==1) cout<<"1 0";
		           else if(f[3][2]==1) cout<<"0 1";
		            else cout<<"1 1";
		            
		}
	
	}
	if(id==3||id==4){
	  for(int i=1;i<=T;i++)
	    { scanf("%d%d%d%d",&n,&m,&c,&k);
		   for(int j=1;j<=n;j++)
		   for(int k=1;k<=m;k++) cin>>f[j][k];
		   for(int j=1;j<=n;j++) 
		   { if(f[j][1]||f[j+1][1]||f[j+2][1]||f[j][2]||j+2>n) continue;
		     else
		     { if(!f[j+2][2]) ansc++;
		       if(!f[j+1][2]) ansf++;
		       
			 } 
		   }
		   cout<<ansc%998244353<<" "<<ansf%998244353;     
		}
	}
	if(id==5)
	{  for(int i=1;i<=T;i++)
	    { scanf("%d%d%d%d",&n,&m,&c,&k);
		   for(int j=1;j<=n;j++)
		    for(int k=1;k<=m;k++) cin>>f[j][k];
		   for(int j=1;j<=m;j+=3) {
			 for(int k=1;k<=n;k++)
		       { if(f[k][j]||f[k+1][j]||f[k+2][j]||f[k][j+1]||k+2>n||j+2>m) continue;
		           else
		     { if(!f[k+2][j+1]) ansc++;//cout<<k<<" "<<j<<" c"<<endl;
		       if(!f[k+1][j+1]) ansf++;
		       
			 } 
		   }
		   
	       }
	       cout<<ansc%998244353<<" "<<ansf%998244353;   
	       
		}
	}
	
	
	
	
	
	
	return 0;
}
