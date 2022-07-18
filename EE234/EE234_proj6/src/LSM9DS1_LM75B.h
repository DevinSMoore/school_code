
#define DATA_RATE_476Hz 0x50
#define SS_ACC_GYRO 	0x0000
#define SS_MAGNETOMETER 0x0001
#define LM75B_ADDRESS	0x48			// b0100100




// Register address'
typedef enum
{
	ACT_THS = 0x04,
	ACT_DUR = 0x05,
	INT_GEN_CFG_XL = 0x06,
	INT_GEN_THS_X_XL = 0x07,
	INT_GEN_THS_Y_XL = 0x08,
	INT_GEN_THS_Z_XL = 0x09,
	INT_GEN_DUR_XL = 0x0A,
	REFERENCE_G = 0x0B,
	INT1_CTRL = 0x0C,				// for INT1_AG pin: bit[7] Gyro INT EN; bit[6] ACC INT EN; [5] FSS5 INT EN; [4] Overrun EN; [3] FIFO threshold EN; [2] BOOT STS; [1] Gyro data RDY EN; [0] ACC data RDY EN;
	INT2_CTRL = 0x0D,				// for int2_AG pint: [7] INACTV EN; bit[6] must be asserted LOW; [5] FSS5 EN; [4] Overrun EN; [3] FIFO threshold; ---- [2] Temperature Data Ready; [1] Gyro data ready; [0] ACC data ready
	WHO_AM_I_ACC_GYRO = 0x0F,				// Returns 0x68; 0110 1000; 0x68

	GYRO_INTR_STS_REG = 0x14,

	ACC_CONFIG_REG_6 = 0x20,



	STS_REG = 0x17,				// 1 means interrupt event generated: [7] is asserted LOW; [6] is ACC intrupt; [5] Gyro INT; [4] inactivity; [3] Boot status; [2] Temp Sens new data; [1] Gyro new data; [0] ACC new data

	GYRO_CONFIG_REG_1 = 0x10,		// [7:5] Output data rate selection; [1:0] are bandwith selection
	GYRO_CONFIG_REG_2 = 0x11,
	GYRO_CONFIG_REG_3 = 0x12,
	GYRO_OUT_X_L = 0x18,
	GYRO_OUT_X_H = 0x19,
	GYRO_OUT_Y_L = 0x1A,
	GYRO_OUT_Y_H = 0x1B,
	GYRO_OUT_Z_L = 0x1C,
	GYRO_OUT_Z_H = 0x1D,

	ACC_OUT_X_L = 0x28,
	ACC_OUT_X_H = 0x29,
	ACC_OUT_Y_L = 0x28,
	ACC_OUT_Y_H = 0x29,
	ACC_OUT_Z_L = 0x28,
	ACC_OUT_Z_H = 0x29
}LSM9DS1_REGISTERS;

enum LM75B_REGISTERS
{
	TEMP	= 0b00,				// Temperature data 11 bit 2s compliment
	CONFIG	= 0b01,
	THYST	= 0b10,				// Hysteresis temp for OS mode
	TOS		= 0b11				// Threshold temp   "   "   "
};
