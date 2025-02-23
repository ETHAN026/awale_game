#include <stdio.h>
#include <stdlib.h>


typedef struct cases{
    int graines;
    struct cases *suivant;
}cases;

// il faut d'abord la création d'une liste chainer circulaire 

typedef struct liste{
    cases *premier;
    cases *dernier;
}liste;


typedef struct jeu{
    liste *cases;
    int gain_jA;
    int gain_jB;
}jeu;

void init_jeu(jeu *j) {

    // Allocation mémoire pour la liste des cases
    j->cases = (liste *)malloc(sizeof(liste));

    // Allocation de la première case
    cases *premier = (cases *)malloc(sizeof(cases));
    premier->graines = 4;  // ici c'est pour initialiser la case avec 4 graines
    premier->suivant = NULL;

     
     j->cases->premier = premier;  

     cases *parcour = premier;

     for (int i = 1; i < 12; i++) {
        // Création d'une nouvelle case
        cases *nouvelle_case = (cases *)malloc(sizeof(cases));
        nouvelle_case->graines = 4;  // Init chaque case avec 4 graines
        nouvelle_case->suivant = NULL;

        parcour->suivant = nouvelle_case;
 
        parcour = nouvelle_case;
    }

    parcour->suivant = premier;

    
    j->gain_jA = 0;
    j->gain_jB = 0;

        char choix;
        printf("Choisissez votre identifiant (A pour joueur A, B pour joueur B) : ");
        scanf(" %c", &choix);
    
        if (choix == 'A' || choix == 'a') {
            printf("Vous etes le joueur A.\n");

            // Ca c'est pour init jA
        } else if (choix == 'B' || choix == 'b') {
            printf("Vous etes le joueur B.\n");

            // Ca c'est pour init jB
        } else {
            printf("Choix invalide. Vous êtes le joueur A par défaut.\n");
            
        }


};

void dessiner_plateau(jeu *j) {
    cases *courant = j->cases->premier;

    // Affichage des cases du joueur A (rangée 1)
    printf("Joueur A:  ");
    for (int i = 0; i < 6; i++) {
        printf("%d   ", courant->graines);  // Affiche le nombre de graines dans la case
        courant = courant->suivant;
    }

    printf("\n");

    // Affichage des cases du joueur B (rangée 2)
    printf("Joueur B:  ");
    for (int i = 0; i < 6; i++) {
        printf("%d   ", courant->graines);  // Affiche le nombre de graines dans la case
        courant = courant->suivant;
    }

    printf("\n");

    
    printf("Gains du joueur A: %d\n", j->gain_jA);
    printf("Gains du joueur B: %d\n", j->gain_jB);
}

int main() {
    jeu j;
    init_jeu(&j);
    dessiner_plateau(&j);
    return 0;
}

