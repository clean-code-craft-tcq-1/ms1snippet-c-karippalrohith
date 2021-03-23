/* ******************************************************************************
 ***
 ***     \file        Checker.c
 ***     \ingroup     Session2-TCQ
 ***     \author      Rohith K N
 ***
 ***     \brief       Main file to check BMS
 ***
 ***     \par         File_description
 ***                  This file explores more about functions
 ***
 *****************************************************************************/
 
/*=============================================================================
 =======                            INCLUDES                             =======
 ============================================================================*/
/*------ standard includes -------*/
#include <cstddef>

/*------ module includes --------*/
#include "sensor-validate.h"

/*=============================================================================
 =======               DEFINES & MACROS FOR GENERAL PURPOSE              =======
 =============================================================================*/

/*=============================================================================
 =======                       CONSTANTS  &  TYPES                       =======
 =============================================================================*/

/*=============================================================================
 =======                VARIABLES & MESSAGES & RESSOURCEN                =======
 ==============================================================================*/

/*=============================================================================
 =======                              METHODS                            =======
 =============================================================================*/


parameter_Deviation_t validate_Deviation_In_Consecutive_Parameter_Values(double value, double nextValue, double maxDelta) 
{
  
  if((nextValue - value) > maxDelta) /*Check if deviation is greater than threshold*/
  {
    return DEVIATION_IN_PARAMETER_VALUE;
  }
  return NO_DEVIATION_IN_PARAMETER_VALUE;
}

parameter_Values_Validity_t validate_Parameter_Status(parameter_Deviation_t parameter_Deviation_Check,parameter_Values_Validity_t retVal)
{
	parameter_Values_Validity_t retVal_r;
	retVal_r = (parameter_Deviation_Check == DEVIATION_IN_PARAMETER_VALUE)?INVALID_PARAMETER_VALUES:VALID_PARAMETER_VALUES;
	retVal_r = retVal_r & retVal;
	
	return retVal_r;
}

/*---------------------------------------------------------------------------*/
/*     FUNCTION: validateParameter_Readings
 */
/*!    \brief   Function to validate the parameters
 *
 *
 *     \param    	paramValues -> Sensor values for the respective parameter
					numOfValues -> Number of samples
					deviationThreshold -> the threshold for which sensor value can vary wrt to the previous value
 *     \returns  	void
 *
 *//*------------------------------------------------------------------------*/
parameter_Values_Validity_t validateParameter_Readings(double* paramValues, int numOfValues, double deviationThreshold) 
{
	
  int lastButOneIndex = numOfValues - 1;
  parameter_Deviation_t parameter_Deviation_Check;
  parameter_Values_Validity_t retVal = 0;
  parameter_Values_Validity_t parameter_Values_Validity_Status = VALID_PARAMETER_VALUES;
  
	if(NULL == paramValues)
	{
		return INVALID_PARAMETER_VALUES;
	}
  
	for(int i = 0; i < lastButOneIndex; i++) 
	{		
		parameter_Deviation_Check = validate_Deviation_In_Consecutive_Parameter_Values(paramValues[i], paramValues[i + 1], deviationThreshold);
		
		retVal = validate_Parameter_Status(parameter_Deviation_Check,retVal);
	}
	
	return retVal;
}
