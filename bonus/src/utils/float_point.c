#include "../../includes/cub3d.h"

fixed_point float_to_fixed(float value) 
{
    return (fixed_point)(value * FIXED_POINT_SCALE);
}

fixed_point int_to_fixed(int value)
{
    return value * FIXED_POINT_SCALE;
}
int fixed_to_int(fixed_point value)
{
    return value / FIXED_POINT_SCALE;
}

float fixed_to_float(fixed_point value)
{
    return (float)value / FIXED_POINT_SCALE;
}

fixed_point fixed_add(fixed_point a, fixed_point b)
{
    return a + b;
}

fixed_point fixed_sub(fixed_point a, fixed_point b)
{
    return a - b;
}

fixed_point fixed_mul(fixed_point a, fixed_point b)
{
    return ((int64_t)a * b) >> FIXED_POINT_SHIFT;
}

fixed_point fixed_div(fixed_point a, fixed_point b)
{
    return ((int64_t)a << FIXED_POINT_SHIFT) / b;
}