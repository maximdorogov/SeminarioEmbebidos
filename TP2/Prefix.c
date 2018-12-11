
#include <stdlib.h>
#include <string.h>
#include "sc_types.h"
#include "Prefix.h"
#include "PrefixRequired.h"
/*! \file Implementation of the state machine 'prefix'
*/

/* prototypes of all internal functions */
static sc_boolean prefix_check_TECX_DEBOUNCE_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_TECX_DEBOUNCE_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_TECX_DEBOUNCE_lr1_lr1(const Prefix* handle);
static sc_boolean prefix_check_TECX_NO_OPRIMIDO_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_TECX_OPRIMIDO_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_Application_ESPERA_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_Application_ESPERA_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_Application_ESPERA_tr2_tr2(const Prefix* handle);
static sc_boolean prefix_check_Application_ESPERA_tr3_tr3(const Prefix* handle);
static sc_boolean prefix_check_forma_TRIANGULAR_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_forma_CUADRADA_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_forma_SENOIDAL_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_magnitud_FRECUENCIA_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_magnitud_FRECUENCIA_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_magnitud_FRECUENCIA_tr2_tr2(const Prefix* handle);
static sc_boolean prefix_check_magnitud_TENSION_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_magnitud_TENSION_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_magnitud_TENSION_tr2_tr2(const Prefix* handle);
static void prefix_effect_TECX_DEBOUNCE_tr0(Prefix* handle);
static void prefix_effect_TECX_DEBOUNCE_tr1(Prefix* handle);
static void prefix_effect_TECX_DEBOUNCE_lr1_lr1(Prefix* handle);
static void prefix_effect_TECX_NO_OPRIMIDO_tr0(Prefix* handle);
static void prefix_effect_TECX_OPRIMIDO_tr0(Prefix* handle);
static void prefix_effect_Application_ESPERA_tr0(Prefix* handle);
static void prefix_effect_Application_ESPERA_tr1(Prefix* handle);
static void prefix_effect_Application_ESPERA_tr2(Prefix* handle);
static void prefix_effect_Application_ESPERA_tr3(Prefix* handle);
static void prefix_effect_forma_TRIANGULAR_tr0(Prefix* handle);
static void prefix_effect_forma_CUADRADA_tr0(Prefix* handle);
static void prefix_effect_forma_SENOIDAL_tr0(Prefix* handle);
static void prefix_effect_magnitud_FRECUENCIA_tr0(Prefix* handle);
static void prefix_effect_magnitud_FRECUENCIA_tr1(Prefix* handle);
static void prefix_effect_magnitud_FRECUENCIA_tr2(Prefix* handle);
static void prefix_effect_magnitud_TENSION_tr0(Prefix* handle);
static void prefix_effect_magnitud_TENSION_tr1(Prefix* handle);
static void prefix_effect_magnitud_TENSION_tr2(Prefix* handle);
static void prefix_enact_TECX_DEBOUNCE(Prefix* handle);
static void prefix_enact_TECX_OPRIMIDO(Prefix* handle);
static void prefix_enact_forma_TRIANGULAR(Prefix* handle);
static void prefix_enact_forma_CUADRADA(Prefix* handle);
static void prefix_enact_forma_SENOIDAL(Prefix* handle);
static void prefix_enact_magnitud_FRECUENCIA(Prefix* handle);
static void prefix_enact_magnitud_TENSION(Prefix* handle);
static void prefix_enseq_TECX_DEBOUNCE_default(Prefix* handle);
static void prefix_enseq_TECX_NO_OPRIMIDO_default(Prefix* handle);
static void prefix_enseq_TECX_OPRIMIDO_default(Prefix* handle);
static void prefix_enseq_Application_ESPERA_default(Prefix* handle);
static void prefix_enseq_forma_TRIANGULAR_default(Prefix* handle);
static void prefix_enseq_forma_CUADRADA_default(Prefix* handle);
static void prefix_enseq_forma_SENOIDAL_default(Prefix* handle);
static void prefix_enseq_magnitud_FRECUENCIA_default(Prefix* handle);
static void prefix_enseq_magnitud_TENSION_default(Prefix* handle);
static void prefix_enseq_TECX_default(Prefix* handle);
static void prefix_enseq_Application_default(Prefix* handle);
static void prefix_enseq_forma_default(Prefix* handle);
static void prefix_enseq_magnitud_default(Prefix* handle);
static void prefix_exseq_TECX_DEBOUNCE(Prefix* handle);
static void prefix_exseq_TECX_NO_OPRIMIDO(Prefix* handle);
static void prefix_exseq_TECX_OPRIMIDO(Prefix* handle);
static void prefix_exseq_Application_ESPERA(Prefix* handle);
static void prefix_exseq_forma_TRIANGULAR(Prefix* handle);
static void prefix_exseq_forma_CUADRADA(Prefix* handle);
static void prefix_exseq_forma_SENOIDAL(Prefix* handle);
static void prefix_exseq_magnitud_FRECUENCIA(Prefix* handle);
static void prefix_exseq_magnitud_TENSION(Prefix* handle);
static void prefix_exseq_TECX(Prefix* handle);
static void prefix_exseq_Application(Prefix* handle);
static void prefix_exseq_forma(Prefix* handle);
static void prefix_exseq_magnitud(Prefix* handle);
static void prefix_react_TECX_DEBOUNCE(Prefix* handle);
static void prefix_react_TECX_NO_OPRIMIDO(Prefix* handle);
static void prefix_react_TECX_OPRIMIDO(Prefix* handle);
static void prefix_react_Application_ESPERA(Prefix* handle);
static void prefix_react_forma_TRIANGULAR(Prefix* handle);
static void prefix_react_forma_CUADRADA(Prefix* handle);
static void prefix_react_forma_SENOIDAL(Prefix* handle);
static void prefix_react_magnitud_FRECUENCIA(Prefix* handle);
static void prefix_react_magnitud_TENSION(Prefix* handle);
static void prefix_react_TECX__entry_Default(Prefix* handle);
static void prefix_react_Application__entry_Default(Prefix* handle);
static void prefix_react_forma__entry_Default(Prefix* handle);
static void prefix_react_magnitud__entry_Default(Prefix* handle);
static void prefix_clearInEvents(Prefix* handle);
static void prefix_clearOutEvents(Prefix* handle);

