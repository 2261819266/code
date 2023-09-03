#include<bits/stdc++.h>
#define maxx 500005
#define maxn 1005
using namespace std;

typedef long long ll;
const int mo=998244353;

void FR(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
}

struct Node{
	int s,t;
	int x;
}co[maxx],ro[maxx];//colum row

int totc,totr;//tot_colum tot_row
bool ish[maxn][maxn];//ishole
int bec[maxn][maxn],ber[maxn][maxn];//belong_colum belong_row

inline int len(int x,int y){
	return ro[ber[x][y]].t-y;
}

int main(){
	//ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	FR();
	//cerr<<((int)-1e9)%mo;
	int T,n,m,c,f,id;
	char ch;
	scanf("%d%d",&T,&id);
	//cin>>T>>id;
	while(T--){
		scanf("%d%d%d%d",&n,&m,&c,&f);
		//cin>>n>>m>>c>>f;
		for(int i=1;i<=n;++i){
			scanf("%c",&ch);
			for(int j=1;j<=m;++j){
				scanf("%c",&ch);
//				cin>>ch;
				ish[i][j]=(ch=='1');
//				cerr<<(int)ish[i][j];
			}
//			cerr<<endl;
		}
		for(int i=1;i<=n;++i) ish[i][m+1]=1;
		for(int j=1;j<=m;++j) ish[n+1][j]=1;
		bool flag=0;
		#if 1
		for(int j=1;j<=m;++j){
			for(int i=1;i<=n+1;++i){
				if(ish[i][j]==1&&flag){
					co[totc].t=i-1;
					totc++;
					flag=0;
				}
				if(ish[i][j]==0&&flag==0){
					co[totc].s=i;
					co[totc].x=j;
					flag=1;
				}
				if(flag){
					bec[i][j]=totc;
				}
			}
		}
		#endif
		flag=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m+1;++j){
				if(ish[i][j]==1&&flag){
					ro[totr].t=j-1;
					totr++;
					flag=0;
				}
				if(ish[i][j]==0&&flag==0){
					ro[totr].s=j;
					ro[totr].x=i;
					flag=1;
				}
				if(flag){
					ber[i][j]=totr;
				}
			}
		}
//		for(int i=0;i<totc;++i) cerr<<co[i].x<<' '<<co[i].s<<' '<<co[i].t<<endl;
//		cerr<<endl;
//		for(int i=0;i<totr;++i) cerr<<ro[i].x<<' '<<ro[i].s<<' '<<ro[i].t<<endl;
//		cerr<<endl;
//		for(int i=1;i<=n;++i){
//			for(int j=1;j<=m;++j) cerr<<bec[i][j];
//			cerr<<endl;
//		}
//		cerr<<endl;
//		for(int i=1;i<=n;++i){
//			for(int j=1;j<=m;++j) cerr<<ber[i][j];
//			cerr<<endl;
//		}
//		cerr<<endl;
		ll ansc=0,ansf=0,sig=0;
		//int la;
		for(int j=1;j<=m;++j){
			flag=0;
			for(int i=1,nowlen,tmp;i<=n;++i){
				if(ish[i][j]==1) flag=0;
				if(ish[i][j]==0){
					nowlen=len(i,j);
					if(flag==0){
						sig=nowlen;
						flag=1;
					}else{
						tmp=(ll)(sig-len(i-1,j)+mo)%mo*(nowlen%mo)%mo;
						ansc+=tmp;
						ansc%=mo;
						ansf+=tmp%mo*((co[bec[i][j]].t-i)%mo)%mo;
						ansf%=mo;
						sig+=nowlen;
						sig%=mo;
					}
				}
			}
		}
		ansc%=mo,ansf%=mo;
		printf("%lld %lld\n",ansc,ansf);
//		cout<<ansc<<' '<<ansf<<endl;
		//cerr<<ansc<<' '<<ansf<<endl;
	}
	return 0;
}
