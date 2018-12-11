
#ifndef PREFIX_H_
#define PREFIX_H_

#include "sc_types.h"
		
#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'prefix'.
*/

/*! Enumeration of all states */ 
typedef enum
{
	Prefix_TECX_DEBOUNCE,
	Prefix_TECX_NO_OPRIMIDO,
	Prefix_TECX_OPRIMIDO,
	Prefix_Application_ESPERA,
	Prefix_forma_TRIANGULAR,
	Prefix_forma_CUADRADA,
	Prefix_forma_SENOIDAL,
	Prefix_magnitud_FRECUENCIA,
	Prefix_magnitud_TENSION,
	Prefix_last_state
} PrefixStates;

/*! Type definition of the data structure for the PrefixIface interface scope. */
typedef struct
{
	sc_boolean evTick_raised;
	sc_boolean evTECXNoOprimido_raised;
	sc_boolean evTECXOprimido_raised;
	sc_integer evTECXOprimido_value;
} PrefixIface;

/* Declaration of constants for scope PrefixIface. */
extern const sc_integer PREFIX_PREFIXIFACE_LEDR;
extern const sc_integer PREFIX_PREFIXIFACE_LEDG;
extern const sc_integer PREFIX_PREFIXIFACE_LEDB;
extern const sc_integer PREFIX_PREFIXIFACE_LED1;
extern const sc_integer PREFIX_PREFIXIFACE_LED2;
extern const sc_integer PREFIX_PREFIXIFACE_LED3;
extern const sc_integer PREFIX_PREFIXIFACE_CTRIANG;
extern const sc_integer PREFIX_PREFIXIFACE_CCUADR;
extern const sc_integer PREFIX_PREFIXIFACE_CSENOID;
extern const sc_integer PREFIX_PREFIXIFACE_CFREC;
extern const sc_integer PREFIX_PREFIXIFACE_CTENS;
extern const sc_string PREFIX_PREFIXIFACE_MSGENTRIANG;
extern const sc_string PREFIX_PREFIXIFACE_MSGENCUAD;
extern const sc_string PREFIX_PREFIXIFACE_MSGENSEN;
extern const sc_string PREFIX_PREFIXIFACE_MSGMAGFREC;
extern const sc_string PREFIX_PREFIXIFACE_MSGMAGTENS;
extern const sc_string PREFIX_PREFIXIFACE_MSGMAGSUBEFREC;
extern const sc_string PREFIX_PREFIXIFACE_MSGMAGBAJAFREC;
extern const sc_string PREFIX_PREFIXIFACE_MSGMAGSUBETENS;
extern const sc_string PREFIX_PREFIXIFACE_MSGMAGBAJATENS;
extern const sc_boolean PREFIX_PREFIXIFACE_LED_ON;
extern const sc_boolean PREFIX_PREFIXIFACE_LED_OFF;
extern const sc_integer PREFIX_PREFIXIFACE_TEC1;
extern const sc_integer PREFIX_PREFIXIFACE_TEC2;
extern const sc_integer PREFIX_PREFIXIFACE_TEC3;
extern const sc_integer PREFIX_PREFIXIFACE_TEC4;

/*! Type definition of the data structure for the PrefixInternal interface scope. */
typedef struct
{
	sc_boolean siTitilarLED_raised;
	sc_boolean siNoTitilarLED_raised;
	sc_boolean siTECXOK_raised;
	sc_boolean evMode_raised;
	sc_boolean evMagn_raised;
	sc_boolean evUp_raised;
	sc_boolean evDown_raised;
	sc_integer viTitilar;
	sc_integer viDebounce;
	sc_integer viTecla;
} PrefixInternal;


/*! Define dimension of the state configuration vector for orthogonal states. */
#define PREFIX_MAX_ORTHOGONAL_STATES 4

/*! 
 * Type definition of the data structure for the Prefix state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	PrefixStates stateConfVector[PREFIX_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	PrefixIface iface;
	PrefixInternal internal;
} Prefix;

/*! Initializes the Prefix state machine data structures. Must be called before first usage.*/
extern void prefix_init(Prefix* handle);

/*! Activates the state machine */
extern void prefix_enter(Prefix* handle);

/*! Deactivates the state machine */
extern void prefix_exit(Prefix* handle);

