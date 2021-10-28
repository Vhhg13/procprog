#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int to_seconds(int hours, int minutes, int seconds){
  return hours*3600+minutes*60+seconds;
}

int main(void){
  bool lamp_on, curtain_open, bright_outside;
  int hours, minutes, seconds;
  const char lamp[10];
  const char curtain[10];

  printf("Включена ли лампа? [да/нет] ");
  scanf("%s", lamp);
  if(strcmp(lamp, "д")==0 || strcmp("да", lamp)==0)
    lamp_on=true;
  else
    lamp_on=false;

  printf("Сколько времени? [чч:мм:сс] ");
  scanf("%d:%d:%d", &hours, &minutes, &seconds);

  int time=to_seconds(hours, minutes, seconds);
  
  if(time<to_seconds(5, 37, 35) ||	// 05:37:35 - Восход
     time>to_seconds(19, 23, 57))	// 19:23:57 - Заход
    bright_outside=false;
  else
    bright_outside=true;

  printf("Открыты ли шторы? [да/нет] ");
  scanf("%s", curtain);
  if(strcmp("д", curtain)==0 || strcmp(curtain, "да")==0)
    curtain_open=true;
  else
    curtain_open=false;

  if((bright_outside && curtain_open) || lamp_on)
    printf("Светло\n");
  else
    printf("Темно\n");

  return 0;
}