const sc_integer PREFIX_PREFIXIFACE_LEDR = 0;
const sc_integer PREFIX_PREFIXIFACE_LEDG = 1;
const sc_integer PREFIX_PREFIXIFACE_LEDB = 2;
const sc_integer PREFIX_PREFIXIFACE_LED1 = 3;
const sc_integer PREFIX_PREFIXIFACE_LED2 = 4;
const sc_integer PREFIX_PREFIXIFACE_LED3 = 5;
const sc_integer PREFIX_PREFIXIFACE_CTRIANG = 10;
const sc_integer PREFIX_PREFIXIFACE_CCUADR = 11;
const sc_integer PREFIX_PREFIXIFACE_CSENOID = 12;
const sc_integer PREFIX_PREFIXIFACE_CFREC = 13;
const sc_integer PREFIX_PREFIXIFACE_CTENS = 14;
const sc_string PREFIX_PREFIXIFACE_MSGENTRIANG = "Entro a Triangular";
const sc_string PREFIX_PREFIXIFACE_MSGENCUAD = "Entro a Cuadrada";
const sc_string PREFIX_PREFIXIFACE_MSGENSEN = "Entro a Senoidal";
const sc_string PREFIX_PREFIXIFACE_MSGMAGFREC = "Cambia magnitud en frecuencia";
const sc_string PREFIX_PREFIXIFACE_MSGMAGTENS = "Cambia magnitud en tension";
const sc_string PREFIX_PREFIXIFACE_MSGMAGSUBEFREC = "Sube la frecuencia";
const sc_string PREFIX_PREFIXIFACE_MSGMAGBAJAFREC = "Baja la frecuencia";
const sc_string PREFIX_PREFIXIFACE_MSGMAGSUBETENS = "Sube la tension";
const sc_string PREFIX_PREFIXIFACE_MSGMAGBAJATENS = "Baja la tension";
const sc_boolean PREFIX_PREFIXIFACE_LED_ON = bool_false;
const sc_boolean PREFIX_PREFIXIFACE_LED_OFF = bool_true;
const sc_integer PREFIX_PREFIXIFACE_TEC1 = 1 << 0;
const sc_integer PREFIX_PREFIXIFACE_TEC2 = 1 << 1;
const sc_integer PREFIX_PREFIXIFACE_TEC3 = 1 << 2;
const sc_integer PREFIX_PREFIXIFACE_TEC4 = 1 << 3;
const sc_integer PREFIX_PREFIXINTERNAL_CI50MS = 50;
const sc_integer PREFIX_PREFIXINTERNAL_CI250MS = 250;
const sc_integer PREFIX_PREFIXINTERNAL_CI500MS = 500;

void prefix_init(Prefix* handle)
{
	sc_integer i;

	for (i = 0; i < PREFIX_MAX_ORTHOGONAL_STATES; ++i)
	{
		handle->stateConfVector[i] = Prefix_last_state;
	}
	
	
	handle->stateConfVectorPosition = 0;

	prefix_clearInEvents(handle);
	prefix_clearOutEvents(handle);

	/* Default init sequence for statechart prefix */
	handle->internal.viTitilar = 0;
	handle->internal.viDebounce = 0;
	handle->internal.viTecla = 0;

}

void prefix_enter(Prefix* handle)
{
	/* Default enter sequence for statechart prefix */
	prefix_enseq_TECX_default(handle);
	prefix_enseq_Application_default(handle);
	prefix_enseq_forma_default(handle);
	prefix_enseq_magnitud_default(handle);
}

