#ifndef BOCEK_H
#define BOCEK_H

#include "Canli.h"

struct BOCEK {

    Canli super;

    void (*destroy) (struct BOCEK*);

};

typedef struct BOCEK* Bocek;

Bocek createBocek(int, int);
void bocekEat(const Canli, const Canli);
void destroyBocek(const Bocek);

#endif