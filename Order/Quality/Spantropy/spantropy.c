float spantropy(u8* data,size_t len){
static size_t first[65535];
static size_t last[65535];
for(size_t i=0;i<65535;i++){first[i]=0;last[i]=0;}
u16* vdata;
for(size_t i=0;i<len-1;i++){
vdata=(u16*)&data[i];
const size_t curfirst=first[*vdata];
first[*vdata]=curfirst?:i+1;
last[*vdata]=i+1;}
size_t occ=0,sumdist=0;
for(size_t i=0;i<65535;i++){
if(!first[i])continue;
size_t dist=last[i]-first[i];
occ++;sumdist+=dist*dist;}
return (float)sumdist/occ;
}
