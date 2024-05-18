#ifndef BITKI_H
#define BITKI_H

#include "Canli.h"

struct BITKI {

    Canli super;

    void (*destroy) (struct BITKI*);

};

typedef struct BITKI* Bitki;

Bitki createBitki(int, int);
void bitkiEat(const Canli, const Canli);
void destroyBitki(const Bitki);

#endif