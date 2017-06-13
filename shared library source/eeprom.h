// Header guard
#ifndef EEPROM_H
#define EEPROM_H


// Header files
#include <cfloat>


// Definitions

// EEPROM types
enum EEPROM_TYPES {EEPROM_INT, EEPROM_FLOAT, EEPROM_STRING, EEPROM_BOOL};

// EEPROM offsets and lengths
#define EEPROM_FIRMWARE_VERSION_OFFSET 0x00
#define EEPROM_FIRMWARE_VERSION_LENGTH 4
#define EEPROM_FIRMWARE_CRC_OFFSET 0x04
#define EEPROM_FIRMWARE_CRC_LENGTH 4
#define EEPROM_LAST_RECORDED_Z_VALUE_OFFSET 0x08
#define EEPROM_LAST_RECORDED_Z_VALUE_LENGTH 4
#define EEPROM_BACKLASH_X_OFFSET 0x0C
#define EEPROM_BACKLASH_X_LENGTH 4
#define EEPROM_BACKLASH_Y_OFFSET 0x10
#define EEPROM_BACKLASH_Y_LENGTH 4
#define EEPROM_BED_ORIENTATION_BACK_RIGHT_OFFSET 0x14
#define EEPROM_BED_ORIENTATION_BACK_RIGHT_LENGTH 4
#define EEPROM_BED_ORIENTATION_BACK_LEFT_OFFSET 0x18
#define EEPROM_BED_ORIENTATION_BACK_LEFT_LENGTH 4
#define EEPROM_BED_ORIENTATION_FRONT_LEFT_OFFSET 0x1C
#define EEPROM_BED_ORIENTATION_FRONT_LEFT_LENGTH 4
#define EEPROM_BED_ORIENTATION_FRONT_RIGHT_OFFSET 0x20
#define EEPROM_BED_ORIENTATION_FRONT_RIGHT_LENGTH 4
#define EEPROM_FILAMENT_COLOR_OFFSET 0x24
#define EEPROM_FILAMENT_COLOR_LENGTH 4
#define EEPROM_FILAMENT_TYPE_AND_LOCATION_OFFSET 0x28
#define EEPROM_FILAMENT_TYPE_AND_LOCATION_LENGTH 1
#define EEPROM_FILAMENT_TEMPERATURE_OFFSET 0x29
#define EEPROM_FILAMENT_TEMPERATURE_LENGTH 1
#define EEPROM_FILAMENT_AMOUNT_OFFSET 0x2A
#define EEPROM_FILAMENT_AMOUNT_LENGTH 4
#define EEPROM_BACKLASH_EXPANSION_X_PLUS_OFFSET 0x2E
#define EEPROM_BACKLASH_EXPANSION_X_PLUS_LENGTH 4
#define EEPROM_BACKLASH_EXPANSION_Y_L_PLUS_OFFSET 0x32
#define EEPROM_BACKLASH_EXPANSION_Y_L_PLUS_LENGTH 4
#define EEPROM_BACKLASH_EXPANSION_Y_R_PLUS_OFFSET 0x36
#define EEPROM_BACKLASH_EXPANSION_Y_R_PLUS_LENGTH 4
#define EEPROM_BACKLASH_EXPANSION_Y_R_MINUS_OFFSET 0x3A
#define EEPROM_BACKLASH_EXPANSION_Y_R_MINUS_LENGTH 4
#define EEPROM_BACKLASH_EXPANSION_Z_OFFSET 0x3E
#define EEPROM_BACKLASH_EXPANSION_Z_LENGTH 4
#define EEPROM_BACKLASH_EXPANSION_E_OFFSET 0x42
#define EEPROM_BACKLASH_EXPANSION_E_LENGTH 4
#define EEPROM_BED_OFFSET_BACK_LEFT_OFFSET 0x46
#define EEPROM_BED_OFFSET_BACK_LEFT_LENGTH 4
#define EEPROM_BED_OFFSET_BACK_RIGHT_OFFSET 0x4A
#define EEPROM_BED_OFFSET_BACK_RIGHT_LENGTH 4
#define EEPROM_BED_OFFSET_FRONT_RIGHT_OFFSET 0x4E
#define EEPROM_BED_OFFSET_FRONT_RIGHT_LENGTH 4
#define EEPROM_BED_OFFSET_FRONT_LEFT_OFFSET 0x52
#define EEPROM_BED_OFFSET_FRONT_LEFT_LENGTH 4
#define EEPROM_BED_HEIGHT_OFFSET_OFFSET 0x56
#define EEPROM_BED_HEIGHT_OFFSET_LENGTH 4
#define EEPROM_RESERVED_OFFSET 0x5A
#define EEPROM_RESERVED_LENGTH 4
#define EEPROM_BACKLASH_SPEED_OFFSET 0x5E
#define EEPROM_BACKLASH_SPEED_LENGTH 4
#define EEPROM_BED_ORIENTATION_VERSION_OFFSET 0x62
#define EEPROM_BED_ORIENTATION_VERSION_LENGTH 1
#define EEPROM_SPEED_LIMIT_X_OFFSET 0x66
#define EEPROM_SPEED_LIMIT_X_LENGTH 4
#define EEPROM_SPEED_LIMIT_Y_OFFSET 0x6A
#define EEPROM_SPEED_LIMIT_Y_LENGTH 4
#define EEPROM_SPEED_LIMIT_Z_OFFSET 0x6E
#define EEPROM_SPEED_LIMIT_Z_LENGTH 4
#define EEPROM_SPEED_LIMIT_E_POSITIVE_OFFSET 0x72
#define EEPROM_SPEED_LIMIT_E_POSITIVE_LENGTH 4
#define EEPROM_SPEED_LIMIT_E_NEGATIVE_OFFSET 0x76
#define EEPROM_SPEED_LIMIT_E_NEGATIVE_LENGTH 4
#define EEPROM_FILAMENT_SIZE_OFFSET 0x82
#define EEPROM_FILAMENT_SIZE_LENGTH 1
#define EEPROM_FILAMENT_UID_OFFSET 0x83
#define EEPROM_FILAMENT_UID_LENGTH 4
#define EEPROM_BED_ORIENTATION_FIRST_SAMPLE_OFFSET 0x106
#define EEPROM_BED_ORIENTATION_FIRST_SAMPLE_LENGTH 4
#define EEPROM_HEATBED_TEMPERATURE_OFFSET 0x28B
#define EEPROM_HEATBED_TEMPERATURE_LENGTH 1
#define EEPROM_SKEW_X_OFFSET 0x28C
#define EEPROM_SKEW_X_LENGTH 4
#define EEPROM_SKEW_Y_OFFSET 0x290
#define EEPROM_SKEW_Y_LENGTH 4
#define EEPROM_EXPAND_PRINTABLE_REGION_OFFSET 0x294
#define EEPROM_EXPAND_PRINTABLE_REGION_LENGTH 1
#define EEPROM_EXTERNAL_BED_HEIGHT_OFFSET 0x295
#define EEPROM_EXTERNAL_BED_HEIGHT_LENGTH 4
#define EEPROM_CALIBRATE_Z0_CORRECTION_OFFSET 0x299
#define EEPROM_CALIBRATE_Z0_CORRECTION_LENGTH 4
#define EEPROM_X_JERK_SENSITIVITY_OFFSET 0x29D
#define EEPROM_X_JERK_SENSITIVITY_LENGTH 1
#define EEPROM_Y_JERK_SENSITIVITY_OFFSET 0x29E
#define EEPROM_Y_JERK_SENSITIVITY_LENGTH 1
#define EEPROM_LAST_RECORDED_X_VALUE_OFFSET 0x29F
#define EEPROM_LAST_RECORDED_X_VALUE_LENGTH 4
#define EEPROM_LAST_RECORDED_Y_VALUE_OFFSET 0x2A3
#define EEPROM_LAST_RECORDED_Y_VALUE_LENGTH 4
#define EEPROM_LAST_RECORDED_X_DIRECTION_OFFSET 0x2A7
#define EEPROM_LAST_RECORDED_X_DIRECTION_LENGTH 1
#define EEPROM_LAST_RECORDED_Y_DIRECTION_OFFSET 0x2A8
#define EEPROM_LAST_RECORDED_Y_DIRECTION_LENGTH 1
#define EEPROM_SAVED_X_STATE_OFFSET 0x2A9
#define EEPROM_SAVED_X_STATE_LENGTH 1
#define EEPROM_SAVED_Y_STATE_OFFSET 0x2AA
#define EEPROM_SAVED_Y_STATE_LENGTH 1
#define EEPROM_FAN_TYPE_OFFSET 0x2AB
#define EEPROM_FAN_TYPE_LENGTH 1
#define EEPROM_FAN_OFFSET_OFFSET 0x2AC
#define EEPROM_FAN_OFFSET_LENGTH 1
#define EEPROM_FAN_SCALE_OFFSET 0x2AD
#define EEPROM_FAN_SCALE_LENGTH 4
#define EEPROM_HEATER_CALIBRATION_MODE_OFFSET 0x2B1
#define EEPROM_HEATER_CALIBRATION_MODE_LENGTH 1
#define EEPROM_X_MOTOR_CURRENT_OFFSET 0x2B2
#define EEPROM_X_MOTOR_CURRENT_LENGTH 2
#define EEPROM_Y_MOTOR_CURRENT_OFFSET 0x2B4
#define EEPROM_Y_MOTOR_CURRENT_LENGTH 2
#define EEPROM_Z_MOTOR_CURRENT_OFFSET 0x2B6
#define EEPROM_Z_MOTOR_CURRENT_LENGTH 2
#define EEPROM_HARDWARE_STATUS_OFFSET 0x2B8
#define EEPROM_HARDWARE_STATUS_LENGTH 2
#define EEPROM_HEATER_TEMPERATURE_MEASUREMENT_B_OFFSET 0x2BA
#define EEPROM_HEATER_TEMPERATURE_MEASUREMENT_B_LENGTH 4
#define EEPROM_HOURS_COUNTER_OFFSET 0x2C0
#define EEPROM_HOURS_COUNTER_LENGTH 4
#define EEPROM_X_MOTOR_STEPS_PER_MM_OFFSET 0x2D6
#define EEPROM_X_MOTOR_STEPS_PER_MM_LENGTH 4
#define EEPROM_Y_MOTOR_STEPS_PER_MM_OFFSET 0x2DA
#define EEPROM_Y_MOTOR_STEPS_PER_MM_LENGTH 4
#define EEPROM_Z_MOTOR_STEPS_PER_MM_OFFSET 0x2DE
#define EEPROM_Z_MOTOR_STEPS_PER_MM_LENGTH 4
#define EEPROM_E_MOTOR_STEPS_PER_MM_OFFSET 0x2E2
#define EEPROM_E_MOTOR_STEPS_PER_MM_LENGTH 4
#define EEPROM_SAVED_Z_STATE_OFFSET 0x2E6
#define EEPROM_SAVED_Z_STATE_LENGTH 2
#define EEPROM_E_MOTOR_CURRENT_OFFSET 0x2E8
#define EEPROM_E_MOTOR_CURRENT_LENGTH 2
#define EEPROM_HEATER_RESISTANCE_M_OFFSET 0x2EA
#define EEPROM_HEATER_RESISTANCE_M_LENGTH 4
#define EEPROM_SERIAL_NUMBER_OFFSET 0x2EF
#define EEPROM_SERIAL_NUMBER_LENGTH 17
#define EEPROM_DECRYPTION_TABLE_OFFSET 0x300
#define EEPROM_DECRYPTION_TABLE_LENGTH 256

