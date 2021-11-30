#include <stdio.h>
#define TEACHER 3
#define EXISTS 4

_Bool exists(int monk, int arr[601][5]){
  
}

int main(void){
  int arr[601][5];
  for(int i=1;i<600;++i)
    for(int j=0;j<4;++j)
      arr[i][j]=-1;
  for(int i=0;i<600;arr[i++][EXISTS]=0);
  
  FILE *fp=fopen("monah.txt", "r");
  char buff[100];
  int a, b, c, d;
  int offs;
  while(!feof(fp)){
    offs=ftell(fp);
    fgets(buff, 100, fp);
    int spaces=0;
    for(int i=0;buff[i]!=0;++i)
      if(buff[i]==' ') spaces++;
    if(spaces!=3) break;
    fseek(fp, offs, SEEK_SET);
    fscanf(fp, "%d %d %d %d\n", &a, &b, &c, &d);
    /* printf("%d %d %d %d %d\n", a, b, c, d); */
    arr[a][0]=b;
    arr[b][TEACHER]=a;
    arr[b][EXISTS]=1;
    
    arr[a][1]=c;
    arr[c][TEACHER]=a;
    arr[c][EXISTS]=1;
    
    arr[a][2]=d;
    arr[d][TEACHER]=a;
    arr[d][EXISTS]=1;
    
    arr[a][EXISTS]=1;
  }
  fseek(fp, offs, SEEK_SET);
  for(int i=0;i<601;++i)
    if(arr[i][EXISTS]==1){
      printf("%d ", i);
      for(int j=0;j<5;++j)
	printf("%d ", arr[i][j]);
      putchar(10);
    }
  return 0;
  
  while(!feof(fp)){
    offs=ftell(fp);
    fgets(buff, 100, fp);
    fseek(fp, offs, SEEK_SET);
    int spaces=0;
    for(int i=0;buff[i]!=0;++i)
      if(buff[i]==' ') spaces++;

    if(spaces==1){
      /* Решить 1 задачу*/
      fscanf(fp, "1 %d\n", &a);
      /* printf("%d\n", a); */
      if(!arr[a][EXISTS]) printf("Монаха №%d не существует\n", a);
      else{
	/* по номеру монаха узнать, был ли такой монах и если был, то кто были его учитель, учитель его учителя и т.д. до самого Святого Павла;*/
	printf("№%d - монах, его учителя -", a);
	int tmp=a;
	while(arr[tmp][TEACHER]!=1){
	  printf(" %d", arr[tmp][TEACHER]);
	  tmp=arr[tmp][TEACHER];
	}
	putchar(10);
      }
    }else if(spaces==2){
      /* Решить 2 задачу*/
      fscanf(fp, "2 %d %d\n", &a, &b);
      /* printf("%d %d\n", a, b); */
      
      if(!arr[a][EXISTS] || !arr[b][EXISTS])
	printf("Монаха №%d не существует\n", !arr[a][EXISTS] ? a : b);
      else{
	/* по двум монашеским номерам найти их общего ближайшего учителя. */
	int t1=arr[a][TEACHER];
	int t2=arr[b][TEACHER];
	while(t1!=t2)
	  if(t2>t1)
	    t2=arr[t2][TEACHER];
	  else
	    t1=arr[t1][TEACHER];
	printf("%d и %d – оба монахи, и их общий учитель %d\n", a, b, t1);
      }
    }
  }
  
  fclose(fp);
  return 0;
}
