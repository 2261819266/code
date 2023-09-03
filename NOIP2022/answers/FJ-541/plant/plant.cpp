#include <bits/stdc++.h>
using namespace std;
const int mod_=998244353;
bool b[1000][1000];
short nor[1000][1001],nod[1001][1000];//nor每一行最后一列用于存储当前位置 ，nod每一列最后一行用于储存当前位置 
int t,id,n,m,c,f,vc,vf,x,y,z;
int find_right(int j,int k){//找坑软件（右侧）   
	for(int l=0;l<nor[j][1000];l++){//查j行在k右侧的第一个坑 
		//cout << nor[j][l] << endl;
		if(nor[j][l]>k){
			return nor[j][l]-k; 
		}
	}
	return m-k;
}
int find_down(int j,int k){//找坑软件（下方）  
	for(int l=0;l<nod[1000][k];l++){//查j行在k下方的第一个坑 
		//cout << nod[l][k] << endl;
		if(nod[l][k]>j){
			return nod[l][k]-j; 
		}
	}
	return n-j;
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin >> t >> id;
	char a;
	for (int i=0;i<t;i++){
		//初始化和输入 
		vc=0,vf=0;
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int j=0;j<n;j++){
			for (int k=0;k<m;k++){
				cin >> a;
				if(a=='1'){
					b[j][k]=true; 
					nor[j][nor[j][1000]]=k;
					nod[nod[1000][k]][k]=j;
					nor[j][1000]++;
					nod[1000][k]++;
				}else{
					b[j][k]=false;
				}
			}
		}
		if(c==0&&f==0){//特判水1分 
			cout << 0 << " " << 0 << endl;
			continue;
		}
		//C形字样
		for(int j=0;j<n-2;j++){//倒数第一行和第二行不可能产生合法的点位（C的左上角） 
			for(int k=0;k<m-1;k++){
				if(b[j][k]==0&&b[j][k+1]==0&&b[j+1][k]==0){//判定合法的C点位
					x=find_down(j,k);
					y=find_right(j,k)-1;
					//cout << y << "+++++++++" << endl;
					for (int l=2;l<x;l++){
						z=find_right(j+l,k)-1;
						//cout << z << endl;
						vc+=y*z;
						vc=vc%mod_;
					}
				}
			}
		}
		cout << vc << " ";
		//F形字样 
		if(f==0){//特判 
			cout << 0 << endl;
			continue;
		} 
		for(int j=0;j<n-3;j++){//倒数第一行和第二行不可能产生合法的点位（F的左上角） 
			for(int k=0;k<m-1;k++){
				if(b[j][k]==0&&b[j][k+1]==0&&b[j+1][k]==0&&b[j+2][k]==0&&b[j+3][k]==0){//判定合法的F点位
					x=find_down(j,k);
					y=find_right(j,k)-1;
					//cout << y << "+++++++++" << endl;
					for (int l=2;l<x-1;l++){
						vf+=y*(find_right(j+l,k)-1)*(x-1-l);
						vf=vf%mod_;
					}
				}
			}
		}
		cout << vf << endl;
		//这糟糕的时间复杂度QAQ 
	}
	return 0;
}
