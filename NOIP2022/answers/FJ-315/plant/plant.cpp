#include<bits/stdc++.h>
using namespace std;

long long t,id,n,m,c,f,a[1005][1005];
long long hang[1005][1005];	//该位置右面的一个1的列
long long lie[1005][1005];	//该位置下面的一个1的行
long long ans_c,ans_f;
void get_c(){
	for(long long i=1;i<=n;i++)
		for(long long j=1;j<=m;j++){//找左上角 
			if(a[i][j]==1) continue;
			if(hang[i][j]-j<=1||lie[i][j]-i<=2) continue;
			long long ans=0;
			for(long long k=i+2;k<lie[i][j];k++)
				ans+=hang[k][j]-j-1,ans%=998244353;
			if(ans==0) continue;
			else ans_c+=ans*(hang[i][j]-j-1),ans_c%=998244353;
//			cout<<i<<" "<<j<<" "<<ans<<endl;
		}
	cout<<(c*ans_c)%998244353<<" ";
}
void get_f(){
	for(long long i=1;i<=n;i++)
		for(long long j=1;j<=m;j++){//找左上角 
			if(a[i][j]==1) continue;
			if(hang[i][j]-j<=1||lie[i][j]-i<=3) continue;
			long long ans=0;
			for(long long k=i+2;k<lie[i][j]-1;k++)
				ans+=(hang[k][j]-j-1)*(lie[i][j]-k-1),ans%=998244353;
			if(ans==0) continue;
			else ans_f+=ans*(hang[i][j]-j-1),ans_f%=998244353;
//			cout<<i<<" "<<j<<" "<<ans<<endl;
		}
	cout<<(f*ans_f)%998244353<<endl;
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>t>>id;
	while(t--){ 
		ans_c=0,ans_f=0;
		memset(a,0,sizeof(a));
		memset(hang,0,sizeof(hang));
		memset(lie,0,sizeof(lie));
		cin>>n>>m>>c>>f;
		for(long long i=1;i<=n;i++)
			for(long long j=1;j<=m;j++){
				char cnt;
				cin>>cnt;
				a[i][j]=cnt-'0';
			}
		if(c==0&&f==0){
			cout<<0<<" "<<0<<endl;
		}else{
			for(long long i=1;i<=n;i++){
				long long cnt=m+1;
				for(long long j=m;j>=1;j--){
					if(a[i][j]==1) hang[i][j]=j,cnt=j;
					else hang[i][j]=cnt;
				}
			}
			for(long long j=1;j<=m;j++){
				long long cnt=n+1;
				for(long long i=n;i>=1;i--){
					if(a[i][j]==1) lie[i][j]=i,cnt=i;
					else lie[i][j]=cnt;
				}
			}
			get_c();
			get_f();
		}
	}
	return 0;
}
