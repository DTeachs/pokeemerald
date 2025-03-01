#include "global.h"
#include "random.h"

// IWRAM common
COMMON_DATA u32 gRngValue = 0;
COMMON_DATA u32 gRng2Value = 0;

u16 Random(void) {
    gRngValue ^= gRngValue << 13;
    gRngValue ^= gRngValue >> 17;
    gRngValue ^= gRngValue << 5;
    return gRngValue & 0xFFFF;
} 

void SeedRng(u32 seed)
{
    gRngValue = seed;
}

void SeedRng2(u32 seed)
{
    gRng2Value = seed;
}

u16 Random2(void) {
    gRng2Value ^= gRng2Value << 13;
    gRng2Value ^= gRngValue >> 17;
    gRng2Value ^= gRng2Value << 5;
    return gRng2Value & 0xFFFF;
} 
