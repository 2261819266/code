#ifndef _Thing

#define _Thing
#include "const.cpp"
#include <map>
struct Thing {
    char is;

    char *name=new char;
    // 代号
    int cl;

    // 初始量
    int initial_value;
    Thing() { cl = -1; }
    // 点击增量
    int press_inc;

    int res=1000;

    int bv;
    int ln;
    int load[maxn];
    int an;
    int attack[maxn];

    // 攻击力
    int agg;
};

#endif