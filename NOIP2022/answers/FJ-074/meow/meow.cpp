#include<cstdio>
#define N 303
#define M 2000002
#define pt putchar
using namespace std;
int T;
int n,m,k,a,stk[2][N];
int Qe[2][M],head[2],tail[2];
int cnt,ans[2][M];
inline int Fr(){
	int res=0;char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>47&&c<58){res=(res<<1)+(res<<3)+(c^48);c=getchar();}
	return res;
}
inline void Fp(int x){
	while(x>9)Fp(x/10);
	pt((x%10)^48);
	return;
}
inline void go1(){
	for(int i=1;i<=n;i++)stk[0][i]=stk[1][i]=0;
	for(int i=1;i<=m;i++){
		a=Fr()+1;int _=a>>1;
		if(!stk[0][_]&&!stk[1][_]){
			cnt++;
			ans[0][cnt]=1,ans[1][cnt]=_;
			stk[0][_]=a;
			continue;
		}
		if(stk[1][_]==a||(stk[0][_]==a&&!stk[1][_])){
			cnt++;
			ans[0][cnt]=1,ans[1][cnt]=_;
			for(int j=0;j<2;j++)if(stk[j][_]==a)stk[j][_]=0;
			continue;
		}
		if(stk[0][_]==a&&stk[1][_]){
			cnt++;
			ans[0][cnt]=1;ans[1][cnt]=n;
			cnt++;
			ans[0][cnt]=2;ans[1][cnt]=_;
			stk[0][_]=stk[1][_];stk[1][_]=0;
			continue;
		}
		cnt++;
		ans[0][cnt]=1,ans[1][cnt]=_;
		stk[1][_]=a;
	}
	Fp(cnt);pt('\n');
	for(int i=1;i<=cnt;i++){
		Fp(ans[0][i]),pt(' ');
		if(ans[0][i]==1)Fp(ans[1][i]);
		else Fp(ans[1][i]),pt(' '),Fp(n);
		pt('\n');
	}
	return;
}
inline void go2(){
	for(int i=0;i<2;i++)
		for(int j=head[i];j<tail[i];j++)Qe[i][j]=0;
	head[0]=head[1]=tail[0]=tail[1]=1;
	for(int i=1;i<=m;i++){
		a=Fr();int _=i&1,__=(i&1)^1;
		if(Qe[_][tail[_]-1]==a){
			++cnt;printf("1");
			ans[0][cnt]=1;ans[1][cnt]=_+1;
			Qe[_][--tail[_]]=0;
			continue;
		}
		if(Qe[__][head[__]]==a){
			++cnt;printf("2");
			ans[0][cnt]=1;ans[1][cnt]=_+1;
			++cnt;
			ans[0][cnt]=2;ans[1][cnt]=_;
			Qe[__][head[__]++]=0;
			continue;
		}
		++cnt;printf("3");
		ans[0][cnt]=1;ans[1][cnt]=_+1;
		Qe[_][++tail[_]]=a;
	}
	Fp(cnt);pt('\n');
	for(int i=1;i<=cnt;i++){
		Fp(ans[0][i]),pt(' ');
		if(ans[0][i]==1)Fp(ans[1][i]);
		else Fp(ans[1][i]+1),pt(' '),Fp((ans[1][i]^1)+1);
		pt('\n');
	}
	return;
}
inline void go3(){
	return;
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	T=Fr();
	while(T--){
		n=Fr();m=Fr();k=Fr();
		cnt=0;
		if(k==(n-1)<<1)go1();
		else if(n==2)go2();
		else go3();
	}
	return 0;
}
