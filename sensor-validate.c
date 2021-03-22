#include "sensor-validate.h"

int _give_me_a_good_name(double value, double nextValue, double maxDelta) {
  if(nextValue - value > maxDelta) {
    return 0;
  }
  return 1;
}

int validateParameter_Readings(double* values, int numOfValues, double deviationValue) {
  int lastButOneIndex = numOfValues - 1;
  for(int i = 0; i < lastButOneIndex; i++) {
    if(!_give_me_a_good_name(values[i], values[i + 1], deviationValue)) {
      return 0;
    }
  }
  return 1;
}
