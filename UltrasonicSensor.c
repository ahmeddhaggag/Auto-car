/*
 *_*
 * ultrasonicSensor.c
 *
 *  Created on: 28 April 2024
 *      Author: Maab-Sayed 
  version ; 1.1
 */

 #include "ultrasonicSensor.h"


/* Function prototypes */
void Timer1_Init(Timer1_Mode_t mode, Timer1_OCRA1_Config_t OCRA1_config, Timer1_OCRB1_Config_t OCRB1_config);
void Timer1_ICU_SetCallBack(void (*callback_func)(void));
void Timer1_SetCallBack_COMPA(void (*callback_func)(void));
void Timer1_Interrupt_COMPA_enable(void);
void Timer1_InputCaptureEdge(Timer1_ICU_Edge_t edge);
void Timer1_ICU_InterruptEnable(void);
void Timer1_ICU_InterruptDisnable(void);
void _delay_us(u16 us);
void  DIO_voidSetPortValue(u8 Copy_u8PortID, u8 Copy_u8Value);

static volatile u16 ut1, ut2; // Capture values for rising and falling edges
static volatile u8 uflag = 0; // Flag for capture events (0: idle, 1: rising, 2: falling)
static volatile u16 overflow_count = 0; // Counter for timer overflows

u16 UltrasonicReadDistance(){
    u16 distance = 0;
    u32 time = 0;

    TCNT1 = 0; /* Clear Timer1 counter */
    DIO_voidSetPinValue(ULTRASONIC_PORT,TRIG_PIN , DIO_HIGH);  /* Trigger high pulse */
    _delay_us(10);             /* Trigger pulse duration */
    DIO_voidSetPinValue(ULTRASONIC_PORT,TRIG_PIN , DIO_LOW);   /* Trigger low pulse */
    time = Timer1_u32MeasurePulseDuration(); //each unit time is 1 us, prescaler 8

    distance = (u16)((0.0346*time)/(2*1.5));
    return distance;

}

static void Func_ICU(void) {
    if (uflag == 0) {
        ut1 = ICR1;
        uflag = 1;
        Timer1_InputCaptureEdge(FALLING_EDGE);  // Switch to capture falling edge
    } else if (uflag == 1) {
        ut2 = ICR1;
        uflag = 2;
        Timer1_ICU_InterruptDisnable(); // Disable ICU interrupt
        TMR1_Interrupt_COMPA_Disable(); // Disable COMPARE_A interrupt (optional)
    }
}

static void TMR_OVR(void) {
    overflow_count++; // Increment overflow counter
}

void Ultrasonic_init(void) {
    Timer1_Init(TMR1_PWM_FAST_MODE_OCR1A, OCRA1_DISCONNECTED, OCRB1_NON_INVERTING);
    OCR1A = 20000; /* Set OCR1A value for desired pulse width (adjust as needed) */
    Timer1_ICU_SetCallBack(Func_ICU);
    Timer1_SetCallBack_COMPA(TMR_OVR); /* Set callback for COMPARE_A interrupt  */
    TMR1_Interrupt_COMPA_enable();     /* Enable COMPARE_A interrupt */
}


