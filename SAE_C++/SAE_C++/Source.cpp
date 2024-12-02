#include "Header.h"

int main(int argc, const char* argv[]) {
    int nbJoueur = 0; // nombre total des joueurs
    char joueurs[20]; // tableau de char qui stock le nombre de joueurs
    char motEnCours[26]; // tableau de caractères qui stock le mot en cours
    int nbTour = 0; // variable qui compte tous les tours depuis le début 
    int* ptr = &nbTour;
    int perdant = 1; // désignation du perdant
    int* ptr2 = &perdant;  
    int robots = 0; // variable pour designer les joueurs robots
    int humains = 0; // variable pour designer les joueurs humains
    int tourJoueur = 1; // variable qui permet de savoir c'est le tour de quel joueur

    for (int i = 0; i < 26; i++) { //initialisation du tableau à rien
        motEnCours[i] = '\0';
    }
    cin >> joueurs;
    for (int i = 0; i < strlen(joueurs); i++) { // transforme les miniscules en MAJUSCULES 
        joueurs[i] = toupper(joueurs[i]);
    }
    int joueursPartie[20];
    for (int i = 0; i < strlen(joueurs); i++) { // Compte le nombre d'humains et de robots
        if (joueurs[i] == 'H') {
            humains++;
            joueursPartie[i] = 1;
        }
        if (joueurs[i] == 'R') {
            robots++;
            joueursPartie[i] = 2;
        }
    }
    nbJoueur = strlen(joueurs);
    float* singe = new float[nbJoueur]; // création du tableau des scores 
    for (int i = 0; i < nbJoueur + 1; i++) { // initialisation des scores à 0
        singe[i] = 0;
    }
    while (verification(singe)) {
        if (nbTour == 0) { 
            tourJoueur = perdant; // désignation du perdant
        }
        saisir(motEnCours, ptr, tourJoueur, nbJoueur, singe, joueursPartie, ptr2); 
        nbTour++;
        tourJoueur++;
        if (tourJoueur == nbJoueur + 1) { // reviens au premier joueur lorsque le dernier joueur a joué
            tourJoueur = 1;
        }
    }
    return 0;
}