// EEPROM types
#define EEPROM_BACKLASH_X_TYPE EEPROM_FLOAT
#define EEPROM_BACKLASH_Y_TYPE EEPROM_FLOAT
#define EEPROM_BACKLASH_SPEED_TYPE EEPROM_FLOAT
#define EEPROM_BED_ORIENTATION_BACK_RIGHT_TYPE EEPROM_FLOAT
#define EEPROM_BED_ORIENTATION_BACK_LEFT_TYPE EEPROM_FLOAT
#define EEPROM_BED_ORIENTATION_FRONT_LEFT_TYPE EEPROM_FLOAT
#define EEPROM_BED_ORIENTATION_FRONT_RIGHT_TYPE EEPROM_FLOAT
#define EEPROM_BED_OFFSET_BACK_LEFT_TYPE EEPROM_FLOAT
#define EEPROM_BED_OFFSET_BACK_RIGHT_TYPE EEPROM_FLOAT
#define EEPROM_BED_OFFSET_FRONT_RIGHT_TYPE EEPROM_FLOAT
#define EEPROM_BED_OFFSET_FRONT_LEFT_TYPE EEPROM_FLOAT
#define EEPROM_BED_HEIGHT_OFFSET_TYPE EEPROM_FLOAT
#define EEPROM_FILAMENT_TEMPERATURE_TYPE EEPROM_INT
#define EEPROM_SPEED_LIMIT_X_TYPE EEPROM_FLOAT
#define EEPROM_SPEED_LIMIT_Y_TYPE EEPROM_FLOAT
#define EEPROM_SPEED_LIMIT_Z_TYPE EEPROM_FLOAT
#define EEPROM_SPEED_LIMIT_E_POSITIVE_TYPE EEPROM_FLOAT
#define EEPROM_SPEED_LIMIT_E_NEGATIVE_TYPE EEPROM_FLOAT
#define EEPROM_LAST_RECORDED_X_VALUE_TYPE EEPROM_FLOAT
#define EEPROM_LAST_RECORDED_Y_VALUE_TYPE EEPROM_FLOAT
#define EEPROM_LAST_RECORDED_Z_VALUE_TYPE EEPROM_FLOAT
#define EEPROM_X_MOTOR_STEPS_PER_MM_TYPE EEPROM_FLOAT
#define EEPROM_Y_MOTOR_STEPS_PER_MM_TYPE EEPROM_FLOAT
#define EEPROM_Z_MOTOR_STEPS_PER_MM_TYPE EEPROM_FLOAT
#define EEPROM_E_MOTOR_STEPS_PER_MM_TYPE EEPROM_FLOAT
#define EEPROM_X_JERK_SENSITIVITY_TYPE EEPROM_INT
#define EEPROM_Y_JERK_SENSITIVITY_TYPE EEPROM_INT
#define EEPROM_CALIBRATE_Z0_CORRECTION_TYPE EEPROM_FLOAT
#define EEPROM_EXPAND_PRINTABLE_REGION_TYPE EEPROM_BOOL
#define EEPROM_EXTERNAL_BED_HEIGHT_TYPE EEPROM_FLOAT
#define EEPROM_SKEW_X_TYPE EEPROM_FLOAT
#define EEPROM_SKEW_Y_TYPE EEPROM_FLOAT
#define EEPROM_HEATBED_TEMPERATURE_TYPE EEPROM_INT

