#include "mbed.h"
#include "SDFileSystem.h"
#include "dof9RazorImuAhrs.h"
 
SDFileSystem sd(p5, p6, p7, p8, "sd");

DigitalIn calibrate(p26);
DigitalIn hall_sensor(p25);

Serial xbee(p13, p14);

dof9RazorImuAhrs theRazor(p9, p10);

DigitalOut myled(LED1);

int main() {
    while(1) {
        myled = 1;
        wait(0.2);
        myled = 0;
        wait(0.2);
    }
}
