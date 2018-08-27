#include "./Headers/Matrix.h"
#include "./Headers/List_CH.h"
#include "./Headers/Suppr.h"

int main(int argc, char *argv[])
{

    if (argc > 2)
    {
        int m = 0, n = 0;
        double **matrix = NULL;
        int K = atoi(argv[2]);

        Scanner myscanner;

        /* Initializing the linked cost list */
        Liste *mylist = Initialisation();
        /* La lecture de la matrice des coûts à partir d'un fichier */
        myscanner = Lecture_Initialisation_Remplissage_Matrice(argv[1], mat, m, n, myscanner);

        mat = myscanner.mat;
        m = myscanner.m;
        n = myscanner.n;

        /* Display an empty linked list */
        printf("\n Display an empty linked list \n");
        Display_List(mylist);

        /* Remplissage de la liste chaînée depuis la matrice puis affichage de la liste chaînée */
        Insert_Matrix(mylist, mat, m, n, K);
        printf("\n Display a linked list after an add \n");
        Display_List(mylist);

        /* Suppression de quelques occurences then display the linked list */
        Suppression_Occurencet(mylist, 0);
        printf("\n Display a linked list after deleting of the 0 Affichage de la liste chaînée après une suppression d'occurences de l'usine 0 \n");
        Display_List(mylist);

        /* Sauvegarde de la liste chaînée dans un fichier */
        File_Save(mylist, "Tests/file_res.txt");
    }
    else
    {

        printf("Veuillez entrer le bon nombre d'arguments!\n");
    }
    return 0;
}