#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    4. Napisati C program koji će pseudo-slučajno generirati broj iz intervala za short tip podatka, te taj
    broj pretvoriti u binarni ekvivalent popunjavanjem cjelobrojnog polja duljine 32 elementa. Pripaziti
    na postupak pretvorbe kada je broj negativan i kada je pozitivan.
 */

#define MIN -32768
#define MAX 32767
#define LEN 32

int main(void) {
    srand((unsigned) time(NULL));
    short num = (rand() / (float) RAND_MAX) * (MAX - MIN) + MIN;
    printf("short: %d\n", num);

    int p = 1;
    if (num < 0) {
        p = -1;
        num *= -1;
    }

    int bin[LEN];
    for (int i = 0; i < LEN; i++) {
        bin[i] = num % 2;
        num /= 2;
    }

    if (p < 0) {
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
    for (int i = LEN - 1; i >= 0; i--) {
        printf("%d", bin[i]);
    }
    printf("\n");

    return 0;
}