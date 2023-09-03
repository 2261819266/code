#include<cstdio>
#define itn int
#define mod 1000000007
#define N 1000010
#define M 2000010
#define ll long long
const ll ny2=500000004;
ll modmod3;
int mi(int x,int y){return x<y?x:y;}
int ma(int x,int y){return x>y?x:y;}
int n,m;
int ahead[N],anxt[M],ato[M],atot;
void aadd(int x,int y){
	anxt[++atot]=ahead[x];ato[atot]=y;ahead[x]=atot;
}

//this is a
int low[N],dfn[N],tartot;
int stac[N],stactot;
int color[N],colortot,colords[N];
int yz[N];
void tarjan(int x,int ie){
	low[x]=dfn[x]=++tartot;
	stac[++stactot]=x;
	int y=0;
	for(int i=ahead[x];i;i=anxt[i]){
		y=ato[i];
		if((i^ie)!=1){
			if(!dfn[y]){
			tarjan(y,i);
			low[x]=mi(low[x],low[y]);
			}
			else{
				low[x]=mi(low[x],dfn[y]);
			}
		}
	}
	
	if(low[x]==dfn[x]){
		++colortot;
		while(stactot){
			y=stac[stactot--];
			color[y]=x;
			++colords[x];
			if(y==x)	break;
		}
	}
}

int bhead[N],bnxt[M],bto[M],btot;
void badd(int x,int y){
	bnxt[++btot]=bhead[x];bto[btot]=y;bhead[x]=btot;
}

ll ny(ll x){
	ll tms=mod-2,rt=1,bs=x;
	while(tms){
		if(tms&1){
			rt*=bs;
			rt%=mod;
		}
		bs*=bs;
		bs%=mod;
		tms/=2;
	}
	return rt;
}

ll p2(int x){
	int y=1;
	for(int i=1;i<=x;++i){
		y*=2;
		if(y>mod)	y-=mod;
	}
	return y;
}

ll dp[3][N];
ll ans;
ll zb,yb,wyb;
void pdfs(int x,int id){
	int y=0,fl=0;;
	for(int i=bhead[x];i;i=bnxt[i]){
		y=bto[i];
		if(y!=id){
			fl=1;
			pdfs(y,x);
		}
	}
	if(fl==0){
		yz[x]=1;
	}
}

void dfs(int x,int id){
	int y;
	ll p2c,pzm1,hzs,pm1z;
	ll dpfst,dp12=1,dp2=1,dpf2;
		//leave jiedian
		p2c=p2(colords[x]);
	if(yz[x]){
		dp[1][x]=dp[0][x]=p2c-1;
		dp[2][x]=1;
		return ;
	}//leave jd ok;
	//init
	for(int i=bhead[x];i;i=bnxt[i]){
		y=bto[i];
		if(y!=id){
			dfs(y,x);
			++hzs;
		}
	}
	pzm1=p2(hzs)-1;pm1z=p2(hzs-1);
	//printf("%lld",)
	
	
	for(int i=bhead[x];i;i=bnxt[i]){
		y=bto[i];
		dp12*=(dp[1][y]+2*dp[2][y]);
		//printf("%lld\n",dp[1][y]);
		dp12%=mod;
		dp2*=(dp[2][y]*2);
		dp2%=mod;
	}
	//printf("%d %lld %lld\n",x,dp12,dp2);
	dp[2][x]=dp2;
	
	dp[0][x]+=dp12*p2c;
	dp[1][x]+=dp12*p2c;
	dp[1][x]-=dp2;
	dp[0][x]-=dp2;
	dp[0][x]%=mod;
	dp[1][x]%=mod;
	for(int i=bhead[x];i;i=bnxt[i]){
		y=bto[i];
		if(y!=id){
			// qiu dp 0 x
			//dpfst biao shi chu le zhe ge wei shang de 0,qi ta dp 0 de cheng ji
			dpfst=dp2*ny(2*dp[2][y]);
			dpfst%=mod;
			dp[0][x]+=(dp[0][y]*dpfst*2);
			//printf("%lld",dp[0][y]*dpfst*2);
			
			
			dpf2=pm1z*dpfst;
			dpf2%=mod;
			dpf2*=dp[1][y];
			dpf2%=mod;
			//printf("%lld\n",dpf2);
			
			dp[0][x]-=dpf2;
			dp[0][x]%=mod;
		}
	}
}

itn i,j;
int c1,c2;
itn main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	modmod3=(ll)mod*(ll)mod*3;
	atot=1;
	for(i=1;i<=m;++i){
		scanf("%d%d",&c1,&c2);
		aadd(c1,c2);
		aadd(c2,c1);
		++zb;
	}
	tarjan(1,0);
	for(i=1;i<=n;++i){
		if(i==color[i])
		for(j=ahead[i];j;j=anxt[j]){
			if(color[ato[j]]!=color[i]){
				badd(color[i],color[ato[j]]);
				++yb;
			}
		}
	}
	yb/=2;
	//for(i=1;i<=n;++i){
	//	for(j=bhead[i];j;j=bnxt[j]){
	//		printf("%d",bto[j]);
	//	}
	//	printf("\n");
	//}
	wyb=zb-yb;
	
	pdfs(1,0);//to find yz
	dfs(1,0);
	//for(i=1;i<=n;++i){	printf("%d %lld %lld %lld\n",yz[i],dp[0][i],dp[1][i],dp[2][i]);
	//}
	ans=dp[0][1]*p2(wyb);
	ans%=mod;
	printf("%lld",ans);
	return 0;
}
