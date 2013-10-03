#include <stdio.h>
#include <ctype.h>

#define BUF_SIZE 1024

int is_vowel(char c) {
  if(tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u')
  	return 1;
  return 0; 
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
  int nonV = 0;
  int i;
  for(i = 0; i < num_chars; i++){
    if(is_vowel(in_buf[i]) == 0){
      out_buf[nonV] = in_buf[i];
      nonV++;
    }
  }
  return nonV;
}

void disemvowel(FILE* inputFile, FILE* outputFile) {
  int outSize, inSize;
  char in_buf[BUF_SIZE];
  char out_buf[BUF_SIZE];

  inSize = fread(in_buf, sizeof(char), BUF_SIZE, inputFile);
  outSize = copy_non_vowels(inSize, in_buf, out_buf);
  fwrite(out_buf, sizeof(char), outSize, outputFile);
  
}

int main(int argc, char *argv[]) {
  FILE *inputFile = stdin;
  FILE *outputFile = stdout;

  if(argc >= 2){ // if there is one or more arguments
    inputFile = fopen(argv[1], "r"); // open the input file
    if(inputFile == 0){
      printf("File did not open!");
      return 0;
    }
  }
  if(argc == 3){ // if there are 3 files
    outputFile = fopen(argv[2], "w"); // open the output file
    if(outputFile == 0){
      printf("File did not open!");
      return 0;
    }
  }

  disemvowel(inputFile, outputFile);
  return 0;
}
