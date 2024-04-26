

#ifndef BITMATH_H_
#define BITMATH_H_
#define SET_BIT(var, bit) var|= (1<<bit)
#define CLR_BIT(var, bit) var&= (~(1<<bit))
#define TOGGLE_BIT(var, bit) var^= ((1<<bit))
#define GET_BIT(var, bit) (var>>bit)&1
#endif
