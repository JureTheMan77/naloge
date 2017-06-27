#include <stdio.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

typedef long long llong;

typedef struct Argumenti {
    int nivo;
    int st_nivojev;
    llong vsota;
    int **tab;
    pthread_t id;
} Argumenti;

pthread_t tid[18];
int stevec = 0;

void rekurzija(Argumenti *arg) {
    int start_stevec = stevec;

    for (int i = arg->tab[arg->nivo][0]; i <= arg->tab[arg->nivo][1]; i++) {
        llong dodatek = (llong) pow(10, arg->st_nivojev - arg->nivo) * i;
        arg->vsota += dodatek;

        if (arg->st_nivojev == arg->nivo) {
            printf("%lld\n", arg->vsota);
        } else {
            stevec++;
            Argumenti *vstop = (Argumenti *) malloc(sizeof(Argumenti));
            vstop->tab = arg->tab;
            vstop->nivo = arg->nivo + 1;
            vstop->st_nivojev = arg->st_nivojev;
            vstop->vsota = arg->vsota;
            vstop->id = tid[stevec];
            pthread_create(&(tid[stevec]), NULL, (void *(*)(void *)) &rekurzija, vstop);
        }
        arg->vsota -= dodatek;
    }
    if (arg->id == 0) {
        return;
    }
    if (arg->st_nivojev == arg->nivo) {
        pthread_exit(0);
    } else {
        for (int i = arg->tab[arg->nivo][0]; i <= arg->tab[arg->nivo][0]; i++) {
            pthread_join(tid[start_stevec + i], 0);
        }
    }
    return;
}

int main() {
    clock_t begin = clock();
    int mesta;
    scanf("%d", &mesta);
    int **tabela = (int **) malloc(mesta * sizeof(int *));
    for (int i = 0; i < mesta; i++) {
        tabela[i] = (int *) malloc(2 * sizeof(int));
        scanf("%d %d", &tabela[i][0], &tabela[i][1]);
    }

    Argumenti *vstop = (Argumenti *) malloc(sizeof(Argumenti));
    vstop->tab = tabela;
    vstop->nivo = 0;
    vstop->st_nivojev = mesta - 1;
    vstop->vsota = 0;
    vstop->id = 0;

    rekurzija(vstop);
    sleep(25);

    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("%f", time_spent);
    return 0;
}