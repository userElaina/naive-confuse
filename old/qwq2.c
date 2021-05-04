// code by 1677
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<setjmp.h>
#include<stdint.h>
#include<stdbool.h>

#define UC unsigned char
#define inline 

UC psw[1000]="qwq";
char fi[1000]="1.in",fo[1000]="1.in.qwq";
FILE *i,*o;

inline void _fre(){
    memset(psw,0,sizeof(psw));
    memset(fi,0,sizeof(psw));
    memset(fo,0,sizeof(psw));
	fclose(i);
	fclose(o);
    getchar();
    getchar();
    exit(0);
}

inline void _help(){
	printf(
		"\nqwq2 xor encoder helper\n\n"
    	"[INPUT_FILE_ADDRESS]\n    INPUT_FILE_ADDRESS will be encoded (or decode).\n"
    	"This parameter is necessary. It should be given first.\n\n"
		"-o [OUTPUT_FILE_ADDRESS]\n    OUTPUT_FILE_ADDRESS will be *.qwq by default where * is INPUT_FILE_ADDRESS.\n"
    	"This parameter is not necessary.\n\n"
		"-p [PASSWORD]\n    Encode with PASSWORD.\n"
		"-f [PASSWORD_FILE_ADDRESS]\n    Code with the file PASSWORD_FILE_ADDRESS.\n"
    	"There should be only one of these two parameters. They are not necessary and should be given last.\n\n"
    	"You can use it like this:\n"
    	"    qwq2 /root/c/1.txt -o /root/c/1.out -p 123456\n\n"
    	"Warning:\n"
    	"If the output address exists in a file, it will disappear forever.\n\n"
    	"Or you can read README.md to get help.\n\n"
	);
	_fre();
}

inline void geti(){
	i=fopen(fi,"rb");
	if(i!=NULL)return;
	printf(
		"Illegal input file address!\n"
	);
	_fre();
}

inline void geto(){
	o=fopen(fo,"rb");
	if(o!=NULL){
		printf(
			"Warning: [%s]\n"
			"The output address exists in a file. \n"
			"And it will disappear forever after encoding. \n"
			"Are you sure (y/n)? ",
			fo
		);
		if(getchar()!='y'){
			printf(
				"You exit, and the file had not encoded.\n"
			);
			_fre();
		}
	}
	fclose(o);
	o=fopen(fo,"wb");
	return;
}

inline void encode(){
	geti();
	geto();
	int pl=strlen(psw);
	fseek(i,0,SEEK_END);       
	int l=ftell(i);  
	rewind(i);
	UC c;
	for(int j=0;j<l;j++) {
		fread(&c,sizeof(UC),1,i);
		c^=psw[j%pl];
		fwrite(&c,sizeof(UC),1,o);
	}
	printf("%s 2 %s SUCC!\n",fi,fo);
	_fre();
}

int main(int argc,char**argv){
    if(argc<2)_help();
    if(!strcmp("-h",argv[1]))_help();
	strcpy(fi,argv[1]);
	strcpy(fo,argv[1]);
	strcat(fo,".qwq");
	if(argc==2)encode();
	if(argc==4){
		if(!strcmp("-o",argv[2])){
           strcpy(fo,argv[3]);
        }else if(!strcmp("-p",argv[2])){
           strcpy(psw,argv[3]);
        }else _help();
	}else if(argc==6){
		if(!strcmp("-o",argv[2])){
           strcpy(fo,argv[3]);
        }else _help();
		if(!strcmp("-p",argv[4])){
           strcpy(psw,argv[3]);
        }else _help();
	}else _help();
	encode();
}
