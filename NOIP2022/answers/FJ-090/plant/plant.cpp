#include<iostream>
#include<cstring>
using namespace std;

string a[10000];
bool buc(int x1,int x2,int y0,int y1,int y2,int m){
	if(x1+1>=x2||y0>=y1||y2>=m){
		return false;
	}
	for(int i=y0;i<=y1;i++){
		if(a[x1][i]=='1'){
			return false;
		}
	}
	for(int i=y0;i<=y2;i++){
		if(a[x2][i]=='1'){
			return false;
		}
	}
	for(int i=x1;i<=x2;i++){
		if(a[x1][y0]=='1'){
			return false;
		}
	}
	return true;
}

int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,id,Vc=0,Vf=0;
	cin>>T>>id;
	for(int k=1;k<=T;k++){
		int n,m,c,f;
		cin>>n>>m>>c>>f;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
	}
	int e1=0,e2=0;
	cout<<e1<<" "<<e2;
	return 0;
}
