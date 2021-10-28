#include <stdio.h>

int main(void){
  FILE * fp=fopen("file.txt", "w+");
  int a;
  for(int i=0;i<9;i++){
    scanf("%d", &a);
    fprintf(fp, "%d ", a);
  }
  scanf("%d", &a);
  fprintf(fp, "%d", a);

  fclose(fp);


  
  FILE * fp2=fopen("file.txt", "r");
  char ch=fgetc(fp2);
  int num=0;
  int sum=0;
  printf("Содержимое файла:\n");
  while(ch!=EOF){
    if(ch!=' ')
      num=num*10+(ch-48);
    else{
      sum+=num;
      num=0;
    }
    
    putchar(ch);
    ch=fgetc(fp2);
  }

  
  printf("\nСумма чисел: %d\n", sum+num);
  fclose(fp2);
  return 0;
}
