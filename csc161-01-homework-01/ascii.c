#include <stdio.h>
#define NUM_STEPS 5

int a = NUM_STEPS;

void reverse_triangle(void){
  for (int i=0; i < 6 ; i++) {
    for (int j=6; j > i; j-- ){
        printf("*");
      }
           printf("\n");
         }
          }

void pyramid (void) {
   for (int i=0; i<6; i++) {
    for (int j=1; j< 12; j++) {
      if (j>= (6-i) && j<= (6+ i))
       {
        printf("#");
      }
      else  printf (".");
       }
    printf("\n");
   }

}

void head (void){
  for (int i = 0; i <5; i++){
    for (int j = 0 ; j < 7 + (a * 2) - i;j++){
      printf (" ");
    }
    if (i == 0) {
      printf("/");
    }
    else printf("//");
    for (int k =0; k < i -1; k++){
      printf("\\/");
    }
    if (i==0){
      printf("\\");
    }
    else printf("\\\\");
    printf ("\n"); 
  }
}

void controlroom (void){
  for (int i = 0; i <3; i++){    
    if (i==1){
      printf(" ");
      for (int k=0; k < a+1; k++){
        printf("o ");}
      printf("| % %    % |");
      for (int p=0; p < a+1; p++){
        printf(" o");}
    }
    if (i==0 || i == 2){
      for (int j=0; j < ( a * 2)+3 ; j++){
        printf("-");}
        printf("| % %    % |");
        for (int q=0; q < ( a * 2)+3 ; q++){
          printf("-");
        } }
    printf("\n");
  }
 }
    
void steps(void){
  for (int i=0;i<3*a  ;i++){
    if (i % 3 == 0) {
    printf("~");
    for (int j=1+a;j> i/3;j--){
      printf("^~");}
    printf("/");
    for (int k=0;k<8 + 4* i/3 ;k++){
      printf("-");
    }
    printf("\\");
      printf("~");
      for (int p=1+a;p>i/3;p--){
        printf("^~");
      }
    }
    else if (i % 3 == 1 ) {
      for (int j=a+1;j>(i-1)/3;j--){
      printf("^~");}
    printf("/");
    for (int k=0;k<10+4*(i-1)/3;k++){
      printf("-");
    }
    printf("\\");
    for (int p=a+1;p>(i-1)/3;p--){
        printf("~^");
      }
    }
    //i%3==2
    else {
      for (int j=2* (a+1);j>(i-2)/1.5;j--){
      printf(" ");}
    printf ("|");
    for (int k=0;k<10+4*(i-2)/3;k++){
      printf("=");
    }
      printf("|");
    }
 printf("\n");
  } 
}

void base1(void){
  for (int i=0; i<3;i++){
    for (int j=3;j>i;j--) {
      printf(" ");
    }
    printf("/");
    if (i==0){
      for (int k=0;k<8+4*a;k++){
        printf(" ");
      }
    }
    if (i==1){
      printf("  ");
      for (int j=0;j<6+4*a;j++){
        printf("=");
      }
      printf("  ");
    }
    if (i==2){
      printf("  / ");
      for (int j=0; j<4+4*a;j++){
      printf("\"");
      }
      printf(" \\  ");
    }
    printf("\\\n"); 
  }
}

void base2(void){
  printf("|  | ");
  for (int i=0; i<6+4*a; i++){
    printf("\"");
  }
  printf(" |  |\n");
}

void base3(void){
    for (int i=0; i<3;i++){
      for (int j=0;j<=i;j++) {
        printf(" ");
      }
      printf("\\");
    if (i==0){
      printf("  \\ ");
      for (int j=0; j<4+4*a;j++){
        printf("\"");
      }
      printf(" /  ");
    }
   else if (i==1){
      printf("  ");
      for (int j=0;j<6+4*a;j++){
        printf("=");
      }
      printf("  ");
   }
    //i ==2
    else  {
        for (int k=0;k<8+4*a;k++){
          printf("_");
        }
    }
   printf("/\n"); 
    }
}

void base (void){
  base1();
  base2();
  base3();
}

void rocky_steps(void){
  head();
  controlroom();
  steps();
  base();
}

int main (void){
  reverse_triangle ();
  pyramid();
  rocky_steps();
  return 0;
}
 
