//****************************************************************************/
// Description:
//
//  Read attitude and heading reference system [AHRS] data from the SparkFun
//  9DOF Razor Inertial Measurement Unit [IMU].
//
// AHRS code:
//
//  http://code.google.com/p/sf9domahrs/
//
// 9DOF Razor IMU:
//
//  http://www.sparkfun.com/commerce/product_info.php?products_id=9623
//****************************************************************************/

//****************************************************************************/
// Includes
//****************************************************************************/
#include "dof9RazorImuAhrs.h"

dof9RazorImuAhrs::dof9RazorImuAhrs(PinName tx, PinName rx) {

    razor = new Serial(tx, rx);
    razor->baud(BAUD_RATE);

}

void dof9RazorImuAhrs::update(void) {

    //Make sure we get to the start of a line.
    while (razor->getc() != '\n');

#if PRINT_EULER == 1
    razor->scanf("!ANG:%f,%f,%f", &roll, &pitch, &yaw);
#endif

#if PRINT_ANALOGS == 1
    razor->scanf(",AN:%f,%f,%f", &gyro_x, &gyro_y, &gyro_z);
    razor->scanf(",%f,%f,%f", &acc_x, &acc_y, &acc_z);
    razor->scanf(",%f,%f,%f", &mag_x, &mag_y, &mag_z);
#endif

}

float dof9RazorImuAhrs::getRoll(void){

    return roll;

}

float dof9RazorImuAhrs::getPitch(void){

    return pitch;

}

float dof9RazorImuAhrs::getYaw(void){

    return yaw;

}

float dof9RazorImuAhrs::getGyroX(void){

    return gyro_x;

}

float dof9RazorImuAhrs::getGyroY(void){

    return gyro_y;

}

float dof9RazorImuAhrs::getGyroZ(void){

    return gyro_z;

}

float dof9RazorImuAhrs::getAccX(void){

    return acc_x;

}

float dof9RazorImuAhrs::getAccY(void){

    return acc_x;

}

float dof9RazorImuAhrs::getAccZ(void){

    return acc_z;

}

float dof9RazorImuAhrs::getMagX(void){

    return mag_x;

}

float dof9RazorImuAhrs::getMagY(void){

    return mag_y;

}

float dof9RazorImuAhrs::getMagZ(void){

    return mag_z;

}
