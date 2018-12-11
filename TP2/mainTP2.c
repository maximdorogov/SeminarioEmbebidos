/*
 * @brief Statechart example using sysTick
 *
 * @note
 * Copyright(C) NXP Semiconductors, 2013
 * All rights reserved.
 *
 * @par
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * LPC products.  This software is supplied "AS IS" without any warranties of
 * any kind, and NXP Semiconductors and its licensor disclaim any and
 * all warranties, express or implied, including all implied warranties of
 * merchantability, fitness for a particular purpose and non-infringement of
 * intellectual property rights.  NXP Semiconductors assumes no responsibility
 * or liability for the use of the software, conveys no license or rights under any
 * patent, copyright, mask work right, or any other intellectual property rights in
 * or to any products. NXP Semiconductors reserves the right to make changes
 * in the software without notification. NXP Semiconductors also makes no
 * representation or warranty that such application will be suitable for the
 * specified use without further testing or modification.
 *
 * @par
 * Permission to use, copy, modify, and distribute this software and its
 * documentation is hereby granted, under NXP Semiconductors' and its
 * licensor's relevant copyrights in the software, without fee, provided that it
 * is used in conjunction with NXP Semiconductors microcontrollers.  This
 * copyright, permission, and disclaimer notice must appear in all copies of
 * this code.
 */

#include "board.h"

#include "sc_types.h"
#include "Prefix.h"

/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/
#define TICKRATE_HZ (1000)	/* 1000 ticks per second */

#define TICKRATE_10HZ (10)				/* 10 ticks per second */
#define TICKRATE_100HZ (100)			/* 100 ticks per second */
#define TICKRATE_1000HZ (1000)			/* 1000 ticks per second */
#define TICKRATE_HZ1 (TICKRATE_1000HZ)

#define TP2_X ('X')	/* Test Statechart EDU-CIAA-NXP - Blink LED3 */
#define TP2_Y ('Y')	/* Test Statechart EDU-CIAA-NXP - Idle Blink LED3 */
#define TP2_Z ('Y')	/* Test Statechart EDU-CIAA-NXP - Button */
#define TP2_1 (1)	/* Test Statechart EDU-CIAA-NXP - IDE LPCXpresso - Application */
#define TP2_2 (2)	/* Test Statechart EDU-CIAA-NXP - Panel de Control Generador de Señales */
#define TP2_3 (3)	/* Test Statechart EDU-CIAA-NXP - Puerta Corrediza */
#define TP2_4 (4)	/* Test Statechart EDU-CIAA-NXP - Portón de Cochera */
#define TP2_5 (5)	/* Test Statechart EDU-CIAA-NXP - Escalera Mecánica */
#define TP2_6 (6)	/* Test Statechart EDU-CIAA-NXP - Horno Microondas */

#define TEST (TP2_3)

/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/
volatile bool SysTick_Time_Flag = false;

/*variables para TP2_2*/
volatile sc_integer formaDeOnda;
volatile sc_integer toMeasure;
volatile sc_integer frecVal =20;
volatile sc_integer tensVal =0;


static Prefix statechart;

/*****************************************************************************
 * Private functions
 ****************************************************************************/

/*****************************************************************************
 * Public functions
 ****************************************************************************/
#if (TEST == TP2_X)
/**
 * @brief	Handle interrupt from SysTick timer
 * @return	Nothing
 */
void SysTick_Handler(void)
{
	SysTick_Time_Flag = true;
}


void prefixIface_opLED(Prefix* handle, sc_integer LEDNumber, sc_boolean State)
{
	Board_LED_Set((uint8_t) LEDNumber, State);
}

/**
 * @brief	main routine for statechart example
 * @return	Function should not exit.
 */
int main(void)
{
	/* Generic Initialization */
	SystemCoreClockUpdate();
	Board_Init();

	/* Enable and setup SysTick Timer at a periodic rate */
	SysTick_Config(SystemCoreClock / TICKRATE_HZ1);

	/* Statechart Initialization */
	prefix_init(&statechart);
	prefix_enter(&statechart);

	/* LEDs toggle in main */
	while (1) {
		__WFI();

		if (SysTick_Time_Flag == true) {
			SysTick_Time_Flag = false;
			prefixIface_raise_evTick(&statechart);					// Event -> evTick => OK

			prefix_runCycle(&statechart);							// Run Cycle of Statechart
		}
	}
}
#endif


#if (TEST == TP2_Y)
/**
 * @brief	Handle interrupt from SysTick timer
 * @return	Nothing
 */
void SysTick_Handler(void)
{
	SysTick_Time_Flag = true;
}


void prefixIface_opLED(Prefix* handle, sc_integer LEDNumber, sc_boolean State)
{
	Board_LED_Set((uint8_t) LEDNumber, State);
}

