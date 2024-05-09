#include <avr/io.h>
#include <util/delay.h>
#include "servo.h"
#include "TIMER_interface.h"
#include "DIO_int.h"
#include "ultrasonicSensor.h"

// Define motor pins
#define MOTOR1_FORWARD_PIN  DIO_PIN0
#define MOTOR1_BACKWARD_PIN DIO_PIN1
#define MOTOR2_FORWARD_PIN  DIO_PIN2
#define MOTOR2_BACKWARD_PIN DIO_PIN3

#define STOP_DISTANCE     40
// Define motor speeds
#define MOTOR_SPEED_FAST 255
#define MOTOR_SPEED_SLOW 128

// Define distance thresholds
#define OBSTACLE_THRESHOLD 20
#define CRASH_THRESHOLD    10

// Function prototypes
void Robot_Move_Forward();
void Robot_Move_Backward();
void Robot_Move_Right();
void Robot_Move_Left();
void Robot_Stop();
void Robot_Speed(Motor_Speed_t speed);
u8 Ultrasonic_GetDistance();
