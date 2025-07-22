/*********************************************************************
 * @file        APPSNS_ConfigPublic.h
 * @brief       Template_BriefDescription.
 * @note        TemplateDetailsDescription.\n
 *
 * @author      xxxxxx
 * @date        jj/mm/yyyy
 * @version     1.0
 */
  
#ifndef APPSNS_CONFIGPUBLIC_H_INCLUDED
#define APPSNS_CONFIGPUBLIC_H_INCLUDED





    // ********************************************************************
    // *                      Includes
    // ********************************************************************
    #include "TypeCommon.h"
    // ********************************************************************
    // *                      Defines
    // ********************************************************************
    #define APPSNS_LIM_SWCH_NC_CONTACT ((t_uint8)0)
    #define APPSNS_LIM_SWCH_NC_NO_CONTACT ((t_uint8)1)
    // ********************************************************************
    // *                      Types
    // ********************************************************************
    /* CAUTION : Automatic generated code section for Enum: Start */
    /**
    * @brief Enum for Sensors list.
    */
    typedef enum
    {
    
        APPSNS_SENSOR_NB,
    } t_eAPPSNS_Sensors;

    /**
    * @brief Enum for Sensors drivers list.
    */
    typedef enum
    {
    
        APPSNS_DRIVER_NB,
    } t_eAPPSNS_Drivers;

    /**
    * @brief Enum for sensor conversion list.
    */
    typedef enum
    {
        APPSNS_MEASTYPE_RAW = 0x0,                /**< Raw value is not changed */
        APPSNS_MEASTYPE_PRESSURE,                 /**< Sensor value converted to angle in radians */
        APPSNS_MEASTYPE_TEMPERATURE,              /**< Sensor value converted to angle in degrees */
        APPSNS_MEASTYPE_SPEED,                    /**< Sensor value converted to distance in meters */
        APPSNS_MEASTYPE_ANGLE,                    /**< Sensor value converted to distance in millimeters */
        APPSNS_MEASTYPE_DISTANCE,                 /**< Sensor value converted to temperature in Celsius */
        APPSNS_MEASTYPE_FORCE,                    /**< Sensor value converted to temperature in Fahrenheit */
        APPSNS_MEASTYPE_FLOW,                     /**< Sensor value converted to pressure in pascals */
        APPSNS_MEASTYPE_ANGULAR_SPD,              /**< Sensor value converted to pressure in bars */
    
        APPSNS_MEASTYPE_NB,
    } t_eAPPSNS_SnsMeasType;

    /* CAUTION : Automatic generated code section for Enum: End */
	
    //-----------------------------ENUM TYPES-----------------------------//
    /**< Conversion type for temperature */
    typedef enum
    {
        APPSNS_TEMP_UNIT_KELVIN = 0x00,  /**< Temperature convert into degree kelvin */   
        APPSNS_TEMP_UNIT_CELSIUS,        /**< Temperature convert into degree celsius */
        APPSNS_TEMP_UNIT_FAHRENHEIT,    /**< Temperature convert into degree Fahrenheit */

        APPSNS_TEMP_UNIT_NB
    } t_eAPPSNS_TempUnity;

    /**< Conversion type for pressure */
    typedef enum
    {
        APPSNS_PRESSURE_UNIT_PASCAL = 0x00,     /**< Pressure in Pascals (Pa) */
        APPSNS_PRESSURE_UNIT_BAR,               /**< Pressure in Bar */
        APPSNS_PRESSURE_UNIT_PSI,               /**< Pressure in Pounds per Square Inch (psi) */

        APPSNS_PRESSURE_UNIT_NB
    } t_eAPPSNS_PressureUnity;

    /**< Conversion type for speed */
    typedef enum
    {
        APPSNS_SPEED_UNIT_METER_PER_SEC = 0x00,           /**< Speed in Meters per Second (m/s) */
        APPSNS_SPEED_UNIT_KM_PER_HOUR,                 /**< Speed in Kilometers per Hour (km/h) */
        APPSNS_SPEED_UNIT_MILES_PER_HOUR,                  /**< Speed in Miles per Hour (mph) */

        APPSNS_SPEED_UNIT_NB
    } t_eAPPSNS_SpeedUnity;

    typedef enum
    {
        APPSNS_ANGULARSPD_RADIAN_PER_SEC = 0x00,           /**< Angular Speed in radian per second*/
        APPSNS_ANGULARSPD_DEGREE_PER_SEC,                  /**< Angular Speed in Degree per second*/
        APPSNS_ANGULARSPD_ROUND_PER_MIN,                   /**< Angular Speed in Round per minute*/
        APPSNS_ANGULARSPD_ROUND_PER_SEC,                   /**< Angular Speed in Round per second*/
        APPSNS_ANGULARSPD_DEGREE_PER_MIN,                  /**< Angular Speed in degree per minute*/
        
        APPSNS_ANGULARSPD_NB
    } t_eAPPSNS_AngularSpdUnity;

    /**< Conversion type for Angle */
    typedef enum
    {
        APPSNS_ANGLE_UNIT_RADIAN = 0x00,               /**< Angle in Radians (rad) */
        APPSNS_ANGLE_UNIT_DEGREE,        /**< Angle in Degrees (°) */
        APPSNS_ANGLE_UNIT_GRAD,                 /**< Angle in Gradians (gon) */

        APPSNS_ANGLE_UNIT_NB
    } t_eAPPSNS_AngleUnity;

    /**< Conversion type for distance */
    typedef enum
    {
        APPSNS_DISTANCE_UNIT_METER = 0x00,      /**< Distance in Meters (m) */
        APPSNS_DISTANCE_UNIT_CENTIMETER,        /**< Distance in Centimeters (cm) */
        APPSNS_DISTANCE_UNIT_KILOMETER,         /**< Distance in Kilometers (km) */
        APPSNS_DISTANCE_UNIT_MILE,              /**< Distance in Miles (mi) */

        APPSNS_DISTANCE_UNIT_NB
    } t_eAPPSNS_DistanceUnity;

    /**< Conversion type for Force */
    typedef enum
    {
        APPSNS_FORCE_UNIT_NEWTON = 0x00,        /**< Force in Newtons (N) */
        APPSNS_FORCE_UNIT_DYNE,                 /**< Force in Dynes */
        APPSNS_FORCE_UNIT_POUND_FORCE,          /**< Force in Pound-force (lbf) */

        APPSNS_FORCE_UNIT_NB
    } t_eAPPSNS_ForceUnity;

    /**< Conversion type for flow */
    typedef enum
    {
        APPSNS_FLOW_UNIT_LPM = 0x00,            /**< Flow in Liters per Minute (L/min) */
        APPSNS_FLOW_UNIT_M3PS,                  /**< Flow in Cubic Meters per Second (m³/s) */
        APPSNS_FLOW_UNIT_GPM,                   /**< Flow in Gallons per Minute (GPM) */

        APPSNS_FLOW_UNIT_NB
    } t_eAPPSNS_FlowUnity;


    typedef enum 
    {
        APPSNS_SENSOR_STATE_DISABLE = 0,          /**< The sensor is unused in a system configuration */
        APPSNS_SENSOR_STATE_ENABLE,               /**< The sensor is used in a system configuration */
        APPSNS_SENSOR_STATE_NB                    /**< Number of sensor state */
    } t_eAPPSNS_SensorState;

    typedef enum 
    {
        APPSNS_DRIVER_STATE_DISABLE = 0,          /**< The driver is unused in a system configuration */
        APPSNS_DRIVER_STATE_ENABLE,                /**< The driver is used in a system configuration */
        APPSNS_DRIVER_STATE_NB,                    /**< Number of driver state */
    } t_eAPPSNS_DrvState;
	/* CAUTION : Automatic generated code section for Structure: Start */

	/* CAUTION : Automatic generated code section for Structure: End */
    /**< Union to store the idx for convert management */
    typedef union
    {
        t_eAPPSNS_TempUnity         TempUnity_e;
        t_eAPPSNS_PressureUnity     PressureUnity_e;
        t_eAPPSNS_SpeedUnity        SpeedUnity_e;
        t_eAPPSNS_AngleUnity        AngleUnity_e;
        t_eAPPSNS_DistanceUnity     DistanceUnity_e;
        t_eAPPSNS_ForceUnity        ForceUnity_e;
        t_eAPPSNS_FlowUnity         FlowUnity_e;
        t_eAPPSNS_AngularSpdUnity   AngularSpdUnity_e;
    } t_uAPPSNS_ReqestedUnity;
	//-----------------------------STRUCT TYPES---------------------------//
    typedef struct 
    {
        t_uAPPSNS_ReqestedUnity rqstedUnity_u;      /**< The unity ask for a sensors */
        t_float32 rawValue_f32;      /**< Store the sensor rawValue */
        t_float32 SnsValue_f32;      /**< Store the sensor after conversion */
        t_bool   isValueOK_b;       /**< Store flag value validity */
    } t_sAPPSNS_SnsValueInfo;
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

#endif // APPSNS_CONFIGPUBLIC_H_INCLUDED           
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
