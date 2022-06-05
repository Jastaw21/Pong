#ifndef UTILITY_LOC_H
#define UTILITY_LOC_H

// Returns 0 if in range, -1 if below, 1 if above
template <typename T>
int inrange(T value, T min, T max){
if (value <= max && value >= min){return 0;}
else{
return value < min ? -1 : 1;}
}



#endif
