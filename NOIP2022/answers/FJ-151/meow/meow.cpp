#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define mp pair<int,int>

mt19937 rnd(20060423);

const int N=2e6+5;
int T,n,m,k,a[N],top,op,ans1[N<<1],ans2[N<<1],ans3[N<<1],ys[N][3],st[N],qc[N],tt,kym[N],vis[N],xg[N],hm[N],lst[N],kwz,tszt;

priority_queue<pii >ab;
pii zn[N];

int read(){
	int x=0,fs=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') fs=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar(); 
	return x*fs;
}

void kx(int x){
	if(!vis[x]) qc[++tt]=x;
	kym[x]=1; return;
}

void bkx(int x){
	kym[x]=0; return;
}

int zyg(){
	while(tt){
		swap(qc[tt],qc[rnd()%tt+1]);
		int wz=qc[tt];
		if(xg[ys[wz][0]]>xg[ys[wz][1]]) vis[qc[tt]]=0,tt--;
		else{
			tt--; vis[qc[tt+1]]=0,kym[qc[tt+1]]=0;
			return qc[tt+1];
		}
	}
	if(tt==0){
		return 0;
//		cerr<<"3:afadsfasfaafsd\n";
	}
	return 0;
}

int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	T=read(); 
	while(T--){
		n=read(); m=read(); k=read();
		for(int i=1;i<=m;i++) a[i]=read();
		for(int i=m;i>=1;i--){
			hm[i]=lst[a[i]];
			lst[a[i]]=i;
		}
		top=n-1; kwz=n;
		for(int i=1;i<n;i++) st[i]=i;
		
		for(int i=1;i<=m;i++){
//			if(!zn[4].fi) for(int j=1;j<=n;j++) if(ys[j][0]==4||ys[j][1]==4||ys[j][2]==4) cerr<<":::"<<" "<<i<<" "<<j<<" "<<ys[j][1]<<" "<<ys[j][2]<<"\n";
			int u=a[i];
			if(tszt){
				if(zn[u].fi&&zn[u].se==0){
					kwz=zn[u].fi;
					op++; ans1[op]=1; ans2[op]=kwz; tszt=0; while(!ab.empty()) ab.pop();
					zn[u].fi=zn[u].se=0;
					continue;
				}else{
					if(zn[u].fi){
						op++; ans1[op]=1; ans2[op]=zn[u].fi;
						st[++top]=zn[u].fi; ab.push(mp(xg[ys[zn[u].fi][0]],zn[u].fi));
						zn[u].fi=zn[u].se=0;
					}else{
						int wz=(ab.top()).se;
						op++; ans1[op]=1; ans2[op]=wz;
						zn[u].fi=wz; zn[u].se=1;
//						for(int i=1;i<=n;i++){
//							cerr<<"  "<<i<<" "<<ys[i][0]<<" "<<ys[i][1]<<" "<<xg[ys[i][0]]<<"\n";
//						}
//			if(i>=42400)cerr<<i<<" "<<ab.size()<<"\n";
						ab.pop();
					}
				}
				continue;
			}
//			if(i>=78649&&i<=78655) cerr<<zn[4].fi<<"\n";
			if(zn[u].fi){
				if(zn[u].se==1){
//					if(ys[zn[u].fi][2]) cerr<<i<<" "<<u<<" "<<zn[u].fi<<" "<<"1:afaffaasadsfasdfads\n";
					op++; ans1[op]=1; ans2[op]=zn[u].fi;
					int wz=zn[u].fi;
					ys[wz][1]=0; bkx(wz); st[++top]=zn[u].fi; zn[u].fi=zn[u].se=0;
					continue;
				}
				if(zn[u].se==0){
					op++; ans1[op]=1; ans2[op]=kwz; op++; ans1[op]=2; ans2[op]=kwz; ans3[op]=zn[u].fi;
//					cerr<<op<<" "<<ans1[op]<<"\n";
					ys[zn[u].fi][0]=ys[zn[u].fi][1]; ys[zn[u].fi][1]=ys[zn[u].fi][2]; ys[zn[u].fi][2]=0;
					int v=ys[zn[u].fi][0],w=ys[zn[u].fi][1];
//					bkx(zn[u].fi);if(u==4&&v==6&&zn[u].fi==1) cerr<<v<<" "<<zn[u].fi<<" "<<zn[v].se<<"\n";
					if(v) zn[v].se=0;
					if(w) zn[w].se=1;
					if(v&&!w) st[++top]=zn[u].fi;
					if(v&&w&&xg[v]<xg[w]) kx(zn[u].se);
//			if(i==78649) cerr<<a[i]<<" "<<zn[u].se<<" "<<ys[zn[u].fi][0]<<" "<<zn[u].fi<<" "<<zn[4].fi<<"\n";
					zn[u].fi=0; zn[u].se=0;
					continue;
				}
				if(zn[u].se==2){
//			if(i==73567)cerr<<a[i]<<" "<<ys[zn[u].fi][2]<<"\n";
					op++; ans1[op]=1; ans2[op]=zn[u].fi;
					int wz=zn[u].fi;
					ys[wz][2]=0;
					int v=ys[wz][0],w=ys[wz][1];
					if(xg[v]<xg[w]) kx(wz);else bkx(wz);
					zn[u].fi=zn[u].se=0;
					continue;
				}
				continue;
			}
			xg[u]=hm[i];
			if(top) swap(st[top],st[rnd()%top+1]);
			while(top&&(st[top]==kwz||ys[st[top]][1])){top--; if(top)swap(st[top],st[rnd()%top+1]);}
			if(top){
				int wz=st[top];
				op++; ans1[op]=1; ans2[op]=wz;
//				if(ys[wz][0]&&ys[wz][1]) cerr<<"2:afafdsfafafdsafdsafdsafdss\n";
				zn[u].fi=wz;
				if(ys[wz][0]) ys[wz][1]=u,zn[u].se=1;
				else ys[wz][0]=u,zn[u].se=0;
//			cerr<<i<<" "<<zn[u].fi<<" "<<zn[u].se<<"\n";
				if(ys[wz][1]){
					int v=ys[wz][0],w=ys[wz][1];
					if(xg[v]<xg[w]) kx(wz);
					top--;
				}
				continue;
			}else{
				int wz=zyg();
//				cerr<<xg[ys[wz][0]]<<" "<<xg[ys[wz][1]]<<"\n";
				if(wz==0){
					tszt=1;
					ys[kwz][0]=u; zn[u].fi=kwz; zn[u].fi=1; kwz=0;
//					if(top!=0) cerr<<"aadsadsafdsfasfdsa";
					st[top=1]=kwz;
					ab.push(mp(xg[u],kwz));
					continue;
				}
				op++; ans1[op]=1; ans2[op]=wz;
				zn[u].fi=wz; zn[u].se=2;
				ys[wz][2]=u;
			}
		}
		for(int i=1;i<=op;i++){
//			cerr<<"  "<<i<<" "<<ans1[i]<<"\n";
			if(ans1[i]==1) printf("1 %d\n",ans2[i]);
			if(ans1[i]==2) printf("2 %d %d\n",ans2[i],ans3[i]);
		}
		
		tszt=0;
		for(int i=1;i<=k;i++) zn[i]=mp(0,0);
		for(int i=1;i<=n;i++) st[i]=0,ys[i][0]=ys[i][1]=ys[i][2]=kym[i]=vis[i]=hm[i]=lst[i]=xg[i]=0;
		for(int i=1;i<=tt;i++) qc[i]=0;
		tt=0;
		for(int i=1;i<=op;i++) ans1[i]=ans2[i]=ans3[i]=0;
		op=0;
	}
	return 0;
}
