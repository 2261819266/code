#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int T,id;
int n,m,c,f;
bool matrix[1005][1005];
long long pre[1005][1005];
long long pre1[1005][1005]; 
long long rc,rf;
void calc_result(int x,int y){
	long long curc = 0,curf = 0;
	int x1 = x+2;
	if(matrix[x+1][y])return ;
	while(matrix[x1][y] == 0&&x1<=n){
		curc+=(pre[x][y]-1)*(pre[x1][y]-1);
		curf+=(pre[x][y]-1)*(pre[x1][y]-1)*(pre1[x1][y]-1);
		curc%=MOD;
		curf%=MOD;
		x1++;
	}
	rc+=curc;
	rc%=MOD;
	rf+=curf;
	rf%=MOD;
	return ;
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d %d",&T,&id);
	while(T--){
		rc = rf = 0;
		memset(pre,0,sizeof(pre));
		memset(pre1,0,sizeof(pre1));
		memset(matrix,0,sizeof(matrix));
		scanf("%d %d %d %d",&n,&m,&c,&f);
		for(int i = 1;i<=n;i++){
			getchar();
			for(int j = 1;j<=m;j++){
				char c = getchar();
				matrix[i][j] = (c-0x30);
			}
		}
		for(int i = n;i>=1;i--){
			for(int j = m;j>=1;j--){
				if(!matrix[i][j]){
					pre[i][j] = pre[i][j+1]+1;
					pre1[i][j] = pre1[i+1][j]+1;
				}else{
					pre[i][j] = 0;
					pre1[i][j] = 0;
				}	
			}
		}
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=m;j++){
				if(pre[i][j]){
					calc_result(i,j);
				}
			}
		}
		printf("%lld %lld\n",c*rc,f*rf);
	}
	return 0;
}
/*
看复杂度应该是O(TNM)
C形有想法了，就是说定义数组pre[i][j]表示第i行第j列后面有多少个连续的0
先找到一个f[x][y]=0的点作为C的左上角，然后x++，以f[x1][y]为左下角，直到f[x][y]为1或出界
要注意x1>x+1 
对于每一行的，C形数量就是(pre[x][y]-1)(pre[x1][y]-1) 
C成功了！！！ 
F形其实就是C形再加几行就是了
也就是我们再定义一个pre1[i][j]表示第i行第j列以下有多少个连续的0
我们算C形数量的时候是(pre[x][y]-1)(pre[x1][y]-1)，再乘上(pre1[x1][y]-1)即可 
9:25 T1 大样例，通过！！！！ 
估分100pts 
*/
