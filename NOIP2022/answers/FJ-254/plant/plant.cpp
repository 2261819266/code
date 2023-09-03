#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long 
#define itn int 
inline int read(){
	int x = 0, f = 1;
	char ch;
	ch = getchar();
	while(!isdigit(ch)){
		if(ch=='-'){
			f=-f;
		}
		ch = getchar();
	}
	while(isdigit(ch)){
		x = (x << 1) + (x << 3) +(ch - '0');
		ch = getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0) {
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
		putchar(x%10+'0');
	}
	else putchar(x+'0');
}
const int N = 0x3f3f3f;
int T,id,n,m,c,f,C,F,ansc,ansf,ss;
ll mapp[1005][1005];
string s1;
char s;
ll xc[N],xf[N],yc[N],yf[N],sumc,sumf;
void searchc(){
	for(int i=1;i<=sumc;i++){
		int j = yc[i],sum1=0,sum2=0;
		while(mapp[xc[i]][j+1]==0){
			j++;
			sum1++;
		} 
	//	cout<<"c : sum1 : "<<sum1<<endl;
		for(int k = xc[i]+2;k<=n;k++){
			if(mapp[k][yc[i]]==0){
				j = yc[i];
				while(mapp[k][j+1]==0){
					j++;
					sum2++;
				} 
			}
			else break;
		}
		ansc=(ansc+sum1*sum2)%998244353;
//		cout<<"c : sum2 : "<<sum2<<endl;
	}
}
void searchf(){
	for(int i=1;i<=sumf;i++){
		int j = yf[i],sum1=0,sum2=0,sum3=0,sum4,k = xf[i]+3;
		while(mapp[xf[i]][j+1]==0){
			j++;
			sum1++;
		}
		while(mapp[k][yf[i]]==0){
			k++;
			sum3++;
		}
//		cout<<"f : sum1 : "<<sum1<<endl;
//		cout<<"f : sum3 : "<<sum3<<endl;
		for(k = xf[i]+3;k<=n;k++){
			sum4=0;
			if(mapp[k][yf[i]]==0){
				j = yf[i];
				while(mapp[k-1][j+1]==0){
					j++;
					sum4++;
				}
				sum2+=(sum4*(sum3-k+xf[i]+3));
			//	cout<<"f : sum4 : "<<sum4<<endl;
			}
			else break;
		}
		ansf=(ansf+sum1*sum2)%998244353;
	//	cout<<"f : sum2 : "<<sum2<<endl;
	}
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	T=read();s = getchar();
	id = s-'0';
	while(T--){
		memset(mapp,1,sizeof(mapp));
		ansc=ansf=0;
		memset(xc,0,sizeof(xc));
		memset(xf,0,sizeof(xf));
		memset(yc,0,sizeof(yc));
		memset(yf,0,sizeof(yf));
		sumc=sumf=0;
		n = read();
		//cout<<n<<" ";
		m = read();
		//cout<<m;
		c = read();
		//cout<<c<<" ";
		s = getchar();
		f = s-'0';
		//cout<<f;
		for(int i=1;i<=n;i++){
			cin>>s1;
			for(int j=1;j<=m;j++){
				mapp[i][j] = s1[j-1]-'0';
			//	cout<<mapp[i][j];
				if(i-2>0&&mapp[i-2][j]==0&&mapp[i-1][j]==0&&mapp[i][j]==0) {
					sumc++;
					xc[sumc]=i-2;
					yc[sumc]=j;
			//		cout<<xc[sumc]<<" "<<yc[sumc]<<endl;
					if(i-3>0&&mapp[i-3][j]==0) {
						sumf++;
						xf[sumf]=i-3;
						yf[sumf]=j;
					}
				}
			}
			//cout<<endl;
		}
		searchc();
		searchf();
		ansc*=c;
		ansf*=f;
		write(ansc);
		cout<<" ";
		write(ansf);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
