#ifndef TIMER_H
#define TIMER_H

#include "types.h"

u16 level_control_timer(s32 timerOp);
void level_timer_tick(void);
void level_timer_reset(void);
s8 level_timer_is_running(void);

#endif // TIMER_H
