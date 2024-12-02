#include "Header.h"

/////
int verification(float singe[30]) {
    int end = 1;
    for (int i = 0; i < 30; i++) {
        if (singe[i] == 1) {
            std::cout << "La partie est finie" << std::endl;
            end = 0;
        }
    }
    return end;
}
/////
void resultat(float singe[30], int nbJoueur, int joueurs[20]) {
    for (int i = 1; i < nbJoueur + 1; i++) {
        std::cout << i; 
        if (joueurs[i - 1] == 1) {
            std::cout << "H : " << singe[i];
        }
        if (joueurs[i - 1] == 2) {
            std::cout << "R : " << singe[i];
        }
        if (i < nbJoueur) {
            std::cout << "; ";
        }
    }
    std::cout << endl;
}
/////
void comparaison(char motEnCours[26], int* nbTour, int tourJoueur, int nbJoueur, float singe[30], int joueurs[20], int* perdant) {
    char verifier[26];
    int joueurPrecedent;
    int mesure = 0;
    if (tourJoueur - 1 == 0) {
        joueurPrecedent = nbJoueur;
    }
    else {
        joueurPrecedent = tourJoueur - 1;
    }
    if (joueurs[joueurPrecedent - 1] == 2) { // tour du robot lors de la saisi de "?"
        ifstream in("ods4.txt"); // on ouvre le fichier
        if (!in) {
            cout << "le dictionnaire n'a pu etre ouvert" << endl;
        }
        int nb = 0, longueur = 0;
        const int MAX = 26;
        char s[MAX];
        int erreur = 0;
        int exit = 0;
        in >> setw(MAX) >> s; // on essaye de lire le premier mot
        while (in && exit == 0) {
            ++nb; // ça s'est bien passé, on le compte
            longueur += strlen(s); // et on accumule sa longueur
            for (int i = 0; i < *nbTour; i++) { 
                if (s[i] != motEnCours[i]) { // on vérifie si le mot du dictionnaire est identique au mot en cours
                    erreur++;
                }
            }
            if (erreur == 0) {
                exit = 1;
            }
            erreur = 0;
            in >> setw(MAX) >> s; // on essaye de lire le mot suivant

        }
        in.close(); // on ferme le fichier
        if (exit == 0) {
            std::cout << joueurPrecedent << "R, saisir le mot >" << motEnCours << std::endl;
            std::cout << "le mot "<< motEnCours << " existe pas, le joueur " << joueurPrecedent << "R prend un quart de singe" << std::endl;
            singe[joueurPrecedent] += 0.25;
            *perdant = joueurPrecedent;
            resultat(singe, nbJoueur, joueurs);
            for (int i = 0; i < 26; i++) {
                motEnCours[i] = '\0';
            }
            *nbTour = -1;
        }
        else {
            std::cout << joueurPrecedent << "R, saisir le mot >" << s << std::endl;
            std::cout << "le mot " << s;
            std::cout << " existe, le joueur " << tourJoueur << "H prend un quart de singe" << std::endl;
            singe[tourJoueur] += 0.25;
            *perdant = tourJoueur;
            resultat(singe, nbJoueur, joueurs); // affichage des résultats et réinitialisation du mot en cours
            for (int i = 0; i < 26; i++) {
                motEnCours[i] = '\0';
            }
            *nbTour = -1;
        }
        
    }
    else { // tour de l'humain lors de la saisi de "?"
        std::cout << joueurPrecedent << "H, saisir le mot > ";
        std::cin.clear();
        std::cin >> verifier;
        for (int i = 0; i < strlen(verifier); i++) {
            verifier[i] = toupper(verifier[i]);
        }
        int erreur = 0;
        for (int i = 0; i < *nbTour; i++) { 
            if (verifier[i] != motEnCours[i]) {
                erreur++;
            }
        }
        if (erreur != 0) { // on vérifie si le mot que le joueur a écrit commence par le mot en cours
            std::cout << "le mot " << verifier << " ne commence pas par les lettres attendues, le joueur " << joueurPrecedent << "H prend un quart de singe" << std::endl;
            singe[joueurPrecedent] += 0.25;
            *perdant = joueurPrecedent;
            resultat(singe, nbJoueur, joueurs);
            for (int i = 0; i < 26; i++) {
                motEnCours[i] = '\0';
            }
            *nbTour = -1;
        }
        else { // on regarde si le mot tapé existe bien dans le dictionnaire
            ifstream in("ods4.txt"); 
            if (!in) {
                cout << "le dictionnaire n'a pu etre ouvert" << endl;
            }
            int nb = 0, longueur = 0;
            const int MAX = 26;
            char s[MAX];
            int erreur = 0;
            in >> setw(MAX) >> s; 
            while (in) {
                ++nb; 
                longueur += strlen(s); 
                if (strcmp(verifier, s) == 0 && *nbTour > 1) {
                    std::cout << "le mot ";
                    for (int i = 0; i < strlen(verifier); i++) { 
                        std::cout << verifier[i];
                    }
                    std::cout << " existe, le joueur " << tourJoueur << "H prend un quart de singe" << std::endl;
                    singe[tourJoueur] += 0.25;
                    *perdant = tourJoueur;
                    resultat(singe, nbJoueur, joueurs);
                    for (int i = 0; i < 26; i++) {
                        motEnCours[i] = '\0';
                    }
                    mesure += 1;
                    *nbTour = -1;
                }
                in >> setw(MAX) >> s;
            }
            in.close();
            if (mesure == 0) {
                std::cout << "le mot ";
                for (int i = 0; i < strlen(verifier); i++) {
                    std::cout << verifier[i];
                }
                std::cout << " existe pas, le joueur " << joueurPrecedent << "H prend un quart de singe" << std::endl;
                singe[joueurPrecedent] += 0.25;
                *perdant = joueurPrecedent;
                resultat(singe, nbJoueur, joueurs);
                for (int i = 0; i < 26; i++) {
                    motEnCours[i] = '\0';
                }
                *nbTour = -1;
            }
        }
    }
}
/////
void motExiste(char motEnCours[26], float singe[30], int tourJoueur, int nbJoueur, int* nbTour, int* perdant, int joueurs[20]) {
    ifstream in("ods4.txt"); // on ouvre le fichier
    if (!in) {
        cout << "le dictionnaire n'a pu etre ouvert" << endl;
    }
    int nb = 0, longueur = 0;
    const int MAX = 26;
    char s[MAX];
    int erreur = 0;
    in >> setw(MAX) >> s; // on essaye de lire le premier mot
    while (in) {
        ++nb; // ça s'est bien passé, on le compte
        longueur += strlen(s); // et on accumule sa longueur
        if (strcmp(motEnCours, s) == 0 && *nbTour > 1) { // on compare si le mot en cours est identique à un mot du dictionnaire
            std::cout << "le mot ";
            for (int i = 0; i < strlen(motEnCours); i++) {
                std::cout << motEnCours[i];
            }
            std::cout << " existe, le joueur " << tourJoueur;
            if (joueurs[tourJoueur] == 1)
                std::cout << "H";
            else
                std::cout << "R";
            std::cout << " prend un quart de singe" << std::endl;
            erreur++;
        }
        in >> setw(MAX) >> s; // on essaye de lire le mot suivant
    }
    if (erreur != 0) {
        singe[tourJoueur] += 0.25;
        *perdant = tourJoueur;
        resultat(singe, nbJoueur, joueurs);
        for (int i = 0; i < 26; i++) {
            motEnCours[i] = '\0';
        }
        *nbTour = -1;
    }
}
/////
void saisir(char motEnCours[26], int* nbTour, int tourJoueur, int nbJoueur, float singe[30], int joueurs[20], int* perdant) {
    char type;
    char temp;
    if (joueurs[tourJoueur - 1] == 1) {
        type = 'H';
    }
    if (joueurs[tourJoueur - 1] == 2) {
        type = 'R';
    }
    std::cout << tourJoueur << type << ", (";
    for (int i = 0; i < *nbTour; i++) {
        std::cout << motEnCours[i];
    }
    std::cout << ") > ";
    if (type == 'H') { // Pour un humain
        cin >> temp;
        if (temp == '?') {
            comparaison(motEnCours, nbTour, tourJoueur, nbJoueur, singe, joueurs, perdant);
        }
        else {
            temp = toupper(temp);
            motEnCours[*nbTour] = temp;
            if (*nbTour > 1) {
                motExiste(motEnCours, singe, tourJoueur, nbJoueur, nbTour, perdant, joueurs);
            }
        }
        if (temp == '!') {
            std::cout << "le joueur " << tourJoueur << "H abandonne la manche et prend un quart de singe" << std::endl;
            singe[tourJoueur] += 0.25;
            *perdant = tourJoueur;
            resultat(singe, nbJoueur, joueurs);
            for (int i = 0; i < 26; i++) {
                motEnCours[i] = '\0';
            }
            *nbTour = -1;
        }
    }
    if (type == 'R') { // Pour un robot
        ifstream in("ods4.txt"); // on ouvre le fichier
        if (!in) {
            cout << "le dictionnaire n'a pu etre ouvert" << endl;
        }
        int nb = 0, longueur = 0;
        const int MAX = 26;
        char s[MAX];
        int erreur = 0;
        int exit = 0;
        in >> setw(MAX) >> s; // on essaye de lire le premier mot
        while (in && exit == 0) {
            ++nb; // ça s'est bien passé, on le compte
            longueur += strlen(s); // et on accumule sa longueur
            for (int i = 0; i < *nbTour; i++) {
                if (s[i] != motEnCours[i]) {
                    erreur++;
                }
            }
            if (erreur == 0) {
                exit = 1;
            }
            erreur = 0;
            in >> setw(MAX) >> s; // on essaye de lire le mot suivant

        }
        in.close(); // on ferme le fichier
        char lettreR = s[*nbTour];
        motEnCours[*nbTour] = lettreR;
        if (*nbTour == 0) { // permet au robot de saisir une lettre au hasard entre A et Z s'il commence en premier
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis('A', 'Z');
            char letter = dis(gen);
            motEnCours[*nbTour] = letter;
        }
        std::cout << motEnCours[*nbTour] << std::endl;
        motExiste(motEnCours, singe, tourJoueur, nbJoueur, nbTour, perdant, joueurs);
    }
}