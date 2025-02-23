/*#include <stdio.h>
#include <stdlib.h>

#define ROWS 2
#define COLUMNS 6
#define TOTAL_SEEDS 4

// Structure pour représenter le plateau
typedef struct {
    int cases[ROWS][COLUMNS];
} AwaleBoard;

// Fonction d'initialisation du jeu
void initBoard(AwaleBoard *board) {
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

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            board->cases[i][j] = TOTAL_SEEDS; // Chaque trou reçoit 4 graines
        }
    }
}

// Fonction d'affichage du plateau
void displayBoard(AwaleBoard *board) {
    printf("\n           --- Awale ---\n");
    printf("   ------------------------------\n");

    // Affichage de la ligne supérieure (adversaire)
    printf("   ");
    for (int j = COLUMNS - 1; j >= 0; j--) {
        printf("[%2d] ", board->cases[0][j]);

    }
    printf(" <-- Joueur A\n");

    printf("   ------------------------------\n");
    printf("   ");


    // Affichage de la ligne inférieure (joueur)
    for (int j = 0; j < COLUMNS; j++) {

        printf("[%2d] ", board->cases[1][j]);
    }
    printf(" <-- Joueur B");
    printf("\n   ------------------------------\n");
}

// Programme principal
int main() {
    AwaleBoard game;
    initBoard(&game);
    displayBoard(&game);

    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>

#define ROWS 2
#define COLUMNS 6
#define TOTAL_SEEDS 4

// Structure pour représenter le plateau
typedef struct {
    int cases[ROWS][COLUMNS];
} AwaleBoard;

// Fonction d'initialisation du jeu
void initBoard(AwaleBoard *board) {
    // Initialiser les graines de chaque case à 4
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            board->cases[i][j] = TOTAL_SEEDS;
        }
    }
}

// Fonction d'affichage du plateau
void displayBoard(AwaleBoard *board) {
    printf("\n           --- Awale ---\n");
    printf("   ------------------------------\n");

    // Affichage de la ligne supérieure (Joueur A)
    printf("   ");
    for (int j = COLUMNS - 1; j >= 0; j--) {
        printf("[%2d] ", board->cases[0][j]);
    }
    printf(" <-- Joueur A\n");

    printf("   ------------------------------\n");
    printf("   ");

    // Affichage de la ligne inférieure (Joueur B)
    for (int j = 0; j < COLUMNS; j++) {
        printf("[%2d] ", board->cases[1][j]);
    }
    printf(" <-- Joueur B\n");
    printf("   ------------------------------\n");
}

// Fonction pour distribuer les graines
void distribuer(AwaleBoard *board, int joueur, int case_depart) {
    int graines;
    int i = case_depart;

    // On commence par récupérer les graines de la case choisie
    if (joueur == 0) {  // Joueur A
        graines = board->cases[0][i];
        board->cases[0][i] = 0;
    } else {  // Joueur B
        graines = board->cases[1][i];
        board->cases[1][i] = 0;
    }

    while (graines > 0) {
        // On passe à la case suivante
        i = (i + 1) % (COLUMNS * 2);  // On fait une rotation circulaire
        int ligne = i / COLUMNS;  // 0 pour A, 1 pour B

        // Si c'est le tour du joueur A, on ne distribue pas sur sa propre ligne (0 à 5)
        if (ligne == 0 && (i < 6) && joueur == 1) {
            continue;  // Si on passe sur la ligne du joueur A pendant le tour du joueur B, on continue
        }

        // Si c'est le tour du joueur B, on ne distribue pas sur sa propre ligne (6 à 11)
        if (ligne == 1 && (i >= 6) && joueur == 0) {
            continue;  // Si on passe sur la ligne du joueur B pendant le tour du joueur A, on continue
        }

        if (ligne == 0) {  // Joueur A
            board->cases[0][i % COLUMNS]++;
        } else {  // Joueur B
            board->cases[1][i % COLUMNS]++;
        }

        graines--;
    }
}

// Programme principal
int main() {
    AwaleBoard game;
    initBoard(&game);
    displayBoard(&game);

    // Exemple : Le joueur A sème à partir de la case 2
    printf("\nLe joueur A sème à partir de la case 2...\n");
    distribuer(&game, 0, 2);  // Joueur A (0) commence à semer depuis la case 2
    displayBoard(&game);

    // Exemple : Le joueur B sème à partir de la case 7
    printf("\nLe joueur B sème à partir de la case 7...\n");
    distribuer(&game, 1, 7);  // Joueur B (1) commence à semer depuis la case 7
    displayBoard(&game);

    return 0;
}
