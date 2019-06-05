#include "AnalogKeypad.h"

const uint16_t KeypadHoldTimeMs = 2000; // durée du hold
const uint8_t KeypadAnalogPin = A0;

AnalogKeypad keypad(KeypadAnalogPin, KeypadHoldTimeMs);

// the button event callback
// this will be called when buttons are pressed and released
void ButtonHandler(const ButtonParam& param)
{
  switch (param.button)
  {
    case ButtonId_1:
    Serial.print(Button_name_1);
    break;
    case ButtonId_2:
    Serial.print(Button_name_2);
    break;
    case ButtonId_3:
    Serial.print(Button_name_3);
    break;
    case ButtonId_4:
    Serial.print(Button_name_4);
    break;
    case ButtonId_5:
    Serial.print(Button_name_5);
    break;
    default:
    break;
  };
  
  switch (param.state)
  {
    case ButtonState_Up:
    Serial.print("Up ");
    break;
    
    case ButtonState_Down:
    Serial.print("Down ");
    break;
    
    case ButtonState_Click:
    Serial.print("Click ");
    break;
    
    case ButtonState_DoubleClick:
    Serial.print("Double Click ");
    break;
    
    case ButtonState_Hold:
    Serial.print("Hold ");
    break;
  }
  
  Serial.println();
}

void setup() {
  
    Serial.begin(115200);
    while (!Serial); // wait for serial attach

    Serial.println();
    Serial.println("Initialized");
}

void loop() {
  
  keypad.loop(ButtonHandler);
}
