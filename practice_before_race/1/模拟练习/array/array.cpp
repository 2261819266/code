# include "iostream"
# include "cstdio"

using namespace std;

const int maxm=1e6+10;
const int maxn=2e3+10; 
const int Mod=998244353;

int n,k; 
int Dp[maxm][30];
int f[maxm]; 
int W[30];
 
void Subtask1(){
	if(k==1){
		printf("1"); 
	}else{
		printf("%d",n>>1); 
	}
	return; 
} 

void Subtask2(){
	Dp[0][0]=1;
	register int i,j,l;
	for(i=1;i<=k;i++){
		for(j=1;j<=n;j++){
			for(l=0;l*2<=j;l++){ 
				Dp[j][i]=(Dp[j][i]+Dp[l][i-1])%Mod;
			}
		}
	}
	printf("%d",Dp[n][k]);
	return; 
}

void Subtask3(){ 
	register int i,j,l;
	f[0]=1; 
	for(i=1;i<=k;i++){
		W[i]=1<<(i-1); 
	}
	if(n-W[k]<0){
		printf("0");
		return; 
	} 
	for(i=1;i<=k;i++){
		for(j=W[i];j<=n-W[k];j++){
			f[j]=(f[j]+f[j-W[i]])%Mod; 
		}
	}
	printf("%d",f[n-W[k]]); 
	return;
}


int main(){
	freopen("array8.in","r",stdin);
	freopen("array8.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(k<=2){
		Subtask1();
		return 0; 
	}else if(n<=2000){
		Subtask2();
		return 0; 
	}else{
		Subtask3(); 
	} 
	return 0; 
} 
