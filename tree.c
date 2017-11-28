#include<dirent.h>
#include<stdio.h>
#include<string.h>
int dr=0,fl=0;
void ls(char *argv, int s){
	int i;
	DIR *dir;
	struct dirent *ent;
	if((dir=opendir(argv))!=NULL){
		while((ent=readdir(dir))!=NULL){
			if(strcmp(ent->d_name,".")==0) continue;
			else if(strcmp(ent->d_name,"..")==0) continue;
			else{
				for(i=0;i<s;i++) printf("    ");
				printf("--");
				printf("> %s\n", ent->d_name);
				fl++;
				if(ent->d_type==DT_DIR){
					dr++;
					char next[1000];
					strcpy(next,argv);
					strcat(next,"/");
					strcat(next,ent->d_name);
					ls(next,s+1);
				}
			}
		}
		closedir(dir);
	}
}
void main(int argc, char *argv[]){
	if(argc==1) argv[1]=".";
	if((opendir(argv[1]))!=NULL){
		printf("%s\n",argv[1]);
		ls(argv[1],0);
	}
	else printf("%s [error opening dir]\n",argv[1]);
	printf("\n%d directories, %d files\n", dr,fl-dr);
}
