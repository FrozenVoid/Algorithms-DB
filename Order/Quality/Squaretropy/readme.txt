Amounts of duplicate items
squared / lowest uniqueness.
Example code for 24-bit items:

static f64 squaretropy(const u8* restrict data,const size_t len){
//return  triple density
static u32 fract[65536*256];
static size_t lenm;
 size_t maxsq=(len-2)*(len-2);//max=1
lenm=0;
for(uint_fast64_t i=0;i<len-2;i++)fract[(data[i+2]<<16)+(data[i+1]<<8)+data[i]]++;
for(uint_fast32_t i=0;i<65536*256;i++){;//sq dens
if(!fract[i])continue;
const uint_fast64_t fr=fract[i];lenm+=(fr)*(fr);fract[i]=0;}
return 1.0-(1.0*lenm/maxsq);}
