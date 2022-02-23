Amount of unique differences squared.
Example for short ints:

static f64 xsqtropy(const u8* restrict data,const size_t len){
//return  xorsq density
 u32 fract[65536]={0};size_t maxsq=(len-3)*(len-3);
 size_t lenm;//max=1
lenm=0;//i+3<len-3
for(uint_fast64_t i=0;i<len-3;i++){
const u16 a=(data[i+1]<<8)+data[i];
const u16 b=(data[i+3]<<8)+data[i+2];
fract[a^b]++;
}
for(uint_fast32_t i=0;i<65536;i++){;//sq dens
if(!fract[i])continue;
const uint_fast64_t fr=fract[i];lenm+=(fr)*(fr);;}
return 1.0-(1.0*lenm/maxsq);}
