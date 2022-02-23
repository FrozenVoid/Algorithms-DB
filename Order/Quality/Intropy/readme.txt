Intropy is amount of unique integers
 from a possibility pool.
Example code to calculate:

static int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

static f64 intropy(const u8* restrict data,const size_t len){
int store[(len-3)];u64 sum=0;
for(size_t i=0;i<len-3;i++)
{int*a=(int*)&data[i];
store[i]=a[0];}
//sort int(slow)
qsort(store, len-3, sizeof(int), cmpfunc);
for(size_t i=1;i<len-3;i++){sum+=store[i]==store[i-1];}
return 1.0-(1.0*sum/(len-3));
}