void prefix_exit(Prefix* handle)
{
	/* Default exit sequence for statechart prefix */
	prefix_exseq_TECX(handle);
	prefix_exseq_Application(handle);
	prefix_exseq_forma(handle);
	prefix_exseq_magnitud(handle);
}

sc_boolean prefix_isActive(const Prefix* handle)
{
	sc_boolean result;
	if (handle->stateConfVector[0] != Prefix_last_state || handle->stateConfVector[1] != Prefix_last_state || handle->stateConfVector[2] != Prefix_last_state || handle->stateConfVector[3] != Prefix_last_state)
	{
		result =  bool_true;
	}
	else
	{
		result = bool_false;
	}
	return result;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean prefix_isFinal(const Prefix* handle)
{
   return bool_false;
}

static void prefix_clearInEvents(Prefix* handle)
{
	handle->iface.evTick_raised = bool_false;
	handle->iface.evTECXNoOprimido_raised = bool_false;
	handle->iface.evTECXOprimido_raised = bool_false;
	handle->internal.siTitilarLED_raised = bool_false;
	handle->internal.siNoTitilarLED_raised = bool_false;
	handle->internal.siTECXOK_raised = bool_false;
	handle->internal.evMode_raised = bool_false;
	handle->internal.evMagn_raised = bool_false;
	handle->internal.evUp_raised = bool_false;
	handle->internal.evDown_raised = bool_false;
}

static void prefix_clearOutEvents(Prefix* handle)
{
}

void prefix_runCycle(Prefix* handle)
{
	
	prefix_clearOutEvents(handle);
	
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < PREFIX_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++)
		{
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition])
		{
		case Prefix_TECX_DEBOUNCE :
		{
			prefix_react_TECX_DEBOUNCE(handle);
			break;
		}
		case Prefix_TECX_NO_OPRIMIDO :
		{
			prefix_react_TECX_NO_OPRIMIDO(handle);
			break;
		}
		case Prefix_TECX_OPRIMIDO :
		{
			prefix_react_TECX_OPRIMIDO(handle);
			break;
		}
		case Prefix_Application_ESPERA :
		{
			prefix_react_Application_ESPERA(handle);
			break;
		}
		case Prefix_forma_TRIANGULAR :
		{
			prefix_react_forma_TRIANGULAR(handle);
			break;
		}
		case Prefix_forma_CUADRADA :
		{
			prefix_react_forma_CUADRADA(handle);
			break;
		}
		case Prefix_forma_SENOIDAL :
		{
			prefix_react_forma_SENOIDAL(handle);
			break;
		}
		case Prefix_magnitud_FRECUENCIA :
		{
			prefix_react_magnitud_FRECUENCIA(handle);
			break;
		}
		case Prefix_magnitud_TENSION :
		{
			prefix_react_magnitud_TENSION(handle);
			break;
		}
		default:
			break;
		}
	}
	
	prefix_clearInEvents(handle);
}


sc_boolean prefix_isStateActive(const Prefix* handle, PrefixStates state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case Prefix_TECX_DEBOUNCE :
			result = (sc_boolean) (handle->stateConfVector[0] == Prefix_TECX_DEBOUNCE
			);
			break;
		case Prefix_TECX_NO_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[0] == Prefix_TECX_NO_OPRIMIDO
			);
			break;
		case Prefix_TECX_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[0] == Prefix_TECX_OPRIMIDO
			);
			break;
		case Prefix_Application_ESPERA :
			result = (sc_boolean) (handle->stateConfVector[1] == Prefix_Application_ESPERA
			);
			break;
		case Prefix_forma_TRIANGULAR :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_forma_TRIANGULAR
			);
			break;
		case Prefix_forma_CUADRADA :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_forma_CUADRADA
			);
			break;
		case Prefix_forma_SENOIDAL :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_forma_SENOIDAL
			);
			break;
		case Prefix_magnitud_FRECUENCIA :
			result = (sc_boolean) (handle->stateConfVector[3] == Prefix_magnitud_FRECUENCIA
			);
			break;
		case Prefix_magnitud_TENSION :
			result = (sc_boolean) (handle->stateConfVector[3] == Prefix_magnitud_TENSION
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}

void prefixIface_raise_evTick(Prefix* handle)
{
	handle->iface.evTick_raised = bool_true;
}
void prefixIface_raise_evTECXNoOprimido(Prefix* handle)
{
	handle->iface.evTECXNoOprimido_raised = bool_true;
}
void prefixIface_raise_evTECXOprimido(Prefix* handle, sc_integer value)
{
	handle->iface.evTECXOprimido_value = value;
	handle->iface.evTECXOprimido_raised = bool_true;
}


