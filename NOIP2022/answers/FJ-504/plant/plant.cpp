#include<bits/stdc++.h>
using namespace std;

#define mod 998244353
int T,ID;
int n,m,c,f;
string a[1005];

//void Debug_c(int x1,int x2,int yo,int yl,int y2){
//	cout<<"x1="<<x1<<",x2="<<x2<<",y0="<<yo<<",y1="<<yl<<",y2="<<y2<<"\n";
//	for(int i=0;i<n;i++){
//		for(int j=0;j<m;j++){
//			if(x1<=i&&i<=x2&&yo==j)cout<<('*');
//			else if(x1==i&&yo<=j&&j<=yl)cout<<('*');
//			else if(x2==i&&yo<=j&&j<=y2)cout<<('*');
//			else cout<<a[i][j];
//		}
//		cout<<("\n");
//	}
//}
//
//void Debug_f(int x1,int x2,int x3,int yo,int yl,int y2){
//	cout<<"x1="<<x1<<",x2="<<x2<<",x3="<<x3<<",y0="<<yo<<",y1="<<yl<<",y2="<<y2<<"\n";
//	for(int i=0;i<n;i++){
//		for(int j=0;j<m;j++){
//			if(x1<=i&&i<=x3&&yo==j)cout<<('*');
//			else if(x1==i&&yo<=j&&j<=yl)cout<<('*');
//			else if(x2==i&&yo<=j&&j<=y2)cout<<('*');
//			else cout<<a[i][j];
//		}
//		cout<<("\n");
//	}
//}

int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T>>ID;
	while(T--){
		cin>>n>>m>>c>>f;
		int Vc=0,Vf=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		if(c){
			for(int x1=0;x1<n;x1++){
				for(int x2=x1+2;x2<n;x2++){
					for(int yo=0;yo<m;yo++){
						for(int yl=yo+1;yl<m;yl++){
							for(int y2=yo+1;y2<m;y2++){
								bool flag=false;
								/* TODO (#1#): check[1] */
								for(int j=yo;j<=yl;j++){
									if(a[x1][j]=='1'){
										flag=true;
										break;
									}
								}
								if(flag)break;
								/* TODO (#1#): check[1] */
								/* TODO (#1#): check[2] */
								for(int i=x1;i<=x2;i++){
									if(a[i][yo]=='1'){
										flag=true;
										break;
									}
								}
								if(flag)break;
								/* TODO (#1#): check[2] */
								/* TODO (#1#): check[3] */
								for(int j=yo;j<=y2;j++){
									if(a[x2][j]=='1'){
										flag=true;
										break;
									}
								}
								if(flag)break;
								/* TODO (#1#): check[3] */
								
								/* TODO (#1#): Debug */
//								Debug_c(x1,x2,yo,yl,y2);
								/* TODO (#1#): Debug */
								
								Vc++;
								if(Vc>=mod)Vc-=mod;
							}
						}
					}
				}
			}
			cout<<Vc<<" ";
		}
		else cout<<"0 ";
		if(f){
			for(int x1=0;x1<n;x1++){
				for(int x2=x1+2;x2<n;x2++){
					for(int x3=x2+1;x3<n;x3++){
						for(int yo=0;yo<m;yo++){
							for(int yl=yo+1;yl<m;yl++){
								for(int y2=yo+1;y2<m;y2++){
									//check 1
									bool flag=false;
									for(int j=yo;j<=yl;j++){
										if(a[x1][j]=='1'){
											flag=true;
											break;
										}
									}
									if(flag)break;
									//check 1
									//check 2
									for(int i=x1;i<=x3;i++){
										if(a[i][yo]=='1'){
											flag=true;
											break;
										}
									}
									if(flag)break;
									//check 2
									//check 3
									for(int j=yo;j<=y2;j++){
										if(a[x2][j]=='1'){
											flag=true;
											break;
										}
									}
									if(flag)break;
									//check 3
									
									//Debug
//									Debug_f(x1,x2,x3,yo,yl,y2);
									//Debug
									
									Vf++;
									if(Vf>=mod)Vf-=mod;
								}
							}
						}
					}
				}
			}
			cout<<Vf<<"\n";
		}
		else cout<<"0\n";
	}
	return 0;
}

//NOIP ti yan sai zhen hao wan.