#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Declaration of a linked list node type */
typedef struct Node Node;
struct Node
{
    int indice_colonne; /* Column index */
    int indice_ligne;   /* Line index */
    int Cout;           /* Cost */
    Node *next;         /* Pointer on next node */
};

/* Declaration of a linked list type */
typedef struct List List;
struct List
{
    Node *first; /* Pointer on the first node of the list */
};

/* Initilisation Function */

List *Initialisation();

/* Linked List Insertion Function */

void Bloc_Insertion(List *list, double **matrix, int i, int j, Node *prec, Node *cour);
void Sorted_Insertion(List *list, double **matrix, int i, int j);
void Matrix_Insertion(List *list, double **matrix, int m, int n, int K);

/* First Linked List Node Delete Function */

void Delete_First_Node(List *list);

/* Display Linked List Function */

void Display_List(List *list);

/* Free Linked List Function */

void Free_List(List *list);

#endif
