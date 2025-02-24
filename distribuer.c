#include<stdio.h>
#include<stdlib.h>
void distribuer(int numcase, char joueur) {
    // Vérifier si la case est valide
    if (numcase < 0 || numcase >= 12) {
        printf("Case invalide. Veillez choisir une case valide.\n");
        return;
    }

    // Vérifier si la case est vide
    if (plateau[numcase] == 0) {
        printf("La case %d est vide. Choisissez une autre case.\n", numcase);
        return;
    }

    // Récupérer les graines de la case sélectionnée
    int graine_distribuer = plateau[numcase];
    plateau[numcase] = 0; // Vider la case

    // Distribuer les graines
    int case_courante = numcase;
    while (graine_distribuer > 0) {
        case_courante = (case_courante + 1) % 12; // Passer à la case suivante (boucler si nécessaire)
        if (case_courante != numcase) { // Ne pas redistribuer dans la case d'origine
            plateau[case_courante]++;
            graines_a_distribuer--;
        }
    }

