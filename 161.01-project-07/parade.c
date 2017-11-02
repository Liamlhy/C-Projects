#include <stdio.h>
#include <stdlib.h>
#include <MyroC.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define INITIAL_SIZE 16
#define GROWTH_FACTOR 2

//Piano Frequencies
#define A5 880.00
#define B5 987.767
#define D5 587.330
#define E5 659.255
#define F5 698.456
#define G5sharp 830.609
#define B6 1975.53
#define C6sharp 1108.73
#define D6 1174.66
#define E6 1318.51
#define beats_per_min (127)
#define seconds_per_beat (60.0/beats_per_min)
double dur4() {return seconds_per_beat;}
double dotsix() {return seconds_per_beat * 0.875;}
double eight() {return seconds_per_beat / 2.0;}
double halfdot() {return seconds_per_beat * 3.0;}

char* ensure_capacity(char *buf, int *sz, int pos) {
  if (*sz == pos) {
    // N.B. realloc grows or shrinks its input buffer to the given size,
    // returning an updated pointer to the new buffer.  The elements of the
    // old buffer are copied automatically to the new buffer.
    char *newbuf = (char*) realloc(buf, *sz * GROWTH_FACTOR);
    if (newbuf == NULL) {
      free(buf);
      *sz = 0;
      return NULL;
    } else {
      *sz *= GROWTH_FACTOR;
      return newbuf;
    }
  } else {
    return buf;
  }
}

// Returns a heap-allocated line of input from the user or NULL if the
// allocation fails.  The caller of this function owns the resulting string.
char* fetchline(FILE *f) {
  int pos = 0;
  int sz  = INITIAL_SIZE;
  char *buf = (char*) malloc(sizeof(char) * sz);
  if (buf == NULL) { return NULL; }
  char ch = fgetc(f);
  if (ch == EOF) {
    free(buf);
    return NULL;
  }
  while (ch != '\n') {
    buf = ensure_capacity(buf, &sz, pos);
    if (buf == NULL) { return NULL; }
    buf[pos++] = ch;
    ch = fgetc(f);
  }
  buf = ensure_capacity(buf, &sz, pos);
  if (buf == NULL) { return NULL; }
  buf[pos++] = '\0';
  return buf;
}


//While going through the file line by line, will match up the command in a given line and excute a command
void robotCommand(char *line){
  char *order = strtok(line, " ");
  if (strcmp(order, "forward") == 0){
    //will move forward
    rForward(1.0, atoi (strtok(NULL, " ")));
  }
  else if (strcmp(order, "turn") == 0) {
    int degrees = atoi(strtok(NULL, " "));
    //will turn at a given degree
    if (degrees==45){
      rTurnSpeed(strtok(NULL, " "),0.5, 0.78);
    }
    else if (degrees==90){
      rTurnSpeed(strtok(NULL, " "),0.5, 1.57);
    }
    else if (degrees==360){
      rTurnSpeed(strtok(NULL, " "),0.5, 6.28);
    }
  }          
  else if (strcmp(order, "spin") == 0){
    //will spin in a certain direction;
    if (strcmp(line, "right") == 0){
      rTurnRight(1.0, 2.0);
    }
    if (strcmp(line, "left") == 0){
      rTurnLeft(1.0, 2.0);
    }
  }
  else if (strcmp(order, "beep") == 0){
    //will beep
    rBeep (1.0, 698);
  }
  else if (strcmp(order, "ditty") == 0){
    //will play the beginning of Happy Together
  rBeep (0.50, E6);
  rBeep (0.25, B6);
  rBeep (0.25, G5sharp);
    
  }
  else if (strcmp(order, "song") == 0){
    //will play middle of Happy Together
   rBeep (0.5, E5);
  rBeep (0.5, D5);
  rBeep (0.5, F5);
  rBeep (0.5, A5);
  rBeep (0.5, C6sharp);
  rBeep (0.5, D6);
  }
}
    
int main (int argc, char* argv[]){ 
  rConnect("/dev/rfcomm0");
  printf("Press enter");
  getchar();
  rForward(0.25, 0);
  printf("Press enter again");
  getchar();
  rStop();
  //maybe need to figure out log
  FILE *commands;
  //checks that the file exists
  if(argc != 4 && argc != 2) {
    printf("Invalid argument length\n");
    return 0;
  }
  else if(argc == 2) {
    commands = fopen (argv[1], "r");
    if(commands != NULL) {
      printf("File exists\n");
       char *line;
       line = fetchline(commands);
      robotCommand (line);
    }
    else {
      printf("File does not exist!\n");
    }
  }
  else if (argc==4){

    //if have correct log 
    if (strcmp(argv[1],"-log")==0){
    commands = fopen (argv[3], "r");
    FILE *loggingFile;
    loggingFile = fopen(argv[2], "w");
     char *line;
     line = fetchline(commands);
    while(line!=NULL){
    robotCommand (line);
    time_t current_time = time(NULL);
    fprintf(loggingFile, "Time: %s", ctime(&current_time));
    fprintf(loggingFile, "Command: %s",line);
    fprintf(loggingFile, "Left: %d",rGetLightTxt("left", 5));
    fprintf(loggingFile, "Right: %d",rGetLightTxt("right", 5));
    fprintf(loggingFile, "Average: %d\n",(rGetLightTxt("left", 5)+rGetLightTxt("right", 5)+rGetLightTxt("middle", 5))/3);  
    line = fetchline(commands);
    
    }
    fclose(loggingFile);
    }
    else {
      printf("Logging Fails!");
    }
  }
      
    // if have the txt file 
  
  /*  while (logging == true){
    FILE *loggingFile;
    time_t current_time = time(NULL);
    fprintf(loggingFile, "The current time is: %s", ctime(&current_time));
    }*/

  

  //graceful exit
  printf("exit\n");
  rForward (1.0, 2.0);
  rDisconnect();
  fclose(commands);
  
    }
  