/**
 * @brief	main routine for statechart example
 * @return	Function should not exit.
 */
int main(void)
{
	uint32_t BUTTON_Status;

	/* Generic Initialization */
	SystemCoreClockUpdate();
	Board_Init();

	/* Enable and setup SysTick Timer at a periodic rate */
	SysTick_Config(SystemCoreClock / TICKRATE_HZ1);

	/* Statechart Initialization */
	prefix_init(&statechart);
	prefix_enter(&statechart);

	/* LEDs toggle in main */
	while (1) {
		__WFI();

		if (SysTick_Time_Flag == true) {
			SysTick_Time_Flag = false;
			prefixIface_raise_evTick(&statechart);					// Event -> evTick => OK

			BUTTON_Status = Buttons_GetStatus();
			if (BUTTON_Status != 0)
				prefixIface_raise_evTECXOprimido(&statechart,BUTTON_Status);		// Event -> evTECXOprimodo => OK
			else
				prefixIface_raise_evTECXNoOprimido(&statechart);	// Event -> evTECXNoOprimido => OK

			prefix_runCycle(&statechart);							// Run Cycle of Statechart
		}
	}
}
#endif


#if (TEST == TP2_1)
/**
 * @brief	Handle interrupt from SysTick timer
 * @return	Nothing
 */
void SysTick_Handler(void)
{
	SysTick_Time_Flag = true;
}


void prefixIface_opLED(Prefix* handle, sc_integer LEDNumber, sc_boolean State)
{
	Board_LED_Set((uint8_t) LEDNumber, State);
}

/**
 * @brief	main routine for statechart example
 * @return	Function should not exit.
 */
int main(void)
{
	uint32_t BUTTON_Status;

	/* Generic Initialization */
	SystemCoreClockUpdate();
	Board_Init();

	/* Enable and setup SysTick Timer at a periodic rate */
	SysTick_Config(SystemCoreClock / TICKRATE_HZ1);

	/* Statechart Initialization */
	prefix_init(&statechart);
	prefix_enter(&statechart);

	/* LEDs toggle in main */
	while (1) {
		__WFI();

		if (SysTick_Time_Flag == true) {
			SysTick_Time_Flag = false;
			prefixIface_raise_evTick(&statechart);					// Event -> evTick => OK

			BUTTON_Status = Buttons_GetStatus();
			if (BUTTON_Status != 0)									// Event -> evTECXOprimodo => OK
				prefixIface_raise_evTECXOprimido(&statechart, BUTTON_Status);	// Value -> Tecla
			else													// Event -> evTECXNoOprimido => OK
				prefixIface_raise_evTECXNoOprimido(&statechart);

			prefix_runCycle(&statechart);							// Run Cycle of Statechart
		}
	}
}
#endif

#if (TEST == TP2_2)
/**
 * @brief	Handle interrupt from SysTick timer
 * @return	Nothing
 */
void SysTick_Handler(void)
{
	SysTick_Time_Flag = true;
}


void prefixIface_opLED(Prefix* handle, sc_integer LEDNumber, sc_boolean State)
{
	Board_LED_Set((uint8_t) LEDNumber, State);
}

void prefixIface_opLEDToggle(const Prefix* handle, const sc_integer LEDNumber){

	Board_LED_Toggle(LEDNumber);

}


void prefixIface_opSetMode(const Prefix* handle, const sc_integer WAVEForm){

	// aca deberia cambiar el waveform con una funcion

	formaDeOnda = WAVEForm;

}

void prefixIface_opEnviarSerie(const Prefix* handle, const sc_string Mensaje){

	DEBUGOUT(Mensaje);
	DEBUGOUT("\n Frecuencia %d \n Tension %d",frecVal,tensVal);
}

void prefixIface_opSetMagn(const Prefix* handle, const sc_integer MAGNChange){

	toMeasure = MAGNChange;

}
void prefixIface_opIncFrec(const Prefix* handle){

	frecVal++;

}
void prefixIface_opDecFrec(const Prefix* handle){
	frecVal--;
}
void prefixIface_opIncTens(const Prefix* handle){

	tensVal++;
}
void prefixIface_opDecTens(const Prefix* handle){

	tensVal--;
}



/**
 * @brief	main routine for statechart example
 * @return	Function should not exit.
 */
int main(void)
{
	uint32_t BUTTON_Status;

	/* Generic Initialization */
	SystemCoreClockUpdate();
	Board_Init();

	/* Enable and setup SysTick Timer at a periodic rate */
	SysTick_Config(SystemCoreClock / TICKRATE_HZ1);

	/* Statechart Initialization */
	prefix_init(&statechart);
	prefix_enter(&statechart);

	/* LEDs toggle in main */
	while (1) {
		__WFI();

		if (SysTick_Time_Flag == true) {
			SysTick_Time_Flag = false;
			prefixIface_raise_evTick(&statechart);					// Event -> evTick => OK

			BUTTON_Status = Buttons_GetStatus();
			if (BUTTON_Status != 0)									// Event -> evTECXOprimodo => OK
				prefixIface_raise_evTECXOprimido(&statechart, BUTTON_Status);	// Value -> Tecla
			else													// Event -> evTECXNoOprimido => OK
				prefixIface_raise_evTECXNoOprimido(&statechart);

			prefix_runCycle(&statechart);							// Run Cycle of Statechart
		}
	}
}
#endif


