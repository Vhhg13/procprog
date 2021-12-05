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
  printf("Содержимое файла:\n");
  
  int res=0;
  int tmp;
  while(!feof(fp2)){
    fscanf(fp2, "%d ", &tmp);
    printf("%d ", tmp);
    res+=tmp;
  }

  
  printf("\nСумма чисел: %d\n", res);
  fclose(fp2);
  return 0;
}
