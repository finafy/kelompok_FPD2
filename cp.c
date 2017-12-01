#include<dirent.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
void cp(char *src, char *dst){
		FILE *in,*out;
		in=fopen(src,"r");
		char copy[1000];
		sprintf(copy,"%s/%s",dst,src);
		out=fopen(copy,"w+");
		char str;
		while((str=fgetc(in))!=EOF) fputc(str,out);
		fclose(in);
		fclose(out);
}
void cpnew(char *src, char *dst){
		FILE *in,*out;
		in=fopen(src,"r");
		char copy[1000];
		sprintf(copy,"%s",dst);
		out=fopen(copy,"w+");
		char str;
		while((str=fgetc(in))!=EOF) fputc(str,out);
		fclose(in);
		fclose(out);
}
void cpdir(char *src, char *dst){
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
				if(ent->d_type==DT_DIR){
					char next[1000];
					sprintf(next,"%s/%s",src,ent->d_name);
					cpdir(next,dst);
					continue;
				}
				else{
					cp(ent->d_name,dnew);
					continue;
				}
			}
		}
		closedir(dir);
	}
}
void main(int argc, char *argv[]){
	if(argc<=2){
		printf("cp: cannot proceed, need more arguments\n");
		return;
	}
	else if(strcmp(argv[1],"-R")==0) cpdir(argv[2],argv[3]);
	else{
		DIR *path;
		if((path=opendir(argv[argc-1]))!=NULL){
			closedir(path);
			int i;
			for(i=1;i<argc-1;i++){
				DIR *dir;
				char *dr=".";
				struct dirent *ent;
				if((dir=opendir(dr))!=NULL){				
					while((ent=readdir(dir))!=NULL){
						if(strcmp(ent->d_name,argv[i])==0){
							if(ent->d_type!=DT_DIR){
								cp(argv[i],argv[argc-1]);
								break;
							}
							else{
								printf("cp: omitting directory '%s'\n",argv[i]);
								break;
							}
						}
						else continue;
					}
					closedir(dir);
				}
			}
		}
		else cpnew(argv[1],argv[2]);
	}
}
