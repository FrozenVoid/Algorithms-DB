#include "Util/void.h"
#include "gmp.h"
#define mpz1(var) mpz_t var;mpz_init(var);
#define mpz(var...) toatom(chainapply(mpz1,var))
#define bitspan 8
#define percent print("\nIter:",iter,"Popcount:",cbits, " Percent:",100.0*( cbits/(fsize*8.0)));
#define retcline return __LINE__
 char *get_filename_ext( char *filename) {
     char *dot = strrchr(filename, '.');
    if(!dot || dot == filename) return "";
    return dot + 1;
}

int main(int argc,char**argv){
if(argc<3){print("Syntax:inf e|d file\ne=encode d=decode");retcline;}
FILE* in=fopen(argv[2],"rb");
FILE* out;
if(!in){perror("Bad filename");retcline;}
u64 fsize=filesize(in);u8* data=malloc(fsize);
print("File:",argv[2]," Size:",fsize,"\n");
if(!data){perror("Memory allocation failed");retcline;}
u64 bytes_read=fread(data,1,fsize,in);
if(bytes_read!=fsize){perror("Read size mismatch, data incomplete");retcline;}
if(fsize<bitspan){perror("File too small");retcline;}
mpz(fileint,temp,a,b,best,res);
mpz_import (fileint, fsize, 1, 1, 0, 0, data);


u64 iter=0,bestiter=0,cbits= mpz_popcount(fileint);
u64 bestbits=cbits;
char resfilename[255];
if(argv[1][0]=='e'){//encode
print("Encoding:",argv[2]," Popcount:",cbits,"\n");
percent ;
mpz_set(b,fileint);
mpz_set(a,fileint);mpz_set(best,fileint);
for( ;;){iter++;
 mpz_tdiv_q_2exp (a,a, 1);//x>>1
 mpz_xor (b,b, a);//x^(x>>1);
cbits= mpz_popcount(b);//bit transitions=popcount of prev gray code.
mpz_set(a,b);
if(!(iter&0xffff))putchar('*');
if(!mpz_cmp (b,fileint))break;

//print(cbits,"\n");
if(cbits<bestbits ){bestbits=cbits;mpz_set(best,a);
percent;
bestiter=iter;}

}

print("Encoding done:", bestbits, " bits\nBest iter->",bestiter," of ",iter);
mpz_export (data, NULL, 1, 1,0,0, best);
sprintf(resfilename,"%s.%" PRIu64,argv[2],bestiter);
out=fopen(resfilename,"wb");
fwrite(data,1,fsize,out);
}else if(argv[1][0]=='d'){//decode
print("Decoding:",argv[2]," Popcount:",cbits,"\n");
mpz_set(b,fileint);//num
mpz_set(a,fileint);//mask
long unsigned int iters=0;
char* junk=get_filename_ext(argv[2]);
sscanf(junk,"%" PRIu64,&iters);
print("Iterations:",iters,"\n");
while(iters!=0){iters--;
while(mpz_cmp_ui(a,0)!=0){
 mpz_tdiv_q_2exp (a,a, 1);//x>>1
 //print("tdiv");
 mpz_xor (b,b, a);//x^(x>>1);
}
if(!(iters&0xff))print("Remaining iters:",iters,"\n");
mpz_set(a,b);//print(iters,"\n");
}

mpz_export (data, NULL, 1, 1,0,0, a);
sprintf(resfilename,"%s.dec",argv[2]);
out=fopen(resfilename,"wb");
fwrite(data,1,fsize,out);
print("Result file:",resfilename);
}

return 0;}
