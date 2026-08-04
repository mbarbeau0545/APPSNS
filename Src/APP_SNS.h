/*********************************************************************
 * @file        APP_SNS.h
 * @brief       Template_BriefDescription.
 * @note        TemplateDetailsDescription.\n
 *
 * @author      xxxxxx
 * @date        jj/mm/yyyy
 * @version     1.0
 */
  
#ifndef APP_SNS_H_INCLUDED
#define APP_SNS_H_INCLUDED





    // ********************************************************************
    // *                      Includes
    // ********************************************************************
    #include "TypeCommon.h"
    #include "./APP_SNS_CAL.h"
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
    t_eReturnCode APPSNS_Init(void);
    /**
    *
    *	@brief      Perform all Cyclic action for this module.\n
    *   @note       In preOpe mode -> If one of the configuration is not set the Module Cyclic 
    *               retry indefinitely and the module state doesn't change until all 
    *               sensors configuration are set
    *               In Ope mode -> call driver cyclic
    *
    */
    t_eReturnCode APPSNS_Cyclic(void);
    /**
    *
    *	@brief Function to know the module state.\n 
    *
    *	@param[out] f_State_pe : destination for the current module state.
    *
    *   @retval RC_OK                             @ref RC_OK
    *   @retval RC_ERROR_PTR_NULL                 @ref RC_ERROR_PTR_NUL
    */
    t_eReturnCode APPSNS_GetState(t_eCyclicModState *f_State_pe);
    /**
    *
    *	@brief Function to update the module state.\n
    *
    *	@param[in]  f_State_e : the new value, value from @ref t_eCyclicModState
    *
    *   @retval RC_OK                             @ref RC_OK
    */
    t_eReturnCode APPSNS_SetState(t_eCyclicModState f_State_e);
    /**
    *
    *	@brief  Get sensor value 
    *
    *	@param[in]  f_Sns_e : sensor interface identifier.
    *	@param[out] f_SnsValue_ps16 : destination for the sensor value and status.
    * 
    */
    t_eReturnCode APPSNS_Get_SnsValue(t_eAPPSNS_SnsInterface f_Sns_e, t_sAPPSNS_SnsValueInfo *f_SnsValue_ps16);

#endif // APP_SNS_H_INCLUDED           
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
