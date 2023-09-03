#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[1010][1010],n,m;
long long js1,js2;
void cwork(int x,int y,int zb){
	for(int i=x;i<=y;i++){
		for(int j=i+2;j<=y;j++){
			int hz1=zb,hz2=zb;
			while(!a[i][++hz1]){}
			while(!a[j][++hz2]){}
			hz1--;
			hz2--;
			if(hz1==zb||hz2==zb){
				continue;
			}
			js1=(js1+(hz1-zb)%mod*(hz2-zb)%mod)%mod;
		}
	}
}
void fwork(int x,int y,int zb){
	for(int i=x;i<=y;i++){
		for(int j=i+2;j<=y;j++){
			int hz1=zb,hz2=zb,hyl=j;
			while(!a[i][++hz1]){}
			while(!a[j][++hz2]){}
			while(hyl<=y&&(!a[hyl++][zb])){}
			hz1--;
			hz2--;
			hyl--;
			if(hz1==zb||hz2==zb){
				continue;
			}
			js2=(js2+(((hz1-zb)%mod*(hz2-zb)%mod)*(hyl-j))%mod)%mod;
		}
	}
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,id,c,f;
	char x;
	cin>>T>>id;
	while(T--){
		cin>>n>>m>>c>>f;
		js1=0;
		js2=0;
		memset(a,1,sizeof(a));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>x;
				a[i][j]=(x-'0');
			}
		}
		if(c==0&&f==0){
			cout<<0<<" "<<0<<endl;
			continue;
		}
		for(int i=1;i<=m;i++){
			int dq=0;
			for(int j=1;j<=n+1;j++){
				if(!a[j][i]){
					dq++;
				}
				else{
					if(dq>=3){
						cwork(j-dq,j-1,i);
					}
					if(dq>=4){
						fwork(j-dq,j-1,i);
					}
					dq=0;
				}
			}
		}
		cout<<(js1*c)%mod<<" "<<(js2*f)%mod<<endl;
	}
	return 0;
}
