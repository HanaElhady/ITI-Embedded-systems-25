#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/Timer/TIMER_int.h"
#include "../MCAL/EXTI/EXTI_int.h"
#include "../HAL/led/led_int.h"
#include "../HAL/ssd/ssd_int.h"
#include "../HAL/switch/switch_int.h"
#include "TrafficLight/trafficLight.h"


int main(void) {

	Hled_vInit();
    SSD_vInit();
    Hswitch_vInit();
    TrafficLight();

    while(1) {
    }
    return 0;
}
