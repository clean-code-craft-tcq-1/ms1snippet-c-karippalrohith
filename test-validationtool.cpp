#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "sensor-validate.h"

TEST_CASE("reports error when soc jumps abruptly") {
  double socReadings[] = {0.0, 0.01, 0.5, 0.51};
  int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
  REQUIRE(validateParameter_Readings(socReadings, numOfSocReadings,DEVIATION_THRESHOLD_FOR_SOC) == 0);
}

TEST_CASE("reports error when current jumps abruptly") {
  double currentReadings[] = {0.0, 0.02, 0.03, 0.33};
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  REQUIRE(validateParameter_Readings(currentReadings, numOfCurReadings,DEVIATION_THRESHOLD_FOR_CURRENT) == 0);
}

TEST_CASE("reports error when current passes NULL value") {
  double currentReadings[] = {0.0, 0.02, 0.03, 0.33};
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  REQUIRE(validateParameter_Readings(NULL, numOfCurReadings,DEVIATION_THRESHOLD_FOR_CURRENT) == 0);
}

TEST_CASE("no error when no jump observed in soc") {
  double socReadings[] = {0.0, 0.01, 0.03, 0.02};
  int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
  REQUIRE(validateParameter_Readings(socReadings, numOfSocReadings,DEVIATION_THRESHOLD_FOR_SOC) == 1);
}

TEST_CASE("no error when no jump observed in current") {
  double currentReadings[] = {0.0, 0.01, 0.03, 0.02};
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  REQUIRE(validateParameter_Readings(currentReadings, numOfCurReadings,DEVIATION_THRESHOLD_FOR_CURRENT) == 1);
}

TEST_CASE("reports error when soc jumps abruptly up and down") {
  double socReadings[] = {0.0, 0.01, 0.0, 0.51};
  int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
  REQUIRE(validateParameter_Readings(socReadings, numOfSocReadings,DEVIATION_THRESHOLD_FOR_SOC) == 0);
}

TEST_CASE("reports error when current jumps abruptly up and down") {
  double currentReadings[] = {0.0, 0.02, 0.0, 0.33};
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  REQUIRE(validateParameter_Readings(currentReadings, numOfCurReadings,DEVIATION_THRESHOLD_FOR_CURRENT) == 0);
}
