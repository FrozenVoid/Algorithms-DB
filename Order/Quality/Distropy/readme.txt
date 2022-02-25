Average of 256 x(Average distance between 
bytes of same kind)
example:
f64 distropy(u8* data,size_t len){
size_t count[256]={0};f64 sum=0;
size_t seen[256]={0};size_t dist[256]={0};
for(u64 i=0;i<len;i++){count[data[i]]++;
if(seen[data[i]])dist[data[i]]=i;else
seen[data[i]]=i+1;}

size_t tot=0;
for(size_t i=0;i<256;i++){
if(!count[data[i]])continue;
tot++;
size_t di=dist[i]-seen[i];sum+=1.0*di/count[i];}
return sum/tot;
}
