#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int aleatroire() {
    srand(time(NULL));
    int generated_number = (rand() % 1000) + 1;
    return generated_number >= 500;
}

int main() {
    int montant_total;
    int mise;
    int value;
    printf("Combien d'argent avez vous ?(€)");
    scanf("%d", &montant_total);
    getchar();
    printf("1. Joueur\n2. Retirer\n");
    scanf("%d", &value);
    getchar();
    while (value != 2) {
        if (value == 1) {
            printf("Solde actuel: %d\n", montant_total);
            printf("mise(€): ");
            scanf("%d", &mise);
            getchar();
            if (mise > montant_total || mise < 0) {
                printf("error somme impossible\n");
            } else {
                if (aleatroire() == 1) {
                    montant_total += mise;
                } else montant_total -= mise;
            }
            if(montant_total == 0){
                printf("Perdu solde nul");
                return 0;
            }
            printf("Solde actuel: %d\n", montant_total);
            printf("1. Joueur\n2. Retirer\n");
            scanf("%d", &value);
            getchar();
        } else if (value != 1) {
            printf("valeur impossible\n");
            printf("1. Joueur\n2. Retirer\n");
            scanf("%d", &value);
            getchar();
        }
    }
    printf("Vous repartez avec: %d",montant_total);
    return 0;
}
