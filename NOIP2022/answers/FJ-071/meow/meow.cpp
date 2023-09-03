#include<bits/stdc++.h>
using namespace std;
int a[2000010];
struct node{
	int to,ed;
}T[501];
inline int xsq(int x,int y)
{
	int cc=x/y;
	if(y*cc==x) return cc;
	else return cc+1; 
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);	
	int t;
	cin>>t;
	while(t--)
	{
			memset(a,0,sizeof a);
			memset(T,0,sizeof 0);
			int n,m,k,tot=0;
			cin>>n>>m>>k;
			for(int i=1;i<=m;i++){
				cin>>a[i];
				if(T[xsq(a[i],2)].ed==0){
					tot++,T[xsq(a[i],2)].ed=a[i];
				}else{
					if(T[xsq(a[i],2)].to==0){
						tot++,T[xsq(a[i],2)].to=a[i];
					}else{
						if(T[xsq(a[i],2)].to==a[i]){
							tot+=1,T[xsq(a[i],2)].to=0;
						}else{
							tot+=2,T[xsq(a[i],2)].ed=T[xsq(a[i],2)].to,T[xsq(a[i],2)].to=0;
						}
                   	}
				}
			}
			memset(T,0,sizeof T);
			cout<<tot<<endl;
			for(int i=1;i<=m;i++){
				if(T[xsq(a[i],2)].ed==0){
					T[(xsq(a[i],2))].ed=a[i],cout<<1<<" "<<xsq(a[i],2)<<endl;
				}else{
					if(T[xsq(a[i],2)].to==0){
						T[xsq(a[i],2)].to=a[i],cout<<1<<" "<<xsq(a[i],2)<<endl;	
					}else{
						if(T[xsq(a[i],2)].to==a[i]){
							T[xsq(a[i],2)].to=0,cout<<1<<" "<<xsq(a[i],2)<<endl;	
						}else{
							T[xsq(a[i],2)].ed=T[xsq(a[i],2)].to,T[xsq(a[i],2)].to=0,cout<<1<<" "<<n<<endl;cout<<2<<" "<<xsq(a[i],2)<<" "<<n<<endl; 	
						} 
					} 
				
				} 
			}
	} 
		
}

