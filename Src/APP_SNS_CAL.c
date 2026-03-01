/*********************************************************************
 * @file        APP_SNS_CAL.c
 * @brief       Sensor calibration management module.
 * @note        Generic per-sensor offset/gain calibration.
 *
 * @author      xxxxxx
 * @date        jj/mm/yyyy
 * @version     1.0
 */





// ********************************************************************
// *                      Includes
// ********************************************************************
#include "TypeCommon.h"
#include "./APP_SNS_CAL.h"
#include "APP_CFG/ConfigFiles/APPSNSCAL_ConfigPrivate.h"
// ********************************************************************
// *                      Defines
// ********************************************************************

// ********************************************************************
// *                      Types
// ********************************************************************
/* CAUTION : Automatic generated code section for Enum: Start */

/* CAUTION : Automatic generated code section for Enum: End */
//-----------------------------ENUM TYPES-----------------------------//
///@brief Information about calibration
typedef struct 
{
    t_bool isEnable_b;
    const t_sAPPSNSCAL_CalibCfg * cfg_ps;
    t_float32 currOffset_f32;
    t_float32 currGain_f32;
} t_sAPPSNSCAL_CalibInfo;

/* CAUTION : Automatic generated code section for Structure: Start */

/* CAUTION : Automatic generated code section for Structure: End */
//-----------------------------STRUCT TYPES---------------------------//
/* CAUTION : Automatic generated code section : Start */

/* CAUTION : Automatic generated code section : End */
//-----------------------------TYPEDEF TYPES---------------------------//
// ********************************************************************
// *                      Prototypes
// ********************************************************************

// ********************************************************************
// *                      Variables
// ********************************************************************
static t_bool g_AppSnsCal_Initialized_b = FALSE;
static t_sAPPSNSCAL_CalibInfo g_AppSnsCal_Calib_as[APPSNS_SNSITF_NB];
/* CAUTION : Automatic generated code section for Variable: Start */
/* CAUTION : Automatic generated code section for Variable: End */
//********************************************************************************
//                      Local functions - Prototypes
//********************************************************************************

//****************************************************************************
//                      Public functions - Implementation
//********************************************************************************
/*********************************
 * APPSNSCAL_Init
 *********************************/
t_eReturnCode APPSNSCAL_Init(void)
{
    t_eReturnCode Ret_e = RC_OK;
    t_uint8 idxSnsIf_u8;

    if((sizeof(g_AppSnsCal_Calib_as) / sizeof(g_AppSnsCal_Calib_as[0])) != APPSNS_SNSITF_NB)
    {
        Ret_e = RC_ERROR_WRONG_CONFIG;
        ASSERT((t_uint16)APPSNS_SNSITF_NB);
    }

    if(Ret_e == RC_OK)
    {
        for(idxSnsIf_u8 = (t_uint8)0; idxSnsIf_u8 < (t_uint8)APPSNS_SNSITF_NB; idxSnsIf_u8++)
        {
            g_AppSnsCal_Calib_as[idxSnsIf_u8].cfg_ps = &c_AppSnsCal_CalibCfg_as[idxSnsIf_u8];

            g_AppSnsCal_Calib_as[idxSnsIf_u8].currGain_f32 = 
                g_AppSnsCal_Calib_as[idxSnsIf_u8].cfg_ps->gain_f32;
            g_AppSnsCal_Calib_as[idxSnsIf_u8].currOffset_f32 = 
                g_AppSnsCal_Calib_as[idxSnsIf_u8].cfg_ps->offset_f32;
        }

        g_AppSnsCal_Initialized_b = TRUE;
    }

    return Ret_e;
}
/*********************************
 * APPSNSCAL_Apply
 *********************************/
t_eReturnCode APPSNSCAL_Apply(t_eAPPSNS_SnsInterface f_sns_e,
                              t_float32 f_input_f32,
                              t_float32 *f_output_pf32)
{
    t_eReturnCode Ret_e;
    t_sAPPSNSCAL_CalibInfo * calibInfo_ps;

    if(f_output_pf32 == (t_float32 *)NULL)
    {
        Ret_e = RC_ERROR_PTR_NULL;
        ASSERT((t_uint16)0);
    }
    else if(g_AppSnsCal_Initialized_b == FALSE)
    {
        Ret_e = RC_ERROR_MODULE_NOT_INITIALIZED;
    }
    else if(f_sns_e >= APPSNS_SNSITF_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
        ASSERT((t_uint16)0);
    }
    else
    {
        Ret_e = RC_OK;
        calibInfo_ps = &g_AppSnsCal_Calib_as[f_sns_e];

        if((calibInfo_ps->cfg_ps->mode_e == APPSNSCAL_CALMODE_BYPASS)
        || (calibInfo_ps->isEnable_b == FALSE))
        {
            *f_output_pf32 = f_input_f32;
        }
        else if(calibInfo_ps->cfg_ps->mode_e == APPSNSCAL_CALMODE_OFFSET_GAIN)
        {
            *f_output_pf32 = (f_input_f32 * calibInfo_ps->currGain_f32) + calibInfo_ps->currOffset_f32;
        }
        else
        {
            *f_output_pf32 = f_input_f32;
            Ret_e = RC_WARNING_NOT_ALLOWED;
            ASSERT((t_uint16)calibInfo_ps->cfg_ps->mode_e);
        }
    }

    return Ret_e;
}
/*********************************
 * APPSNSCAL_SetCalib
 *********************************/
