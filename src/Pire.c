#include "Pire.h"

Pire createPire(int value, int order) {

    Pire this;
    this = (Pire)malloc(sizeof(struct PIRE));
    this -> super = createCanli(value, order);

    this -> super -> setCh(this -> super);
    this -> super -> eat = &pireEat;
    this -> destroy = &destroyPire;

    return this;
}

void pireEat(const Canli arg1, const Canli arg2) {
    int temp = arg1 -> value;
    int toCheck = arg2 -> value;
    int ord1 = arg1 -> order;
    int ord2 = arg2 -> order;

    if((toCheck >= 51 && toCheck <= 99) && (temp != toCheck)) {
        if(temp > toCheck) {
            arg2 -> ch = "X";
        } else if(toCheck > temp) {
            arg1 -> ch = "X";
        }
    } else if((toCheck >= 51 && toCheck <= 99) && (temp == toCheck)) {
        if(ord1 > ord2) {
            arg1 -> ch = "X";
        } else if(ord2 > ord1) {
            arg2 -> ch = "X";
        }
    } else if(!(toCheck >= 51 && toCheck <= 99)) {
        arg1 -> ch = "X";
    }

}

void destroyPire(const Pire this) {
    if(this == NULL) return; 
    this -> super -> destroy(this -> super);
    free(this);
}