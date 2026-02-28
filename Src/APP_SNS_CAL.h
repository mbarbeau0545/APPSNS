/*********************************************************************
 * @file        APP_SNS_CAL.h
 * @brief       Sensor calibration management module.
 * @note        Provide generic offset/gain calibration per sensor interface.
 *
 * @author      xxxxxx
 * @date        jj/mm/yyyy
 * @version     1.0
 */
  
#ifndef APP_SNS_CAL_H_INCLUDED
#define APP_SNS_CAL_H_INCLUDED





    // ********************************************************************
    // *                      Includes
    // ********************************************************************
    #include "TypeCommon.h"
    #include "APP_CFG/ConfigFiles/APPSNS_ConfigPublic.h"
    #include "APP_CFG/ConfigFiles/APPSNSCAL_ConfigPublic.h"
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
    // ********************************************************************
    // *                      Prototypes
    // ********************************************************************
        
    // ********************************************************************
    // *                      Variables
    // ********************************************************************

    //********************************************************************************
    //                      Public functions - Prototyupes
    //********************************************************************************
    /**
    *
    *	@brief      Perform all Init action for this module.\n
    *
    */
    t_eReturnCode APPSNSCAL_Init(void);
    /**
    *
    *	@brief      Apply calibration to a sensor value.\n
    *
    *	@param[in]  f_sns_e       : sensor interface.
    *	@param[in]  f_input_f32   : value before calibration.
    *	@param[out] f_output_pf32 : value after calibration.
    *
    */
    t_eReturnCode APPSNSCAL_Apply( t_eAPPSNS_SnsInterface f_sns_e,
                                   t_float32 f_input_f32,
                                   t_float32 *f_output_pf32);
    /**
    *
    *	@brief      Set complete offset/gain calibration.
    *
    */
    t_eReturnCode APPSNSCAL_SetCalib( t_eAPPSNS_SnsInterface f_sns_e,
                                      t_float32 f_offset_f32,
                                      t_float32 f_gain_f32);
    /**
    *
    *	@brief      Enable/Disable calibration for a sensor.
    *
    */
    t_eReturnCode APPSNSCAL_SetEnable(t_eAPPSNS_SnsInterface f_sns_e, t_bool f_enable_b);
    /**
    *
    *	@brief      Get current calibration for a sensor.
    *
    */
    t_eReturnCode APPSNSCAL_GetCalib(   t_eAPPSNS_SnsInterface f_sns_e,
                                        t_eAPPSNSCAL_CalibMode * f_calibMode_pe,
                                        t_float32 * f_offset_pf32,
                                        t_float32 * f_gain_pf32);
    /**
    *
    *	@brief      Register measured value as zero reference.
    *   @note       Equivalent to expected value = 0.
    *
    */
    t_eReturnCode APPSNSCAL_RegisterZero(t_eAPPSNS_SnsInterface f_sns_e,
                                         t_float32 f_measuredValue_f32);
    /**
    *
    *	@brief      Register one reference point to update offset.
    *   @note       offset <- expected - (measured * gain).
    *
    */
    t_eReturnCode APPSNSCAL_RegisterReference( t_eAPPSNS_SnsInterface f_sns_e,
                                               t_float32 f_measuredValue_f32,
                                               t_float32 f_expectedValue_f32);
    /**
    *
    *	@brief      Load calibration values from persistent storage.
    *   @note       Stub for future APPSPM/EEPROM binding.
    *
    */
    t_eReturnCode APPSNSCAL_Load(t_eAPPSNS_SnsInterface f_sns_e);

#endif // APP_SNS_CAL_H_INCLUDED           
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
