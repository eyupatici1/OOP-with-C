#include "Bitki.h"

Bitki createBitki(int value, int order) {

    Bitki this;
    this = (Bitki)malloc(sizeof(struct BITKI));
    this -> super = createCanli(value, order);

    this -> super -> setCh(this -> super);
    this -> super -> eat = &bitkiEat;
    this -> destroy = &destroyBitki;

    return this;
}

void bitkiEat(const Canli arg1, const Canli arg2) {
    int temp = arg1 -> value;
    int toCheck = arg2 -> value;
    int ord1 = arg1 -> order;
    int ord2 = arg2 -> order;

    if((toCheck >= 21 && toCheck <= 50) || (toCheck >= 51 && toCheck <= 99)) {
        arg2 -> ch = "X";
    } else if((toCheck >= 1 && toCheck <= 9) && (temp != toCheck)) {
        if(temp > toCheck) {
            arg2 -> ch = "X";
        } else if(toCheck > temp) {
            arg1 -> ch = "X";
        }
    } else if((toCheck >= 1 && toCheck <= 9) && (temp == toCheck)) {
        if(ord1 > ord2) {
            arg1 -> ch = "X";
        } else if(ord2 > ord1) {
            arg2 -> ch = "X";
        }
    } else if((toCheck >= 10 && toCheck <= 20)) {
        arg1 -> ch = "X";
    }
}

void destroyBitki(const Bitki this) {
    if(this == NULL) return; 
    this -> super -> destroy(this -> super);
    free(this);
}