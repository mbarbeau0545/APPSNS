/*********************************************************************
 * @file        APP_SNS.c
 * @brief       Template_BriefDescription.
 * @note        TemplateDetailsDescription.\n
 *
 * @author      xxxxxx
 * @date        jj/mm/yyyy
 * @version     1.0
 */






// ********************************************************************
// *                      Includes
// ********************************************************************

#include "./APP_SNS.h"
#include "APP_CTRL/APP_SYS/Src/APP_SYS.h"
#include "Constant.h"
#include "APP_CFG/ConfigFiles/APPSNS_ConfigPrivate.h"
// ********************************************************************
// *                      Defines
// ********************************************************************

// ********************************************************************
// *                      Types
// ********************************************************************
/* CAUTION : Automatic generated code section for Enum: Start */

/* CAUTION : Automatic generated code section for Enum: End */
//-----------------------------ENUM TYPES-----------------------------//


/* CAUTION : Automatic generated code section for Structure: Start */

/* CAUTION : Automatic generated code section for Structure: End */
//-----------------------------STRUCT TYPES---------------------------//
/* CAUTION : Automatic generated code section : Start */

/* CAUTION : Automatic generated code section : End */
//-----------------------------TYPEDEF TYPES---------------------------//
typedef struct 
{
    t_eAPPSNS_SensorState state_e;      /**< State of the sensors */
    t_float32 snsValues_f32;            /**< For Debug Purpose */
    t_bool isConfigured_b;
} t_sAPPSNS_SnsInfo;
// ********************************************************************
// *                      Prototypes
// ********************************************************************
	
// ********************************************************************
// *                      Variables
// ********************************************************************
/* CAUTION : Automatic generated code section for Variable: Start */
/* CAUTION : Automatic generated code section for Variable: End */
static t_eCyclicModState g_AppSns_ModState_e = STATE_CYCLIC_CFG;
/**
 * @brief Sensors Information Cfg
 */
t_sAPPSNS_SnsInfo g_SnsInfo_as[APPSNS_SENSOR_NB];

/**< Variable for Sensors Drivers State*/
t_eAPPSNS_SensorState g_snsState_ae[APPSNS_SENSOR_NB];

/**< Variable for Sensors Drivers State*/
t_eAPPSNS_DrvState g_SnsDrvState_ae[APPSNS_DRIVER_NB];
//********************************************************************************
//                      Local functions - Prototypes
//********************************************************************************
/**
*
*	@brief
*	@note   
*
*
*	@param[in] 
*	@param[out]
*	 
*
*
*/
static t_eReturnCode s_AppSns_ConfigurationState(void);
/**
 *
 *	@brief      Perform preOperationnal action.\n
 *  @note       Set the sensor configuration.\n
 *              Call driver init function.\n
 *              If one of the configuration is not set the Module Cyclic 
 *              retry indefinitely.\n
 *              
 * 
 *  @retval RC_OK                             @ref RC_OK
 *  @retval RC_ERROR_PARAM_INVALID            @ref RC_ERROR_PARAM_INVALID
 *  @retval RC_ERROR_WRONG_STATE              @ref RC_ERROR_WRONG_STATE

 */
static t_eReturnCode s_APPSNS_Operational(void);
/**
*
*	@brief  Convert Management.\n
*   @note   If the sensors value requested is not a voltage, depending on 
            rqstedUnity_u this function called the right function to calculate the unity ask.\n
*   
*	@param[in] f_snsInfo_ps : Structure that contains all information.\n
*	 
*
*
*/
t_eReturnCode s_APPSNS_ConvertingManagement(t_eAPPSNS_Sensors f_sns_e, t_sAPPSNS_SnsValueInfo *f_snsInfo_ps);
/**
*
*	@brief  Convert Temperature Management
*
*	@param[in] f_unity_e : Temperature unity requested
*	@param[in] f_snsValueSI_s16 : Temperature value in SI unity
*	@param[in] f_SnsValue_f32 : Temperature value in f_unity_e unity
*	@param[out]
*	 
*
*
*/
static t_eReturnCode s_APPSNS_ConvertTemperature(t_eAPPSNS_TempUnity f_unity_e, 
                                                    t_sint16 f_snsValueSI_s16, 
                                                    t_float32 * f_snsValue_pf32);
