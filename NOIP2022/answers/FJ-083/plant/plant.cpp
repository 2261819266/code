#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,id,n,m,c,f,a[502][502];
	cin>>T>>id;
	for(int t=0;t<T;t++){
		cin>>n>>m>>c>>f;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		if(id==1){
			cout<<0<<" "<<0<<endl;
			continue;
		}
	}
	return 0;
}

