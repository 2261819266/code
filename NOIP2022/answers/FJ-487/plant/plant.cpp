#include<bits/stdc++.h>
using namespace std;
int t,id,n,m,maxn=-999,cou,f,p;
int a[1001][1001];
string l;
int a1[1001][1001]={9999};
int get(int x1,int y1){
		for(int j11=y1;j11>=0;j11--){
			if(a1[x1][j11]!=9999){
				return a1[x1][j11];
			}
		}
}
int ifa(int x2,int y2,int z2){
    int minn=100,tmp1=y2-1,minnn,l;
	for(int i=x2;i<=z2;i++){
		l=a1[i][tmp1];
		if(a1[i][tmp1]==9999)l=get(i,tmp1);
		if(l<minn){
			minn=l;
			minnn=a1[i][y2];
			if(a1[i][y2]==9999)minnn=get(i,y2);
		}
	}
	return minnn;
}
int check(int x,int y){
	int up1,mid,down1,ans11=0,cnt,cnt1;
	bool flag=1;
	for(int i=x+2;i<n;i++){
		bool flag=1;
		for(int j1=x;j1<=i;j1++){
			if(((a1[i][y]<2)||((a1[j1][y]<1)))){
				flag=0;
			}
			if((a1[i][y]>=2)&&(a1[j1][y]>=1)){
				if(j1==x-1)mid=a1[j1][y];
				else if(a1[j1][y]<mid&&j1!=x&&j1!=y)mid=a1[j1][y];
			}
		}
		if(flag==1){
			up1=a1[x][y];
			down1=a1[i][y];
			if(a1[x][y]==9999)up1=get(x,y);
			if(a1[i][y]==9999)down1=get(i,y);
			if(y!=0)up1=mid=down1=ifa(x,y,i);
			if(mid>1)mid-=1;
			int up11=up1-1,down11=down1-1;
			if(up1>=2&&down1>=2){
			for(int i=0;i<mid;i++){
				ans11=(up11*down11)+ans11;
				up11--;
				down11--;
				if(up11<2||down11<2)break;
			}
		}
		}
				int up1=0,mid=0;down1=0;
	}
	if(flag==0)return -1;
	return ans11;
}

int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
    cin>>t>>id;
    for(int i=0;i<t;i++){
    	cin>>n>>m>>f>>p;
    	for(int j=0;j<n;j++){
    	   cin>>l;
    	   for(int z=0;z<m;z++)a[j][z]=l[z]-'0';
    }
    	int tmp=0,ans=0,ans1=0,temp=0;
    	for(int j=0;j<n;j++){
    		for(int z=0;z<m;z++){
    		    if(a[j][z]==0){
    		    	ans++;
    		    	if(z!=0&&ans1!=0){
    		    		a1[temp][tmp]=ans1;
    		    		tmp++;
    		    		ans1=0;
					}
					if(z==m-1){
						a1[temp][tmp]=ans;
    		    		tmp++;
    		    		ans1=0;
					}
				}
    		    if(a[j][z]==1){
    		    	ans1--;
    		    	if(z!=0&&ans!=0){
    		    		a1[temp][tmp]=ans;
    		    		tmp++;
    		    		ans=0;
					}
					if(z==m-1){
						a1[temp][tmp]=ans1;
    		    		tmp++;
    		    		ans1=0;
					}
			   }
			}
			ans=0;
			ans1=0;
			if(tmp>maxn)maxn=tmp;
			tmp=0;
			temp++;
		}
		int anss=0;
		for(int j=0;j<temp;j++){
			for(int z=0;z<maxn;z++){
				if(a1[j][z]==0)a1[j][z]=9999;
			}
		}

		for(int j=0;j<temp;j++){
			for(int z=0;z<maxn;z++){
				if(a1[j][z]>=2){
					if(check(j,z)!=-1)anss+=check(j,z);
				}
			}
		}
	cout<<anss%998244353<<" "<<(anss/2)%998244353;
	}
	return 0;
}
