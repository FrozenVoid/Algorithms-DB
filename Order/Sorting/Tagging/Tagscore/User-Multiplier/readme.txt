User Multiplier is a tag filtering mechanism that
doesn't block the tag but reduces its tagscore;-
This is used for mixed tag listings where post's highest scoring tags
determine its rank(e.g. post with #cat at 10 votes and #dog at 20 votes will 
be normally ranked 20 in such a listing)
example;
user A likes tag #cat and doesn't like tag #dog, but doesn't want to block
all #dog posts because sometimes there are good enough posts with this tag.
user A set a tagscore_multiplier for #cat at 3.0 and #dog at 0.2,
so that tagscore 1 #cat will have tagscore 3.0(1*3.0) and 
tagscore 15 #dog will also have tagscore 3.0(15*0.2), making both appear
at equal rank in listings despite the tag #dog requiring much more score.