/**
*
*	@brief  Convert Pressure Management
*
*	@param[in] f_unity_e : Pressure unity requested
*	@param[in] f_snsValueSI_s16 : Pressure value in SI unity
*	@param[in] f_SnsValue_f32 : Pressure value in f_unity_e unity
*	 
*
*
*/
static t_eReturnCode s_APPSNS_ConvertPressure(t_eAPPSNS_PressureUnity f_unity_e, 
                                                    t_sint16 f_snsValueSI_s16, 
                                                    t_float32 * f_snsValue_pf32);
/**
*
*	@brief  Convert Speed Management
*
*	@param[in] f_unity_e : Speed unity requested
*	@param[in] f_snsValueSI_s16 : Speed value in SI unity
*	@param[in] f_SnsValue_f32 : Speed value in f_unity_e unity
*	 
*
*
*/
static t_eReturnCode s_APPSNS_ConvertSpeed(t_eAPPSNS_SpeedUnity f_unity_e, 
                                                    t_sint16 f_snsValueSI_s16, 
                                                    t_float32 * f_snsValue_pf32);
/**
*
*	@brief  Convert Angular Speed Management
*
*	@param[in] f_unity_e : Angular Speed unity requested
*	@param[in] f_snsValueSI_s16 : Angular Speed value in SI unity
*	@param[in] f_SnsValue_f32 : Angular Speed value in f_unity_e unity
*	@param[out]
*	 
*
*
*/
static t_eReturnCode s_APPSNS_ConvertAngularSpeed(t_eAPPSNS_AngularSpdUnity f_unity_e, 
                                                    t_sint16 f_snsValueSI_s16, 
                                                    t_float32 * f_snsValue_pf32);

/**
*
*	@brief  Convert Angle Management
*
*	@param[in] f_unity_e : Speed unity requested
*	@param[in] f_snsValueSI_s16 : Speed value in SI unity
*	@param[in] f_SnsValue_f32 : Speed value in f_unity_e unity
*	@param[out]
*	 
*
*
*/
static t_eReturnCode s_APPSNS_ConvertAngle(t_eAPPSNS_AngleUnity f_unity_e, 
                                                    t_sint16 f_snsValueSI_s16, 
                                                    t_float32 * f_snsValue_pf32);
/**
*
*	@brief  Convert Distance Management
*
*	@param[in] f_unity_e : Distance unity requested
*	@param[in] f_snsValueSI_s16 : Distance value in SI unity
*	@param[in] f_SnsValue_f32 : Distance value in f_unity_e unity
*	@param[out]
*	 
*
*
*/
static t_eReturnCode s_APPSNS_ConvertDistance(t_eAPPSNS_DistanceUnity f_unity_e, 
                                                    t_sint16 f_snsValueSI_s16, 
                                                    t_float32 * f_snsValue_pf32);
/**
*
*	@brief  Convert Force Management
*
*	@param[in] f_unity_e : Force unity requested
*	@param[in] f_snsValueSI_s16 : Force value in SI unity
*	@param[in] f_SnsValue_f32 : Force value in f_unity_e unity
*	@param[out]
*	 
*
*
*/
static t_eReturnCode s_APPSNS_ConvertForce(t_eAPPSNS_ForceUnity f_unity_e, 
                                                    t_sint16 f_snsValueSI_s16, 
                                                    t_float32 * f_snsValue_pf32);
/**
*
*	@brief  Convert Flow Management
*
*	@param[in] f_unity_e : Flow unity requested
*	@param[in] f_snsValueSI_s16 : Flow value in SI unity
*	@param[in] f_SnsValue_f32 : Flow value in f_unity_e unity
*	@param[out]
*	 
*
*
*/
static t_eReturnCode s_APPSNS_ConvertFlow(t_eAPPSNS_FlowUnity f_unity_e, 
                                                    t_sint16 f_snsValueSI_s16, 
                                                    t_float32 * f_snsValue_pf32);
