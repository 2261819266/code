#include<cstdio>
using namespace std;
int a[1000];
int qzh(int n){
    if(n==0)return a[0];
    return a[n]+qzh(n-1);
}
int main(){
    int c,d,e,n;
    scanf("%d",&n);
    for(c=0;c<n;c++){
        scanf("%d",&a[c]);
        printf("%d",qzh(c));
    }
}