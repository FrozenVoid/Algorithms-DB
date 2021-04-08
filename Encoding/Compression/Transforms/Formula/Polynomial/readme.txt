The general idea is as follows
1.File is converted to integer X( arbitrary precision number)

2.A search space is created by multiplying  X by Y and Y+1 creating an interval gap (X*Y)<gap>(X*(Y+1))

3.A polynomial is constructed in form of z^k+n^m-h^A+...-...
that converges into the gap. This is the key area:
The idea is to search for number base^power that brings one as close to the gap as possible. Search is guided by averaging the min/max values of either power or base that are above/below the gap and finding the closest distance base^power result.

3a. Multiple variables can be used at same time to optimize distance into the gap: such as ((x^y)+-(Z^K)) can be searched for both instead of optimizing for each member of polynomial (x^y).

4.That polynomial is recorded along with Y factor(typically a power of 2, it also can be shifted back and forth to suit the polynomial result location(i.e. any gap location multiplied/divided by power of 2 will also fit)).

5.To decode the polynomial is divided by Y and fractional parts are discarded, giving back X.

6.The result (X) is converted back to file.
