#include <stdio.h>
#include <math.h>

/*
     5. Napisati C program koji će korisniku omogućiti unos realnog broja koji je veći ili jednak 2 s barem
    tri decimalna mjesta i pomoću standarda IEEE 754 jednostruke preciznosti pretvoriti broj u binarni
    ekvivalent popunjavanjem cjelobrojnog polja duljine 32 elementa. Pripaziti na postupak pretvorbe
    kada je broj negativan i kada je pozitivan.
 */

#define B_LEN 32
#define S_LEN 8
#define M_LEN 23

struct divider_t {
    float last_value;
    int count;
};

int has_dec_places(float num, int count) {
    float temp = num;
    if (temp < 0) {
        temp *= -1;
    }
    for (int i = 0; i < count; i++) {
        temp = (float) fmodf(temp, 1.0f) * 10.0f;
        if ((int) temp <= 0) {
            return 0;
        }
    }
    return 1;
}

struct divider_t get_divider(float num, float divider) {
    float temp = num;
    int count = 0;
    while (temp > divider) {
        temp /= divider;
        count++;
    }
    struct divider_t return_value = {
            .last_value = temp,
            .count = count
    };
    return return_value;
}

int main(void) {
    float num;
    do {
        printf("Unesi realni broj: ");
        scanf("%f", &num);
    } while (fabsf(num) < 2 || has_dec_places(num, 3) == 0);

    int P = 0;
    if (num < 0) {
        P = 1;
        num *= -1;
    }

    struct divider_t divider = get_divider(num, 2);
    int K = divider.count + 127;

    int k_bin[S_LEN];
    for (int i = 0; i < S_LEN; i++) {
        k_bin[i] = K % 2;
        K /= 2;
    }

    float val = fmodf(divider.last_value, 1.0f);
    int m_bin[M_LEN];
    for (int i = 0; i < M_LEN; i++) {
        val *= 2;
        m_bin[i] = (int) val;
        val = fmodf(val, 1.0f);
    }

    int bin[B_LEN];
    for (int i = 0; i < M_LEN; i++) {
        bin[i] = m_bin[(M_LEN - 1) - i];
    }
    for (int i = 0; i < S_LEN; i++) {
        bin[M_LEN + i] = k_bin[i];
    }
    bin[B_LEN - 1] = P;

    for (int i = B_LEN - 1; i >= 0; i--) {
        printf("%d", bin[i]);
    }

    return 0;
}