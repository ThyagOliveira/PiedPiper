#include "ValueFrequency.h"

struct valueFrequency {
	byte value;
	unsigned int frequency;
};

ValueFrequency * ValueFrequencyFactory(byte value, unsigned frequency) {
  ValueFrequency * vf = (ValueFrequency *) malloc(sizeof(ValueFrequency));
  vf->value = value;
	vf->frequency = frequency;
	return vf;
}

int GetFrequency(ValueFrequency * vf){
  return vf->frequency;
}
byte GetValue(ValueFrequency * vf){
  return vf->value;
}