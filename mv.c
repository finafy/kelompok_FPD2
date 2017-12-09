<<<<<<< HEAD
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
=======
#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
void mv(char *src, char *dst){
		FILE *in,*out;
		in=fopen(src,"r");
		char copy[1000];
		sprintf(copy,"%s/%s",dst,src);
		out=fopen(copy,"w+");
		if(in==NULL){
			fclose(out);
			remove(src);
			return;
		}
		else{
			char str;
			while((str=fgetc(in))!=EOF) fputc(str,out);
			fclose(in);
			fclose(out);
			remove(src);
			return;
		}
}
void mvdir(char *src, char *dst){
	int i;
	DIR *dir;
	struct dirent *ent;
	if((dir=opendir(src))!=NULL){
		char dnew[1000];
		sprintf(dnew,"%s/%s",dst,src);
		mkdir(dnew,0777);
		while((ent=readdir(dir))!=NULL){
			if(strcmp(ent->d_name,".")==0) continue;
			else if(strcmp(ent->d_name,"..")==0) continue;
			else{
				char now[1000];
				sprintf(now,"%s",ent->d_name);
				if(ent->d_type==DT_DIR){
					char next[1000];
					sprintf(next,"%s/%s",src,now);
					mvdir(next,dst);
					continue;
				}
				else{
					mv(now,dnew);
					continue;
				}
			}
		}
		closedir(dir);
	}
	return;
}
void main(int argc, char *argv[]){
	FILE *in, *out;
	DIR *dir;
	if(argc<=2){
		printf("mv: cannot proceed, need more arguments\n");
		return;
	}
	if((dir=opendir(argv[argc-1]))!=NULL){
		closedir(dir);
		for(int i=1;i<argc-1;i++){
			if((strcmp(argv[i],argv[argc-1])==0)){
				printf("mv: cannot move '%s' to a subdirectory of itself, %s/%s\n", argv[i],argv[i],argv[i]);
				continue;
			}
			if((dir=opendir(argv[i]))!=NULL){
				closedir(dir);
				mvdir(argv[i],argv[argc-1]);
				remove(argv[i]);
			}
			else mv(argv[i],argv[argc-1]);
		}
	}
	else{
		in=fopen(argv[1],"r");
		out=fopen(argv[2],"w+");
		char c;
		while((c=fgetc(in))!=EOF) fputc(c,out);
		fclose(in);
		fclose(out);
		remove(argv[1]);
	}
>>>>>>> 3089b28e93b5aed9feb404b9ed4545f7f3a6b90e
}
