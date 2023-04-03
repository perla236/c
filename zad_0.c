#include <stdio.h>

/*
    1. Napisati C program koji s tipkovnice učitava cijeli broj u intervalu [-128, 127]. Potrebno je izračunati
    i na ekran ispisati binarni zapis učitanog broja duljine 8 bita. Pripaziti na postupak pretvorbe kada
    je broj negativan i kada je pozitivan.
 */

int main() {
    int num;
    do {
        printf("Unesi broj (-128 <> 127): ");
        scanf("%d", &num);
    } while (num < -128 || num > 127);
    printf("%d: ", num);

    int p = 1;
    if (num < 0) {
        p = -1;
        num *= -1;
    }

    static const int len = 8;
    int bin[len];
    for (int i = 0; i < len; i++) {
        bin[i] = num % 2;
        num /= 2;
    }

    if (p < 0) {
        int flag = 0;
        for (int i = 0; i < len; i++) {
            int bit = bin[i];
            if (flag == 1) {
                bin[i] = bit == 0 ? 1 : 0;
            }
            if (bit == 1) {
                flag = 1;
            }
        }
    }
    for (int i = len - 1; i >= 0; i--) {
        printf("%d", bin[i]);
    }
    printf("\n");

    return 0;
}
