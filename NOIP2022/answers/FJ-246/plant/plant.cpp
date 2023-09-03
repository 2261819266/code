#include<iostream>
#include<cstdio>
using namespace std;
int T,id;
int n,m,c,f;
int a[1010][1010];
int sr[1010][1010];
int sc[1010][1010];
long long vc,vf;
const int md = 998244353;
int main(){
  freopen("plant.in","r",stdin);
  freopen("plant.out","w",stdout);
	cin>>T>>id;
	while(T--){
		cin>>n>>m>>c>>f;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%1d",&a[i][j]);
				sr[i][j]=sr[i][j-1]+a[i][j];
				sc[i][j]=sc[i-1][j]+a[i][j];
			}
		}
		vc=vf=0;
		if(c==0 && f==0){
			cout<<"0 0"<<endl;
			continue;
		}
		//
		for(int x1=1;x1<=n;x1++){
			for(int x2=x1+2;x2<=n;x2++){
				for(int y1=1;y1<=m;y1++){
					if(sc[x2][y1]-sc[x1-1][y1]>0) continue;
					int l,r,y2,y3,x3;
					//
					l=y1;r=m;
					while(l<r){
						int mid=(l+r)>>1;
						if(l == mid) mid++;
						if(sr[x1][mid]-sr[x1][y1-1]>0){
							r=mid-1;
						}
						else{
							l=mid;
						}
					}
					y2=l;
					l=y1;r=m;
					while(l<r){
						int mid=(l+r)>>1;
						if(l == mid) mid++;
						if(sr[x2][mid]-sr[x2][y1-1]>0){
							r=mid-1;
						}
						else{
							l=mid;
						}
					}
					y3=l;
					//
					vc+=(y2-y1)*(y3-y1);
					vc%=md;
					//
					if(x2 == n || a[x2+1][y1] || f==0) continue;
					l=x2+1,r=n;
					while(l<r){
						int mid = (l+r)>>1;
						if(l == mid) mid++;
						if(sc[mid][y1]-sc[x2-1][y1]>0){
							r = mid-1;
						}
						else{
							l = mid;
						}
					}
					x3=l;
					vf+=(y2-y1)*(y3-y1)*(x3-x2);
					vf%=md;
				}
			}
		}
		//
		cout<<vc*c<<" "<<vf*f<<endl;
	}
	return 0;
}

