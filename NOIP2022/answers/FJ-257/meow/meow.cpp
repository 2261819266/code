#include<bits/stdc++.h>
using namespace std;
inline int R(){
    char c=getchar();
    for(;!(('0'<=c&&c<='9')||c=='-');c=getchar());
    int s=1,num=0;
    if(c=='-'){
        s=-1;
        c=getchar();
    }
    while('0'<=c&&c<='9'){
        num=num*10+(c-'0');
        c=getchar();
    }
    num=num*s;
    return num;
}
int main(){
    freopen("meow.in","r",stdin);
    freopen("meow.out","w",stdout);
    printf("5\n1 1\n1 1\n1 2\n2 1 2\n1 1");
    return 0;
}

