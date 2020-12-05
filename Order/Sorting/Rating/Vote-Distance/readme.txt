In a vote-distance system the rating change is calculated from
1.User selected rating add/sub(e.g. +1 upvote, or more if upvotes use user karma pool)
2.Distance from the last rating point(last user before this one):
e.g. user A upvotes post X, then in 10 seconds user B upvotes it again.
10 seconds is the vote-distance metric.
3.Vote distance metric is use with the #1 score to determine rating change.
e.g. vote distance to last rating(if none,time distance to sumbission date)
is multiplied by score(user-given score) and divided by some factor;
examples of divide factor;
A.inverse thread rank(1/log-rank)
B.1/User rank(user who scores the thread)
C.Popularity log-rank of thread(log(unique_users_viewed))