t_eReturnCode APPSNSCAL_SetCalib(t_eAPPSNS_SnsInterface f_sns_e,
                                 t_float32 f_offset_f32,
                                 t_float32 f_gain_f32)
{
    t_eReturnCode Ret_e;
    t_sAPPSNSCAL_CalibInfo * calibInfo_ps;
    t_uAPPSPM_PrmValType prmOffset_u;
    t_uAPPSPM_PrmValType prmGain_u;

    if(g_AppSnsCal_Initialized_b == FALSE)
    {
        Ret_e = RC_ERROR_MODULE_NOT_INITIALIZED;
        ASSERT((t_uint16)0);
    }
    else if(f_sns_e >= APPSNS_SNSITF_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
        ASSERT((t_uint16)0);
    }
    else if(g_AppSnsCal_Calib_as[f_sns_e].cfg_ps->mode_e != 
        APPSNSCAL_CALMODE_OFFSET_GAIN)
    {
        Ret_e = RC_ERROR_WRONG_CONFIG;
        ASSERT((t_uint16)0);
    }
    else 
    {
        Ret_e = RC_OK;
        calibInfo_ps = &g_AppSnsCal_Calib_as[f_sns_e];
        calibInfo_ps->currOffset_f32 = f_offset_f32;
        calibInfo_ps->currGain_f32 = f_gain_f32;

        //---- save param ----//
        if(calibInfo_ps->cfg_ps->prmOffsetID_e != APPSPM_PRM_NB)
        {
            prmOffset_u.prmVal_f32 = calibInfo_ps->currOffset_f32;
            Ret_e = APPSPM_SetParam(calibInfo_ps->cfg_ps->prmOffsetID_e, prmOffset_u);
        }
        if(Ret_e == RC_OK)
        {
            if(calibInfo_ps->cfg_ps->prmGainID_e != APPSPM_PRM_NB)
            {
                prmGain_u.prmVal_f32 = calibInfo_ps->currGain_f32;
                Ret_e = APPSPM_SetParam(calibInfo_ps->cfg_ps->prmGainID_e, prmGain_u);
            }
        }
    }

    return Ret_e;
}
/*********************************
 * APPSNSCAL_SetEnable
 *********************************/
t_eReturnCode APPSNSCAL_SetEnable(t_eAPPSNS_SnsInterface f_sns_e, t_bool f_enable_b)
{
    t_eReturnCode Ret_e;

    if(g_AppSnsCal_Initialized_b == FALSE)
    {
        Ret_e = RC_ERROR_MODULE_NOT_INITIALIZED;
    }
    else if(f_sns_e >= APPSNS_SNSITF_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
        ASSERT((t_uint16)0);
    }
    else if(g_AppSnsCal_Calib_as[f_sns_e].cfg_ps->mode_e >= 
            APPSNSCAL_CALMODE_NB)
    {
        Ret_e = RC_WARNING_NOT_ALLOWED;
    }
    else
    {
        Ret_e = RC_OK;
        g_AppSnsCal_Calib_as[f_sns_e].isEnable_b = f_enable_b;
    }
    return Ret_e;
}
/*********************************
 * APPSNSCAL_GetCalib
 *********************************/
 t_eReturnCode APPSNSCAL_GetCalib(  t_eAPPSNS_SnsInterface f_sns_e,
                                    t_eAPPSNSCAL_CalibMode * f_calibMode_pe,
                                    t_float32 * f_offset_pf32,
                                    t_float32 * f_gain_pf32)
{
    t_eReturnCode Ret_e;
    t_sAPPSNSCAL_CalibInfo * calibInfo_ps; 

    if((f_calibMode_pe == NULL)
    || (f_gain_pf32 == NULL)
    || (f_offset_pf32 == NULL))
    {
        Ret_e = RC_ERROR_PTR_NULL;
        ASSERT((t_uint16)0);
    }
    else if(g_AppSnsCal_Initialized_b == FALSE)
    {
        Ret_e = RC_ERROR_MODULE_NOT_INITIALIZED;
    }
    else if(f_sns_e >= APPSNS_SNSITF_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
        ASSERT((t_uint16)0);
    }
    else
    {
        Ret_e = RC_OK;
        calibInfo_ps = &g_AppSnsCal_Calib_as[f_sns_e];

        *f_calibMode_pe = calibInfo_ps->cfg_ps->mode_e;
        *f_offset_pf32 = calibInfo_ps->currOffset_f32;
        *f_gain_pf32 = calibInfo_ps->currGain_f32;
    }

    return Ret_e;
}
/*********************************
 * APPSNSCAL_RegisterZero
 *********************************/
