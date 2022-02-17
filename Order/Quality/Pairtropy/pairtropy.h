f64 pairtropy(u8* data,size_t len){
static f64 invcube[65536];static int cubeset=0;
if(!cubeset){cubeset=1;
invcube[0]=2.0;
for(size_t i=1;i<65536;i++){
f64 r=1.0/(i);invcube[i]=r*r*r;
}}
//return  pair density
 u16 dev[65536]={0};f64 lenm=1.0;
for(size_t i=0;i<len-1;i++){
u16 devents=dev[(data[i]<<8)+data[i+1]];
dev[(data[i]<<8)+data[i+1]]=devents!=0xffff?devents+1:devents;
;}
for(size_t i=0;i<65536;i++)lenm+=invcube[dev[i]];
return (65536.0/lenm);}


f64 tripletropy(u8* data,size_t len){
static f64 invsq[65536];static int sqset=0;
if(!sqset){sqset=1;invsq[0]=1.0;
for(size_t i=1;i<65536;i++){
f64 r=1.0/(i+1);invsq[i]=r*r;}}
//return  triple density

static u32 dev[256][256][256];
 f64 lenm=0.0;
for(size_t i=0;i<len-2;i++){
dev[data[i]][data[i+1]][data[i+2]]++;}

for(size_t i=0;i<256;i++){
for(size_t k=0;k<256;k++){
for(size_t z=0;z<256;z++){
size_t devt=dev[i][k][z]<65536?dev[i][k][z]:65535;lenm+=invsq[devt];
dev[i][k][z]=0;
}}}

return ((256.0*256.0*256.0)-(lenm))/(256.0*256.0*256.0);}
