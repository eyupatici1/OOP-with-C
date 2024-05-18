#ifndef PIRE_H
#define PIRE_H

#include "Canli.h"

struct PIRE {

    Canli super;

    void (*destroy) (struct PIRE*);

};

typedef struct PIRE* Pire;

Pire createPire(int, int);
void pireEat(const Canli, const Canli);
void destroyPire(const Pire);

#endif