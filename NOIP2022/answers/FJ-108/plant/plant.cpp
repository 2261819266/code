#include <cstring>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("plant.in");
ofstream fout("plant.out");
typedef long long LL;
const LL Mod=998244353;
LL AnsC,AnsF,Sum,Ans[1200][1200];
int T,N,M,C,F,Id,L[1200][1200];
bool A[1200][1200];
char Input;
int main(){
	fin.tie(0),fout.tie(0),fin>>T>>Id;
	while (T--){
		fin>>N>>M>>C>>F,AnsC=AnsF=0;
		memset(L,0,sizeof L);
		memset(Ans,0,sizeof Ans);
		for (int i=1,j;i<=N;++i)
			for (j=1;j<=M;++j)
				fin>>Input,A[i][j]=Input=='0';
		for (int i=1,j;i<=N;++i)
			for (j=M;j>0;--j)
				if (A[i][j])
					L[i][j]=L[i][j+1]+1;
		for (int i,j=1;j<=M;++j)
			for (Sum=0,i=1;i<=N;++i){
				if (L[i][j]>1){
					Ans[i][j]=LL(L[i][j]-1)*Sum%Mod;
					if ((AnsC+=Ans[i][j])>=Mod)
						AnsC-=Mod;
				}
				Sum+=max(L[i-1][j]-1,0);
				if (L[i][j]==0)
					Sum=0;
			}
		for (int i,j=1;j<=M;++j)
			for (i=N;i>0;--i)
				if (A[i][j])
					L[i][j]=L[i+1][j]+1;
		for (int i=1,j;i<=N;++i)
			for (j=1;j<=M;++j)
				if (L[i][j]>1)
					AnsF=(AnsF+Ans[i][j]*LL(L[i][j]-1))%Mod;
		fout<<AnsC*C<<' '<<AnsF*F,fout.put(10);
	}
	return 0;
}
