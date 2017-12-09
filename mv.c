#include "types.h"
#include "stat.h"
#include "user.h"

int main (int argc, char *argv[]){
  if (argc != 3){
    printf(2, "Usage: mv oldname newname\n");
    exit();
  }

  if ((link(argv[1], argv[2]) < 0) || (unlink(argv[1]) < 0))
    printf(2, "mv %s to %s failed\n", argv[1], argv[2]);
else if(argc>=4){
for(int i=1;i<argc;i++){
if ((link(argv[i], argv[argc-1]) < 0) || (unlink(argv[i]) < 0))
    printf(2, "mv %s to %s failed\n", argv[i], argv[argc-1]);
}
}
  exit();
}