const sc_integer prefixIface_get_lEDR(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LEDR;
}
const sc_integer prefixIface_get_lEDG(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LEDG;
}
const sc_integer prefixIface_get_lEDB(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LEDB;
}
const sc_integer prefixIface_get_lED1(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LED1;
}
const sc_integer prefixIface_get_lED2(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LED2;
}
const sc_integer prefixIface_get_lED3(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LED3;
}
const sc_integer prefixIface_get_cTRIANG(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_CTRIANG;
}
const sc_integer prefixIface_get_cCUADR(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_CCUADR;
}
const sc_integer prefixIface_get_cSENOID(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_CSENOID;
}
const sc_integer prefixIface_get_cFREC(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_CFREC;
}
const sc_integer prefixIface_get_cTENS(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_CTENS;
}
const sc_string prefixIface_get_msgEnTriang(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_MSGENTRIANG;
}
const sc_string prefixIface_get_msgEnCuad(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_MSGENCUAD;
}
const sc_string prefixIface_get_msgEnSen(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_MSGENSEN;
}
const sc_string prefixIface_get_msgMagFrec(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_MSGMAGFREC;
}
const sc_string prefixIface_get_msgMagTens(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_MSGMAGTENS;
}
const sc_string prefixIface_get_msgMagSubeFrec(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_MSGMAGSUBEFREC;
}
const sc_string prefixIface_get_msgMagBajaFrec(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_MSGMAGBAJAFREC;
}
const sc_string prefixIface_get_msgMagSubeTens(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_MSGMAGSUBETENS;
}
const sc_string prefixIface_get_msgMagBajaTens(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_MSGMAGBAJATENS;
}
const sc_boolean prefixIface_get_lED_ON(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LED_ON;
}
const sc_boolean prefixIface_get_lED_OFF(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LED_OFF;
}
const sc_integer prefixIface_get_tEC1(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_TEC1;
}
const sc_integer prefixIface_get_tEC2(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_TEC2;
}
const sc_integer prefixIface_get_tEC3(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_TEC3;
}
const sc_integer prefixIface_get_tEC4(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_TEC4;
}

/* implementations of all internal functions */

