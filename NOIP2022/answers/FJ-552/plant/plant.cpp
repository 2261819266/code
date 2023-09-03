#include<bits/stdc++.h>
using namespace std;
long long p=998244353;
int n,m,c,f,t,id;
char a[1005][1005];
long long ans_c,ans_f;
void pdC(){
	int ans_C;
	for(int i=1;i<=n-1;i++){
//		for(int j=1;j<=m-1;j++){
//			cout<<"i="<<i<<" ";
			int x=1,y=1,z=-1;
			while(a[i][x]!='1'&&x<=m){
				x++;
			}
			x--;
//			cout<<"x="<<x;
			while(a[y][i]!='1'&&y<=n){
				y++;
			}
			y--;
//			cout<<" y="<<y<<" ";
			if(x>=2&&y>=3){
				int y1=y;
				while(y1>=3){
					while(a[y1][z]!='1'&&z<=m){
						z++;
					}
					z--;y1--;
//					cout<<"z="<<z<<endl;
					if(z>=2){
						ans_C=(x-1)*(z-1);
						ans_c+=ans_C;
//						cout<<"ans_c="<<ans_c<<endl;
					}
				}
			}
//		}
	}
}
void pdF(){
	int ans_F;
	for(int i=1;i<=n-3;i++){
//		cout<<"i="<<i<<" ";
		int x=1,y=1,z=-1;
		while(a[i][x]!='1'&&x<=m){
			x++;
		}
		x--;
//		cout<<"x="<<x<<" ";
		while(a[y][i]!='1'&&y<=n){
			y++;
		}
		y--;
//		cout<<"y="<<y<<" ";
		if(x>=2&&y>=4){
			int y1=y-1;
			while(y1>=3){
				while(a[y1][z]!='1'&&z<=m){
					z++;
				}
				z--;y1--;
//				cout<<"z="<<z<<endl;
				if(z>=2){
					ans_F=(x-1)*(z-1);
					ans_f+=ans_F;
//					cout<<"ans_f="<<ans_f<<endl;
				}
			}
		}
	}
}	
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdin);	
	cin>>t>>id;
	while(t--){
		ans_c=ans_f=0;
		cin>>n>>m>>c>>f;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
//		cout<<"C..."<<endl;
		pdC();
//		cout<<"F..."<<endl;
		pdF();
		ans_c%=p;
		ans_f%=p;
		cout<<ans_c<<" "<<ans_f<<endl;
	}
	return 0;
}
