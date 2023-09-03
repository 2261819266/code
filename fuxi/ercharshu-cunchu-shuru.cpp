#include <cstdio>

struct node {
    char name;
    int rc, lc;
    node() { rc = lc = 0; }
    /* data */
};

node getnode() {
    node a;
    int x, y;
    char s[10];
    scanf("%c%d%d",a.name,a.lc,a.rc);
    return a;
}

void putnode(node a){
    printf("%d",a.name);
}

int main(){

}