static sc_boolean prefix_check_TECX_DEBOUNCE_tr0_tr0(const Prefix* handle)
{
	return ((handle->iface.evTECXNoOprimido_raised) && (handle->internal.viDebounce == 0)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_TECX_DEBOUNCE_tr1_tr1(const Prefix* handle)
{
	return ((handle->iface.evTECXOprimido_raised) && (handle->internal.viDebounce == 0)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_TECX_DEBOUNCE_lr1_lr1(const Prefix* handle)
{
	return ((handle->iface.evTick_raised) && (handle->internal.viDebounce != 0)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_TECX_NO_OPRIMIDO_tr0_tr0(const Prefix* handle)
{
	return handle->iface.evTECXOprimido_raised;
}

static sc_boolean prefix_check_TECX_OPRIMIDO_tr0_tr0(const Prefix* handle)
{
	return handle->iface.evTECXNoOprimido_raised;
}

static sc_boolean prefix_check_Application_ESPERA_tr0_tr0(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_TEC4)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_Application_ESPERA_tr1_tr1(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_TEC3)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_Application_ESPERA_tr2_tr2(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_TEC2)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_Application_ESPERA_tr3_tr3(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_TEC1)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_forma_TRIANGULAR_tr0_tr0(const Prefix* handle)
{
	return handle->internal.evMode_raised;
}

static sc_boolean prefix_check_forma_CUADRADA_tr0_tr0(const Prefix* handle)
{
	return handle->internal.evMode_raised;
}

static sc_boolean prefix_check_forma_SENOIDAL_tr0_tr0(const Prefix* handle)
{
	return handle->internal.evMode_raised;
}

static sc_boolean prefix_check_magnitud_FRECUENCIA_tr0_tr0(const Prefix* handle)
{
	return handle->internal.evDown_raised;
}

static sc_boolean prefix_check_magnitud_FRECUENCIA_tr1_tr1(const Prefix* handle)
{
	return handle->internal.evUp_raised;
}

static sc_boolean prefix_check_magnitud_FRECUENCIA_tr2_tr2(const Prefix* handle)
{
	return handle->internal.evMagn_raised;
}

static sc_boolean prefix_check_magnitud_TENSION_tr0_tr0(const Prefix* handle)
{
	return handle->internal.evMagn_raised;
}

static sc_boolean prefix_check_magnitud_TENSION_tr1_tr1(const Prefix* handle)
{
	return handle->internal.evDown_raised;
}

static sc_boolean prefix_check_magnitud_TENSION_tr2_tr2(const Prefix* handle)
{
	return handle->internal.evUp_raised;
}

static void prefix_effect_TECX_DEBOUNCE_tr0(Prefix* handle)
{
	prefix_exseq_TECX_DEBOUNCE(handle);
	prefix_enseq_TECX_NO_OPRIMIDO_default(handle);
}

static void prefix_effect_TECX_DEBOUNCE_tr1(Prefix* handle)
{
	prefix_exseq_TECX_DEBOUNCE(handle);
	prefix_enseq_TECX_OPRIMIDO_default(handle);
}

static void prefix_effect_TECX_DEBOUNCE_lr1_lr1(Prefix* handle)
{
	handle->internal.viDebounce -= 1;
}

static void prefix_effect_TECX_NO_OPRIMIDO_tr0(Prefix* handle)
{
	prefix_exseq_TECX_NO_OPRIMIDO(handle);
	prefix_enseq_TECX_DEBOUNCE_default(handle);
}

static void prefix_effect_TECX_OPRIMIDO_tr0(Prefix* handle)
{
	prefix_exseq_TECX_OPRIMIDO(handle);
	prefix_enseq_TECX_NO_OPRIMIDO_default(handle);
}

static void prefix_effect_Application_ESPERA_tr0(Prefix* handle)
{
	prefix_exseq_Application_ESPERA(handle);
	prefixIface_opLEDToggle(handle, PREFIX_PREFIXIFACE_LED3);
	handle->internal.evDown_raised = bool_true;
	prefix_enseq_Application_ESPERA_default(handle);
}

static void prefix_effect_Application_ESPERA_tr1(Prefix* handle)
{
	prefix_exseq_Application_ESPERA(handle);
	prefixIface_opLEDToggle(handle, PREFIX_PREFIXIFACE_LED2);
	handle->internal.evUp_raised = bool_true;
	prefix_enseq_Application_ESPERA_default(handle);
}

static void prefix_effect_Application_ESPERA_tr2(Prefix* handle)
{
	prefix_exseq_Application_ESPERA(handle);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED2, PREFIX_PREFIXIFACE_LED_ON);
	handle->internal.evMagn_raised = bool_true;
	prefix_enseq_Application_ESPERA_default(handle);
}

static void prefix_effect_Application_ESPERA_tr3(Prefix* handle)
{
	prefix_exseq_Application_ESPERA(handle);
	handle->internal.evMode_raised = bool_true;
	prefix_enseq_Application_ESPERA_default(handle);
}

static void prefix_effect_forma_TRIANGULAR_tr0(Prefix* handle)
{
	prefix_exseq_forma_TRIANGULAR(handle);
	prefixIface_opSetMode(handle, PREFIX_PREFIXIFACE_CCUADR);
	prefix_enseq_forma_CUADRADA_default(handle);
}

static void prefix_effect_forma_CUADRADA_tr0(Prefix* handle)
{
	prefix_exseq_forma_CUADRADA(handle);
	prefixIface_opSetMode(handle, PREFIX_PREFIXIFACE_CSENOID);
	prefix_enseq_forma_SENOIDAL_default(handle);
}

static void prefix_effect_forma_SENOIDAL_tr0(Prefix* handle)
{
	prefix_exseq_forma_SENOIDAL(handle);
	prefixIface_opSetMode(handle, PREFIX_PREFIXIFACE_CTRIANG);
	prefix_enseq_forma_TRIANGULAR_default(handle);
}

static void prefix_effect_magnitud_FRECUENCIA_tr0(Prefix* handle)
{
	prefix_exseq_magnitud_FRECUENCIA(handle);
	prefixIface_opDecFrec(handle);
	prefixIface_opEnviarSerie(handle, PREFIX_PREFIXIFACE_MSGMAGBAJAFREC);
	prefix_enseq_magnitud_FRECUENCIA_default(handle);
}

static void prefix_effect_magnitud_FRECUENCIA_tr1(Prefix* handle)
{
	prefix_exseq_magnitud_FRECUENCIA(handle);
	prefixIface_opIncFrec(handle);
	prefixIface_opEnviarSerie(handle, PREFIX_PREFIXIFACE_MSGMAGSUBEFREC);
	prefix_enseq_magnitud_FRECUENCIA_default(handle);
}

static void prefix_effect_magnitud_FRECUENCIA_tr2(Prefix* handle)
{
	prefix_exseq_magnitud_FRECUENCIA(handle);
	prefixIface_opSetMagn(handle, PREFIX_PREFIXIFACE_CTENS);
	prefix_enseq_magnitud_TENSION_default(handle);
}

static void prefix_effect_magnitud_TENSION_tr0(Prefix* handle)
{
	prefix_exseq_magnitud_TENSION(handle);
	prefixIface_opSetMagn(handle, PREFIX_PREFIXIFACE_CFREC);
	prefix_enseq_magnitud_FRECUENCIA_default(handle);
}

static void prefix_effect_magnitud_TENSION_tr1(Prefix* handle)
{
	prefix_exseq_magnitud_TENSION(handle);
	prefixIface_opDecTens(handle);
	prefixIface_opEnviarSerie(handle, PREFIX_PREFIXIFACE_MSGMAGBAJATENS);
	prefix_enseq_magnitud_TENSION_default(handle);
}

static void prefix_effect_magnitud_TENSION_tr2(Prefix* handle)
{
	prefix_exseq_magnitud_TENSION(handle);
	prefixIface_opIncTens(handle);
	prefixIface_opEnviarSerie(handle, PREFIX_PREFIXIFACE_MSGMAGSUBETENS);
	prefix_enseq_magnitud_TENSION_default(handle);
}

/* Entry action for state 'DEBOUNCE'. */
static void prefix_enact_TECX_DEBOUNCE(Prefix* handle)
{
	/* Entry action for state 'DEBOUNCE'. */
	handle->internal.viDebounce = PREFIX_PREFIXINTERNAL_CI50MS;
}

/* Entry action for state 'OPRIMIDO'. */
static void prefix_enact_TECX_OPRIMIDO(Prefix* handle)
{
	/* Entry action for state 'OPRIMIDO'. */
	handle->internal.siTECXOK_raised = bool_true;
	handle->internal.viTecla = handle->iface.evTECXOprimido_value;
}

/* Entry action for state 'TRIANGULAR'. */
static void prefix_enact_forma_TRIANGULAR(Prefix* handle)
{
	/* Entry action for state 'TRIANGULAR'. */
	prefixIface_opEnviarSerie(handle, PREFIX_PREFIXIFACE_MSGENTRIANG);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDR, PREFIX_PREFIXIFACE_LED_ON);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDG, PREFIX_PREFIXIFACE_LED_OFF);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDB, PREFIX_PREFIXIFACE_LED_OFF);
}

/* Entry action for state 'CUADRADA'. */
static void prefix_enact_forma_CUADRADA(Prefix* handle)
{
	/* Entry action for state 'CUADRADA'. */
	prefixIface_opEnviarSerie(handle, PREFIX_PREFIXIFACE_MSGENCUAD);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDR, PREFIX_PREFIXIFACE_LED_OFF);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDG, PREFIX_PREFIXIFACE_LED_ON);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDB, PREFIX_PREFIXIFACE_LED_OFF);
}

