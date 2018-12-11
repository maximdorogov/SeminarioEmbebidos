#include "sapi.h"


#define TP1_1 (1)
#define TP1_2 (2)
#define TP1_3 (3)
#define TP1_4 (4)
#define TP1_5 (5)
#define TEST (TP1_5)



#if (TEST == TP1_1)

int main(void){

	   boardConfig();

	   while(1) {

		  /* Prendo el led azul */
		  gpioWrite( LEDG, ON );

		  delay(50);

		  /* Apago el led azul */
		  gpioWrite( LEDG, OFF );

		  delay(50);

	   }

	   return 0 ;
}

#endif

#if (TEST == TP1_2)

int main(void){

	   boardConfig();

	   gpioConfig( GPIO0, GPIO_INPUT );

	   gpioConfig( GPIO1, GPIO_OUTPUT );

	   bool_t valor;

	   while(1) {

		  valor = !gpioRead( TEC1 );
		  gpioWrite( LEDB, valor );

		  valor = !gpioRead( TEC2 );
		  gpioWrite( LED1, valor );

		  valor = !gpioRead( TEC3 );
		  gpioWrite( LED2, valor );

		  valor = !gpioRead( TEC4 );
		  gpioWrite( LED3, valor );

		  valor = !gpioRead( GPIO0 );
		  gpioWrite( GPIO1, valor );

	   }

	   return 0 ;
	}

#endif

#if (TEST == TP1_3)

void myTickHook( void *);

int main(void){
	   /* ------------- INICIALIZACIONES ------------- */

	   /* Inicializar la placa */
	   boardConfig();

	   /* Inicializar el conteo de Ticks con resolucion de 50ms (se ejecuta
	      periodicamente una interrupcion cada 50ms que incrementa un contador de
	      Ticks obteniendose una base de tiempos). */
	   tickConfig( 50 );

	   /* Se agrega ademas un "tick hook" nombrado myTickHook. El tick hook es
	      simplemente una funcion que se ejecutara peri�odicamente con cada
	      interrupcion de Tick, este nombre se refiere a una funcion "enganchada"
	      a una interrupcion.
	      El segundo parametro es el parametro que recibe la funcion myTickHook
	      al ejecutarse. En este ejemplo se utiliza para pasarle el led a titilar.
	   */
	   tickCallbackSet( myTickHook, (void*)LEDR );
	   delay(1000);

	   /* ------------- REPETIR POR SIEMPRE ------------- */
	   while(1) {
	      tickCallbackSet( myTickHook, (void*)LEDG );
	      delay(1000);
	      tickCallbackSet( myTickHook, (void*)LEDB );
	      delay(1000);
	      tickCallbackSet( myTickHook, (void*)LED1 );
	      delay(1000);
	      tickCallbackSet( myTickHook, (void*)LED2 );
	      delay(1000);
	      tickCallbackSet( myTickHook, (void*)LED3 );
	      delay(1000);
	      tickCallbackSet( myTickHook, (void*)LEDR );
	      delay(1000);
	   }

	   return 0 ;
}

void myTickHook( void *ptr ){

				static bool_t ledState = OFF;

				gpioMap_t led = (gpioMap_t)ptr;

				if( ledState ){
					ledState = OFF;
				}
				else{
					ledState = ON;
				}
				gpioWrite( led, ledState );
			}

#endif

#if (TEST == TP1_4)

#define TICKRATE_MS	50
#define LED_TOGGLE_MS 500


void myTickHook( void *);
bool_t MytickConfig( tick_t );

int main(void){
	   /* ------------- INICIALIZACIONES ------------- */

	   /* Inicializar la placa */
	   boardConfig();
	   DEBUG_PRINT_ENABLE;
	   debugPrintConfigUart( UART_USB, 115200 );

	   /* Inicializar el conteo de Ticks con resolucion de 50ms (se ejecuta
	      periodicamente una interrupcion cada 50ms que incrementa un contador de
	      Ticks obteniendose una base de tiempos). */
	   tickConfig(  TICKRATE_MS	 );

	   /* Se agrega ademas un "tick hook" nombrado myTickHook. El tick hook es
	      simplemente una funcion que se ejecutara peri�odicamente con cada
	      interrupcion de Tick, este nombre se refiere a una funcion "enganchada"
	      a una interrupcion.
	      El segundo parametro es el parametro que recibe la funcion myTickHook
	      al ejecutarse. En este ejemplo se utiliza para pasarle el led a titilar.
	   */
	   tickCallbackSet( myTickHook, (void*)LEDR );
	   delay(LED_TOGGLE_MS);

	   debugPrintString( "DEBUG c/sAPI\r\n" );
	   debugPrintString( "LED Toggle\n" );
	   /* ------------- REPETIR POR SIEMPRE ------------- */
	   while(1) {
	      tickCallbackSet( myTickHook, (void*)LEDG );
	      delay(LED_TOGGLE_MS);
	      tickCallbackSet( myTickHook, (void*)LEDB );
	      delay(LED_TOGGLE_MS);
	      tickCallbackSet( myTickHook, (void*)LED1 );
	      delay(LED_TOGGLE_MS);
	      tickCallbackSet( myTickHook, (void*)LED2 );
	      delay(LED_TOGGLE_MS);
	      tickCallbackSet( myTickHook, (void*)LED3 );
	      delay(LED_TOGGLE_MS);
	      tickCallbackSet( myTickHook, (void*)LEDR );
	      delay(LED_TOGGLE_MS);
	   }

	   return 0 ;
}

void myTickHook( void *ptr ){

				static bool_t ledState = OFF;

				gpioMap_t led = (gpioMap_t)ptr;

				if( ledState ){
					ledState = OFF;
				}
				else{
					ledState = ON;
				}
				gpioWrite( led, ledState );
			}

#endif

#if (TEST == TP1_5)

#define LED_QTY_MAX  4

typedef enum{BTN_ON = 0,
			BTN_OFF}btn_status_t;

bool_t IsPressed(gpioMap_t);

int main(void){


	uint8_t leds[LED_QTY_MAX] = {LEDB,LED1,LED2,LED3};
	size_t counter = 0;

	boardConfig();
	gpioConfig( GPIO0, GPIO_INPUT );
	gpioConfig( GPIO1, GPIO_OUTPUT );


	while(1) {

		if (IsPressed(TEC1)){

			if(counter != 0){

				gpioWrite( leds[counter-1], LOW );
				if(counter == LED_QTY_MAX) {counter = 0;}

			}

			gpioWrite( leds[counter], HIGH);

			counter ++;


		}
	}

	return 0 ;
}

bool_t IsPressed(gpioMap_t pin){

	int btn_past_state;
	int btn_actual_state = !gpioRead(pin);

	btn_past_state =  btn_actual_state;

	return (!gpioRead(pin) == btn_actual_state) && (btn_past_state == TRUE);


}

#endif


