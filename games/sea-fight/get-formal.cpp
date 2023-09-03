#include "Thing.cpp"
#include "func.cpp"
#include <cstdio>
#include <cstring>
#ifndef _formal
#define _formal
void get_formal_Basic_info(FILE *fin, Thing *thing) {
    int x;
    char *str = new char;
    while (true) {
        fscanf(fin, "%d", &x);
        if (x == -1)
            return;
        fscanf(fin, "%s", str);
        if (Isxisy_str(str, "mat")) {
            fscanf(fin,"%s", str);
            thing[x].is = 'M';
            strcpy(thing[x].name, str);
            thing[x].cl=x;
        }
        if (Isxisy_str(str, "shell")) {
            fscanf(fin,"%s", str);
            thing[x].is = 'S';
            strcpy(thing[x].name, str);
            thing[x].cl=x;
        }
        if (Isxisy_str(str, "gun")) {
            fscanf(fin,"%s", str);
            thing[x].is = 'G';
            strcpy(thing[x].name, str);
            thing[x].cl=x;
        }
    }
}
#endif