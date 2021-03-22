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

typedef enum {	DEVIATION_IN_PARAMETER_VALUE, 
				NO_DEVIATION_IN_PARAMETER_VALUE
}parameter_Deviation_t;

typedef enum {	INVALID_PARAMETER_VALUES, 
				VALID_PARAMETER_VALUES
}parameter_Values_Validity_t;

parameter_Deviation_t validate_Deviation_In_Consecutive_Parameter_Values(double value, double nextValue, double maxDelta);

parameter_Values_Validity_t validateParameter_Readings(double* paramValues, int numOfValues, double deviationThreshold);

#endif /*SENSOR_VALIDATION_H_*/
