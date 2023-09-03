#include<bits/stdc++.h>
using namespace std;
long long n,m,c,f,a[1010][1010],t,id,ansc,ansf,sl[1010][1010],sr[1010][1010],sl1[1010][1010],sr1[1010][1010];
const long long p=998244353;

void s(){
	for(int i=1;i<=n;i++){
		int cnt;
		for(int j=m;j>=1;j--){
			while(a[i][j]==1&&j>=1) j--;
			if(j<1) break;
			if(j==m||a[i][j+1]==1) cnt=j;
			sl[i][j]=cnt-j;
		}
	}
	for(int i=1;i<=m;i++){
		int cnt;
		for(int j=n;j>=1;j--){
			while(a[j][i]==1&&j>=1) j--;
			if(j<1) break;
			if(j==n||a[j+1][i]==1) cnt=j;
			sr[j][i]=cnt-j;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==1) continue;
			if(a[i-1][j]==1){
				sl1[i][j]=sl[i][j];
				continue;
			}
			sl1[i][j]=sl1[i-1][j]+sl[i][j];
		}
	}
			
}

void get_ansc(){
	ansc=0;
	for(int j=1;j<=m;j++){
		for(int i=3;i<=n;i++){
			if(a[i][j]==1||a[i-1][j]==1||a[i-2][j]==1) continue;
			ansc+=sl1[i-2][j]%p*sl[i][j]%p;
		}
	}
	return ;
}

void get_ansf(){
	ansf=0;
	for(int j=1;j<=m;j++){
		for(int i=3;i<=n;i++){
			if(a[i][j]==1||a[i-1][j]==1||a[i-2][j]==1) continue;
			ansf+=sl1[i-2][j]%p*sl[i][j]%p*sr[i][j]%p;
		}
	}
	return ;
}
	
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>t>>id;
	while(t--){
		scanf("%lld%lld%lld%lld",&n,&m,&c,&f);
		memset(sl,0,sizeof sl);
		memset(sr,0,sizeof sr);
		memset(sl1,0,sizeof sl1);
		memset(sr1,0,sizeof sr1);
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char c;
				cin>>c;
				a[i][j]=c-'0';
			}
		}
		if(id==1){
			cout<<0<<" "<<0<<endl;
		}
		else{
			s();
//			for(int i=1;i<=n;i++){
//				for(int j=1;j<=m;j++){
//					cout<<sr[i][j]<<" ";
//				}
//				cout<<endl;
//			}
//			cout<<endl;
//			for(int i=1;i<=n;i++){
//				for(int j=1;j<=m;j++){
//					cout<<sl1[i][j]<<" ";
//				}
//				cout<<endl;
//			}
			get_ansc();
			get_ansf();
			printf("%lld %lld\n",ansc*c,ansf*f);
		}
	}
	return 0;
}
