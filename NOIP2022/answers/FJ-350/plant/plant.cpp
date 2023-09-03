#include <bits/stdc++.h>
typedef long long ll;
bool ST;
const int N=1027,p=998244353;

inline ll rd(){
	ll w=1,r=0;char c=getchar();
	while(!isdigit(c)) ((c=='-')&&(w=-1)),c=getchar();
	while(isdigit(c)) r=r*10+c-'0',c=getchar();
	return w*r;
}

int n,m,c,f,T,id;
bool a[N][N];
int ans1,ans2,f1[N][N][3],f2[N][N][3],len[N][N],mul1[N],mul2[N];

bool ED;
int main(){
	//std::cerr<<(&ED-&ST)/1024.0/1024.0<<'\n';
	freopen("plant.in","r",stdin);freopen("plant.out","w",stdout);
	T=rd(),id=rd();
	n=rd(),m=rd(),c=rd(),f=rd();
	for(int i=1;i<=n;++i){
		char t;
		for(int j=1;j<=m;++j) scanf("%1s",&t),a[i][j]=(t=='0');
	}
	 
	for(int i=1;i<=n;++i){
		for(int j=0,p;j<=m;++j){
			if(!a[i][j]){
				p=j+1;
				while(a[i][p]) ++p;
				len[i][j]=p-j;
			}else{
				len[i][j]=len[i][j-1]-1;
			}
		} 
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(!a[i][j]) len[i][j]=0;
			//printf("%d ",len[i][j]);
		}
		//printf("\n");
	}

	for(int j=1,l,lst;j<=m;++j){
		l=lst=0;
		while(l<n){
			while(!a[lst][j]) ++lst;
			if(lst>n) break;
			l=lst;
			while(a[l][j]) ++l;
			if(l-lst>2){
				//printf("%d %d\n",lst,l);
				int res1=0,res2=0;
				mul1[lst]=len[lst][j+1];
				mul2[lst]=len[lst][j+1]*(l-lst-1)%p;
				for(int i1=lst+1;i1<l;++i1){
					mul1[i1]=(mul1[i1-1]+len[i1][j+1])%p;	
					mul2[i1]=(mul2[i1-1]+1ll*len[i1][j+1]*(l-i1-1)%p)%p;
					//printf("i:%d m1:%d m2:%d\n",i1,mul1[i1],mul2[i1]);	
				}  
				for(int i1=lst;i1<l-1;++i1){
					//printf("%d %d\n",len[i1][j+1],mul1[l-1]-mul1[i1+1]);
					res1=(res1+1ll*len[i1][j+1]*(((mul1[l-1]-mul1[i1+1])%p+p)%p)%p)%p;
					res2=(res2+1ll*len[i1][j+1]*(((mul2[l-1]-mul2[i1+1])%p+p)%p)%p)%p;
				}
				ans1=(ans1+res1)%p;
				ans2=(ans2+res2)%p;
				//printf("%d\n",res);
			}
			lst=l;
		}
	}
	printf("%d %d\n",ans1*c,ans2*f);
	return 0;
	
}
