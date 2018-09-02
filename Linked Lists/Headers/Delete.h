#ifndef DELETE_H_INCLUDED
#define DELETE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Headers/Linked_List.h"

/* Delete the "u" factory occurrences then display the linked list */

void Delete_Occurence(List *list, int u);

/* Node Delete Function */

void Delete_Node(List *list, Node *pt_prec, Node *pt_cour);

/* Linked list File Saving Function */

void File_Save(List *list, char *file);

#endif
