#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("match.in");
ofstream fout("match.out");
typedef unsigned long long uLL;
const int MAXN=4000;
int TTT,N,Q,L,R;
uLL A[2][MAXN],Ans[4000][4000],Max1,Max2,Ans1;
int main(){
	fin>>TTT>>N;
	for (int o=0,i;o<2;++o)
		for (i=1;i<=N;++i)
			fin>>A[o][i];
	fin>>Q;
	for (int i=1,j;i<=N;++i)
		for (Max1=Max2=0,j=i;j>0;--j)
			Max1=max(Max1,A[0][j]),Max2=max(Max2,A[1][j]),Ans[j][i]=Ans[j+1][i]+Max1*Max2;
	while (Q--){
		Ans1=0;
		fin>>L>>R;
		for (int i=L;i<=R;++i)
			Ans1+=Ans[L][i];
		fout<<Ans1<<endl;
	}
	return 0;
}
