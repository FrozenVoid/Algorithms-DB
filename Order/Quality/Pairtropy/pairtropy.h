f64 pairtropy(u8* data,size_t len){
static f64 invcube[65536];static int cubeset=0;
if(!cubeset){cubeset=1;
invcube[0]=2.0;
for(size_t i=1;i<65536;i++){
f64 r=1.0/(i);invcube[i]=r*r*r;
}}
//return  pair density 
 u16 dev[65536]={0};f64 lenm=1.0;
for(size_t i=0;i<len-1;i++)dev[(data[i]<<8)+data[i+1]]++;
for(size_t i=0;i<65536;i++)lenm+=invcube[dev[i]];
return (65536.0/lenm);}
