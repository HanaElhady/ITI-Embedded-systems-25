#ifndef HAL_SWITCH_SWITCH_INT_H_
#define HAL_SWITCH_SWITCH_INT_H_

#include "switch_cfg.h"

#define NO_PRESS    0
#define UP_PRESS    1
#define DOWN_PRESS  2

void Hswitch_vInit(void);
u8 Hswitch_u8GetPress(void);

#endif /* HAL_SWITCH_SWITCH_INT_H_ */
