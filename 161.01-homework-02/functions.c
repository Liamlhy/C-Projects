#include <stdio.h>

void slash (int n) {
  for (int i=0; i<n; i++){
    for (int j=0; j<i;j++){
      printf (" ");
    }
    printf ("\\*\\\n");
  }
}

void num_square(int n, int m){
  for (int i=0; i< m - n + 1; i++){
    for (int j=n+i; j<m+1; j++){     
      printf("%d",j);
    }
    for (int k=n; k<i+n;k++) {
      printf("%d",k);
    }
    printf("\n");
  }
}

int calculate_whole (int n, int m){
  int a = n / m;
  return a;
}

int calculate_remainder(int n, int m){
  int b = n % m;
  return b;
}
  
void make_change (int c){
 int d = calculate_whole(c,100);
 printf("dollars = %d\n", d);
 int q =calculate_remainder (c,100);
 printf("quaters = %d\n", calculate_whole(q,25));
 int m =calculate_remainder (q,25);
 printf("dimes = %d\n",calculate_whole(m,10));
 int n =calculate_remainder(m,10);
 printf("nickels = %d\n",calculate_whole(n,5));
 int e =calculate_remainder(n,5); 
 printf("cents = %d\n", e);
}


int main (void) {
    slash(3);
    slash(7);
    num_square(4, 9);
    num_square(3,7);
    make_change(157);
    make_change(141);
    return 0;
}
