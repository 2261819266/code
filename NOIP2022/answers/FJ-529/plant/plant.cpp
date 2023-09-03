//#include<iostream>
//#include<stdio.h>
#include<bits/stdc++.h>
#define fon(n,i) for(int i=1;i<=n;i++)
#define fen(k,n,i) for(int i=k;i<=n;i++)
#define mo(i) i%998244353
#define MAXN ( 1010 )
using namespace std;
int T,id,n,m,c,f,vc,vf,a[MAXN][MAXN];
void chef(int y,int x,int u,int h){
//	printf("%d %d %d %d ",x,y,h,u);
	int s=0; 
	fen(x+1,n,i){
		if(a[i][y]){
			break;
		}
		s++;
	}
//	cout<<s*u*h<<endl;
	vf+=s*u*h;
	return ;
}
void chec(int x=0,int y=0)
{
//	printf("%d %d \n",x,y);
	if(a[x][y]==1) return ;
	int h=0;
	fen(y+1,m,j){
		if(a[x][j]==1){
			break;
		}
		h++;
	}
//	cout<<"	"<<h<<"\n";
	if(h==0) return ;
	int ans=0,u=0;
	if(a[x+1][y]==1) return ;
	fen(x+2,n,i){
		if(a[i][y]==1) break;
		u=0;
		fen(y+1,m,j){
			if(a[i][j]==1){
				break;
			}
			u++;
		}
		ans+=u;
//		cout<<"  "<<u;
		if(f==1&&i<n&&u!=0) chef(y,i,u,h);
	}
//		cout<<"\n "<<ans<<endl;
//	cout<<ans*h<<"\n";
	vc+=ans*h;
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d%d%d%d%d",&T,&id,&n,&m,&c,&f);
	vc=c;vf=f;
	char t[1002];
	for(int i=1;i<=n;i++){
		cin>>t;
		for(int j=1;j<=m;j++){
			a[i][j]=t[j-1]-'0';
//			cout<<a[i][j]<<" ";
		}
//		cout<<endl;
	}
	if(c){
		vc=0,vf=0;
		fon(n-2,i){
			fon(m-1,j) chec(i,j);
		}
	}
//	if(f) chef();
	printf("%d %d\n",mo(vc),mo(vf));
	return 0;
}
