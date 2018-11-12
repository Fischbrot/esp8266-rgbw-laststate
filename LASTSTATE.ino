#include <EEPROM.h>

int white_address = 0;
int red_address = 4;
int green_address = 8;
int blue_address = 12;
int  white_val = 0;
int  red_val = 0;
int  green_val = 0;
int  blue_val = 0;


void setup() {
  Serial.begin(9600);
  EEPROM.begin(512); 

  getMem();
}

void loop() {
  

}

void getMem() {
  EEPROM.get(white_address, white_val);
  EEPROM.get(red_address, red_val);
  EEPROM.get(green_address, green_val);
  EEPROM.get(blue_address, blue_val);

  Serial.print("EEPROM contents is (WRGB) : ");
  Serial.println(white_val);
  Serial.println(red_val);
  Serial.println(green_val);
  Serial.println(blue_val);


  EEPROM.put(white_address, white_val);
  EEPROM.put(red_address, red_val);
  EEPROM.put(green_address, green_val);
  EEPROM.put(blue_address, blue_val);


  EEPROM.commit();
  Serial.print("EEPROM contents at white_address(0) is  : ");

  white_val = 0;
  red_val = 0;
  green_val = 0;
  blue_val = 0;


  EEPROM.get(white_address, white_val);
  EEPROM.get(red_address, red_val);
  EEPROM.get(green_address, green_val);
  EEPROM.get(blue_address, blue_val);


  Serial.println(white_val);
  Serial.println(red_val);
  Serial.println(green_val);
  Serial.println(blue_val);

  EEPROM.end();
  
  white_address += EEPROM.get(white_address, white_val);
  red_address += EEPROM.get(red_address, red_val);
  green_address += EEPROM.get(green_address, green_val);
  blue_address += EEPROM.get(blue_address, blue_val);
  
  EEPROM.commit();
  Serial.println(white_val);
  Serial.println(red_val);
  Serial.println(green_val);
  Serial.println(blue_val);
}
