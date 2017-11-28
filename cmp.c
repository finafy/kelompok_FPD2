#include<stdio.h>
#include<string.h>
void main(int argc, char *argv[]){
	FILE *f1,*f2;
	char byte1,byte2;
	if(argc<=2){
		printf("cmp: cannot proceed, need more arguments\n");
		return;
	}
	int cm=0,flag=0;
	int dif1,dif2;
	if(strcmp(argv[1],"-l")==0) cm=1;	
	else if(strcmp(argv[1],"-i")==0){
		int len,i;
		char temp[100];
		int j=0, k=0, a=0;
		char c1[100],c2[100];
		sprintf(temp,"%s",argv[2]);
		len=strlen(temp);
		for(i=0;i<len;i++){
			if(temp[i]!=':'){
				c1[j]=temp[i];
				j++;
			}
			else{
				flag=1;
				for(k=i+1;k<len;k++){
					c2[a]=temp[k];
					a++;
				}
				break;
			}
		}
		dif1 = (int) c1;
		if(flag==1) dif2 = (int) c2;
		cm=2;
	}
	int line=1,line1=1,line2=1, byte_count=1;
	f1=fopen(argv[cm+1],"r");
	f2=fopen(argv[cm+2],"r");
	if(cm==2){
		int length;
		if(flag==0){
			fseek(f1,0,SEEK_END);
			length=ftell(f1);
			fseek(f1,(length-dif1),SEEK_SET);
			fseek(f2,0,SEEK_END);
			length=ftell(f2);
			fseek(f2,(length-dif1),SEEK_SET);
		}
		else{
			fseek(f1,0,SEEK_END);
			length=ftell(f1);
			fseek(f1,(length-dif1),SEEK_SET);
			fseek(f2,0,SEEK_END);
			length=ftell(f2);
			fseek(f2,(length-dif2),SEEK_SET);
		}
	}
	if(cm==1){
		while((byte1=fgetc(f1))!=EOF&&(byte2=fgetc(f2))!=EOF){
			if(byte1=='\n'||byte2=='\n') line++;
			if(byte1==byte2){
				byte_count++;
				continue;
			}
			else{
				printf("%2d %3o %3o\n",byte_count,byte1,byte2);
				byte_count++;
				continue;
			}
		}
		
	}
	else{
		while((byte1=fgetc(f1))!=EOF&&(byte2=fgetc(f2))!=EOF){
			if(byte1=='\n') line1++;
			if(byte2=='\n') line2++;
			if(byte1==byte2){
				byte_count++;
				continue;
			}
			else break;
		}
		if(line1>line2) line1=line2;
		printf("%s %s differ: byte %d, line %d\n",argv[cm+1],argv[cm+2],byte_count,line1);
	}
	fclose(f1);
	fclose(f2);
}