//****************************************************************************
//                      Public functions - Implementation
//********************************************************************************
/*********************************
 * APPSNS_Init
 *********************************/
t_eReturnCode APPSNS_Init(void)
{
    t_eReturnCode Ret_e = RC_OK;
    t_uint8 idxSns_u8;
    t_uint8 LLDRV_u8;


    // check sensors cfg
    for(idxSns_u8 = (t_uint8)0 ; (idxSns_u8 < APPSNS_SENSOR_NB) && (Ret_e == RC_OK) ; idxSns_u8++)
    {   
        if(c_AppSns_SysSns_apf[idxSns_u8].GetValue_pcb == (t_cbAppSns_GetSigValue *)NULL_FUNCTION
        || c_AppSns_SysSns_apf[idxSns_u8].SetCfg_pcb == (t_cbAppSns_SetSnsCfg *)NULL_FUNCTION
        || c_AppSns_SysSns_apf[idxSns_u8].FormatValSI_pcb == (t_cbAppSns_FormatValSI *)NULL_FUNCTION
        || c_AppSns_SysSns_apf[idxSns_u8].measTyp_e > APPSNS_MEASTYPE_NB)
        {
            Ret_e = RC_ERROR_PARAM_INVALID;
            ASSERT((t_uint16)idxSns_u8);
        }

        //---- set default value ----//
        g_SnsInfo_as[idxSns_u8].isConfigured_b = (t_bool)False;
        g_SnsInfo_as[idxSns_u8].snsValues_f32 = (t_float32)0.0f;
        g_SnsInfo_as[idxSns_u8].state_e = APPSNS_SENSOR_STATE_DISABLE;
    }
    //---- driver init -----//
    for(LLDRV_u8 = (t_uint8)0; (LLDRV_u8 < APPSNS_DRIVER_NB) && (Ret_e == RC_OK) ; LLDRV_u8++)
    {
        if(c_AppSns_SysDrv_apf[LLDRV_u8].Init_pcb != (t_cbAppSns_DrvInit *)NULL_FUNCTION)
        {
            Ret_e = (c_AppSns_SysDrv_apf[LLDRV_u8].Init_pcb)();
        }
    }

    return Ret_e;
}
/*********************************
 * APPSNS_Init
 *********************************/
t_eReturnCode APPSNS_Cyclic(void)
{
    t_eReturnCode Ret_e = RC_OK;

    switch (g_AppSns_ModState_e)
    {
    case STATE_CYCLIC_CFG:
    {
        Ret_e = s_AppSns_ConfigurationState();
        if(Ret_e == RC_OK)
        {
            g_AppSns_ModState_e = STATE_CYCLIC_WAITING;
        }
        break;
    }
    case STATE_CYCLIC_PREOPE:
    {
        g_AppSns_ModState_e = STATE_CYCLIC_OPE;
        break;
    }
    case STATE_CYCLIC_WAITING:
    {
        // nothing to do, just wait all module are Ope
        break;
    }
    case STATE_CYCLIC_OPE:
    {
        Ret_e = s_APPSNS_Operational();
        if(Ret_e < RC_OK)
        {
            g_AppSns_ModState_e = STATE_CYCLIC_ERROR;
        }
        break;
    }
    case STATE_CYCLIC_ERROR:
    {
        break;
    }
    case STATE_CYCLIC_BUSY:
    default:
        Ret_e = RC_OK;
        break;
    }
    return Ret_e;
}

/*********************************
 * APPSNS_GetState
 *********************************/
