/* 2)Создать файл, содержащий сведения в библиотеке о книгах: ФИО автора, название, год издания. Данные вводить с клавиатуры. */
/* 1. найти название книги, автор и год издания которой вводятся вручную; */
/* 2. определить имеется ли книга, в названии которой есть слово «Паскаль». Если «да», то сообщить автора и год издания. */
#include <stdio.h>
#include <wchar.h>
#define match_pas\
  for(int j=0;j<7;++j) fl&=buff[i++]==pascal[j]

char lower(char ch){
  return ch;
}

int strlen(char buff[200]){
  int i=0;
  for(i=0;buff[i]!=0;++i);
  return i;
}

_Bool includes_pascal(char buff[200]){
  int sl=strlen(buff);
  if(sl<7) return 0;
  const wchar_t pascal="Паскаль";
  int i=0;
  if(sl==7){
    _Bool fl;
    match_pas;
    return fl;
  }
  // паскаль0
  // 01234567
  for(;;){
    if(buff[i+7]==0 && buff[i]!='П') return 0;
    if(buff[i+7]==0){
      _Bool fl=1;
      match_pas;
      return fl;
    }
    if(buff[i]=='П'){
      _Bool fl;
      match_pas;
      if(fl==1) return 1;
    }
    i++;
  }
  return 0;
}

int main(void){
  FILE* fp=fopen("FILE2.txt", "w");
  char* locale=setlocale(LC_ALL, "RUS");
  char second_name[200], first_name[200], third_name[200], name[200];
  int year;
  
  for(;;){
    scanf("%s %s %s %s %d", &second_name, &first_name, &third_name, &name, &year);
    
    if(second_name[0]=='1' || second_name[0]=='2')
      break;
    
    fprintf(fp, "%s %s %s %s %d\n", &second_name, &first_name, &third_name, &name, &year);
  }
  
  fclose(fp);
  fp=fopen("FILE2.txt", "r");
  for(;;){
    if(second_name[0]=='1'){//first_name=="DOSTOEVSKY"  third_name="2021"
      
    }else if(second_name[0]=='0') break;
    }else if(second_name[0]=='2'){
    
      fscanf(fp, "%s %s %s %s %d\n", &second_name, &first_name, &third_name, &name, &year);
      if(includes_pascal(name))
	printf("%s %s %s %d", &second_name, &first_name, &third_name, &year);
      
    }
    if(feof(fp)) rewind(fp);
  }
  return 0;
}
