#include "../Headers/Linked_List.h"

/**
 * \file      Linked_List.c					
 * \author    Rousset & Mania
 * \date      12 March 2018
 * \brief     Define all necessary functions to create a linked list containing the "K" low costs
 *            and their index in a matrix, its display and release.
**/

/* ----------------------Initialisation----------------------------
* Initilisation Function
* Entrance :
 * Any.
* Exit :
 * list		: Pointer on the head of the linked list.
* ------------------------------------------------------------------ */

List *Initialisation()
{
    List *list = malloc(sizeof(*list));
    Node *node = malloc(sizeof(*node));

    if (list == NULL || node == NULL)
    {
        exit(EXIT_FAILURE);
    }

    node->indice_colonne = -1;
    node->indice_ligne = -1;
    node->Cout = -1;
    node->next = NULL;

    list->first = node;

    return list;
}

/* ----------------------Bloc_Insertion----------------------------
* Bloc insertion in the linked list Function from a previous and next pointers
* Entrance :
 * list		: Pointer on the head of the linked list.
 * prec : Pointer on the previous node.
 * cour : Pointer on the next node.
 * matrix : Pointer on the matrix.
 * i : Node to insert line index.
 * j : Node to insert column index.
* Exit :
 * Any.
* ------------------------------------------------------------------ */

void Bloc_Insertion(List *list, double **matrix, int i, int j, Node *prec, Node *cour)
{
    Node *nouveau = malloc(sizeof(*nouveau));

    if (list == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->indice_ligne = i;
    nouveau->indice_colonne = j;
    nouveau->Cout = matrix[i][j];

    if (prec == list->first && prec == cour) /* If the previous is a head pointer */
    {
        nouveau->next = list->first; /* Head Insertion */
        list->first = nouveau;
    }
    else
    {
        nouveau->next = prec->next; /* Normal Insertion */
        prec->next = nouveau;
    }
}

/* ----------------------Sorted_Insertion----------------------------
* Matrix Costs Descending Order Bloc Insertion in the linked list
* Entrance :
 * list		: Pointer on the head of the linked list.
 * matrix : Pointer on the matrix.
 * i : Node to insert line index.
 * j : Node to insert column index.
* Exit :
 * Any.
/* ------------------------------------------------------------------ */

void Sorted_Insertion(List *list, double **matrix, int i, int j)
{

    Node *pt_cour = NULL;
    Node *pt_prec = NULL;

    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }

    pt_cour = list->first;
    pt_prec = list->first;

    while (pt_cour != NULL && matrix[i][j] < (pt_cour->Cout))
    {
        pt_prec = pt_cour;
        pt_cour = pt_cour->next;
    }

    Bloc_Insertion(list, matrix, i, j, pt_prec, pt_cour);
}

/* ----------------------Matrix_Insertion----------------------------
* Insertion of the K low costs in the linked list Function
* Entrance :
 * list		: Pointer on the head of the linked list.
 * matrix : Pointer on the matrix.
 * m : Number of lines.
 * n : Number of lines.
 * K : Number of nodes to insert in the linked list.
* Exit :
 * Any.
* ------------------------------------------------------------------ */

void Matrix_Insertion(List *list, double **matrix, int m, int n, int K)
{
    int compteur = 0;
    int i, j;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            Sorted_Insertion(list, matrix, i, j);
            compteur++;
            if (compteur > K)
            {
                Delete_First_Node(list);
            }
        }
    }
}

/* ----------------------Delete_First_Node----------------------------
* First Linked List Node Delete Function
* Entrance :
 * list		: Pointer on the head of the linked list.
* Exit :
 * Any.
* ------------------------------------------------------------------ */

void Delete_First_Node(List *list)
{
    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (list->first != NULL)
    {
        Node *adSupp = list->first;
        list->first = list->first->next;
        free(adSupp);
    }
}

/* ----------------------Display_List----------------------------
* Display Linked List Function.
* Entrance :
 * list		: Pointer on the head of the linked list.
* Exit :
 * Any.
* ------------------------------------------------------------------ */

void Display_List(List *list)
{
    Node *actuel = list->first;

    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }

    while (actuel != NULL)
    {
        if (actuel->indice_ligne != -1)
        {
            printf("[ Line: %d, Column: %d, Cost: %d ] -> \n", actuel->indice_ligne, actuel->indice_colonne, actuel->Cout);
        }
        actuel = actuel->next;
    }
    printf("-> NULL \n");
}

/* ----------------------Free_List----------------------------
* Free Linked List Function
* Entrance :
 * list		: Pointer on the head of the linked list.
 
* Exit :
 * Any 
* ------------------------------------------------------------------ */

void Free_List(List *list)
{
    Node *temp = list->first;

    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }

    while ((list->first) != NULL)
    {
        temp = list->first;
        list->first = temp->next;
        free(temp);
    }
    printf("NULL \n");
}