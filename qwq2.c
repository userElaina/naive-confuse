// Code by userElaina
#include<stdio.h>
// #include<math.h>
// #include<stdlib.h>
// #include<string.h>
// #include<time.h>
// #include<setjmp.h>
// #include<stdint.h>
#include<stdbool.h>

#define UC unsigned char
#define inline 
#define MXN 1024
#define MXL 1<<24

UC psw[MXN]="qwq";
char ext[MXN]=".qwq2",reg[MXN];
UC ad[MXN]="https://github.com/userElaina/naive-confuse to find how to decode. ";
char fi[MXN]="_._",fo[MXN]="_._.qwq2";

UC buf[MXL];
bool two_gt=false;

FILE *i=NULL,*o=NULL;

inline void _fre(){
    memset(psw,0,sizeof(psw));
    memset(fi,0,sizeof(psw));
    memset(fo,0,sizeof(psw));
    memset(reg,0,sizeof(psw));
    memset(ext,0,sizeof(psw));
    memset(ad,0,sizeof(psw));

	fclose(i);
	fclose(o);
	
    getchar();
	if(two_gt)getchar();
    exit(0);
}

inline void _help(){
	printf(
		"\nqwq2 xor encoder (decoder) helper\n\n"
		"parameters:\n"
    	"[INPUT_FILE_ADDRESS]\n    INPUT_FILE_ADDRESS will be encoded (decode).\n"
    	"This parameter is necessary. It should be given first.\n\n"
		"-o [OUTPUT_FILE_ADDRESS]\n    OUTPUT_FILE_ADDRESS will be *.qwq by default where * is INPUT_FILE_ADDRESS.\n"
    	"This parameter is not necessary.\n\n"
		"-p [PASSWORD]\n    Encode with PASSWORD.\n"
		// "-f [PASSWORD_FILE_ADDRESS]\n    Code with the file PASSWORD_FILE_ADDRESS.\n"
    	// "There should be only one of these two parameters. They are not necessary and should be given last.\n\n"
    	"This parameter is not necessary and should be given last.\n\n"
    	"You can use it like this:\n"
    	"    qwq2 /root/c/qwq/2/tf/1.zip -o /root/c/qwq/2/tf/mima123456.qwq2 -p 123456\n\n"
    	"warning:\n"
    	"    If the output address exists in a file, it will disappear forever.\n\n"
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
	bool flg=false;
	#ifdef __WINDOWS_
		flg=true;
	#endif
	#ifdef _WIN32
		flg=true;
	#endif
	#ifdef _WIN64
		flg=true;
	#endif

	if(flg){
		o=fopen(fo,"rb");
		if(o!=NULL){
			printf(
				"Warning: [%s]\n"
				"The output address exists in a file.\n"
				"And it will disappear forever after encoding (decoding).\n"
				"Are you sure (y/n)? ",
				fo
			);
			if(getchar()!='y'){
				printf(
					"You exit, and the file has not been encoded (decoded).\n"
				);
				_fre();
			}
			two_gt=true;
		}
		fclose(o);
	}
	o=fopen(fo,"wb");
	return;
}

inline void encode(int ads){
	geti();
	geto();
	printf("Encoding (decoding) '%s' to '%s' ...\n",fi,fo);
	const int pl=strlen(psw);
	const int sz=sizeof(UC);
	if(ads){
		const int len_ad=strlen(ad);
		if(ads>0){
			fread(buf,sz,len_ad,i);
		}else{
			fwrite(ad,sz,len_ad,o);
		}
	}
	UC *p1=buf;
	UC *p2=buf+fread(buf,sizeof(UC),MXL,i);
	for(
		int j=pl-1;
		!(p1==p2&&((fwrite(buf,sz,p2-buf,o),p2=(p1=buf)+fread(buf,sz,MXL,i)),p1==p2));
		*p1++^=psw[j=(j+1)^pl?j+1:0]
	);
	printf("Successfully encoded (decoded) '%s' to '%s' !\n",fi,fo);
	_fre();
}

int main(int argc,char**argv){
    if(argc<2)fgets(reg,MXN,stdin),argc=2;
	else strcpy(reg,argv[1]);

	int len_reg=strlen(reg);
	if(!(reg[len_reg-1]^'\n'))
		reg[--len_reg]=0;
    if(!strcmp("-h",reg))_help();
    if(!strcmp("--help",reg))_help();
    if(!strcmp("help",reg))_help();

	strcpy(fi,reg);
	strcpy(fo,reg);
	strcat(fo,ext);
	// if(argc==2)encode(0);
	if(argc==2){
		bool flg=false;
		const int len_ext=strlen(ext);
		if(len_reg<=len_ext)flg=true;
		else for(int j=1;j<=len_ext;j++)
			if(reg[len_reg-j]^ext[len_ext-j]){
				flg=true;
				break;
			}
		encode(flg?-1:(fo[len_reg-len_ext]=0,1));
	}else if(argc==4){
		if(!strcmp("-o",argv[2]))
           strcpy(fo,argv[3]);
        else if(!strcmp("-p",argv[2]))
           strcpy(psw,argv[3]);
        else _help();
	}else if(argc==6){
		if(!strcmp("-o",argv[2]))
           strcpy(fo,argv[3]);
        else _help();
		if(!strcmp("-p",argv[4]))
           strcpy(psw,argv[3]);
        else _help();
	}else _help();
	encode(0);
}
