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


parameter_Deviation_t validate_Deviation_In_Consecutive_Parameter_Values(double value, double nextValue, double maxDelta) {
  
  if((nextValue - value) > maxDelta) 
  {
    return DEVIATION_IN_PARAMETER_VALUE;
  }
  return NO_DEVIATION_IN_PARAMETER_VALUE;
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
parameter_Values_Validity_t validateParameter_Readings(double* paramValues, int numOfValues, double deviationThreshold) {
	
  int lastButOneIndex = numOfValues - 1;
  
  for(int i = 0; i < lastButOneIndex; i++) 
  {
    if(!validate_Deviation_In_Consecutive_Parameter_Values(paramValues[i], paramValues[i + 1], deviationThreshold)) 
	{
      return INVALID_PARAMETER_VALUES;
    }
  }
  return VALID_PARAMETER_VALUES;
}
