#include<bits/stdc++.h>
#define For(i,s,e) for(unsigned long long i = (s);i<=(e);i++)
#define rof(i,s,e) for(unsigned long long i = (e);i>=(s);i--)

using namespace std;

typedef long long ll;
const int N = 1e3+100;
const unsigned long long mo = 998244353;

ll n,m,cnt,T,id,c,f,ansc,ansf;

int a[N][N]; ll ff[N][N],fc[N][N],Right[N][N],up[N][N];


void Init(){
	memset(a,0,sizeof(a));
	memset(Right,0,sizeof(Right));
	memset(up,0,sizeof(up));
	memset(ff,0,sizeof(ff));
	memset(fc,0,sizeof(fc));
	n = 0;m=0;cnt=0;ansc=0;ansf=0,c=0,f=0;
}


ll Mod(ll x){
	ll s = x % mo ;
	return s;
}

//ans3 114514²ÝÉú 

int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	
	cin>>T>>id;
	while(T--){
	Init();
	cin>>n>>m>>c>>f;
	For(i,1,n){
		string x;
		cin>>x;
		For(j,1,m){
			char y = x[j-1];
			if(y == '1')
			a[i][j] = 1;
			else a[i][j] = 0;
		}
	}
	
//	For(i,1,n){
//		For(j,1,m){
//			cout<<a[i][j];
//		}cout<<endl;
//	}
	//right
	For(i,1,n){
		rof(j,1,m-1){
			if(a[i][j+1]==1) Right[i][j+1] = -1;
			else Right[i][j] = Right[i][j+1]+1; 
		}
	}
	
	//up
//	For(i,2,n){
//		For(j,1,m){
//			if(a[i-1][j]==1) up[i-1][j] = -1;
//			else up[i][j] = up[i-1][j] + 1;
//		}
//	}
	
//	For(i,1,n){
//		For(j,1,m){
//			cout<<up[i][j]<<" ";
//		}cout<<endl;
//	}

// c
	
	For(i,1,n){
		For(j,1,m){
				ll ba = Right[i][j];
				if(ba != 0 && ba != -1)
					For(z,i+2,n){
						if(a[i][j] == 1 || a[i+1][j]==1 || a[i+2][j]==1 || a[z][j]==1) break;
						fc[i][j] = Mod(fc[i][j]+ba*Right[z][j]); 
					} 
			
		}
	}

//f
	
	For(i,1,n){
		For(j,1,m){
				ll ba = Right[i][j];
				if(ba != 0 && ba != -1)
					For(z,i+2,n){
						if(a[i][j] == 1 || a[i+1][j]==1 || a[i+2][j]==1 || a[z][j]==1) break;
						ll k = 0;
						For(t,z+1,n){
							if(a[t][j] == 1) break;
							else k++;
						}
						ff[i][j] = Mod(ff[i][j]+ba*Right[z][j]*k); 
					} 
			
		}
	}
	
	
	For(i,1,n){
		For(j,1,m){
			ansc = Mod(ansc+fc[i][j]);
			ansf = Mod(ansf+ff[i][j]);
		}
	}
	if(c ==0 && f==0){
		cout<<"0 0"<<endl;
	}
	else{
		ll ac = c*ansc,af =f*ansf;
		cout<<Mod(ac)<<" "<<Mod(af)<<endl;
	}
	
	}
	
	return 0;
}
