/*
 * UltraSonic_interface.h
 *
 * Created: 7/3/2024 9:32:15 AM
 *  Author: ahmed
 */ 


#ifndef ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_INTERFACE_H_



extern  volatile u16 distance;

/********** Function to Inzialize UltraSonic Sensor ***********/

void UltraSonic_voidInit(void);

/********* Function to Send trigger pulse to Ultrasonic ****************/

void UltraSonic_SendPulse(void);

/********** Function To Get UltraSonic Sensor Distance Measurement******/

u8 UltraSonic_u8GetDistance(u16 on_ticks);


#endif /* ULTRASONIC_INTERFACE_H_ */