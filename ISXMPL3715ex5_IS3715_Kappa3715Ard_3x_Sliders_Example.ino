/*
 * This example works with the Evaluation Board Kappa3715, 
 * which features an IS3715-I2C DMX Controller chip.
 * The Arduino reads 3 sliders connected to 3.3 V on pin A1, A2 and A3, 
 * scales the value to a DMX range (0–255), and writes it to the IS3715, 
 * which continuously transmits DMX data.
 * For more information, visit www.inacks.com
 */
#include <Wire.h>

// IS3715 Memory Map Registers:
#define DMX_CH1   1
#define DMX_CH2   2
#define DMX_CH3   3
// ...
#define DMX_CH512 512
#define CHIP_ID   513
#define CHIP_REV  514

// Constants:
#define I2C_DEVICE_ADDRESS  21
#define CHIP_ID_VALUE       21

// This routine writes a dmxValue to the specified memory address of 
// the IS3715 memory map. 
void writeIS3715Register(uint16_t address, uint8_t dmxValue) {
  Wire.beginTransmission(I2C_DEVICE_ADDRESS); 

  // Send the 16-bit memory address (high byte first, then low byte).
  Wire.write((address >> 8) & 0xFF); 
  Wire.write(address & 0xFF);        
  
  // Send the 8-bit data value
  Wire.write(dmxValue); 

  Wire.endTransmission();
}

// Read one byte from the specified register address in the IS3715 memory map.
uint8_t readIS3715Register(uint16_t holdingRegisterAddress) {
  uint8_t result; // Variable to store the read data.
  
  Wire.beginTransmission(I2C_DEVICE_ADDRESS); 
  
  // Send the 16-bit memory address (high byte first, then low byte).
  Wire.write((holdingRegisterAddress >> 8) & 0xFF); 
  Wire.write(holdingRegisterAddress & 0xFF);        
  // Send a repeated START condition (no STOP)
  Wire.endTransmission(false); 
  // Request 1 byte from the IS3715.
  Wire.requestFrom(I2C_DEVICE_ADDRESS, 1);  
  result = Wire.read();
  return result; 
}

void setup() {
  uint16_t chipID, chipRev;

  // Initialize the I2C interface
  Wire.begin();           
  // Initialize the serial port for debug output
  Serial.begin(9600);     

  // Detect the chip:
  chipID = readIS3715Register(CHIP_ID);
  chipRev = readIS3715Register(CHIP_REV);
  if (chipID == CHIP_ID_VALUE) {
    Serial.println("IS3715 Chip detected on I2C!");
    Serial.print("Chip ID: "); Serial.println(chipID);
    Serial.print("Chip Rev: "); Serial.println(chipRev);
  }
  else {
    Serial.print("ERROR: IS3715 Chip NOT detected on I2C!");
  }
}

void loop() {
  // Read the potentiometer (0–3.3V) on analog pin A1, A2 and A3
  uint16_t pot1Value = analogRead(A1);
  uint16_t pot2Value = analogRead(A2);
  uint16_t pot3Value = analogRead(A3);

  // Filter for the bottom of the slider
  if (pot1Value > 680) pot1Value = 700;
  if (pot2Value > 680) pot2Value = 700;
  if (pot3Value > 680) pot3Value = 700;

  // Filter for the top of the slider
  if (pot1Value < 3) pot1Value = 0;
  if (pot2Value < 3) pot2Value = 0;
  if (pot3Value < 3) pot3Value = 0;

  // Scale the analog reading to 0–255 (DMX value range)
  uint8_t dmx1Value = map(pot1Value, 0, 700, 255, 0);
  uint8_t dmx2Value = map(pot2Value, 0, 700, 255, 0);
  uint8_t dmx3Value = map(pot3Value, 0, 700, 255, 0);
  Serial.print("DMX value Ch1: ");
  Serial.print(dmx1Value);
  Serial.print("\tCH2: ");
  Serial.print(dmx2Value);
  Serial.print("\tCH3: ");
  Serial.println(dmx3Value);

  // Write the scaled DMX value into DMX channel 1, 2 and 3 registers
  writeIS3715Register(DMX_CH1, dmx1Value);
  writeIS3715Register(DMX_CH2, dmx2Value);
  writeIS3715Register(DMX_CH3, dmx3Value);

}