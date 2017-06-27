#include <stdio.h>
#include <math.h>
#include <time.h>

typedef long long llong;

void rekurzija(int tab[][2], int nivo, int st_nivojev, llong vsota) {
    for (int i = tab[nivo][0]; i <= tab[nivo][1]; i++) {
        llong dodatek = (llong) pow(10, st_nivojev - nivo) * i;
        vsota += dodatek;
        if (st_nivojev == nivo) {
            printf("%lld\n", vsota);
        } else {
            rekurzija(tab, nivo + 1, st_nivojev, vsota);
        }
        vsota -= dodatek;
    }
    return;
}

int main() {
    clock_t begin = clock();
    int mesta;
    scanf("%d", &mesta);
    int tabela[mesta][2];
    for (int i = 0; i < mesta; i++) {
        scanf("%d %d", &tabela[i][0], &tabela[i][1]);
    }
    rekurzija(tabela, 0, mesta - 1, 0);

    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("%f", time_spent);
    return 0;
}