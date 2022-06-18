#pragma once
//rating.h macros
#include <stdint.h>
#include <stddef.h>
/*see https://github.com/FrozenVoid/Algorithms-DB/blob/main/Order/Sorting/Rating/Ratios/square_weight.txt
rate(num_ratings,rat_values,rat_scores)
num_ratings = number of rating slots in
 rat_values array and rat_scores array
rat_values = rating count for value x array
rat_scores = scores for value x array
e.g.[1,2,3,4,5,6,7,8,9,10] for num_ratings==10
*/

#define rate(num_ratings,rat_values,rat_scores) ({long double  votestotal=0.0,votesum=0.0,result,avg,cbsum=0;\
for(size_t i=0;i<num_ratings;i++){\
votestotal+=rat_values[i];\
votesum+=rat_values[i]*scores[i];\
long double cb1=rat_values[i];\
cbsum+=cb1*cb1*cb1;}\
if(votestotal>0.0L){long double avg=votesum/votestotal;\
long double scale=1.0L,sq=votestotal;\
scale-=((cbsum)/(sq*sq*sq));\
result=((1.0L-scale)*rat_scores[num_ratings/2]+(avg*(scale)));\
}else{result=rat_scores[num_ratings/2];}\
; result;})
