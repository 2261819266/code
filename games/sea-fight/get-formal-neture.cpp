#ifndef _neture

#define _neture

#include "Thing.cpp"
#include <queue>
#define _queue std::queue<int>

void get_mat(Thing &thing, int init_, int add) {
    thing.initial_value = init_;
    thing.press_inc = add;
}

void get_gun(Thing &thing, int init_, int _bv, int res, _queue l, _queue a) {
    thing.initial_value = init_;
    thing.bv = _bv;
    thing.res = res;
    while (!l.empty()) {
        thing.load[l.front()] = 1;
        thing.ln++;
        l.pop();
    }
    while (!a.empty()) {
        thing.attack[a.front()] = 1;
        thing.an++;
        a.pop();
    }
}

void get_shell(Thing &thing, int init_, int agg) {
    thing.initial_value = init_;
    thing.agg = agg;
}

void get_neture(FILE *fin, Thing *thing) {
    int x, _init;
    char s;
    while (true) {
        while (s != '\n')
            fscanf(fin, "%c", &s);
        fscanf(fin, "%d,%d,", &x, &_init);
        if (x == -1)
            return;
        if (thing[x].is == 'M') {
            int a;
            fscanf(fin, "%d", &a);
            get_mat(thing[x], _init, a);
        }
        if (thing[x].is == 'G') {
            int c, b, ln, an, d;
            _queue l, a;
            fscanf(fin, "%d,%d,%d", &c, &b, &ln);
            for (int i = 0; i < ln; i++)
                fscanf(fin, ",%d", &d), l.push(d);
            fscanf(fin, ",%d", &an);
            for (int i = 0; i < an; i++)
                fscanf(fin, ",%d", &d), a.push(d);
            get_gun(thing[x], _init, c, b, l, a);
        }
        if (thing[x].is == 'S') {
            int agg;
            fscanf(fin, "%d", &agg);
            get_shell(thing[x], _init, agg);
        }
    }
}

#endif