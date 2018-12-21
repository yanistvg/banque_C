#include "../H/struct.h"

int main(void)
{
  int i = passWord();
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
  
  return 0;
}
