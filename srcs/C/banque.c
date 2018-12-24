#include "../H/struct.h"

int main(void)
{
  int i = passWord();
  int admin = 1;
  int choix;
  char buffer[255];
  if (i==0)
    return 0;
  money_t money;
  FILE* fichier=NULL;
  fichier = fopen("srcs/txt/money.txt", "r+");
  if (fichier == NULL)
    return 0;
  i = 0;
  while (i<5)
  {
    fgets(buffer, 254, fichier);
    money.tab[i++] = atoi(buffer);
  }
  fgets(buffer, 254, fichier);
  money.total = atoi(buffer);
  printf("Nombre de billet\n");
  printf("5 eu : %d\n", money.tab[0]);
  printf("10 eu : %d\n", money.tab[1]);
  printf("20 eu : %d\n", money.tab[2]);
  printf("50 eu : %d\n", money.tab[3]);
  printf("100 eu : %d\n--------------------------------\n", money.tab[4]);
  while (admin)
  {
    affiche(&choix);
    switch (choix)
    {
      case 1:
        retire(); break;
      case 2:
        depose(); break;
      case 3:
        newAccout(); break;
      case 4:
        adminstration(); break;
      default:
        printf("\n**ERROR - le numero choisi ne corespond a auqu'un choix\n"); sleep(1);
    }
  }
  return 0;
}

void retire()
{
  users_t user;
  FILE* fichier=NULL;
  int etat=1;
  char buffer[255];
  int i=0;
  char buf[255];
  fichier = fopen("srcs/txt/users.txt", "r+");
  if (fichier == NULL)
  {
    printf("** ERROR USERS");
    return 0;
  }
  printf("Identifiant > ");
  gets(buffer);
  while (fgets(buf, 254, fichier) && etat)
  {
    while (buffer[i]==buf[i] && buffer[i] && buf[i++]);
    if (buffer[i]=='\0' && buf[i]=='\0')
    {
      user.name = malloc(sizeof(char)*i);
      user.name = buffer;
      fgets(buf, 254, fichier);
      i=0;
      while (buf[i])
        user.pass[i] = buf[i++];
      fgets(buf, 254, fichier);
      user.codeCB = atoi(buf);
      fgets(buf, 254, fichier);
      user.solde = atoi(buf);
      etat = 0;
    }
    printf("%f\n",user.solde);
  }
}

void depose()
{
}

void newAccout()
{
}

void adminstration()
{
}

void affiche(int *choix)
{
  char buffer[255];
  printf("\n1-retirer de l'argent\n2-deposer de l'argent\n3-creer un compte\n4-partie administrateur\n\n>: ");
  gets(buffer);
  *choix = atoi(buffer);
}
