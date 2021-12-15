// consider int a; with binary representation = 101010
// to iterate every subset of a (10, 1000, 1010, 100000, 100010, ...)
for (int subset = set; subset > 0; subset = (subset - 1) & set);