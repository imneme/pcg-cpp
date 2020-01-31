/*<http://creativecommons.org/publicdomain/zero/1.0/>*/

#include <stdint.h>
static inline uint64_t rotl(const uint64_t x, int8_t k) {
	return (x << k) | (x >> (64 - k));
}
static uint64_t s[4];
uint64_t seed(uint64_t x){
    for (int i=0; i<4; i++){
        uint64_t z = (x += 0x9e3779b97f4a7c15);
        z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
        z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
        z = (z ^ (z >> 31));
        s[i]=z;
    }
}
uint64_t next(void) {
	const uint64_t result = rotl(s[1] * 5, 7) * 9;
	const uint64_t t = s[1] << 17;
	s[2] ^= s[0];
	s[3] ^= s[1];
	s[1] ^= s[2];
	s[0] ^= s[3];
	s[2] ^= t;
	s[3] = rotl(s[3], 45);
	return result;
}
uint64_t range(uint64_t min, uint64_t max){
	return next()%(max-min+1)+min;
}
