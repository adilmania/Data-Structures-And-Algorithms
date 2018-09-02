#include "./Headers/Matrix.h"
#include "./Headers/Linked_List.h"
#include "./Headers/Delete.h"

int main(int argc, char *argv[])
{

    if (argc > 2)
    {
        int m = 0, n = 0;
        double **matrix = NULL;
        int K = atoi(argv[2]);

        Scanner myscanner;

        /* Initializing the linked cost list */
        List *mylist = Initialisation();

        /* Reading the cost matrix from a file */
        myscanner = ReadInitFillMatrix(argv[1], matrix, m, n, myscanner);

        matrix = myscanner.matrix;
        m = myscanner.m;
        n = myscanner.n;

        /* Display an empty linked list */
        printf("\n Display an empty linked list \n");
        Display_List(mylist);

        /* Remplissage de la liste chaînée depuis la matrice puis affichage de la liste chaînée */
        Insert_Matrix(mylist, matrix, m, n, K);
        printf("\n Display a linked list after an add \n");
        Display_List(mylist);

        /* Delete some occurrences then display the linked list */
        Delete_Occurence(mylist, 0);
        printf("\n Display a linked list after deleting of all factory 0 all occurrences \n");
        Display_List(mylist);

        /* Saving the linked list in a file */
        File_Save(mylist, "Tests/file_res.txt");
    }
    else
    {

        printf("Please enter all arguments!\n");
    }
    return 0;
}