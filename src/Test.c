#include "Bitki.h"
#include "Bocek.h"
#include "Sinek.h"
#include "Pire.h"
#include "Habitat.h"

int main() {

    Habitat h = createHabitat();
    h -> readFromFile(h);
    h -> destroy(h);

    return 0;
}