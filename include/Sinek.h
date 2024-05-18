#ifndef SINEK_H
#define SINEK_H

#include "Canli.h"

struct SINEK {

    Canli super;

    void (*destroy) (struct SINEK*);

};

typedef struct SINEK* Sinek;

Sinek createSinek(int, int);
void sinekEat(const Canli, const Canli);
void destroySinek(const Sinek);

#endif