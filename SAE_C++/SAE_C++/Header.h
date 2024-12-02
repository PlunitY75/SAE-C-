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
* @brief vérifie si la partie doit être fini en regardant si un joueur n'a pas atteint 1 singe entier
* @param float singe[30] représente les points
*/
int verification(float singe[30]);

/*
* @brief fonction qui permet d'afficher les résultats de chaque joueur
* @param float singe[30] représente les points des joueurs
* @param int nbJoueur repésente le nombre de joueur
* @param int joueurs[20] représente les joueurs 
*/
void resultat(float singe[30], int nbJoueur, int joueurs[20]);

/*
* @brief fonction qui permet de réagir aux différentes situations lors de la saisi de "?" en comparant le mot en cours et un mot existant dans le dictionnaire
* @param chat motEnCours[26] tableau de char qui stock le mot en cours
* @param int* nbTour pointeur sur nbTour qui compte les tours
* @param int tourJoueur désigne le tour du joueur
* @param int nbJoueur repésente le nombre de joueur
* @param float singe[30] représente les points des joueurs
* @param int joueurs[20] représente les joueurs 
* @param int* perdant pointeur sur perdant qui désigne le perdant
*/
void comparaison(char motEnCours[26], int* nbTour, int tourJoueur, int nbJoueur, float singe[30], int joueurs[20], int* perdant);

/*
* @brief fonction qui vérifie si le mot en cours existe dans le dictionnaire
* @param chat motEnCours[26] tableau de char qui stock le mot en cours
* @param float singe[30] représente les points des joueurs
* @param int tourJoueur désigne le tour du joueur
* @param int nbJoueur repésente le nombre de joueur
* @param int* nbTour pointeur sur nbTour qui compte les tours
* @param int* perdant pointeur sur perdant qui désigne le perdant
* @param int joueurs[20] représente les joueurs
*/
void motExiste(char motEnCours[26], float singe[30], int tourJoueur, int nbJoueur, int* nbTour, int* perdant, int joueurs[20]);

/*
* @brief fonction qui permet aux joueurs de saisir une lettre
* @param chat motEnCours[26] tableau de char qui stock le mot en cours
* @param int* nbTour pointeur sur nbTour qui compte les tours
* @param int tourJoueur désigne le tour du joueur
* @param int nbJoueur repésente le nombre de joueur
* @param float singe[30] représente les points des joueurs
* @param int joueurs[20] représente les joueurs 
* @param int* perdant pointeur sur perdant qui désigne le perdant
*/
void saisir(char motEnCours[26], int* nbTour, int tourJoueur, int nbJoueur, float singe[30], int joueurs[20], int* perdant);
#endif 