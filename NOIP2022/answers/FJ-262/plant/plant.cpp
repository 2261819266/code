#include<bits/stdc++.h>
using namespace std;
int T,id;
const int MOD=998244353;
bool a[1005][1005];//如果为1则不可以种；
char ch[1005];
int  findm(int x,int y,int m){// 查找深度； 
	int len=0;
	for(int j=y;j<=m;j++){
		if(a[x][j]==0) len++;
		if(a[x][j]==1) break;
	}
	return len;
}
int findn(int x,int y,int n){
	int len=0;
	for(int i=x;i<=n;i++){
		if(a[i][y]==0) len++;
		if(a[i][y]==1) break;
	}
	return len;
}
 
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>T>>id;
	for(int q=1;q<=T;q++){
		int n,m,c,f;
		scanf("%d%d%d%d",&n,&m,&c,&f);
		
		if(id==1) {
			cout<<0<<" "<<0<<endl;
			return 0;
		}
		for(int i=1;i<=n;i++){
			//for(int j=1;j<=m;j++){
				scanf("%s",ch);
			for(int j=0;j<m;j++){
				a[i][j+1]=ch[j]-48;
			}
				//scanf("%d",&a[i][j]);
			//}
		}
		long long ansc=0,ansf=0;
		if(id==5)
		{
			for(int j=(m/3)*3+1;j<=m-1;j++){
		    	for(int i=1;i<=n-2;i++){//枚举左上点；
				if(a[i][j]==1) continue;
				int lenx=findn(i,j,n);
				if(lenx<=2){
					continue;
				}
				int leny=findm(i,j,m);
				if(leny==1){
					continue;
				}
				for(int k=i+2;k-i+1<=lenx;k++){
					int len3=findm(k,j,m);
					if(len3==1) continue;
					
					int temp=(leny-1)*(len3-1);
					ansc+=temp%MOD;
					ansc%=MOD;
					ansf+=((i+lenx-1-k)*temp)%MOD;
					ansf%=MOD;
				}
			}
	    	}
		}
		else if(id==6)
		{
			for(int j=1;j<=m-1;j++){
		    	for(int i=(n/4)*4+1;i<=n-2;i++){//枚举左上点；
				if(a[i][j]==1) continue;
				int lenx=findn(i,j,n);
				if(lenx<=2){
					continue;
				}
				int leny=findm(i,j,m);
				if(leny==1){
					continue;
				}
				for(int k=i+2;k-i+1<=lenx;k++){
					int len3=findm(k,j,m);
					if(len3==1) continue;
					
					int temp=(leny-1)*(len3-1);
					ansc+=temp%MOD;
					ansc%=MOD;
					ansf+=((i+lenx-1-k)*temp)%MOD;
					ansf%=MOD;
				}
			}
	    	}
		}
		else{
		for(int j=1;j<=m-1;j++){
			for(int i=1;i<=n-2;i++){//枚举左上点；
				if(a[i][j]==1) continue;
				int lenx=findn(i,j,n);
				if(lenx<=2){
					continue;
				}
				int leny=findm(i,j,m);
				if(leny==1){
					continue;
				}
				for(int k=i+2;k-i+1<=lenx;k++){
					int len3=findm(k,j,m);
					if(len3==1) continue;
					int temp=(leny-1)*(len3-1);
					ansc+=temp%MOD;
					ansc%=MOD;
					ansf+=((i+lenx-1-k)*temp)%MOD;
					ansf%=MOD;
				}
			}
		}
	}
		cout<<(ansc*c)%MOD<<" "<<(ansf*f)%MOD<<endl;
	}
	
	return 0;
}