#if (TEST == TP2_3)
/**
 * @brief	Handle interrupt from SysTick timer
 * @return	Nothing
 */
void SysTick_Handler(void)
{
	SysTick_Time_Flag = true;
}

void prefixIface_opLED(const Prefix* handle, const sc_integer LEDNumber, const sc_boolean State){

	Board_LED_Set((uint8_t) LEDNumber, State);


}
void prefixIface_opOpenDoor(const Prefix* handle){

	DEBUGOUT("\n ACA DEBERIA HABER UNA FUNCION QUE ABRE LA PUERTA\n");
}
void prefixIface_opCloseDoor(const Prefix* handle){

	DEBUGOUT("\n ACA DEBERIA HABER UNA FUNCION QUE CIERRA LA PUERTA\n");


}
void prefixIface_opEnviarSerie(const Prefix* handle, const sc_string Mensaje){


	DEBUGOUT(Mensaje);
	DEBUGOUT("\n");
}





/**
 * @brief	main routine for statechart example
 * @return	Function should not exit.
 */
int main(void)
{
	uint32_t BUTTON_Status;

	/* Generic Initialization */
	SystemCoreClockUpdate();
	Board_Init();

	/* Enable and setup SysTick Timer at a periodic rate */
	SysTick_Config(SystemCoreClock / TICKRATE_HZ1);

	/* Statechart Initialization */
	prefix_init(&statechart);
	prefix_enter(&statechart);

	/* LEDs toggle in main */
	while (1) {
		__WFI();

		if (SysTick_Time_Flag == true) {
			SysTick_Time_Flag = false;
			prefixIface_raise_evTick(&statechart);					// Event -> evTick => OK

			BUTTON_Status = Buttons_GetStatus();
			if (BUTTON_Status != 0)									// Event -> evTECXOprimodo => OK
				prefixIface_raise_evTECXOprimido(&statechart, BUTTON_Status);	// Value -> Tecla
			else													// Event -> evTECXNoOprimido => OK
				prefixIface_raise_evTECXNoOprimido(&statechart);

			prefix_runCycle(&statechart);							// Run Cycle of Statechart
		}
	}
}
#endif

#if (TEST == TP2_4)
/**
 * @brief	Handle interrupt from SysTick timer
 * @return	Nothing
 */
void SysTick_Handler(void)
{
	SysTick_Time_Flag = true;
}


void prefixIface_opLED(const Prefix* handle, const sc_integer LEDNumber, const sc_boolean State){

	Board_LED_Set((uint8_t) LEDNumber, State);


}
void prefixIface_opOpenDoor(const Prefix* handle){

	DEBUGOUT("\n ACA DEBERIA HABER UNA FUNCION QUE ABRA LA PUERTA PARA IR A JUGAR\n");

}
void prefixIface_opCloseDoor(const Prefix* handle){

	DEBUGOUT("\n ACA DEBERIA HABER UNA FUNCION QUE CIERRE LA PUERTA PARA IR A DORMIR\n");


}
void prefixIface_opEnviarSerie(const Prefix* handle, const sc_string Mensaje){

	DEBUGOUT("\n");
	DEBUGOUT(Mensaje);
}





/**
 * @brief	main routine for statechart example
 * @return	Function should not exit.
 */
int main(void)
{
	uint32_t BUTTON_Status;

	/* Generic Initialization */
	SystemCoreClockUpdate();
	Board_Init();

	/* Enable and setup SysTick Timer at a periodic rate */
	SysTick_Config(SystemCoreClock / TICKRATE_HZ1);

	/* Statechart Initialization */
	prefix_init(&statechart);
	prefix_enter(&statechart);

	/* LEDs toggle in main */
	while (1) {
		__WFI();

		if (SysTick_Time_Flag == true) {
			SysTick_Time_Flag = false;
			prefixIface_raise_evTick(&statechart);					// Event -> evTick => OK

			BUTTON_Status = Buttons_GetStatus();
			if (BUTTON_Status != 0)									// Event -> evTECXOprimodo => OK
				prefixIface_raise_evTECXOprimido(&statechart, BUTTON_Status);	// Value -> Tecla
			else													// Event -> evTECXNoOprimido => OK
				prefixIface_raise_evTECXNoOprimido(&statechart);

			prefix_runCycle(&statechart);							// Run Cycle of Statechart
		}
	}
}
#endif