/*! Performs a 'run to completion' step. */
extern void prefix_runCycle(Prefix* handle);


/*! Raises the in event 'evTick' that is defined in the default interface scope. */ 
extern void prefixIface_raise_evTick(Prefix* handle);

/*! Raises the in event 'evTECXNoOprimido' that is defined in the default interface scope. */ 
extern void prefixIface_raise_evTECXNoOprimido(Prefix* handle);

/*! Raises the in event 'evTECXOprimido' that is defined in the default interface scope. */ 
extern void prefixIface_raise_evTECXOprimido(Prefix* handle, sc_integer value);

/*! Gets the value of the variable 'LEDR' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_lEDR(const Prefix* handle);
/*! Gets the value of the variable 'LEDG' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_lEDG(const Prefix* handle);
/*! Gets the value of the variable 'LEDB' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_lEDB(const Prefix* handle);
/*! Gets the value of the variable 'LED1' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_lED1(const Prefix* handle);
/*! Gets the value of the variable 'LED2' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_lED2(const Prefix* handle);
/*! Gets the value of the variable 'LED3' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_lED3(const Prefix* handle);
/*! Gets the value of the variable 'cTRIANG' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_cTRIANG(const Prefix* handle);
/*! Gets the value of the variable 'cCUADR' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_cCUADR(const Prefix* handle);
/*! Gets the value of the variable 'cSENOID' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_cSENOID(const Prefix* handle);
/*! Gets the value of the variable 'cFREC' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_cFREC(const Prefix* handle);
/*! Gets the value of the variable 'cTENS' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_cTENS(const Prefix* handle);
/*! Gets the value of the variable 'msgEnTriang' that is defined in the default interface scope. */ 
extern const sc_string prefixIface_get_msgEnTriang(const Prefix* handle);
/*! Gets the value of the variable 'msgEnCuad' that is defined in the default interface scope. */ 
extern const sc_string prefixIface_get_msgEnCuad(const Prefix* handle);
/*! Gets the value of the variable 'msgEnSen' that is defined in the default interface scope. */ 
extern const sc_string prefixIface_get_msgEnSen(const Prefix* handle);
/*! Gets the value of the variable 'msgMagFrec' that is defined in the default interface scope. */ 
extern const sc_string prefixIface_get_msgMagFrec(const Prefix* handle);
/*! Gets the value of the variable 'msgMagTens' that is defined in the default interface scope. */ 
extern const sc_string prefixIface_get_msgMagTens(const Prefix* handle);
/*! Gets the value of the variable 'msgMagSubeFrec' that is defined in the default interface scope. */ 
extern const sc_string prefixIface_get_msgMagSubeFrec(const Prefix* handle);
/*! Gets the value of the variable 'msgMagBajaFrec' that is defined in the default interface scope. */ 
extern const sc_string prefixIface_get_msgMagBajaFrec(const Prefix* handle);
/*! Gets the value of the variable 'msgMagSubeTens' that is defined in the default interface scope. */ 
extern const sc_string prefixIface_get_msgMagSubeTens(const Prefix* handle);
/*! Gets the value of the variable 'msgMagBajaTens' that is defined in the default interface scope. */ 
extern const sc_string prefixIface_get_msgMagBajaTens(const Prefix* handle);
/*! Gets the value of the variable 'LED_ON' that is defined in the default interface scope. */ 
extern const sc_boolean prefixIface_get_lED_ON(const Prefix* handle);
/*! Gets the value of the variable 'LED_OFF' that is defined in the default interface scope. */ 
extern const sc_boolean prefixIface_get_lED_OFF(const Prefix* handle);
/*! Gets the value of the variable 'TEC1' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_tEC1(const Prefix* handle);
/*! Gets the value of the variable 'TEC2' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_tEC2(const Prefix* handle);
/*! Gets the value of the variable 'TEC3' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_tEC3(const Prefix* handle);
/*! Gets the value of the variable 'TEC4' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_tEC4(const Prefix* handle);

/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean prefix_isActive(const Prefix* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean prefix_isFinal(const Prefix* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean prefix_isStateActive(const Prefix* handle, PrefixStates state);

#ifdef __cplusplus
}
#endif 

#endif /* PREFIX_H_ */
