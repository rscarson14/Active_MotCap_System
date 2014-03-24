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

#ifndef DOF9_RAZOR_IMU_H
#define DOF9_RAZOR_IMU_H

//****************************************************************************/
// Includes
//****************************************************************************/
#include "mbed.h"

//****************************************************************************/
// Defines
//****************************************************************************/
#define PRINT_EULER   1     //Corrected heading data.
#define PRINT_ANALOGS 0     //Razor spits out raw gyro/accelerometer/magneto
                            //data.
                            //Set as a define when compiling AHRS code.
#define BAUD_RATE     57600 //Default in AHRS code.

class dof9RazorImuAhrs {

public:

    /**
     * Constructor.
     *
     * Parameters:
     *
     *  tx - Pin to use for Serial transmission.
     *  rx - Pin to use for Serial receive.
     */
    dof9RazorImuAhrs(PinName tx, PinName rx);
    
    /**
     * Update all of the heading data.
     */
    void update(void);
    
    float getRoll(void);
    float getPitch(void);
    float getYaw(void);
    
    float getGyroX(void);
    float getGyroY(void);
    float getGyroZ(void);
    
    float getAccX(void);
    float getAccY(void);
    float getAccZ(void);
    
    float getMagX(void);
    float getMagY(void);
    float getMagZ(void);

private:

    Serial* razor;

    float roll;
    float pitch;
    float yaw;
    
    float gyro_x;
    float gyro_y;
    float gyro_z;
    
    float acc_x;
    float acc_y;
    float acc_z;
    
    float mag_x;
    float mag_y;
    float mag_z;

};

#endif /* DOF9_RAZOR_IMU_H */
