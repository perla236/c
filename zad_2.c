#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
    3. Napisati C program koji će iz cjelobrojnog polja koje predstavlja binarni zapis duljine 32 elemenata
    popunjenog pseudo-slučajnim vrijednostima [0, 1], pretvoriti i ispisati dekadski zapis broja.
    Pripaziti na postupak pretvorbe kada je broj negativan i kada je pozitivan.
 */

#define LEN 32

int main(void) {
    srand((unsigned) time(NULL));

    int bin[LEN];
    for (int i = 0; i < LEN; i++) {
        bin[i] = ((rand() / (float) RAND_MAX) > 0.5f ? 1 : 0);
    }
    printf("bin: ");
    for (int i = 0; i < LEN; i++) {
        printf("%d", bin[i]);
    }
    printf("\n");

    if (bin[0] == 1) {
        int flag = 0;
        for (int i = 0; i < LEN; i++) {
            int bit = bin[i];
            if (flag == 1) {
                bin[i] = bit == 0 ? 1 : 0;
            }
            if (bit == 1) {
                flag = 1;
            }
        }
    }

    int dec = 0;
    for (int i = 0; i < LEN; i++) {
        dec += (int) (bin[i] * pow(2, (LEN - 1) - i));
    }

    printf("dec: %d", dec);

    return 0;
}