#include<iostream>
#include<cstdio>
using namespace std;
int a[300000];
int b[300000];
int lg[300000];
int sta[25000][80];
int stb[25000][80];
int qian[3010][3010];
long long dp[3010][3010];
long long qua(int l,int r){
	return max(sta[l][lg[r-l+1]],sta[r-(1<<lg[r-l+1])+1][lg[r-l+1]]);
}
long long qub(int l,int r){
	return max(stb[l][lg[r-l+1]],stb[r-(1<<lg[r-l+1])+1][lg[r-l+1]]);
}
int main( ){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int t,n;
	cin>>t>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	lg[0]=-1;
	for(int i=1;i<=300000;i++) lg[i]=lg[i>>1]+1; //cout<<lg[250000];
	for(int i=1;i<=n;i++) sta[i][0]=a[i],stb[i][0]=b[i];
	for(int k=1;k<=lg[n];k++){
		for(int i=1;i<=n-(1<<k)+1;i++){
			sta[i][k]=max(sta[i][k-1],sta[i+(1<<(k-1))][k-1]);
			stb[i][k]=max(stb[i][k-1],stb[i+(1<<(k-1))][k-1]);
		}
	}
	
	int q;
	cin>>q;
	if(q<=30&&n<=30){
		int l,r;
		long long ans=0;
		for(int g=1;g<=q;g++){
			scanf("%d%d",&l,&r);
			ans=0;
			for(int i=l;i<=r;i++){
				for(int j=i;j<=r;j++){
					ans+=qua(i,j)*qub(i,j);
					//cout<<i<<" "<<j<<" "<<qua(i,j)<<" "<<qub(i,j)<<endl;
				}
			}		
			cout<<ans<<endl;
		}
	}else
	if(q<=3000&&n<=3000){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++)
			qian[j][i]=qian[j-1][i]+qua(j,i)*qub(j,i);
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				dp[i][j]=dp[i][j-1]+qian[j][j]-qian[i-1][j]+(1ll<<64);
			}
		}
		int l,r;
		long long ans=0;
		for(int g=1;g<=q;g++){
			scanf("%d%d",&l,&r);
			ans=0;
			/*for(int i=l;i<=r;i++){
				for(int j=i;j<=r;j++){
					ans+=qua(i,j)*qub(i,j);
					//cout<<i<<" "<<j<<" "<<qua(i,j)<<" "<<qub(i,j)<<endl;
				}
			}*/		
			cout<<dp[l][r]<<endl;
		}
	}
	return 0;
}
