#ifndef HABITAT_H
#define HABITAT_H

#include "Canli.h"
#include "Bitki.h"
#include "Bocek.h"
#include "Pire.h"
#include "Sinek.h"

struct HABITAT {

    FILE *fp;
    int *arr;
    int count;

    int (*getCount) (struct HABITAT*);
    void (*readFromFile) (struct HABITAT*);
    void (*firstState) (struct HABITAT*);
    int (*countLines) ();
    void (*destroy) (struct HABITAT*);
};

typedef struct HABITAT* Habitat;

Habitat createHabitat();
int getCount(const Habitat);
void readFromFile(const Habitat);
void firstState(const Habitat);
int countLines();
void destroyHabitat(const Habitat);

#endif