t_eReturnCode APPSNS_GetState(t_eCyclicModState *f_State_pe)
{
    t_eReturnCode Ret_e = RC_OK;
    
    if(f_State_pe == (t_eCyclicModState *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if(Ret_e == RC_OK)
    {
        *f_State_pe = g_AppSns_ModState_e;
    }
    return Ret_e;
}
/*********************************
 * APPSNS_GetState
 *********************************/
t_eReturnCode APPSNS_SetState(t_eCyclicModState f_State_e)
{
    g_AppSns_ModState_e = f_State_e;
    return RC_OK;
}

/*********************************
 * APPSNS_Get_SnsValue
 *********************************/
t_eReturnCode APPSNS_Get_SnsValue(t_eAPPSNS_Sensors f_Sns_e, t_sAPPSNS_SnsValueInfo *f_SnsInfo_ps)
{
    t_eReturnCode Ret_e = RC_OK;

    if(g_AppSns_ModState_e != STATE_CYCLIC_OPE)
    {
        Ret_e = RC_WARNING_BUSY;
    }
    if(f_SnsInfo_ps == (t_sAPPSNS_SnsValueInfo *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
        ASSERT((t_uint16)0);
    }
    if(f_Sns_e > APPSNS_SENSOR_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
        ASSERT((t_uint16)f_Sns_e);
    }
    if((Ret_e == RC_OK)
    && (g_SnsInfo_as[f_Sns_e].isConfigured_b == (t_bool)False))
    {
        Ret_e = RC_ERROR_MISSING_CONFIG;
        ASSERT((t_uint16)f_Sns_e);
    }
    if(Ret_e == RC_OK)
    {
        // call specific function to get value
        Ret_e = (c_AppSns_SysSns_apf[f_Sns_e].GetValue_pcb)(&f_SnsInfo_ps->rawValue_f32, &f_SnsInfo_ps->isValueOK_b);
        if(Ret_e == RC_OK)
        {
            Ret_e = s_APPSNS_ConvertingManagement(f_Sns_e, f_SnsInfo_ps);
        }
        else 
        {
            f_SnsInfo_ps->isValueOK_b = (t_bool)False;
            f_SnsInfo_ps->rawValue_f32 = (t_float32)0.0f;
            f_SnsInfo_ps->SnsValue_f32 = (t_float32)0.0f;
        }
        //---- for debug purpose ----//
        g_SnsInfo_as[f_Sns_e].snsValues_f32 = (t_float32)(f_SnsInfo_ps->SnsValue_f32);
    }

    return Ret_e;
}

//********************************************************************************
//                      Local functions - Implementation
//********************************************************************************
/*********************************
 * s_AppSns_ConfigurationState
 *********************************/
static t_eReturnCode s_AppSns_ConfigurationState(void)
{
    t_eReturnCode Ret_e = RC_OK;
    static t_uint8 s_LLSNS_u8 = 0;
    
    // sensors configuration call
    for(; (s_LLSNS_u8 < APPSNS_SENSOR_NB) && (Ret_e == RC_OK) ; s_LLSNS_u8++)
    {
        if(c_AppSns_SysSns_apf[s_LLSNS_u8].SetCfg_pcb != (t_cbAppSns_SetSnsCfg *)NULL_FUNCTION)
        {
            Ret_e = (c_AppSns_SysSns_apf[s_LLSNS_u8].SetCfg_pcb)();

            if(Ret_e == RC_OK)
            {
                g_SnsInfo_as[s_LLSNS_u8].isConfigured_b = (t_bool)True;
            }
        }
        else
        {
            Ret_e = RC_ERROR_PTR_NULL;
            ASSERT((t_uint16)s_LLSNS_u8);
        }
    }
    if(s_LLSNS_u8 < APPSNS_SENSOR_NB
    && Ret_e >= RC_OK) // only if problem has not been captured yet
    {// problem or waiting on init or sensors config just waiting for next cycle
        Ret_e = RC_WARNING_BUSY;
    }

    return Ret_e;
}
/*********************************
 * s_APPSNS_Operational
 *********************************/
static t_eReturnCode s_APPSNS_Operational(void)
{
    t_eReturnCode Ret_e = RC_OK;
    t_uint8 LLI_u8; 

    for(LLI_u8 = (t_uint8)0 ; (LLI_u8 < APPSNS_DRIVER_NB) && (Ret_e == RC_OK); LLI_u8++)
    {
        if(c_AppSns_SysDrv_apf[LLI_u8].Cyclic_pcb != (t_cbAppSns_DrvCyclic *)NULL_FUNCTION)
        {
            Ret_e = (c_AppSns_SysDrv_apf[LLI_u8].Cyclic_pcb)();
        }
    }

    return Ret_e;
}

/*********************************
 * s_APPSNS_ConvertingManagement
 *********************************/
t_eReturnCode s_APPSNS_ConvertingManagement(t_eAPPSNS_Sensors f_sns_e, t_sAPPSNS_SnsValueInfo *f_snsInfo_ps)
{
    t_eReturnCode Ret_e = RC_OK;

    Ret_e = c_AppSns_SysSns_apf[f_sns_e].FormatValSI_pcb(f_snsInfo_ps->rawValue_f32, &f_snsInfo_ps->SnsValue_f32);
    if(Ret_e == RC_OK)
    {
        switch(c_AppSns_SysSns_apf[f_sns_e].measTyp_e)
        {
            case APPSNS_MEASTYPE_RAW:
                f_snsInfo_ps->SnsValue_f32 = (t_float32)f_snsInfo_ps->rawValue_f32;
                Ret_e = RC_OK;
                break;
            case APPSNS_MEASTYPE_PRESSURE:
                Ret_e = s_APPSNS_ConvertPressure((t_eAPPSNS_PressureUnity)f_snsInfo_ps->rqstedUnity_u.PressureUnity_e,
                                                f_snsInfo_ps->rawValue_f32,
                                                &f_snsInfo_ps->SnsValue_f32);
                break;
            case APPSNS_MEASTYPE_TEMPERATURE:
                Ret_e = s_APPSNS_ConvertTemperature((t_eAPPSNS_TempUnity)f_snsInfo_ps->rqstedUnity_u.TempUnity_e,
                                                f_snsInfo_ps->rawValue_f32,
                                                &f_snsInfo_ps->SnsValue_f32);
                break;
            case APPSNS_MEASTYPE_SPEED:
                Ret_e = s_APPSNS_ConvertSpeed((t_eAPPSNS_SpeedUnity)f_snsInfo_ps->rqstedUnity_u.SpeedUnity_e,
                                                f_snsInfo_ps->rawValue_f32,
                                                &f_snsInfo_ps->SnsValue_f32);
                break;
            case APPSNS_MEASTYPE_ANGLE:
                Ret_e = s_APPSNS_ConvertAngle((t_eAPPSNS_AngleUnity)f_snsInfo_ps->rqstedUnity_u.AngleUnity_e,
                                                f_snsInfo_ps->rawValue_f32,
                                                &f_snsInfo_ps->SnsValue_f32);
                break;          
            case APPSNS_MEASTYPE_ANGULAR_SPD:
                Ret_e = s_APPSNS_ConvertAngularSpeed((t_eAPPSNS_AngularSpdUnity)f_snsInfo_ps->rqstedUnity_u.AngularSpdUnity_e,
                                                f_snsInfo_ps->rawValue_f32,
                                                &f_snsInfo_ps->SnsValue_f32);
            case APPSNS_MEASTYPE_DISTANCE:
                Ret_e = s_APPSNS_ConvertDistance((t_eAPPSNS_DistanceUnity)f_snsInfo_ps->rqstedUnity_u.DistanceUnity_e,
                                                f_snsInfo_ps->rawValue_f32,
                                                &f_snsInfo_ps->SnsValue_f32);
                break;
            case APPSNS_MEASTYPE_FORCE:
                Ret_e = s_APPSNS_ConvertForce((t_eAPPSNS_ForceUnity)f_snsInfo_ps->rqstedUnity_u.ForceUnity_e,
                                                f_snsInfo_ps->rawValue_f32,
                                                &f_snsInfo_ps->SnsValue_f32);
                break;
            case APPSNS_MEASTYPE_FLOW:
                Ret_e = s_APPSNS_ConvertFlow((t_eAPPSNS_FlowUnity)f_snsInfo_ps->rqstedUnity_u.FlowUnity_e,
                                                f_snsInfo_ps->rawValue_f32,
                                                &f_snsInfo_ps->SnsValue_f32);
                break;
            case APPSNS_MEASTYPE_NB:
            default:
                Ret_e = RC_ERROR_PARAM_INVALID;
                f_snsInfo_ps->SnsValue_f32 = (t_float32)f_snsInfo_ps->rawValue_f32;
        }
    }
    return Ret_e;
}

/*********************************
 * s_APPSNS_ConvertTemperature
 *********************************/
static t_eReturnCode s_APPSNS_ConvertTemperature(t_eAPPSNS_TempUnity f_unity_e, 
                                                    t_sint16 f_snsValueSI_s16, 
                                                    t_float32 * f_snsValue_pf32)
{
    t_eReturnCode Ret_e = RC_OK;

    if(f_unity_e > APPSNS_TEMP_UNIT_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(f_snsValue_pf32 == (t_float32 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if(Ret_e == RC_OK)
    {
        switch(f_unity_e)
        {
            case APPSNS_TEMP_UNIT_KELVIN:
                *f_snsValue_pf32 = (t_float32)(f_snsValueSI_s16);
                break;
            case APPSNS_TEMP_UNIT_CELSIUS:
                *f_snsValue_pf32 = (t_float32)((t_float32)f_snsValueSI_s16 - (t_float32)273.15); // temperature in degrees
                break;
            case APPSNS_TEMP_UNIT_FAHRENHEIT:
                *f_snsValue_pf32 = (t_float32)(((t_float32)f_snsValueSI_s16 - (t_float32)273.15)  // temperatur in fahrenheit
                                                            * (t_float32)1.8 + (t_float32)32.0);
                break;
            case APPSNS_TEMP_UNIT_NB:
            default:
                *f_snsValue_pf32 = (t_float32)(f_snsValueSI_s16);
                Ret_e = RC_WARNING_NOT_ALLOWED;
        }
    }
    return Ret_e;
}

/*********************************
 * s_APPSNS_ConvertFlow
 *********************************/
static t_eReturnCode s_APPSNS_ConvertFlow(t_eAPPSNS_FlowUnity f_unity_e, 
                                           t_sint16 f_snsValueSI_s16, 
                                           t_float32 * f_snsValue_pf32)
{
    t_eReturnCode Ret_e = RC_OK;

    if(f_unity_e > APPSNS_FLOW_UNIT_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(f_snsValue_pf32 == (t_float32 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if(Ret_e == RC_OK)
    {
        switch(f_unity_e)
        {
            case APPSNS_FLOW_UNIT_LPM:
                *f_snsValue_pf32 = (t_float32)(f_snsValueSI_s16); // Débit en L/min
                break;
            case APPSNS_FLOW_UNIT_M3PS:
                *f_snsValue_pf32 = (t_float32)(f_snsValueSI_s16 / 60000.0f); // Conversion de L/min en m³/s
                break;
            case APPSNS_FLOW_UNIT_GPM:
                *f_snsValue_pf32 = (t_float32)(f_snsValueSI_s16 * 0.264172f); // Conversion de L/min en GPM
                break;
            case APPSNS_FLOW_UNIT_NB:
            default:
                *f_snsValue_pf32 = (t_float32)(f_snsValueSI_s16);
                Ret_e = RC_WARNING_NOT_ALLOWED;
        }
    }
    return Ret_e;
}

/*********************************
 * s_APPSNS_ConvertForce
 *********************************/
static t_eReturnCode s_APPSNS_ConvertForce(t_eAPPSNS_ForceUnity f_unity_e, 
                                            t_sint16 f_snsValueSI_s16, 
                                            t_float32 * f_snsValue_pf32)
{
    t_eReturnCode Ret_e = RC_OK;

    if(f_unity_e > APPSNS_FORCE_UNIT_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(f_snsValue_pf32 == (t_float32 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if(Ret_e == RC_OK)
    {
        switch(f_unity_e)
        {
            case APPSNS_FORCE_UNIT_NEWTON:
                *f_snsValue_pf32 = (t_float32)(f_snsValueSI_s16); // Force en Newtons
                break;
            case APPSNS_FORCE_UNIT_DYNE:
                *f_snsValue_pf32 = (t_float32)(f_snsValueSI_s16 * 100000.0f); // Conversion de Newton en Dyne
                break;
            case APPSNS_FORCE_UNIT_POUND_FORCE:
                *f_snsValue_pf32 = (t_float32)(f_snsValueSI_s16 * 0.224809f); // Conversion de Newton en lbf
                break;
            case APPSNS_FORCE_UNIT_NB:
            default:
                *f_snsValue_pf32 = (t_float32)(f_snsValueSI_s16);
                Ret_e = RC_WARNING_NOT_ALLOWED;
        }
    }
    return Ret_e;
}

/*********************************
 * s_APPSNS_ConvertDistance
 *********************************/
static t_eReturnCode s_APPSNS_ConvertDistance(t_eAPPSNS_DistanceUnity f_unity_e, 
                                               t_sint16 f_snsValueSI_s16, 
                                               t_float32 * f_snsValue_pf32)
{
    t_eReturnCode Ret_e = RC_OK;

    if(f_unity_e > APPSNS_DISTANCE_UNIT_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(f_snsValue_pf32 == (t_float32 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if(Ret_e == RC_OK)
    {
        switch(f_unity_e)
        {
            case APPSNS_DISTANCE_UNIT_METER:
                *f_snsValue_pf32 = (t_float32)(f_snsValueSI_s16); // Distance en mètres
                break;
            case APPSNS_DISTANCE_UNIT_CENTIMETER:
                *f_snsValue_pf32 = (t_float32)(f_snsValueSI_s16 * 100.0f); // Conversion de mètres en cm
                break;
            case APPSNS_DISTANCE_UNIT_KILOMETER:
                *f_snsValue_pf32 = (t_float32)(f_snsValueSI_s16 / 1000.0f); // Conversion de mètres en km
                break;
            case APPSNS_DISTANCE_UNIT_MILE:
                *f_snsValue_pf32 = (t_float32)(f_snsValueSI_s16 * 0.000621371f); // Conversion de mètres en miles
                break;
            case APPSNS_DISTANCE_UNIT_NB:
            default:
                *f_snsValue_pf32 = (t_float32)(f_snsValueSI_s16);
                Ret_e = RC_WARNING_NOT_ALLOWED;
        }
    }
    return Ret_e;
}

/*********************************
 * s_APPSNS_ConvertAngle
 *********************************/
static t_eReturnCode s_APPSNS_ConvertAngle(t_eAPPSNS_AngleUnity f_unity_e, 
                                            t_sint16 f_snsValueSI_s16, 
                                            t_float32 * f_snsValue_pf32)
{
    t_eReturnCode Ret_e = RC_OK;

    if(f_unity_e >= APPSNS_ANGLE_UNIT_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(f_snsValue_pf32 == (t_float32 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if(Ret_e == RC_OK)
    {
        switch(f_unity_e)
        {
            case APPSNS_ANGLE_UNIT_RADIAN:
                *f_snsValue_pf32 = (t_float32)(f_snsValueSI_s16); // Angle en radians
                break;
            case APPSNS_ANGLE_UNIT_DEGREE:
                *f_snsValue_pf32 = (t_float32)(f_snsValueSI_s16) * 57.2958f; // Conversion de radians en degrés
                break;
            case APPSNS_ANGLE_UNIT_NB:
            default:
                *f_snsValue_pf32 = (t_float32)(f_snsValueSI_s16);
                Ret_e = RC_WARNING_NOT_ALLOWED;
        }
    }
    return Ret_e;
}


/*********************************
 * s_APPSNS_ConvertPressure
 *********************************/
static t_eReturnCode s_APPSNS_ConvertPressure(t_eAPPSNS_PressureUnity f_unity_e, 
                                               t_sint16 f_snsValueSI_s16, 
                                               t_float32 * f_snsValue_pf32)
{
    t_eReturnCode Ret_e = RC_OK;

    if(f_unity_e > APPSNS_PRESSURE_UNIT_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(f_snsValue_pf32 == (t_float32 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if(Ret_e == RC_OK)
    {
        switch(f_unity_e)
        {
            case APPSNS_PRESSURE_UNIT_PASCAL:
                *f_snsValue_pf32 = (t_float32)(f_snsValueSI_s16); // Pression en Pa
                break;
            case APPSNS_PRESSURE_UNIT_BAR:
                *f_snsValue_pf32 = (t_float32)(f_snsValueSI_s16) * 0.00001f; // Conversion de Pa en bar
                break;
            case APPSNS_PRESSURE_UNIT_PSI:
                *f_snsValue_pf32 = (t_float32)(f_snsValueSI_s16) * 0.000145038f; // Conversion de Pa en psi
                break;
            case APPSNS_PRESSURE_UNIT_NB:
            default:
                *f_snsValue_pf32 = (t_float32)(f_snsValueSI_s16);
                Ret_e = RC_WARNING_NOT_ALLOWED;
        }
    }
    return Ret_e;
}

/*********************************
 * s_APPSNS_ConvertSpeed
 *********************************/
static t_eReturnCode s_APPSNS_ConvertSpeed(t_eAPPSNS_SpeedUnity f_unity_e, 
                                            t_sint16 f_snsValueSI_s16, 
                                            t_float32 * f_snsValue_pf32)
{
    t_eReturnCode Ret_e = RC_OK;

    if(f_unity_e >= APPSNS_SPEED_UNIT_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if(f_snsValue_pf32 == (t_float32 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if(Ret_e == RC_OK)
    {
        switch(f_unity_e)
        {
            case APPSNS_SPEED_UNIT_METER_PER_SEC:
                *f_snsValue_pf32 = (t_float32)(f_snsValueSI_s16); // Vitesse en m/s
                break;
            case APPSNS_SPEED_UNIT_KM_PER_HOUR:
                *f_snsValue_pf32 = (t_float32)(f_snsValueSI_s16) * 3.6f; // Conversion de m/s en km/h
                break;
            case APPSNS_SPEED_UNIT_MILES_PER_HOUR:
                *f_snsValue_pf32 = (t_float32)(f_snsValueSI_s16) * 2.23694f; // Conversion de m/s en mph
                break;
            case APPSNS_SPEED_UNIT_NB:
            default:
                *f_snsValue_pf32 = (t_float32)(f_snsValueSI_s16);
                Ret_e = RC_WARNING_NOT_ALLOWED;
        }
    }
    return Ret_e;
}

/*********************************
 * s_APPSNS_ConvertAngularSpeed
 *********************************/
static t_eReturnCode s_APPSNS_ConvertAngularSpeed(t_eAPPSNS_AngularSpdUnity f_unity_e, 
                                                   t_sint16 f_snsValueSI_s16, 
                                                   t_float32 * f_snsValue_pf32)
{
    t_eReturnCode Ret_e = RC_OK;

    if (f_unity_e >= APPSNS_ANGULARSPD_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
    }
    if (f_snsValue_pf32 == (t_float32 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
    }
    if (Ret_e == RC_OK)
    {
        switch (f_unity_e)
        {
            case APPSNS_ANGULARSPD_RADIAN_PER_SEC:
                *f_snsValue_pf32 = (t_float32)f_snsValueSI_s16;
                break;

            case APPSNS_ANGULARSPD_DEGREE_PER_SEC:
                *f_snsValue_pf32 = (t_float32)f_snsValueSI_s16 * (t_float32)(180.0 / M_PI);
                break;

            case APPSNS_ANGULARSPD_ROUND_PER_MIN:
                *f_snsValue_pf32 = (t_float32)f_snsValueSI_s16 * (t_float32)(60.0 / (2.0 * M_PI));
                break;

            case APPSNS_ANGULARSPD_ROUND_PER_SEC:
                *f_snsValue_pf32 = (t_float32)f_snsValueSI_s16 / (t_float32)(2.0 * M_PI);
                break;

            case APPSNS_ANGULARSPD_DEGREE_PER_MIN:
                *f_snsValue_pf32 = (t_float32)f_snsValueSI_s16 * (t_float32)(180.0 * 60.0 / M_PI);
                break;

            case APPSNS_ANGULARSPD_NB:
            default:
                *f_snsValue_pf32 = (t_float32)f_snsValueSI_s16;
                Ret_e = RC_WARNING_NOT_ALLOWED;
        }
    }
    return Ret_e;
}


//************************************************************************************
// End of File
//************************************************************************************

/**
 *
 *	@brief
 *	@note   
 *
 *
 *	@params[in] 
 *	@params[out]
 *	 
 *
 *
 */

