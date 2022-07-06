#ifndef _map

#define _map
#include "Thing.cpp"
#include "const.cpp"
#include <cstring>
#include <map>
std::map<std::string, int> thing_cl;

void make_map(const Thing *thing) {
    for (int c = 0; c < maxn; c++) {
        if (thing[c].cl != -1)
            thing_cl[thing[c].name] = thing[c].cl;
    }
}

#endif