#include <stdio.h>
#include <math.h>

/*
    2. Napisati C program koji s tipkovnice učitava brojeve 0 i 1 u polje cijelih brojeva duljine 8 elemenata.
    Potrebno je izračunati i na ekran ispisati dekadski zapis učitanog broja. Pripaziti na postupak
    pretvorbe kada je broj negativan i kada je pozitivan.
 */

#define LEN 8

int main(void) {
    int bin[LEN];
    for (int i = 0; i < LEN; i++) {
        do {
            printf("bin[%d]=", i);
            scanf("%d", &bin[i]);
        } while (bin[i] > 1 || bin[i] < 0);
    }

    int dec = 0;
    for (int i = 0; i < LEN; i++) {
        dec += (int) (bin[i] * pow(2, (LEN - 1) - i));
    }

    printf("dec: %d", dec);

    return 0;
}