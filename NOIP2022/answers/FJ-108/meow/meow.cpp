#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("meow.in");
ofstream fout("meow.out");
int T,N,M,K,X,C[10000],cnt,S[1005][1005],Top[1005];
int main(){
	fin.tie(0),fout.tie(0),fin>>T;
	while (T--){
		fin>>N>>M>>K;
		if (N==2){
			for (int i=1;i<=M;++i){
				fin>>X;
				if (S[1][Top[1]]==X)
					fout<<1<<' '<<1<<endl,--Top[1];
				else if (S[2][Top[2]]==X)
					fout<<1<<' '<<2<<endl,--Top[2];
				else if (S[1][1]==X&&Top[2]==0){
					fout<<1<<' '<<2<<'\n'<<2<<' '<<1<<' '<<2<<endl;
					for (int i=1;i<=Top[1];++i)
						S[1][i]=S[1][i+1];
					--Top[1];
				}else if (S[2][1]==X&&Top[1]==0){
					fout<<1<<' '<<1<<'\n'<<2<<' '<<1<<' '<<2<<endl;
					for (int i=1;i<=Top[2];++i)
						S[2][i]=S[2][i+1];
					--Top[2];
				}
				else 
					fout<<1<<' '<<1<<'\n',S[1][++Top[1]]=X;
			}
		}else{
			for (int i=1;i<=M;++i){
				fin>>X;
				if (S[X>>1][1]==X){
					fout<<1<<' '<<N<<'\n'<<2<<' '<<(X>>1)+1<<' '<<N<<endl;
					for (int i=1;i<=Top[X>>1];++i)
						S[X>>1][i]=S[X>>1][i+1];
					--Top[X>>1];
				}else{
					fout<<1<<' '<<(X>>1)<<endl;
					if (S[X>>1][Top[X>>1]]==X)
						--Top[X>>1];
					else
						S[X>>1][++Top[X>>1]]=X;
				}
			}
		}
	}
	return 0;
}
