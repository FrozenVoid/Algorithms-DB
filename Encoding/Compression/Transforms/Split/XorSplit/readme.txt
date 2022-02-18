XorSplit algorithm transforms
a file X of size N into M parts(usually
just 2) of size N,
which xor back to X(M1^M2^...=X)
the transform allows to
alter bytes of M(n) files to
change their overall entropy/pairtropy
which increases compressibility.
e,g, M1 and M2 can be low-entropy
but M1^M2 will be high-entropy.
