#include <iostream>
#include <string>
#include <locale>
using namespace std;
void remove_newline(char *buff){
  int i;
  for(i=0;buff[i]!=0 && buff[i]!='\n';++i);
  buff[i]=0;
}

#define getinp(str, sep)				\
  printf(str);						\
  fgets(buff, 200, stdin);				\
  remove_newline(buff);					\
  fputs(buff, fp); fputc(sep, fp)


int main(void){
  char* locale=setlocale(LC_ALL, "RUS");
  FILE* fp=fopen("FILE2.txt", "w");
  char buff[200];
  for(;;){
    getinp("Введите ФИО автора\n", '|');
    getinp("Введите название книги\n", '|');
    getinp("Введите год издания\n", '\n');

    printf("Ещё? (Enter или \"нет\")\n");
    fgets(buff, 200, stdin);
    if(buff[0]!='\n') break;
  }
  printf("-------------\n");

  
  fclose(fp);
  fp=fopen("FILE2.txt", "r");
  for(;;){
    int choice;
    printf("Что Вы хотите сделать?\n1. найти название книги, автор и год издания которой вводятся вручную\n2. определить имеется ли книга, в названии которой есть слово «Паскаль». Если «да», то сообщить автора и год издания.\n");
    scanf("%d", &choice);

    char author[200], year[200];
    
    if(choice==1){
      printf("Введите ФИО автора\n");
      fgets(author, 200, stdin);
      remove_newline(author);
      printf("Введите год издания\n");
      fgets(year, 10, stdin);
      remove_newline(year);
      for(;;){
	if
      }
    }else if(choice==2){
      for(;;){
	
      }
    }else
      printf("Такой вариант выбрать нельзя\n");
  }
  
  return 0;
}
