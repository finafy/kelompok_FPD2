#include<stdio.h>
#include<string.h>
#include<dirent.h>
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
			in=fopen(argv[i],"r");
			char new[2000];
			sprintf(new,"%s/%s",argv[argc-1],argv[i]);
			out=fopen(new,"w+");
			char c;
			while((c=fgetc(in))!=EOF) fputc(c,out);
			fclose(in);
			fclose(out);
			remove(argv[i]);
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
}
