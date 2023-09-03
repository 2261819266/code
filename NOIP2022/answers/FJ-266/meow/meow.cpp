#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A[100005];
ll T,N,M,K,Ans1[100005],Ans2[100005],Ans3[100005],Top[100005],stk[100005][4],stk2[5][100005],Head2[5],Top2[5],TopA=0;
bool Q[10005];
bool dfs(ll x,ll num){
	if(x>N){
		while(1){
				ll k=1;
				if(Top2[1]>=Head2[1]&&Top2[2]>=Head2[2]){
					if(stk2[1][Head2[1]]==stk2[2][Head2[2]]){
						k=0;
						Ans1[++TopA]=2;
						Ans2[TopA]=1;
						Ans3[TopA]=2;
						Head2[1]++;
						Head2[2]++;
						num-=2;
					}
				}
				if(Top2[3]>=Head2[3]&&Top2[2]>=Head2[2]){
					if(stk2[3][Head2[3]]==stk2[2][Head2[2]]){
						k=0;
						Ans1[++TopA]=2;
						Ans2[TopA]=3;
						Ans3[TopA]=2;
						Head2[3]++;
						Head2[2]++;
						num-=2;
					}
				}
				if(Top2[1]>=Head2[1]&&Top2[3]>=Head2[3]){
					if(stk2[1][Head2[1]]==stk2[3][Head2[3]]){
						k=0;
						Ans1[++TopA]=2;
						Ans2[TopA]=1;
						Ans3[TopA]=3;
						Head2[1]++;
						Head2[3]++;
						num-=2;
					}
				}
				if(k==1) break;
			}
		if(num==0){
			cout<<TopA<<endl;
			for(int i=1;i<=TopA;i++){
				if(Ans1[i]==1) cout<<1<<" "<<Ans2[i]<<endl;
				else{
					cout<<2<<" "<<Ans2[i]<<" "<<Ans3[i]<<endl;
				}
			}
			return 1;
		}
		return 0;
	}
	for(int i=1;i<=3;i++){
		if(Top2[i]>=Head2[i]){
			if(stk2[i][Top2[i]]==A[x]){
				Ans1[++TopA]=1;
				Ans2[TopA]=i;
				Top2[i]--;
				if(dfs(x+1,num-2)==1) return 1;
				TopA--;
				Top2[i]++;
			}
			else{
				Ans1[++TopA]=1;
				Ans2[TopA]=i;
				stk2[i][++Top2[i]]=A[x];
				if(dfs(x+1,num)==1) return 1;
				TopA--;
				Top2[i]--;
			}
		}
		else{
			Ans1[++TopA]=1;
			Ans2[TopA]=i;
			stk2[i][++Top2[i]]=A[x];
//			for(int j=1;j<=3;j++){
//				if(j==i) continue;
//				if(stk2[j][Head2[j]]==A[x]){
//					Ans1[++TopA]=2;
//					Ans2[TopA]=i;
//					Ans3[TopA]=j;
//					Head2[j]++;
//					Top2[i]--;
//					if(dfs(x+1,num-2)==1) return 1;
//					TopA--;
//					Head2[j]--;
//					Top2[i]++;
//				}
//			}
			if(dfs(x+1,num)==1) return 1;
			TopA--;
			Top2[i]--;
		}
	}
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>N>>M>>K;
		for(int i=1;i<=M;i++){
			scanf("%lld",&A[i]);
			Ans1[i]=Ans2[i]=Ans3[i]=Top[i]=0;
			if(i<=3){
				Top2[i]=0;
				Head2[i]=1;
			}
		}
		TopA=0;
		if(K==2*N-2){
			for(int i=1;i<=M;i++){
				ll sum=(A[i]+1)/2;
				if(!stk[sum][Top[sum]]){
					stk[sum][++Top[sum]]=A[i];
					Ans1[++TopA]=1;
					Ans2[TopA]=sum;
				}
				else{
					if(stk[sum][Top[sum]]==A[i]){
						Ans1[++TopA]=1;
						Ans2[TopA]=sum;
						Top[sum]--;
					}
					else{
						if(Top[sum]==2){
							Ans1[++TopA]=1;
							Ans2[TopA]=N;
							Ans1[++TopA]=2;
							Ans2[TopA]=sum;
							Ans3[TopA]=N;
							stk[sum][1]=stk[sum][2];
							Top[sum]--;
						}
						else{
							Ans1[++TopA]=1;
							Ans2[TopA]=sum;
							stk[sum][++Top[sum]]=A[i];
						}
					}
				}
			}
			cout<<TopA<<endl;
			for(int j=1;j<=TopA;j++){
				if(Ans1[j]==1) cout<<1<<" "<<Ans2[j]<<endl;
				else{
					cout<<2<<" "<<Ans2[j]<<" "<<Ans3[j]<<endl;
				}
			}
		}
		else{
			if(N==2){
				
			}
			else{
			for(int i=1;i<=3;i++) Head2[i]=1;
			ll s=dfs(1,M);
			}
		}
	}
	return 0;
}
