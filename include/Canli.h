#ifndef CANLI_H
#define CANLI_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "windows.h"
#include <windows.h>

struct CANLI {

    char* ch;
    int order;
    int value;

    void (*setCh) (struct CANLI*);
    int (*getOrder) (struct CANLI*);
    int (*getValue) (struct CANLI*);
    int (*checkIfKilled) (struct CANLI*);
    char* (*getCh) (struct CANLI*);
    char* (*gorunum) (struct CANLI*, void*);
    void (*eat) ();
    void (*destroy) (struct CANLI*);

};

typedef struct CANLI* Canli;

Canli createCanli(int, int);
void setCh(const Canli);
char* getCh(const Canli);
int getOrder(const Canli);
int getValue(const Canli);
int checkIfKilled(const Canli);
char* gorunum(const Canli, void*);
void destroyCanli(const Canli);

#endif