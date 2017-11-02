#include <stdio.h>
#include <math.h>
#include <sys/stat.h> 

unsigned char binaryStringToValue(char digits [8]) {
  
 unsigned num = 0;

 for (int i=0; i<8; i++){
    if (digits[i] != '0' && digits[i] != '1') {
      return 0;
    }
    if (digits[i] == '1'){
      num += pow(2,(7-i));
  }
  }
    return num;
}

void writeValueAsBinaryString (unsigned char val, char digits[8]){
  for (int i=0; i<8; i++) {
    int num = pow (2, 7-i);
    if (val >= num) {
      digits [i] = '1';
      val -= num;
    }
    else {
      digits [i] = '0';
    }
}
}

unsigned char hexStringToValue(char digits[2]){
  unsigned num = 0;
  for (int i=0; i <2; i++) {
    if (digits[i] >='0' && digits[i] <='9') {
      num +=   pow(16,(1-i)) * (digits[i]-'0') ;
    }
    else if (digits[i] >= 'a' && digits [i] <= 'f'){
      num += pow(16,(1-i)) * (digits[i]-'a' + 10) ;
  }
    else if (digits[i] >= 'A' && digits [i] <= 'F'){
      num += pow(16,(1-i)) * (digits[i]-'A' + 10) ;
  }
    else{
      return 0; // Fall out of the range of the digits or letters 
       }
  }
   return num;
 }


void writeValueAsHexString(unsigned char val, char digits[2]) {
  for (int i=0; i <2; i++) {
    int a = pow(16,(1-i));
    int  num = val/a;
    val = val % a;
    if ( num < 10){
      digits[i]='0'+num;
    }
    else {
      digits[i]= num -10 + 'A';
    }
  }
}


void writePermissionString(int perms, char str[9]) {

  for (int i=0; i<9; i++) {
    if (perms % 2 ==1) {

      if (i % 3 == 0 ){
        str[8-i] = 'x';
      }
      else if (i % 3 == 1 ){
        str[8-i] = 'w';
      }
      else if(i % 3 == 2 ){
        str[8-i] = 'r';
      }
    }
    else {
      str [8-i] = '-';
    }
    perms /= 2;
  }
}
        

int generatePermissionBits(char str[9]) {
  int num =0;
  for (int i = 0; i<9; i++){
    if (str[i] != '-') {
      int val = pow (2, 8 -i) ;
      num += val;
    }
  }
  return num;
}


void printArray (char arr [], unsigned int len) {
  for (int i = 0; i < len; i++) {
    printf("%c", arr [i]);
  }
  printf ("\n");
}


int main (void){
  char arr8[8];
  char arr9[9];
  char arr2[2]; 

  printf("%u\n", binaryStringToValue("00001011"));
  printf("%u\n", binaryStringToValue("01000101"));

  writeValueAsBinaryString(11,arr8);
  printArray(arr8, 8);
  writeValueAsBinaryString(69,arr8);
  printArray(arr8, 8);

  printf("%u\n",hexStringToValue("06"));
  printf("%u\n",hexStringToValue("0A"));
  printf("%u\n",hexStringToValue("a1"));

  writeValueAsHexString(1,arr2);
  printArray(arr2, 2);
  writeValueAsHexString(161,arr2);
  printArray(arr2, 2);

   
  writePermissionString(0664, arr9);
  printArray(arr9, 9);
  writePermissionString(0755, arr9);
  printArray(arr9, 9);
    
  printf("%o\n", generatePermissionBits("r-xrwxr-x"));
  printf("%o\n", generatePermissionBits("r--rwx---"));


  return 0; 
}


