#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <random>
#include <fstream> 
#include <iomanip>
#include <cctype>
#include <cstring>
using namespace std;


/*
* @brief v�rifie si la partie doit �tre fini en regardant si un joueur n'a pas atteint 1 singe entier
* @param float singe[30] repr�sente les points
*/
int verification(float singe[30]);

/*
* @brief fonction qui permet d'afficher les r�sultats de chaque joueur
* @param float singe[30] repr�sente les points des joueurs
* @param int nbJoueur rep�sente le nombre de joueur
* @param int joueurs[20] repr�sente les joueurs 
*/
void resultat(float singe[30], int nbJoueur, int joueurs[20]);

/*
* @brief fonction qui permet de r�agir aux diff�rentes situations lors de la saisi de "?" en comparant le mot en cours et un mot existant dans le dictionnaire
* @param chat motEnCours[26] tableau de char qui stock le mot en cours
* @param int* nbTour pointeur sur nbTour qui compte les tours
* @param int tourJoueur d�signe le tour du joueur
* @param int nbJoueur rep�sente le nombre de joueur
* @param float singe[30] repr�sente les points des joueurs
* @param int joueurs[20] repr�sente les joueurs 
* @param int* perdant pointeur sur perdant qui d�signe le perdant
*/
void comparaison(char motEnCours[26], int* nbTour, int tourJoueur, int nbJoueur, float singe[30], int joueurs[20], int* perdant);

/*
* @brief fonction qui v�rifie si le mot en cours existe dans le dictionnaire
* @param chat motEnCours[26] tableau de char qui stock le mot en cours
* @param float singe[30] repr�sente les points des joueurs
* @param int tourJoueur d�signe le tour du joueur
* @param int nbJoueur rep�sente le nombre de joueur
* @param int* nbTour pointeur sur nbTour qui compte les tours
* @param int* perdant pointeur sur perdant qui d�signe le perdant
* @param int joueurs[20] repr�sente les joueurs
*/
void motExiste(char motEnCours[26], float singe[30], int tourJoueur, int nbJoueur, int* nbTour, int* perdant, int joueurs[20]);

/*
* @brief fonction qui permet aux joueurs de saisir une lettre
* @param chat motEnCours[26] tableau de char qui stock le mot en cours
* @param int* nbTour pointeur sur nbTour qui compte les tours
* @param int tourJoueur d�signe le tour du joueur
* @param int nbJoueur rep�sente le nombre de joueur
* @param float singe[30] repr�sente les points des joueurs
* @param int joueurs[20] repr�sente les joueurs 
* @param int* perdant pointeur sur perdant qui d�signe le perdant
*/
void saisir(char motEnCours[26], int* nbTour, int tourJoueur, int nbJoueur, float singe[30], int joueurs[20], int* perdant);
#endif 