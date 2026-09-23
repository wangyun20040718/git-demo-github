#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#include <string.h>
//#include <stdint.h> /* 定义整数类型，如uint8_t, uint16_t, uint32_t等 */

typedef char uint8_t;
typedef short uint16_t;
typedef int uint32_t;

typedef struct{
    uint8_t name[10];
    uint8_t age;
    uint8_t sex[10];
}people_st;


#endif
