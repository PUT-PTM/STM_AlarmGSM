#include "init.h"

int counter=0;
unsigned int audio=0;
extern const u8 rawAudio[96078];

bool IsAlarmOn = false;
bool clockon = false;
bool alarmring = false;

void poweron();
void poweroff();
void alarmloop();
void binaryclock(int counter);

