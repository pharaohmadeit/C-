Near Containers: built-in array, bitset, String, valarray

bitset Near Container

Highly specialized container specifically for bit manuipulation

b.set(bitNumber);

b.reset(bitNumber);

b.flip(bitNumber);

b[bitNumber]

b.test(bitNumber);
-perform range checking on bitNumber first. if bitNumber is in range, test returns true

b.size()
-returns the number of bits

b.count()
-returns the number of bits that are set (true)

b.any()
-returns ture if any bit is set

b.all()
-returns true if all of the bits are set (true)

b &= b1;
-perform bit-by-by AND betweeen b and b1, setting each bit in b "on" if its "on" in both b and b1

b |= b1;

b ^= b2;

~b

b >>= n;

b <<= n;

b.to_string()

b.to_ulong()

b.to_ullong()
