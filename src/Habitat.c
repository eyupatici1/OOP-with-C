#include "Habitat.h"
#include <Windows.h>

Habitat createHabitat() {

    Habitat this;
    this = (Habitat)malloc(sizeof(struct HABITAT));
    this -> count = 0;

    this -> getCount = &getCount;
    this -> readFromFile = &readFromFile;
    this -> firstState = &firstState;
    this -> countLines = &countLines;
    this -> destroy = &destroyHabitat;

    return this;
}

void readFromFile(const Habitat this) {

    this -> count = 0;
    int putOrder = 0;

    FILE* fp;
    int num = 0;

    fp = fopen("./doc/Veri.txt", "r");

    if(fp == NULL) {
        printf("Error opening file!\n");
    }

    while(fscanf(fp, "%d", &num) != EOF) this -> count++;
    //printf("%d: ", this -> count);
    /* char line[100];
    while(fgets(line, sizeof(line), fp)) {
        if(strlen(line) == 1 && line[0] == '\n') this -> count--;
    } */

    rewind(fp);

    this -> arr = (int *)malloc(this -> count * sizeof(int));
    if(this -> arr == NULL) {
        printf("Memory allocation failed!\n");
        fclose(fp);
    }

    this -> count = 0;
    while(fscanf(fp, "%d", &this -> arr[this -> count]) != EOF) this -> count++;
    //printf("%d: ", count);

    int lineCount = this -> countLines();
    //printf("Line count: %d", lineCount);
    int eachLine = this -> count / lineCount;
    //printf("Each line will have: %d", eachLine);

    // eachLine = row
    // lineCount = column
    Canli *canlilar = malloc(this -> count * sizeof(Canli));
    Bitki *bitkiler = malloc(this -> count * sizeof(Bitki));
    Bocek *bocekler = malloc(this -> count * sizeof(Bocek));
    Sinek *sinekler = malloc(this -> count * sizeof(Sinek));
    Pire *pireler = malloc(this -> count * sizeof(Pire));

    int bitkiCount = 0; int bocekCount = 0; int sinekCount = 0; int pireCount = 0;

    for(int i = 0; i < this -> count; i++) {
        int temp = this -> arr[i];
        //printf("%d ", temp);

        if(temp >= 1 && temp <= 9) {
            Bitki bitki = createBitki(temp, putOrder);
            canlilar[i] = bitki -> super;
            bitkiler[bitkiCount] = bitki;
            bitkiCount++;
        } else if(temp >= 10 && temp <= 20) {
            Bocek bocek = createBocek(temp, putOrder);
            canlilar[i] = bocek -> super;
            bocekler[bocekCount] = bocek;
            bocekCount++;
        } else if(temp >= 21 && temp <= 50) {
            Sinek sinek = createSinek(temp, putOrder);
            canlilar[i] = sinek -> super;
            sinekler[sinekCount] = sinek;
            sinekCount++;
        } else if(temp >= 51 && temp <= 99) {
            Pire pire = createPire(temp, putOrder);
            canlilar[i] = pire -> super;
            pireler[pireCount] = pire;
            pireCount++;
        }
        
        canlilar[i] -> gorunum(canlilar[i], canlilar[i]);
        /* Canli canli = createCanli(temp, putOrder);
        canli -> setCh(canli);
        canlilar[i] = canli; */

        putOrder++;

        if(putOrder % eachLine == 0) {
            printf("\n");
        } 
    }

    printf("\n\n");
    printf("Waiting for user input to continue: ");
    getchar();
    system("cls");
    //printf("\e[1;1H\e[2J");

    int temporary = 1;
    for(int i = 0; i < this -> count;) {

        read_again:
        if(i >= this -> count - 1 || temporary >= this -> count) break;

        if(canlilar[i] -> checkIfKilled(canlilar[i])) {
            system("cls");
            //printf("\e[1;1H\e[2J");

            //printf("i: %d, temp: %d so \n", i, temporary);
            canlilar[i] -> eat(canlilar[i], canlilar[temporary]);

            int status = 0;
            for(int j = 0; j < this -> count; j++) {
                status++;
                canlilar[j] -> gorunum(canlilar[j], canlilar[j]);

                if(status % eachLine == 0) {
                    printf("\n");
                } 
            }

            if(temporary >= this -> count - 1) {
                int idx1 = i / eachLine;
                int idx2 = i % eachLine;
                printf("Kazanan: %s : (%d, %d)", canlilar[i] -> ch, idx1, idx2);
            }
            
            temporary++;
            goto read_again;

        } else {
            i++;
            continue;
        }
    }

    for(int i = 0; i < this -> count; i++) {
        canlilar[i] -> destroy(canlilar[i]);
    }

    for(int i = 0; i < bitkiCount; i++) {
        bitkiler[i] -> destroy(bitkiler[i]);
    }

    for(int i = 0; i < bocekCount; i++) {
        bocekler[i] -> destroy(bocekler[i]);
    }

    for(int i = 0; i < sinekCount; i++) {
        sinekler[i] -> destroy(sinekler[i]);
    }

    for(int i = 0; i < pireCount; i++) {
        pireler[i] -> destroy(pireler[i]);
    } 

    fclose(fp);
    free(canlilar); free(bitkiler); free(bocekler); free(sinekler); free(pireler);
    free(this -> arr);
}

void firstState(const Habitat this) {
}

int countLines() {

    FILE *fp = fopen("./doc/Veri.txt", "r");
    FILE *fpEmpty = fopen("./doc/Veri.txt","r");

    if (fp == NULL) {
        printf("Dosya acilamadi. \n");
    }


    //int c = 0; 
    int line_count = 0;

    /* for (c = getc(fp); c != EOF; c = getc(fp)) {
        if (c == '\n') {
            line_count++;
        }
    } */

    char line[2048];

    if(fpEmpty == NULL) {
        printf("Dosya acilamadi. \n");
    }

    while((fgets(line, sizeof(line), fpEmpty) != NULL)) {
        line_count++;
        //printf("strlen(line): %d, number of line currently: %d\n", strlen(line), line_count);
        if(strlen(line) == 1 || line[0] == ' ' || line[0] == '\t') {
            line_count--; 
        }
    }
    
    fclose(fpEmpty);
    fclose(fp);
    //printf("The file has %d lines\n", line_count);

    return line_count;
}

int getCount(const Habitat this) {
    return this -> count;
}

void destroyHabitat(const Habitat this) {
    if(this == NULL) return;
    free(this);
}