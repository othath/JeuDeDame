#include "alea.h"

float frand(){
    struct timeval tm;
    gettimeofday(&tm, NULL);
    srandom(tm.tv_sec+tm.tv_usec*1000000ul);
    return (float)random()/RAND_MAX;
}
