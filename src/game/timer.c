#include "timer.h"
#include "level_update.h"

static s8 sTimerRunning;

u16 level_control_timer(s32 timerOp) {
    switch (timerOp) {
        case TIMER_CONTROL_SHOW:
            gHudDisplay.flags |= HUD_DISPLAY_FLAG_TIMER;
            sTimerRunning = FALSE;
            gHudDisplay.timer = 0;
            break;

        case TIMER_CONTROL_START:
            sTimerRunning = TRUE;
            break;

        case TIMER_CONTROL_STOP:
            sTimerRunning = FALSE;
            break;

        case TIMER_CONTROL_HIDE:
            gHudDisplay.flags &= ~HUD_DISPLAY_FLAG_TIMER;
            sTimerRunning = FALSE;
            gHudDisplay.timer = 0;
            break;
    }

    return gHudDisplay.timer;
}

void level_timer_tick(void) {
    if (sTimerRunning && gHudDisplay.timer < 17999) {
        gHudDisplay.timer++;
    }
}

void level_timer_reset(void) {
    sTimerRunning = FALSE;
    gHudDisplay.timer = 0;
}

s8 level_timer_is_running(void) {
    return sTimerRunning;
}
