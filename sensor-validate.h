/* ******************************************************************************
 ***     \file        sensor-validate.h
 ***     \ingroup     Evaluation-TCQ
 ***     \author      Rohith K N
 ***
 ***     \brief       Header file for the module
 ***
 ***     \par         File_description
 ***                  This file have the declarations of the variables and methods of the module
 ***
 *****************************************************************************/
#ifndef SENSOR_VALIDATION_H_
#define SENSOR_VALIDATION_H_
/*=============================================================================
 =======                            INCLUDES                             =======
 ============================================================================*/
/*------ standard includes -------*/

/*------ module includes -------*/

#define DEVIATION_THRESHOLD_FOR_CURRENT    			0.1
#define DEVIATION_THRESHOLD_FOR_SOC	    			0.05

#define DEVIATION_IN_PARAMETER_VALUE				0u
#define NO_DEVIATION_IN_PARAMETER_VALUE				1u
				
#define INVALID_PARAMETER_VALUES					0u
#define VALID_PARAMETER_VALUES						1u

int validate_Deviation_In_Consecutive_Parameter_Values(double value, double nextValue, double maxDelta);

int validateParameter_Readings(double* paramValues, int numOfValues, double deviationThreshold);

int validate_Parameter_Status(int parameter_Deviation_Check,int retVal);

#endif /*SENSOR_VALIDATION_H_*/
