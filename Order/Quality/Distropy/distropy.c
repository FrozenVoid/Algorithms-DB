static f64 distropy(const u8* restrict  data,const size_t len){
static size_t stat[256*3];
 size_t* restrict count=&stat[0];
 size_t* restrict dist=&stat[256];
 size_t* restrict seen=&stat[256*2];
f64 sum=0;
for(size_t i=0;i<len;i++){
const size_t b=data[i];
dist[b]=i+1;
seen[b]+=(i+1)*(!count[b]++);}

size_t tot=0;
for(size_t i=0;i<256;i++){
if(!count[i])continue;
tot++;
f64 di=dist[i]-seen[i];sum+=di/count[i];}
memset(stat,0,sizeof(stat));
return sum/tot;}
