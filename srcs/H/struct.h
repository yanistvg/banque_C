#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void affiche(int *choix);
void retire();
void depose();
void newAccout();
void adminstration();

typedef struct Users
{
  char *name;
  char pass[255];
  int codeCB;
  float solde;
} users_t;

typedef struct Argent
{
  int tab[5];
  float total;
} money_t;

int passWord()
{
  int i=3, etat=1, e;
  char buffer[255];
  users_t admin;
  FILE* fichier = NULL;
  fichier = fopen("srcs/txt/pass.txt", "r+");
  if (fichier == NULL)
    return 0;
  fgets(admin.pass, 254, fichier);
  while (i>0 && etat)
  {
    e = 0;
    printf("PASSWORD > ");
    gets(buffer);
    while (buffer[e] == admin.pass[e] && admin.pass[e++]!='\n');
    
    if (buffer[e] == '\0' && admin.pass[e] == '\n')
      return 1;
    i--;
  }
  return 0;
}