t_eReturnCode APPSNSCAL_RegisterZero(t_eAPPSNS_SnsInterface f_sns_e,
                                     t_float32 f_measuredValue_f32)
{
    return APPSNSCAL_RegisterReference(f_sns_e, f_measuredValue_f32, 0.0F);
}
/*********************************
 * APPSNSCAL_RegisterReference
 *********************************/
t_eReturnCode APPSNSCAL_RegisterReference(t_eAPPSNS_SnsInterface f_sns_e,
                                          t_float32 f_measuredValue_f32,
                                          t_float32 f_expectedValue_f32)
{
    t_eReturnCode Ret_e;
    t_uAPPSPM_PrmValType prmOffset_u;
    t_sAPPSNSCAL_CalibInfo * calibInfo_ps;

    if(g_AppSnsCal_Initialized_b == FALSE)
    {
        Ret_e = RC_ERROR_MODULE_NOT_INITIALIZED;
    }
    else if(f_sns_e >= APPSNS_SNSITF_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
        ASSERT((t_uint16)0);
    }
    else if(g_AppSnsCal_Calib_as[f_sns_e].cfg_ps->mode_e != 
        APPSNSCAL_CALMODE_OFFSET_GAIN)
    {
        Ret_e = RC_ERROR_WRONG_CONFIG;
        ASSERT((t_uint16)0);
    }
    else
    {
        Ret_e = RC_OK;
        calibInfo_ps = &g_AppSnsCal_Calib_as[f_sns_e]; 
        calibInfo_ps->currOffset_f32 = f_expectedValue_f32 -
            (f_measuredValue_f32 * g_AppSnsCal_Calib_as[f_sns_e].currGain_f32);

        if(calibInfo_ps->cfg_ps->prmOffsetID_e != APPSPM_PRM_NB)
        {
            prmOffset_u.prmVal_f32 = calibInfo_ps->currOffset_f32;
            Ret_e = APPSPM_SetParam(calibInfo_ps->cfg_ps->prmOffsetID_e, prmOffset_u);
        }
    }

    return Ret_e;
}

/*********************************
 * APPSNSCAL_Load
 *********************************/
t_eReturnCode APPSNSCAL_Load(t_eAPPSNS_SnsInterface f_sns_e)
{
    t_eReturnCode Ret_e;
    t_sAPPSNSCAL_CalibInfo * calibInfo_ps;
    t_uAPPSPM_PrmValType prmOffset_u;
    t_uAPPSPM_PrmValType prmGain_u;

    if(g_AppSnsCal_Initialized_b == FALSE)
    {
        Ret_e = RC_ERROR_MODULE_NOT_INITIALIZED;
    }
    else if(f_sns_e >= APPSNS_SNSITF_NB)
    {
        Ret_e = RC_ERROR_PARAM_INVALID;
        ASSERT((t_uint16)0);
    }
    else
    {
        Ret_e = RC_OK;
        //---- get parameter ----//
        calibInfo_ps = &g_AppSnsCal_Calib_as[f_sns_e];
        if(calibInfo_ps->cfg_ps->prmOffsetID_e != APPSPM_PRM_NB)
        {
            prmOffset_u.prmVal_f32 = calibInfo_ps->currOffset_f32;
            Ret_e = APPSPM_GetParam(calibInfo_ps->cfg_ps->prmOffsetID_e, &prmOffset_u);
        }
        if(Ret_e == RC_OK)
        {
            if(calibInfo_ps->cfg_ps->prmGainID_e != APPSPM_PRM_NB)
            {
                prmGain_u.prmVal_f32 = calibInfo_ps->currGain_f32;
                Ret_e = APPSPM_GetParam(calibInfo_ps->cfg_ps->prmGainID_e, &prmGain_u);
            }
        }
        if(Ret_e == RC_OK)
        {
            calibInfo_ps->currGain_f32 = prmGain_u.prmVal_f32;
            calibInfo_ps->currOffset_f32 = prmOffset_u.prmVal_f32;
        }
    }

    return Ret_e;
}

//********************************************************************************
//                      Local functions - Implementation
//********************************************************************************