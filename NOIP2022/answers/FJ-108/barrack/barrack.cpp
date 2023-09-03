#include <fstream>
#include <cstring>
using namespace std;
ifstream cin("barrack.in");
ofstream cout("barrack.out");
const int MAXN=10000;
int N,M,X[MAXN],Y[MAXN],Head[MAXN],cnt=1,F[20],P,Q,Ans;
bool V[20];
int Get(int X){
	if (X==F[X])
		return X;
	return F[X]=Get(F[X]);
}
int main(){
	//ios::sync_with_stdio(false);
	cin.tie(0),cin>>N>>M;
	for (int i=0;i<M;++i)
		cin>>X[i]>>Y[i];
	for (int i=1,j,k,l,S;i<1<<N;++i)
		for (j=0;j<1<<M;++j){
			for (k=0;k<M;++k){
				memset(V,0,sizeof V);
				S=(1<<M)-1-(1<<k)|j,cnt=0;
				//cout<<i<<' '<<j<<' '<<k<<' '<<S<<' '<<(1<<M)-1<<endl;
				for (l=1;l<=N;++l)
					F[l]=l;
				for (l=0;l<M;++l)
					if (S&1<<l)
						/*if ((i&1<<X[l]-1)&&(i&1<<Y[l]-1))*/{
							P=Get(X[l]),Q=Get(Y[l]);
							if (P!=Q)
								F[Q]=P;
						}
				for (l=0;l<N;++l)
					if (i&1<<l)
						V[Get(l+1)]=true;
				for (l=1;l<=N;++l)
					cnt+=V[l];
				//cout<<i<<' '<<j<<' '<<S<<' '<<cnt<<endl;
				if (cnt>=2)
					goto Fail;
			}
			++Ans;
			Fail:continue;
		}
	return cout<<Ans<<endl&&0;
}
