#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
ll N,M,T,CC,FF,ID,A[1050][1050],DP[1050][1050],stk[10050],Top=0,DAan1=0,DAan2=0;
char S;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>T>>ID;
	while(T--){
		scanf("%lld%lld%lld%lld",&N,&M,&CC,&FF);
		DAan1=0;
		DAan2=0;
		for(int i=1;i<=N;i++){
			for(int j=1;j<=M;j++){
				cin>>S;
				A[i][j]=S-'0';
//				cout<<A[i][j]<<" ";
			}
//			cout<<" "<<endl;
		}
		for(int i=1;i<=N;i++){
			for(int j=M;j>=1;j--){
				if(A[i][j]==1) DP[i][j]=0;
				else{
					DP[i][j]=DP[i][j+1]+1;
				}
			}
		}
//		for(int i=1;i<=N;i++){
//			for(int j=1;j<=M;j++){
//				cout<<DP[i][j]<<" ";
//			}
//			cout<<" "<<endl;
//		}
		ll Ans1=0,Sum1=0,Ans2=0,Sum2=0;
		for(int j=1;j<=M;j++){
			Ans1=0;Sum1=0;Ans2=0;Sum2=0;
			Top=0;
			for(int i=1;i<=N;i++){
//				if(j==2){
//					cout<<Sum1<<" "<<Ans1<<" "<<Sum2<<" "<<Ans2<<endl;
//				}
				if(DP[i][j]==0){
					Top=0;
					Ans1=(Ans1+Sum1)%MOD;
					Ans2=(Ans2+Sum2)%MOD;
					Sum1=0;
					Sum2=0;
					continue;
				}
				else{
					if(Top<=1){
						stk[++Top]=DP[i][j];
					}
					else{
						Sum2=(Sum2+Sum1)%MOD;
						Sum1=(Sum1+(stk[Top-1]-1)*(DP[i][j]-1))%MOD;
						stk[Top-1]=(stk[Top-1]+stk[Top]-1)%MOD;
						stk[Top]=DP[i][j];
					}
				}
			}
			Ans1=(Ans1+Sum1)%MOD;
			Ans2=(Ans2+Sum2)%MOD;
//			cout<<Ans1<<" ";
			DAan1=(DAan1+Ans1)%MOD;DAan2=(DAan2+Ans2)%MOD;
		}
		cout<<(DAan1*CC)%MOD<<" "<<(DAan2*CC)%MOD<<endl;
	}
	return 0;
}
