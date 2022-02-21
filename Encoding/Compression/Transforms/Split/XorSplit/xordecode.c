#include "Util/void.h"
#define retcline return __LINE__
//-------------------------------------------------
int main(int argc,char**argv){
nooutbuffer;
if(argc<3){print("Syntax:xormerge filename i\n i=chunks to decode(i->1)\nex: xormerge file.split 2");retcline;}
size_t chunks=atoi(argv[2]);
u64 fsize;;
u8* orig=loadfile(argv[1],&fsize);//original data
if(!orig){perror("Memory allocation failed");retcline;}
print("File:",argv[1]," Size:",fsize,"Chunks:",chunks,"\n");
char resfilename[255];
size_t chunklen=fsize/chunks;
for(size_t z=1;z<chunks;z++){
print("\nDecoding chunk:", z, " size:",chunklen,"bytes");
u8* bdata=&orig[chunklen*z];
for(size_t i=0;i<chunklen;i++){
orig[i]^=bdata[i];}}


sprintf(resfilename,"%s.dec",argv[1]);
FILE* out=fopen(resfilename,"wb");
fwrite(orig,1,chunklen,out);
print("\nResult file:",resfilename);
return 0;}