#if (TEST == TP2_5)
/**
 * @brief	Handle interrupt from SysTick timer
 * @return	Nothing
 */
void SysTick_Handler(void)
{
	SysTick_Time_Flag = true;
}


void prefixIface_opLED(const Prefix* handle, const sc_integer LEDNumber, const sc_boolean State){

	Board_LED_Set((uint8_t) LEDNumber, State);


}
void prefixIface_opStairsGoUp(const Prefix* handle){

	DEBUGOUT("ACA UNA FUNCION DONDE LAS ESCALERAS DEBERIAN SUBIR\n");

}
void prefixIface_opStairsGoDown(const Prefix* handle){
	DEBUGOUT("ACA UNA FUNCION DONDE LAS ESCALERAS DEBERIAN BAJAR\n");


}
void prefixIface_opStopStairs(const Prefix* handle){
	DEBUGOUT("ACA UNA FUNCION DONDE LAS ESCALERAS DEBERIAN PARAR\n");


}



/**
 * @brief	main routine for statechart example
 * @return	Function should not exit.
 */
int main(void)
{
	uint32_t BUTTON_Status;

	/* Generic Initialization */
	SystemCoreClockUpdate();
	Board_Init();

	/* Enable and setup SysTick Timer at a periodic rate */
	SysTick_Config(SystemCoreClock / TICKRATE_HZ1);

	/* Statechart Initialization */
	prefix_init(&statechart);
	prefix_enter(&statechart);

	/* LEDs toggle in main */
	while (1) {
		__WFI();

		if (SysTick_Time_Flag == true) {
			SysTick_Time_Flag = false;
			prefixIface_raise_evTick(&statechart);					// Event -> evTick => OK

			BUTTON_Status = Buttons_GetStatus();
			if (BUTTON_Status != 0)									// Event -> evTECXOprimodo => OK
				prefixIface_raise_evTECXOprimido(&statechart, BUTTON_Status);	// Value -> Tecla
			else													// Event -> evTECXNoOprimido => OK
				prefixIface_raise_evTECXNoOprimido(&statechart);

			prefix_runCycle(&statechart);							// Run Cycle of Statechart
		}
	}
}
#endif



#if (TEST == TP2_6)
/**
 * @brief	Handle interrupt from SysTick timer
 * @return	Nothing
 */
void SysTick_Handler(void)
{
	SysTick_Time_Flag = true;
}


void prefixIface_opLED(const Prefix* handle, const sc_integer LEDNumber, const sc_boolean State){

	Board_LED_Set((uint8_t) LEDNumber, State);
}

void prefixIface_opEncenderLuz(const Prefix* handle, const sc_integer LUZ){
	Board_LED_Set((uint8_t) LUZ, FALSE);

}
void prefixIface_opApagarLuz(const Prefix* handle, const sc_integer LUZ){
	Board_LED_Set((uint8_t) LUZ, TRUE);

}

void prefixIface_opEncenderHorno(const Prefix* handle, const sc_integer C){

	switch(C){
		case 20: 		DEBUGOUT("HORNO ENCENDIDO\n");
												break;
		case 21: 		DEBUGOUT("GRILL ENCENDIDO\n");
												break;
		case 22: 	DEBUGOUT("HORNO Y GRILL ENCENDIDOS\n");
												break;
		case 23:	DEBUGOUT("HORNO APAGADO\n");
												break;
		}


}

void prefixIface_opEnviarSerie(const Prefix* handle, const sc_string Mensaje){

	DEBUGOUT(Mensaje);
	DEBUGOUT("\n");
}





/**
 * @brief	main routine for statechart example
 * @return	Function should not exit.
 */
int main(void)
{
	uint32_t BUTTON_Status;

	/* Generic Initialization */
	SystemCoreClockUpdate();
	Board_Init();

	/* Enable and setup SysTick Timer at a periodic rate */
	SysTick_Config(SystemCoreClock / TICKRATE_HZ1);

	/* Statechart Initialization */
	prefix_init(&statechart);
	prefix_enter(&statechart);

	/* LEDs toggle in main */
	while (1) {
		__WFI();

		if (SysTick_Time_Flag == true) {
			SysTick_Time_Flag = false;
			prefixIface_raise_evTick(&statechart);					// Event -> evTick => OK

			BUTTON_Status = Buttons_GetStatus();
			if (BUTTON_Status != 0)									// Event -> evTECXOprimodo => OK
				prefixIface_raise_evTECXOprimido(&statechart, BUTTON_Status);	// Value -> Tecla
			else													// Event -> evTECXNoOprimido => OK
				prefixIface_raise_evTECXNoOprimido(&statechart);

			prefix_runCycle(&statechart);							// Run Cycle of Statechart
		}
	}
}
#endif



