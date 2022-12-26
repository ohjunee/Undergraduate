#include <stdio.h>

typedef unsigned char uint8;
typedef unsigned int uint32;

uint8 set_bits(uint32 code, uint8 pNum, uint8 bCnt)
{
	uint8 result = 0;
	uint8 bitLen = pNum * 2 + 1;
	uint8 cp = bitLen - bCnt - 1;
	uint32 cb = 1;

	if (bCnt >= 0 && bCnt < pNum)
	{
		result = 0;
	}
	else if (bCnt >= pNum && bCnt < bitLen)
	{
		result = (cb << cp) & code ? 1 : 0;
	}
	return result;
}