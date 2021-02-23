#include <stdio.h>
#include <string.h>
#define TRUE  1
#define FALSE 0
void dessine_plateau (int plateau[][3]) {
   int i=0,j=0;
   printf ("\n-------\n");
   for (i=0;i<3;i++) {
      for (j=0;j<3;j++) {
         printf("|");
         switch(plateau[i][j]) {
            case 0:
               printf(" ");
               break;
            case 1:
               printf("O");
               break;
            case 2:
               printf("X");
               break;
         }
      }
      printf ("|\n");
      printf ("-------\n");
   }
}
int fin_jeu (int plateau[][3]) {
   int i=0,j=0;
   for (i=0;i<3;i++) {
      for (j=0;j<3;j++) {
         if (plateau [i][j]==0) {
            return FALSE;
         }
      }
   }
   return TRUE;
}
int saisie_donnee (char *invite) {
   int valeur;
   do {
      printf ("%s", invite);
      scanf ("%d",&valeur);
   } while (( valeur <1) || (valeur >3));
   return (valeur);
}
int gagne (int plateau[][3]) {
   int i=0;
   // Test sur les lignes
   for ( i=0; i<3; i++) {
      if (( plateau[i][0] >0) && ( plateau[i][0] == plateau[i][1] ) && ( plateau[i][1] == plateau[i][2] )) {
         puts ("GAGNE");
         return TRUE;
      }
   }
   // Test sur les colonnes
   for ( i=0; i<3; i++) {
      if (( plateau[0][i] >0) && ( plateau[0][i] == plateau[1][i] ) && ( plateau[1][i] == plateau[2][i] )) {
         puts ("GAGNE");
         return TRUE;
      }
   }
   // Test sur les diagonales
   if (( plateau[0][0] >0) && ( plateau[0][0] == plateau[1][1] ) && ( plateau[1][1] == plateau[2][2] )) {
      puts ("GAGNE");
      return TRUE;
   }
   // Test sur les diagonales
   if (( plateau[0][2] >0) && ( plateau[0][2] == plateau[1][1] ) && ( plateau[1][1] == plateau[2][0] )) {
      puts ("GAGNE");
      return TRUE;
   }
   return FALSE;
}
void jeu (int plateau[][3], int joueur) {
   int pos_x=0,pos_y=0;
   int correct=FALSE;
   do {
      printf ("Joueur %d\n",joueur);
      pos_x= saisie_donnee ("Ligne : ");
      pos_y= saisie_donnee ("Colonne : ");
      if ( plateau[pos_x-1][pos_y-1]>0 ) {
         printf ("Case occupee !\n");
      } else {
         plateau[pos_x-1][pos_y-1]=joueur;
         correct=TRUE;
      }
   }
   while (! correct);
   dessine_plateau (plateau);
}
int main () {
   int plateau [3][3];
   int joueur=1;
   // la fonction memset permet d'initialiser chacun
   // des octets d'une zone donnée avec une valeur
   // déterminée (ici: 0)
   memset (plateau, 0, 9*sizeof (int));
   dessine_plateau (plateau);
   do {
      jeu (plateau, joueur);
      if ( joueur==1 ) {
         joueur=2;
      } else {
         joueur=1;
      }
   }
   while (( !gagne (plateau)) && (!fin_jeu (plateau)) );
   return 0;
}