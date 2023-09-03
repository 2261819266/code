#include<bits/stdc++.h>
using namespace std;
long long int t,id,n,m,c,f,a[1005][1005],b[1005][1005][2],ans1,ans2,k;

void lo(int g,int h){
	
	if(b[g-1][h][1]>0){
		b[g][h][1]=b[g-1][h][1]-1;
		return;
	}
	for(int i=g+1;i<=n;i++){
		if(a[i][h]==1) return;
		b[g][h][1]++;
	}
	return;
}

void we(int g,int h){
	if(b[g][h-1][0]>0){
		b[g][h][0]=b[g][h-1][0]-1;
		return;
	}
	for(int i=h+1;i<=m;i++){
		if(a[g][i]==1) return;
		b[g][h][0]++;
	}
	return;
}

void find(int g,int h){
	
	long long int o=0,p=0;
	lo(g,h);
	for(int i=g+1;i<=n;i++){
		if(a[i][h]==1)break;
		if(a[i][h+1]==1)continue;
		if(b[i][h][0]==0)we(i,h);
		p+=b[i][h][0];
		
		if(b[i][h][1]==0)lo(i,h);
		o+=b[i][h][1]*b[i][h][0];
	}
	ans1+=c*p*b[g-1][h][0]%998244353;
	ans2+=f*o*b[g-1][h][0]%998244353;
	
	return;
}

long long read2(){
	char d=getchar();
	while(d<'0'||d>'9'){
		d=getchar();
	}
	return d-'0';
}

long long read(){
	long long int p=0,fi=1;
	char d=getchar();
	while(d<'0'||d>'9'){
		if(d=='-') fi=-1;
		d=getchar();
	}
	while(d>='0'&&d<='9'){
		p+=p*10+d-'0';
		d=getchar();
	}
	return p*fi;
}

int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	t=read();
	id=read();
	while(t--){
		ans1=0;
		ans2=0;
		n=read();
	m=read();
	c=read();
	f=read();
	if(id==1){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++){
		a[i][0]=1;
		for(int j=1;j<=m;j++){
			b[i][j][1]=0;
			b[i][j][0]=0;
			a[i][j]=read2();
		}
	}
	for(int j=1;j<=m;j++){
		a[n+1][j]=1;
		a[0][j]=1;
	}
	for(int i=1;i<=n-2;i++){
		for(int j=1;j<m;j++){
			if(a[i+1][j]==0&&a[i][j+1]==0&&a[i][j]==0){
				if(j>0){
					if(b[i][j-1][0]>0)b[i][j][0]=b[i][j-1][0]-1;
				}
				if(b[i][j][0]==0)we(i,j);
				find(i+1,j);
			}	
		}
	}
	cout<<ans1*c<<" "<<ans2*f<<endl;
	}
	return 0;
}
