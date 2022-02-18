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
static f64 invsq[256];static int sqset=0;
u64 counts[256]={0};
if(!sqset){sqset=1;
for(size_t i=1;i<254;i++){
f64 r=1.0/(i);invsq[i]=r*r;}}
//return  triple density
static u8 dev[256][256][256];
 f64 lenm=0.0;
for(size_t i=0;i<len-2;i++){
u8 c=dev[data[i]][data[i+1]][data[i+2]];
if(c==255)continue;
c++;counts[c]++;counts[c-1]--;
dev[data[i]][data[i+1]][data[i+2]]=c;
}

memset(dev,0,sizeof(dev));
for(size_t i=1;i<254;i++)lenm+=invsq[i]*counts[i];
return ((lenm))/(256.0*256.0*256.0);}