// EEPROM default values
#define EEPROM_BACKLASH_X_DEFAULT 0.3
#define EEPROM_BACKLASH_Y_DEFAULT 0.6
#define EEPROM_BACKLASH_SPEED_DEFAULT 1500.0
#define EEPROM_BED_ORIENTATION_BACK_RIGHT_DEFAULT 0.0
#define EEPROM_BED_ORIENTATION_BACK_LEFT_DEFAULT 0.0
#define EEPROM_BED_ORIENTATION_FRONT_LEFT_DEFAULT 0.0
#define EEPROM_BED_ORIENTATION_FRONT_RIGHT_DEFAULT 0.0
#define EEPROM_BED_OFFSET_BACK_LEFT_DEFAULT 0.0
#define EEPROM_BED_OFFSET_BACK_RIGHT_DEFAULT 0.0
#define EEPROM_BED_OFFSET_FRONT_RIGHT_DEFAULT 0.0
#define EEPROM_BED_OFFSET_FRONT_LEFT_DEFAULT 0.0
#define EEPROM_BED_HEIGHT_OFFSET_DEFAULT 0.0
#define EEPROM_FILAMENT_TEMPERATURE_DEFAULT (215 - 100)
#define EEPROM_SPEED_LIMIT_X_DEFAULT 1500.0
#define EEPROM_SPEED_LIMIT_Y_DEFAULT 1500.0
#define EEPROM_SPEED_LIMIT_Z_DEFAULT 60.0
#define EEPROM_SPEED_LIMIT_E_POSITIVE_DEFAULT 102.0
#define EEPROM_SPEED_LIMIT_E_NEGATIVE_DEFAULT 360.0
#define EEPROM_LAST_RECORDED_X_VALUE_DEFAULT 54.0
#define EEPROM_LAST_RECORDED_Y_VALUE_DEFAULT 50.0
#define EEPROM_LAST_RECORDED_Z_VALUE_DEFAULT 5.0
#define EEPROM_X_MOTOR_STEPS_PER_MM_DEFAULT 19.3067875
#define EEPROM_Y_MOTOR_STEPS_PER_MM_DEFAULT 18.00885
#define EEPROM_Z_MOTOR_STEPS_PER_MM_DEFAULT 646.3295
#define EEPROM_E_MOTOR_STEPS_PER_MM_DEFAULT 128.451375
#define EEPROM_X_JERK_SENSITIVITY_DEFAULT 195
#define EEPROM_Y_JERK_SENSITIVITY_DEFAULT 195
#define EEPROM_CALIBRATE_Z0_CORRECTION_DEFAULT 0.0
#define EEPROM_EXPAND_PRINTABLE_REGION_DEFAULT false
#define EEPROM_EXTERNAL_BED_HEIGHT_DEFAULT 0.0
#define EEPROM_SKEW_X_DEFAULT 0.0
#define EEPROM_SKEW_Y_DEFAULT 0.0
#define EEPROM_HEATBED_TEMPERATURE_DEFAULT 70

