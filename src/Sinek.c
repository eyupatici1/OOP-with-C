#include "Sinek.h"

Sinek createSinek(int value, int order) {

    Sinek this;
    this = (Sinek)malloc(sizeof(struct SINEK));
    this -> super = createCanli(value, order);

    this -> super -> setCh(this -> super);
    this -> super -> eat = &sinekEat;
    this -> destroy = &destroySinek;

    return this;
}

void sinekEat(const Canli arg1, const Canli arg2) {
    int temp = arg1 -> value;
    int toCheck = arg2 -> value;
    int ord1 = arg1 -> order;
    int ord2 = arg2 -> order;

    if((toCheck >= 10 && toCheck <= 20) || (toCheck >= 51 && toCheck <= 99)) {
        arg2 -> ch = "X";
    } else if((toCheck >= 21 && toCheck <= 50) && (temp != toCheck)) {
        if(temp > toCheck) {
            arg2 -> ch = "X";
        } else if(toCheck > temp) {
            arg1 -> ch = "X";
        }
    } else if((toCheck >= 21 && toCheck <= 50) && (temp == toCheck)) {
        if(ord1 > ord2) {
            arg1 -> ch = "X";
        } else if(ord2 > ord1) {
            arg2 -> ch = "X";
        }
    } else if((toCheck >= 1 && toCheck <= 9)) {
        arg1 -> ch = "X";
    }

}

void destroySinek(const Sinek this) {
    if(this == NULL) return; 
    this -> super -> destroy(this -> super);
    free(this);
}