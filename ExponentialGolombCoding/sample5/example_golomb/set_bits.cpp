#include <stdio.h>

typedef unsigned char uint8;
typedef unsigned int uint32;

uint8 set_bits(uint32 code, uint8 prefixNum, uint8 bit_count)
{
	uint8 result = 0;
	uint8 bitLen = prefixNum * 2 + 1;
	uint8 cp = bitLen - bit_count - 1;
	uint32 cb = 1;

	if (bit_count >= 0 && bit_count < prefixNum)
	{
		result = 0;
	}
	else if (bit_count >= prefixNum && bit_count < bitLen)
	{
		result = (cb << cp) & code ? 1 : 0;
	}
	return result;
}