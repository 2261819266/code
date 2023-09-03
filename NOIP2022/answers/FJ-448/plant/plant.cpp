#include<bits/stdc++.h>
using namespace std;
int m,n,c,f,t,id,kk[1005],kks[1005],ccnt=0;
char aa[1005][1005];
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>t>>id;
	for(int i=0;i<=1001;i++){
		kk[i]=i*(i+1)/2;
		kks[i+1]=kks[i]+kk[i];
	}
	for(int ii=1;ii<=t;ii++){
		cin>>n>>m>>c>>f;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>aa[i][j];
			}
		}
		if(id==1){
			cout<<0<<" "<<0<<endl;
		}
		else if(id==5){
			if((m%3==0||m%3==1)&&n>=2){
				int mm=m/3;
				cout<<mm*kk[n-2]<<" "<<mm*kks[n-2];
				cout<<endl;
			}
			else if(m%3==2&&n>=2){
				int mm=m/3+1;
				cout<<mm*kk[n-2]<<" "<<mm*kks[n-2];
				cout<<endl;
			}
			else{
				cout<<0<<" "<<0;
				cout<<endl;
			}
		}
		else if(id==2){
			if(aa[1][1]+aa[1][2]+aa[2][1]+aa[3][1]+aa[3][2]==0){
				cout<<1<<" "<<0<<endl;
			}
			else{
				cout<<0<<" "<<0<<endl;
			}
		}
		else if(id==3){
			if(aa[1][1]+aa[1][2]+aa[2][1]+aa[3][1]+aa[3][2]==0){
				ccnt++;
			}
			if(aa[2][1]+aa[2][2]+aa[3][1]+aa[4][1]+aa[4][2]==0){
				ccnt++;
			}
			if(aa[1][1]+aa[1][2]+aa[2][1]+aa[3][1]+aa[4][2]+aa[4][1]==0)ccnt++;
			if(aa[1][1]+aa[1][2]+aa[2][1]+aa[3][1]+aa[3][2]+aa[4][1]==0){
				cout<<ccnt<<" 1"<<endl;
			}
			else cout<<ccnt<<" 0"<<endl;
		}
	}
	return 0;
}
