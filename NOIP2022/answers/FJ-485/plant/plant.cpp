#include<bits/stdc++.h>
#define open(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout)
#define For(i,b,e) for(l i = b ; i <= e ; i++)
using namespace std;
typedef long long l;
bool debug = 0;
struct node{
	l b,e;
	l which;
};
//
int T,id;
int n,m,c,f;
l tem;
l data1[1005][1005];//x
//l data2[1005][1005];//y
vector<node>xr;//[begin,end]
vector<node>yr;
l mod=998244353;
l tc=0;
l tf=0;
node xt,y1t,y2t;
node make_node(l b,l e,l le){
	node x;
	x.b = b;x.e = e;x.which= le;
	return x;
}
l jix(l x){
	if(x==0 or x==1)return 1;
	else return x*(jix(x-1)%mod);
}
void show(node x){
	if(debug)printf("b:%lld,e:%lld,which:%lld\n",x.b,x.e,x.which);
}
/*
1 ≤T ≤ 5，
1 ≤ n,m ≤ 1e3 
0 ≤ c,f ≤ 1
a i,j ∈ {0,1}
*/
int main(){
	open(plant);
	cin>>T>>id;
	For(i,1,T){
		cin>>n>>m>>c>>f;
		char *temp = new char[m+1];
		For(j,1,n){
			cin>>temp;
			For(x,1,m){
				data1[j][x] = temp[x-1]-'0';
//				data2[j][x] = temp[x-1]-'0';
			}
		}
		delete temp; 
		if(c==0 and f==0){
			cout<<0<<" "<<0<<endl;
			continue;
		}
		//o(2 n*m)
		For(x,1,n){
			//y
			l lsp = -1;
			For(y,1,m){
				if(data1[x][y]==0){
					if(lsp == -1)lsp = y;
				}
				else{
					if(lsp!=-1){
						if(lsp+1!=y)yr.push_back(make_node(lsp,y-1,x));
						lsp=-1;
					}
				}
			}
			if(lsp!=-1)yr.push_back(make_node(lsp,m,x));
		}
		For(y,1,m){
			//y
			l lsp = -1;
			For(x,1,n){
				if(data1[x][y]==0){
					if(lsp == -1)lsp = x;
				}
				else{
					if(lsp!=-1){
						if(abs(x-lsp)>=2)xr.push_back(make_node(lsp,x-1,y));
						lsp=-1;
					}
				}
			}
			if(lsp!=-1)xr.push_back(make_node(lsp,n,y));
		}
//		//c
		tc=0;
		tf=0; 
		for(l x=0;x<xr.size();x++){
			xt = xr[x];

			if(debug)cout<<x<<"(x):";
			show(xt);
			for(l y1=0;y1<yr.size();y1++){
				y1t = yr[y1];
				if(debug)cout<<y1<<"*(y1):";
				show(y1t);
				if(not(xt.which<=y1t.e and xt.which>=y1t.b))continue;//y0<y1
				if(y1t.which>=xt.e)break;//出去了
				if(not(xt.b<=y1t.which and xt.e>=y1t.which))continue;// (1)x在区间内 
				if(debug)cout<<y1<<"(y1):";
				show(y1t);
				if(debug)cout<<y1<<"(sel)\n";
				for(l y2=y1+1;y2<yr.size();y2++){
					y2t = yr[y2];
					if(debug)cout<<y2<<"*(y2):";
					show(y2t);
					if(y1t.which>=xt.e)break;//出去了 
					if(abs(y2t.which-y1t.which)<=1)continue;
					if(not(xt.which<=y2t.e and xt.which>=y2t.b))continue;//y0<y2 
					if(y2t.which==y1t.which)continue;//查重	
					if(not(xt.b<=y2t.which and xt.e>=y2t.which))continue;// (1)x在区间内 
					if(debug)cout<<y2<<"(y2):";
					show(y2t);
					if(debug)cout<<y2<<"(sel)\n";
					tem =((y2t.e-xt.which)*(y1t.e-xt.which))%mod;
					if(debug)printf("tem:%lld\n",tem);
					tc+=tem;
					tc%=mod;
					if(xt.e-max(y2t.which,y1t.which)>=1){
						if(debug)printf("temf:%lld\n",tem*(xt.e-max(y2t.which,y1t.which)));
						tf+=tem*(xt.e-max(y2t.which,y1t.which));
						tc%=mod;
					}
				}
			}
		}
		cout<<tc*c<<" "<<tf*f<<endl;
	}
	
}
