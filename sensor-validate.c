/* ******************************************************************************
 ***
 ***     \file        sensor-validate.c
 ***     \ingroup     Assessment1-TCQ
 ***     \author      Rohith K N
 ***
 ***     \brief       Main file to check Sensor parameters
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

/*---------------------------------------------------------------------------*/
/*     FUNCTION: validate_Deviation_In_Consecutive_Parameter_Values
 */
/*!    \brief   Function to validate the jump in consecutive parameter values
 *
 *
 *     \param    	currentValue -> Current value of the parameter
					nextValue -> Next value of the parameter
					deviationThreshold -> the threshold for which sensor value can vary wrt to the previous value
 *     \returns  	int -> Status of sudden jump in parameter value
 *//*------------------------------------------------------------------------*/
int validate_Deviation_In_Consecutive_Parameter_Values(double currentValue, double nextValue, double deviationThreshold) 
{  
  if((nextValue - currentValue) > deviationThreshold) /*Check if consective values have deviation greater than threshold*/
  {
    return SUDDEN_DEVIATION_IN_PARAMETER_VALUE;
  }
  else
  {
	return NO_SUDDEN_DEVIATION_IN_PARAMETER_VALUE;
  }
}

/*---------------------------------------------------------------------------*/
/*     FUNCTION: validate_Parameter_Status
 */
/*!    \brief   Function to validate the jump in consecutive parameter values
 *
 *
 *     \param    	parameter_Deviation_Check -> Status of sudden jump in parameter value
					parameter_Validation_Status -> Status of parameter till the value that was evaluated
 *     \returns  	int -> Status of overall validity of parameter based on sudden jump
 *//*------------------------------------------------------------------------*/
int validate_Parameter_Status(int parameter_Deviation_Check,int parameter_Validation_Status)
{
	int parameter_Validation_Status_Current;
	int parameter_Validation_Status_Overall;
	
	if(parameter_Deviation_Check == SUDDEN_DEVIATION_IN_PARAMETER_VALUE) /*Assign the parameter validity to invalid if there is a sudden jump*/
	{
		parameter_Validation_Status_Current = INVALID_PARAMETER_VALUES;
	}
	else
	{
		parameter_Validation_Status_Current = VALID_PARAMETER_VALUES;
	}
	
	/*Assign the overall validity of the parameter based on the current value and previous values*/
	parameter_Validation_Status_Overall = parameter_Validation_Status_Current & parameter_Validation_Status;
		
	return parameter_Validation_Status_Overall;
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
 *     \returns  	int -> Status of validated parameter readings
 *
 *//*------------------------------------------------------------------------*/
int validateParameter_Readings(double* paramValues, int numOfValues, double deviationThreshold) 
{
	
  int lastButOneIndex = numOfValues - 1;
  int parameter_Deviation_Check;
  int parameter_Validation_Status = INVALID_PARAMETER_VALUES;
  
  
	if(NULL == paramValues)
	{
		return INVALID_PARAMETER_VALUES;
	}
  
	for(int i = 0; i < lastButOneIndex; i++) 
	{	
		/*Check the deviation in consecutive parameter values*/
		parameter_Deviation_Check = validate_Deviation_In_Consecutive_Parameter_Values(paramValues[i], paramValues[i + 1], deviationThreshold);
		
		/*Checks the overall validity of the paramter based on sudden jumps*/
		parameter_Validation_Status = validate_Parameter_Status(parameter_Deviation_Check,parameter_Validation_Status);
	}

	return parameter_Validation_Status;
}
