#include <stdio.h>
#define TEACHER 3

_Bool exists(int monk, int arr[601][4]){
  return !(arr[monk][0]==-1 && arr[monk][1]==-1 && arr[monk][2]==-1 && arr[monk][3]==-1);
}

int main(void){
  int arr[601][4];
  for(int i=1;i<600;++i)
    for(int j=0;j<4;++j)
      arr[i][j]=-1;
  
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
    
    arr[a][0]=b;
    arr[b][TEACHER]=a;
    
    arr[a][1]=c;
    arr[c][TEACHER]=a;
    
    arr[a][2]=d;
    arr[d][TEACHER]=a;
  }
  fseek(fp, offs, SEEK_SET);
  
  while(!feof(fp)){
    offs=ftell(fp);
    fgets(buff, 100, fp);
    fseek(fp, offs, SEEK_SET);
    int spaces=0;
    for(int i=0;buff[i]!=0;++i)
      if(buff[i]==' ') spaces++;

    if(spaces==1){
      fscanf(fp, "1 %d\n", &a);
      if(!exists(a, arr)) printf("Монаха №%d не существует\n", a);
      else{
	printf("№%d - монах, его учителя -", a);
	int tmp=a;
	while(arr[tmp][TEACHER]!=1){
	  printf(" %d", arr[tmp][TEACHER]);
	  tmp=arr[tmp][TEACHER];
	}
	putchar(10);
      }
    }
    if(spaces==2){
      fscanf(fp, "2 %d %d\n", &a, &b);
      if(!exists(a, arr) || !exists(b, arr))
	printf("Монаха №%d не существует\n", !exists(a, arr) ? a : b);
      else{
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
