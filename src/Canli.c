#include "Canli.h"

Canli createCanli(int value, int order) {

    Canli this;
    this = (Canli)malloc(sizeof(struct CANLI));
    this -> value = value;
    this -> order = order;

    this -> setCh = &setCh;
    this -> getCh = &getCh;
    this -> getOrder = &getOrder;
    this -> getValue = &getValue;
    this -> gorunum = &gorunum;
    this -> checkIfKilled = &checkIfKilled;
    this -> destroy = &destroyCanli;

    return this;
}


void setCh(const Canli this) {

    int temp = this -> value;

    if(temp >= 1 && temp <= 9) {
        this -> ch = "B";
    } else if(temp >= 10 && temp <= 20) {
        this -> ch = "C";
    } else if(temp >= 21 && temp <= 50) {
        this -> ch = "S";
    } else if(temp >= 51 && temp <= 99) {
        this -> ch = "P";
    }
}

char* getCh(const Canli this) {
    return this -> ch;
}

int getOrder(const Canli this) {
    return this -> order;
}

int getValue(const Canli this) {
    return this -> value;
}

int checkIfKilled(const Canli this) {
    char* temp = this -> getCh(this);
    char store = *temp;
    char toCompare[] = "X";

    if(strcmp(temp, toCompare)) {
        return 1;
    } else {
        return 0;
    }
}

char* gorunum(const Canli this, void* p) {
    printf("%s ", this -> ch);
}

void destroyCanli(const Canli this) {
    if(this == NULL) return;
    free(this);
}