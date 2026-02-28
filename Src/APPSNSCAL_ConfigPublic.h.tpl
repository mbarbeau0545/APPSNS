/*********************************************************************
 * @file        APPSNSCAL_ConfigPublic.h
 * @brief       Sensor calibration configuration (public).
 * @note        Shared calibration types and generated calibration list.
 *
 * @author      xxxxxx
 * @date        jj/mm/yyyy
 * @version     1.0
 */
  
#ifndef APPSNSCAL_CONFIGPUBLIC_H_INCLUDED
#define APPSNSCAL_CONFIGPUBLIC_H_INCLUDED





    // ********************************************************************
    // *                      Includes
    // ********************************************************************
    #include "TypeCommon.h"
    #include "APP_CFG/ConfigFiles/APPSNS_ConfigPublic.h"
    // ********************************************************************
    // *                      Defines
    // ********************************************************************
    // ********************************************************************
    // *                      Types
    // ********************************************************************
    /* CAUTION : Automatic generated code section for Enum: Start */

    /* CAUTION : Automatic generated code section for Enum: End */
	
    //-----------------------------ENUM TYPES-----------------------------//
    typedef enum
    {
        APPSNSCAL_CALMODE_BYPASS = 0,       /**< Keep incoming value unchanged */
        APPSNSCAL_CALMODE_OFFSET_GAIN,      /**< Apply value = value * gain + offset */

        APPSNSCAL_CALMODE_NB
    } t_eAPPSNSCAL_CalibMode;

	/* CAUTION : Automatic generated code section for Structure: Start */

	/* CAUTION : Automatic generated code section for Structure: End */
	//-----------------------------STRUCT TYPES---------------------------//
    typedef struct
    {
        t_bool isEnable_b;
        t_eAPPSNSCAL_CalibMode mode_e;
        t_float32 gain_f32;
        t_float32 offset_f32;
    } t_sAPPSNSCAL_CalibCfg;
    
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

#endif // APPSNSCAL_CONFIGPUBLIC_H_INCLUDED           
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
