A tagfilter string is formatted query:
"&tag+tag-tag2^tag>20:tag3"  which applies positive
tags(&combination,+match) and negative tags
(filters)
example pattern set(arbitatrary):
&tag - a tag that must be included
+tag - a tag that increases the score of pattern
-tag - a tag that decreases the score of pattenr
^tag - a tag that must not be included
tag>N - a tag which is valid if more than N points
tag<N - same as above, below N points
tag:tag2 - a tag that is only valid toghether with tag2
tag?tag2 - a tag that is not valid with tag2

