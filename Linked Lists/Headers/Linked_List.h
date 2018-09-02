#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Declaration of a linked list node type */
typedef struct Node Node;
struct Node
{
    int indice_colonne; /* Indice de la column */
    int indice_ligne;   /* Indice de la ligne */
    int Cout;           /* Value */
    Node *next;         /* Pointeur on next node */
};

/* Declaration of a linked list type */
typedef struct List List;
struct List
{
    Node *first; /* Pointeurs sur le premier élément de la list */
};

/* Fonction qui Initialise une list chaînée */

List *Initialisation();

/* Fonction qui Insère dans une liste chaînée */

void Bloc_Insertion(List *list, double **mat, int i, int j, Node *prec, Node *cour);
void Sorted_Insertion(List *list, double **mat, int i, int j);
void Matrix_Insertion(List *list, double **mat, int m, int n, int K);

/* Fonction qui supprime un le premier élément de la liste chaînée */

void Delete_First_Node(List *list);

/* Fonction qui Affiche une liste chaînée */

void Display_List(List *list);

/* Fonction qui libère la liste chaînée */

void Free_List(List *list);

#endif
