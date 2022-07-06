#ifndef _player

#define _player
#include "Thing.cpp"
#include "const.cpp"
#include "func.cpp"
#include "list.cpp"
#include <cstdio>
struct Player {
    void printf_formal_nature_exi(Thing *thing) {
        t = thing;
        int e = 1;
        for (int c = 0; c < maxn; c++) {
            if (e % 21 == 0)
                printf("\n\n\n"), e++;
            int x = getx(), y = gety();
            if (t[c].cl != -1) {
                gotoaddxy(0, 1);
                printf("%d\t", exi[c]);
                gotoxy(x, y);
                printf("%s\t", t[c].name);
                e++;
            }
        }
        printf("\n\n\n");
        for (int c = 0; c < maxn; c++) {
            if (t[c].is == 'G') {
                printf("%s:\t", t[c].name);
                gunbv[c].print("%d\t","\n");
            }
        }
        printf("\n");
    }
    int get_bv() const { return exi[0]; }
    void init_exi(const Thing *thing, const char *str = "player") {
        for (int c = 0; c < maxn; c++) {
            if (thing[c].cl != -1) {
                exi[c] = thing[c].initial_value;
                if (thing[c].is == 'G') {
                    for (int d = 0; d < thing[c].initial_value; d++)
                        gunbv[c].push(thing[c].bv);
                }
            }
        }
        strcpy(name, str);
    }
    Thing *t;
    char *name = new char;
    int exi[maxn];
    list<int> gunbv[maxn];
};

#endif