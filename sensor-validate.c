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


int validate_Deviation_In_Consecutive_Parameter_Values(double value, double nextValue, double maxDelta) 
{  
  if((nextValue - value) > maxDelta) /*Check if deviation is greater than threshold*/
  {
    return DEVIATION_IN_PARAMETER_VALUE;
  }
  else
  {
	return NO_DEVIATION_IN_PARAMETER_VALUE;
  }
}

int validate_Parameter_Status(int parameter_Deviation_Check,int retVal)
{
	int retVal_r;
	
	if(parameter_Deviation_Check == DEVIATION_IN_PARAMETER_VALUE)
	{
		retVal_r = DEVIATION_IN_PARAMETER_VALUE;
	}
	else
	{
		retVal_r = NO_DEVIATION_IN_PARAMETER_VALUE;
	}
	
	retVal_r &= retVal;
	
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
int validateParameter_Readings(double* paramValues, int numOfValues, double deviationThreshold) 
{
	
  int lastButOneIndex = numOfValues - 1;
  int parameter_Deviation_Check;
  int retVal = 0;
  
  
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