// EEPROM min and max values
#define EEPROM_BACKLASH_X_MIN 0.0
#define EEPROM_BACKLASH_X_MAX 2.0
#define EEPROM_BACKLASH_Y_MIN 0.0
#define EEPROM_BACKLASH_Y_MAX 2.0
#define EEPROM_BACKLASH_SPEED_MIN 1.0
#define EEPROM_BACKLASH_SPEED_MAX FLT_MAX
#define EEPROM_BED_ORIENTATION_BACK_RIGHT_MIN -3.0
#define EEPROM_BED_ORIENTATION_BACK_RIGHT_MAX 3.0
#define EEPROM_BED_ORIENTATION_BACK_LEFT_MIN -3.0
#define EEPROM_BED_ORIENTATION_BACK_LEFT_MAX 3.0
#define EEPROM_BED_ORIENTATION_FRONT_LEFT_MIN -3.0
#define EEPROM_BED_ORIENTATION_FRONT_LEFT_MAX 3.0
#define EEPROM_BED_ORIENTATION_FRONT_RIGHT_MIN -3.0
#define EEPROM_BED_ORIENTATION_FRONT_RIGHT_MAX 3.0
#define EEPROM_BED_OFFSET_BACK_RIGHT_MIN -FLT_MAX
#define EEPROM_BED_OFFSET_BACK_RIGHT_MAX FLT_MAX
#define EEPROM_BED_OFFSET_BACK_LEFT_MIN -FLT_MAX
#define EEPROM_BED_OFFSET_BACK_LEFT_MAX FLT_MAX
#define EEPROM_BED_OFFSET_FRONT_LEFT_MIN -FLT_MAX
#define EEPROM_BED_OFFSET_FRONT_LEFT_MAX FLT_MAX
#define EEPROM_BED_OFFSET_FRONT_RIGHT_MIN -FLT_MAX
#define EEPROM_BED_OFFSET_FRONT_RIGHT_MAX FLT_MAX
#define EEPROM_BED_HEIGHT_OFFSET_MIN -FLT_MAX
#define EEPROM_BED_HEIGHT_OFFSET_MAX FLT_MAX
#define EEPROM_FILAMENT_TEMPERATURE_MIN (150 - 100)
#define EEPROM_FILAMENT_TEMPERATURE_MAX (315 - 100)
#define EEPROM_SPEED_LIMIT_X_MIN 120.0
#define EEPROM_SPEED_LIMIT_X_MAX 4800.0
#define EEPROM_SPEED_LIMIT_Y_MIN 120.0
#define EEPROM_SPEED_LIMIT_Y_MAX 4800.0
#define EEPROM_SPEED_LIMIT_Z_MIN 30.0
#define EEPROM_SPEED_LIMIT_Z_MAX 60.0
#define EEPROM_SPEED_LIMIT_E_POSITIVE_MIN 60.0
#define EEPROM_SPEED_LIMIT_E_POSITIVE_MAX 600.0
#define EEPROM_SPEED_LIMIT_E_NEGATIVE_MIN 60.0
#define EEPROM_SPEED_LIMIT_E_NEGATIVE_MAX 720.0
#define EEPROM_LAST_RECORDED_X_VALUE_MIN -FLT_MAX
#define EEPROM_LAST_RECORDED_X_VALUE_MAX FLT_MAX
#define EEPROM_LAST_RECORDED_Y_VALUE_MIN -FLT_MAX
#define EEPROM_LAST_RECORDED_Y_VALUE_MAX FLT_MAX
#define EEPROM_LAST_RECORDED_Z_VALUE_MIN -FLT_MAX
#define EEPROM_LAST_RECORDED_Z_VALUE_MAX FLT_MAX
#define EEPROM_X_MOTOR_STEPS_PER_MM_MIN FLT_MIN
#define EEPROM_X_MOTOR_STEPS_PER_MM_MAX FLT_MAX
#define EEPROM_Y_MOTOR_STEPS_PER_MM_MIN FLT_MIN
#define EEPROM_Y_MOTOR_STEPS_PER_MM_MAX FLT_MAX
#define EEPROM_Z_MOTOR_STEPS_PER_MM_MIN FLT_MIN
#define EEPROM_Z_MOTOR_STEPS_PER_MM_MAX FLT_MAX
#define EEPROM_E_MOTOR_STEPS_PER_MM_MIN FLT_MIN
#define EEPROM_E_MOTOR_STEPS_PER_MM_MAX FLT_MAX
#define EEPROM_X_JERK_SENSITIVITY_MIN 1
#define EEPROM_X_JERK_SENSITIVITY_MAX 255
#define EEPROM_Y_JERK_SENSITIVITY_MIN 1
#define EEPROM_Y_JERK_SENSITIVITY_MAX 255
#define EEPROM_CALIBRATE_Z0_CORRECTION_MIN -FLT_MAX
#define EEPROM_CALIBRATE_Z0_CORRECTION_MAX FLT_MAX
#define EEPROM_EXTERNAL_BED_HEIGHT_MIN 0
#define EEPROM_EXTERNAL_BED_HEIGHT_MAX 50.0
#define EEPROM_SKEW_X_MIN -40.0
#define EEPROM_SKEW_X_MAX 40.0
#define EEPROM_SKEW_Y_MIN -40.0
#define EEPROM_SKEW_Y_MAX 40.0
#define EEPROM_HEATBED_TEMPERATURE_MIN 0
#define EEPROM_HEATBED_TEMPERATURE_MAX 110


#endif
