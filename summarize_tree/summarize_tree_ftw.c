#include <stdio.h>
#include <ftw.h>

static int num_dirs, num_regular;

static int callback(const char *fpath, const struct stat *sb, int typeflag){
  if(typeflag == FTW_D){
    num_dirs++;
  }
  else{
    num_regular++;
  }
  return 0;
}

int main(int argc, char **argv){

  num_dirs = 0;
  num_regular = 0;
  ftw(argv[1], callback, 16);
  printf("Processed all the files from <%s>.\n", argv[1]);
  printf("There were %d directories.\n", num_dirs);
  printf("There were %d regular files.\n", num_regular);

  return 0;
}
