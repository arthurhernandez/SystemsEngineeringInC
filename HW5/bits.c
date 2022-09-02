
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Points: 5
 */
int bitAnd(int x, int y) {
  return ~( ~x | ~y );
}

/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Points: 10
 */
int getByte(int x, int n) {
  return ( x >> ( n << 3 )) & 0xff;
}

/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Points: 10
 */

int byteSwap(int x, int n, int m) {
  int mask = 0;
  n = (n << 3);
  m = (m << 3);
 //  int mask = 0;
  mask = 0xFF & ((x>>n)^(x>>m));
  x = x ^ (mask << n);
  x = x ^ (mask << m);
  return x;
}

/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Points: 15
 */
int logicalShift(int x, int n) {
  return ( x >> n ) & ( ~ ( (( 1 << 31 ) >> n ) << 1 ) );
}

/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Points: 20
 */
int bitCount(int x) {
  int mask = 0, mask2 = 0, sol = 0, sol2 = 0;
  mask = 0x1 | (0x1<<8) | (0x1<<16) | (0x1<<24);
  mask2 = 0xFF; 
  sol = (x & mask) + ( (x>>1) & mask) + ( (x>>2) & mask) + ( (x>>3) & mask) + ( (x>>4) & mask ) + ( (x>>5) & mask) + ( (x>>6) & mask) + ( (x>>7) & mask);
  sol2 = (sol & mask2) + ( (sol>>8) & mask2) + ( (sol>>16) & mask2) + ( (sol>>24) & mask2);
  return sol2;
}

/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Points: 20
 */
int bang(int x) {
  return ( ( ( ~x + 1) | x ) >> 31) + 1;
}

/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Points: 20
 */
int bitParity(int x) {
  x ^= x >> 16;
  x ^= x >> 8;
  x ^= x >> 4;
  x ^= x >> 2;
  x ^= x >> 1;
  x &= 1;
  return x;
}
