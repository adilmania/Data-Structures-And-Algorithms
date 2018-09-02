#include "../Headers/Delete.h"

/**
 * \file      Delete.c					
 * \author    Rousset & Mania
 * \date      12 March 2018
 * \brief     Define all necessary functions for deleting
 *            factory occurences from a linked list, as well as
 *            all necessary functions for saving linked list data 
 *            in a file. 
**/

/* ----------------------Delete_Occurence----------------------------
* Deleting the "u" factory occurrences then display the linked list Function
* Entrance :
	* list		: Pointer on the head of the linked list
	* u 		: the value of the factory to look for
* Exit :
	* Any
* ------------------------------------------------------------------ */

void Delete_Occurence(List *list, int u)
{
    Node *pt_cour = NULL;
    Node *pt_prec = NULL;

    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }

    pt_cour = list->first;
    pt_prec = list->first;
    while (pt_cour != NULL)
    {
        if (pt_cour->indice_ligne == u)
        {
            Suppression_Element(list, pt_prec, pt_cour);
            pt_cour = pt_prec->next;
        }
        else
        {
            pt_prec = pt_cour;
            pt_cour = pt_prec->next;
        }
    }
}

/* ----------------------Delete_Node----------------------------
* Node Delete Function
* Entrance :
	* list		: Pointer on the head of the linked list
	* pt_prec 	: Previous Pointer 
	* pt_cour	: Current Pointeur
* Exit :
	* Any
* ------------------------------------------------------------------ */

void Delete_Node(List *list, Node *pt_prec, Node *pt_cour)
{
    if (pt_prec == pt_cour) /* if the previous pointer is the same as the head */
    {
        Node *adSupp = list->first;
        list->first = list->first->next;
        free(adSupp);
    }
    else
    {
        Node *adSupp = pt_cour;
        pt_prec->next = pt_cour->next;
        free(adSupp);
    }
}

/* ----------------------File_Save----------------------------
* Linked list File Saving Function
* Entrance :
	* list		: Pointer on the head of the linked list
	* file   	: File adress
* Exit :
	* Any
* ------------------------------------------------------------------ */

void File_Save(List *list, char *file)
{
    FILE *f = NULL;
    Node *pt_cour = list->first;

    f = fopen(file, "w+");

    if (f)
    {
        while (pt_cour)
        {
            if (pt_cour->Cout != -1)
            {
                fprintf(f, "%d \n", pt_cour->Cout);
            }
            pt_cour = pt_cour->next;
        }
        fclose(f);
    }
}