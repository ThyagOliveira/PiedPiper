typedef unsigned char byte;
typedef struct valueFrequency ValueFrequency;

ValueFrequency * ValueFrequencyFactory(byte value, unsigned frequency);
int GetFrequency(ValueFrequency * vf);
byte GetValue(ValueFrequency * vf);