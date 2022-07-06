#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
long long a[1000005],c,d,e,n,p=0,q=0;
int main(){
    scanf("%lld",&n);
    for(c=1;c<=n;c++){
        scanf("%d",&a[c]);
    }
    for(int c=n;c>0;c--){
        a[c]-=a[c-1];
    }
    for(c=2;c<=n;c++){
        if(a[c]>0)p+=a[c];
        else q+=abs(a[c]);
    }
    printf("%lld\n%lld",max(p,q),abs(p-q)+1);
}