/* Entry action for state 'SENOIDAL'. */
static void prefix_enact_forma_SENOIDAL(Prefix* handle)
{
	/* Entry action for state 'SENOIDAL'. */
	prefixIface_opEnviarSerie(handle, PREFIX_PREFIXIFACE_MSGENSEN);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDR, PREFIX_PREFIXIFACE_LED_OFF);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDG, PREFIX_PREFIXIFACE_LED_OFF);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDB, PREFIX_PREFIXIFACE_LED_ON);
}

/* Entry action for state 'FRECUENCIA'. */
static void prefix_enact_magnitud_FRECUENCIA(Prefix* handle)
{
	/* Entry action for state 'FRECUENCIA'. */
	prefixIface_opEnviarSerie(handle, PREFIX_PREFIXIFACE_MSGMAGFREC);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED1, PREFIX_PREFIXIFACE_LED_ON);
}

/* Entry action for state 'TENSION'. */
static void prefix_enact_magnitud_TENSION(Prefix* handle)
{
	/* Entry action for state 'TENSION'. */
	prefixIface_opEnviarSerie(handle, PREFIX_PREFIXIFACE_MSGMAGTENS);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED1, PREFIX_PREFIXIFACE_LED_OFF);
}

/* 'default' enter sequence for state DEBOUNCE */
static void prefix_enseq_TECX_DEBOUNCE_default(Prefix* handle)
{
	/* 'default' enter sequence for state DEBOUNCE */
	prefix_enact_TECX_DEBOUNCE(handle);
	handle->stateConfVector[0] = Prefix_TECX_DEBOUNCE;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state NO_OPRIMIDO */
static void prefix_enseq_TECX_NO_OPRIMIDO_default(Prefix* handle)
{
	/* 'default' enter sequence for state NO_OPRIMIDO */
	handle->stateConfVector[0] = Prefix_TECX_NO_OPRIMIDO;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state OPRIMIDO */
static void prefix_enseq_TECX_OPRIMIDO_default(Prefix* handle)
{
	/* 'default' enter sequence for state OPRIMIDO */
	prefix_enact_TECX_OPRIMIDO(handle);
	handle->stateConfVector[0] = Prefix_TECX_OPRIMIDO;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state ESPERA */
static void prefix_enseq_Application_ESPERA_default(Prefix* handle)
{
	/* 'default' enter sequence for state ESPERA */
	handle->stateConfVector[1] = Prefix_Application_ESPERA;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state TRIANGULAR */
static void prefix_enseq_forma_TRIANGULAR_default(Prefix* handle)
{
	/* 'default' enter sequence for state TRIANGULAR */
	prefix_enact_forma_TRIANGULAR(handle);
	handle->stateConfVector[2] = Prefix_forma_TRIANGULAR;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state CUADRADA */
static void prefix_enseq_forma_CUADRADA_default(Prefix* handle)
{
	/* 'default' enter sequence for state CUADRADA */
	prefix_enact_forma_CUADRADA(handle);
	handle->stateConfVector[2] = Prefix_forma_CUADRADA;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state SENOIDAL */
static void prefix_enseq_forma_SENOIDAL_default(Prefix* handle)
{
	/* 'default' enter sequence for state SENOIDAL */
	prefix_enact_forma_SENOIDAL(handle);
	handle->stateConfVector[2] = Prefix_forma_SENOIDAL;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state FRECUENCIA */
static void prefix_enseq_magnitud_FRECUENCIA_default(Prefix* handle)
{
	/* 'default' enter sequence for state FRECUENCIA */
	prefix_enact_magnitud_FRECUENCIA(handle);
	handle->stateConfVector[3] = Prefix_magnitud_FRECUENCIA;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state TENSION */
static void prefix_enseq_magnitud_TENSION_default(Prefix* handle)
{
	/* 'default' enter sequence for state TENSION */
	prefix_enact_magnitud_TENSION(handle);
	handle->stateConfVector[3] = Prefix_magnitud_TENSION;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for region TECX */
static void prefix_enseq_TECX_default(Prefix* handle)
{
	/* 'default' enter sequence for region TECX */
	prefix_react_TECX__entry_Default(handle);
}

/* 'default' enter sequence for region Application */
static void prefix_enseq_Application_default(Prefix* handle)
{
	/* 'default' enter sequence for region Application */
	prefix_react_Application__entry_Default(handle);
}

/* 'default' enter sequence for region forma */
static void prefix_enseq_forma_default(Prefix* handle)
{
	/* 'default' enter sequence for region forma */
	prefix_react_forma__entry_Default(handle);
}

/* 'default' enter sequence for region magnitud */
static void prefix_enseq_magnitud_default(Prefix* handle)
{
	/* 'default' enter sequence for region magnitud */
	prefix_react_magnitud__entry_Default(handle);
}

/* Default exit sequence for state DEBOUNCE */
static void prefix_exseq_TECX_DEBOUNCE(Prefix* handle)
{
	/* Default exit sequence for state DEBOUNCE */
	handle->stateConfVector[0] = Prefix_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state NO_OPRIMIDO */
static void prefix_exseq_TECX_NO_OPRIMIDO(Prefix* handle)
{
	/* Default exit sequence for state NO_OPRIMIDO */
	handle->stateConfVector[0] = Prefix_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state OPRIMIDO */
static void prefix_exseq_TECX_OPRIMIDO(Prefix* handle)
{
	/* Default exit sequence for state OPRIMIDO */
	handle->stateConfVector[0] = Prefix_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state ESPERA */
static void prefix_exseq_Application_ESPERA(Prefix* handle)
{
	/* Default exit sequence for state ESPERA */
	handle->stateConfVector[1] = Prefix_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for state TRIANGULAR */
static void prefix_exseq_forma_TRIANGULAR(Prefix* handle)
{
	/* Default exit sequence for state TRIANGULAR */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state CUADRADA */
static void prefix_exseq_forma_CUADRADA(Prefix* handle)
{
	/* Default exit sequence for state CUADRADA */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state SENOIDAL */
static void prefix_exseq_forma_SENOIDAL(Prefix* handle)
{
	/* Default exit sequence for state SENOIDAL */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state FRECUENCIA */
static void prefix_exseq_magnitud_FRECUENCIA(Prefix* handle)
{
	/* Default exit sequence for state FRECUENCIA */
	handle->stateConfVector[3] = Prefix_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state TENSION */
static void prefix_exseq_magnitud_TENSION(Prefix* handle)
{
	/* Default exit sequence for state TENSION */
	handle->stateConfVector[3] = Prefix_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for region TECX */
static void prefix_exseq_TECX(Prefix* handle)
{
	/* Default exit sequence for region TECX */
	/* Handle exit of all possible states (of prefix.TECX) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Prefix_TECX_DEBOUNCE :
		{
			prefix_exseq_TECX_DEBOUNCE(handle);
			break;
		}
		case Prefix_TECX_NO_OPRIMIDO :
		{
			prefix_exseq_TECX_NO_OPRIMIDO(handle);
			break;
		}
		case Prefix_TECX_OPRIMIDO :
		{
			prefix_exseq_TECX_OPRIMIDO(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region Application */
static void prefix_exseq_Application(Prefix* handle)
{
	/* Default exit sequence for region Application */
	/* Handle exit of all possible states (of prefix.Application) at position 1... */
	switch(handle->stateConfVector[ 1 ])
	{
		case Prefix_Application_ESPERA :
		{
			prefix_exseq_Application_ESPERA(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region forma */
static void prefix_exseq_forma(Prefix* handle)
{
	/* Default exit sequence for region forma */
	/* Handle exit of all possible states (of prefix.forma) at position 2... */
	switch(handle->stateConfVector[ 2 ])
	{
		case Prefix_forma_TRIANGULAR :
		{
			prefix_exseq_forma_TRIANGULAR(handle);
			break;
		}
		case Prefix_forma_CUADRADA :
		{
			prefix_exseq_forma_CUADRADA(handle);
			break;
		}
		case Prefix_forma_SENOIDAL :
		{
			prefix_exseq_forma_SENOIDAL(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region magnitud */
static void prefix_exseq_magnitud(Prefix* handle)
{
	/* Default exit sequence for region magnitud */
	/* Handle exit of all possible states (of prefix.magnitud) at position 3... */
	switch(handle->stateConfVector[ 3 ])
	{
		case Prefix_magnitud_FRECUENCIA :
		{
			prefix_exseq_magnitud_FRECUENCIA(handle);
			break;
		}
		case Prefix_magnitud_TENSION :
		{
			prefix_exseq_magnitud_TENSION(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state DEBOUNCE. */
static void prefix_react_TECX_DEBOUNCE(Prefix* handle)
{
	/* The reactions of state DEBOUNCE. */
	if (prefix_check_TECX_DEBOUNCE_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_TECX_DEBOUNCE_tr0(handle);
	}  else
	{
		if (prefix_check_TECX_DEBOUNCE_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_TECX_DEBOUNCE_tr1(handle);
		}  else
		{
			if (prefix_check_TECX_DEBOUNCE_lr1_lr1(handle) == bool_true)
			{ 
				prefix_effect_TECX_DEBOUNCE_lr1_lr1(handle);
			} 
		}
	}
}

/* The reactions of state NO_OPRIMIDO. */
static void prefix_react_TECX_NO_OPRIMIDO(Prefix* handle)
{
	/* The reactions of state NO_OPRIMIDO. */
	if (prefix_check_TECX_NO_OPRIMIDO_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_TECX_NO_OPRIMIDO_tr0(handle);
	} 
}

/* The reactions of state OPRIMIDO. */
static void prefix_react_TECX_OPRIMIDO(Prefix* handle)
{
	/* The reactions of state OPRIMIDO. */
	if (prefix_check_TECX_OPRIMIDO_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_TECX_OPRIMIDO_tr0(handle);
	} 
}

/* The reactions of state ESPERA. */
static void prefix_react_Application_ESPERA(Prefix* handle)
{
	/* The reactions of state ESPERA. */
	if (prefix_check_Application_ESPERA_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_Application_ESPERA_tr0(handle);
	}  else
	{
		if (prefix_check_Application_ESPERA_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_Application_ESPERA_tr1(handle);
		}  else
		{
			if (prefix_check_Application_ESPERA_tr2_tr2(handle) == bool_true)
			{ 
				prefix_effect_Application_ESPERA_tr2(handle);
			}  else
			{
				if (prefix_check_Application_ESPERA_tr3_tr3(handle) == bool_true)
				{ 
					prefix_effect_Application_ESPERA_tr3(handle);
				} 
			}
		}
	}
}

/* The reactions of state TRIANGULAR. */
static void prefix_react_forma_TRIANGULAR(Prefix* handle)
{
	/* The reactions of state TRIANGULAR. */
	if (prefix_check_forma_TRIANGULAR_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_forma_TRIANGULAR_tr0(handle);
	} 
}

/* The reactions of state CUADRADA. */
static void prefix_react_forma_CUADRADA(Prefix* handle)
{
	/* The reactions of state CUADRADA. */
	if (prefix_check_forma_CUADRADA_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_forma_CUADRADA_tr0(handle);
	} 
}

/* The reactions of state SENOIDAL. */
static void prefix_react_forma_SENOIDAL(Prefix* handle)
{
	/* The reactions of state SENOIDAL. */
	if (prefix_check_forma_SENOIDAL_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_forma_SENOIDAL_tr0(handle);
	} 
}

/* The reactions of state FRECUENCIA. */
static void prefix_react_magnitud_FRECUENCIA(Prefix* handle)
{
	/* The reactions of state FRECUENCIA. */
	if (prefix_check_magnitud_FRECUENCIA_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_magnitud_FRECUENCIA_tr0(handle);
	}  else
	{
		if (prefix_check_magnitud_FRECUENCIA_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_magnitud_FRECUENCIA_tr1(handle);
		}  else
		{
			if (prefix_check_magnitud_FRECUENCIA_tr2_tr2(handle) == bool_true)
			{ 
				prefix_effect_magnitud_FRECUENCIA_tr2(handle);
			} 
		}
	}
}

/* The reactions of state TENSION. */
static void prefix_react_magnitud_TENSION(Prefix* handle)
{
	/* The reactions of state TENSION. */
	if (prefix_check_magnitud_TENSION_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_magnitud_TENSION_tr0(handle);
	}  else
	{
		if (prefix_check_magnitud_TENSION_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_magnitud_TENSION_tr1(handle);
		}  else
		{
			if (prefix_check_magnitud_TENSION_tr2_tr2(handle) == bool_true)
			{ 
				prefix_effect_magnitud_TENSION_tr2(handle);
			} 
		}
	}
}

/* Default react sequence for initial entry  */
static void prefix_react_TECX__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_TECX_NO_OPRIMIDO_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_Application__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_Application_ESPERA_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_forma__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefixIface_opSetMode(handle, PREFIX_PREFIXIFACE_CTRIANG);
	prefix_enseq_forma_TRIANGULAR_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_magnitud__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefixIface_opSetMagn(handle, PREFIX_PREFIXIFACE_CFREC);
	prefix_enseq_magnitud_FRECUENCIA_default(handle);
}


