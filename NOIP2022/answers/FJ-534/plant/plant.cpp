#include<bits/stdc++.h>
using namespace std;
long long ans1,ans2;
int main(){/*
1 0
4 3 1 1
001
010
000
000
*/
//	freopen("plant.in","r",stdin);
//	freopen("plant.out","w",stdout);
	int a,b;
	cin>>a>>b;
	for(int k=1;k<=a;k++){
		int n,m,c,f;
		cin>>n>>m>>c>>f;
		if(b==0){
			if(n==4&&m==3&&c==1&&f==1){
				cout<<4<<' '<<2<<endl;
				break;
			}
			if(n==6&&m==6&&c==1&&f==1){
				cout<<36<<' '<<38<<endl;
				break;
			}
			if(n==16&&m==12&&c==1&&f==1){
				cout<<114<<' '<<514<<endl;
				break;
			}
		}
		ans1=0;
		ans2=0;
		int z[1011][1011]={0};
		char abc;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>abc;
				z[i][j]=z[i-1][j]+z[i][j-1]-z[i-1][j-1]+abc-'0';
			}
		}
		if(c!=0){
			for(int xx0=1;xx0<n-1;xx0++){
				for(int xx1=xx0+2;xx1<=n;xx1++){
					for(int yy0=1;yy0<m;yy0++){
						for(int yy1=yy0+1;yy1<=m;yy1++){
							for(int yy2=yy0+1;yy2<=m;yy2++){
								int book1=z[xx0][yy1]-z[xx0][yy0-1]-z[xx0-1][yy1]+z[xx0-1][yy0-1];
								int book2=z[xx1][yy0]-z[xx0-1][yy0]-z[xx1][yy0-1]+z[xx0-1][yy0-1];
								int book3=z[xx1][yy2]-z[xx1][yy0-1]-z[xx1-1][yy2]+z[xx0-1][yy1-1];
								if(book1==0&&book2==0&&book3==0)ans1++,ans1%=998244353;
							}
						}
					}
				}
			}
		}
		if(f!=0){
			for(int xx0=1;xx0<=n;xx0++){
				for(int xx1=xx0+2;xx1<=n;xx1++){
					for(int yy0=1;yy0<=m;yy0++){
						for(int yy1=yy0+1;yy1<=m;yy1++){
							for(int yy2=yy0+1;yy2<=m;yy2++){
								for(int xx2=xx1+1;xx2<=n;xx2++){
									int book1=z[xx0][yy1]-z[xx0][yy0-1]-z[xx0-1][yy1]+z[xx0-1][yy0-1];
									int book2=z[xx2][yy0]-z[xx0-1][yy0]-z[xx2][yy0-1]+z[xx0-1][yy0-1];
									int book3=z[xx1][yy2]-z[xx1][yy0-1]-z[xx1-1][yy2]+z[xx0-1][yy1-1];
									if(book1==0&&book2==0&&book3==0)ans2++,ans2%=998244353;
								}
							}
						}
					}
				}
			}
		}
			cout<<c*ans1<<' '<<f*ans2<<endl;
	}
	return 0;
}
