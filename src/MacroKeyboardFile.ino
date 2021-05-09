#include <Keyboard.h>
#include <Mouse.h>

//On mouse P- F22, T- F23
//used F13,F14, F15, F16
int delayms = 900;
int RXLED = 10;
boolean toggleClick;
boolean toggleMuted;
boolean toggleRun;

void setup() {
toggleClick = false;
toggleRun = false;
toggleMuted = false;

pinMode(RXLED, OUTPUT);

pinMode(2,INPUT_PULLUP);
pinMode(3,INPUT_PULLUP);
pinMode(4,INPUT_PULLUP);
pinMode(5,INPUT_PULLUP);
pinMode(6,INPUT_PULLUP);

pinMode(7,INPUT_PULLUP);
pinMode(8,INPUT_PULLUP);
pinMode(9,INPUT_PULLUP);
pinMode(16,INPUT_PULLUP);
pinMode(14,INPUT_PULLUP);


Serial.begin(9600);

}

void loop() {
 Keyboard.begin();

  if (digitalRead(6) == 0)  //Microphone F13  [0,4]
    {
      Keyboard.press(KEY_F13);
      delay(100);
      Keyboard.releaseAll();
      if(toggleMuted){
        toggleMuted = false;
        digitalWrite(RXLED, LOW);
      } else {
        toggleMuted = true;
        digitalWrite(RXLED, HIGH);
      }
      delay(delayms);
    }
  else if (digitalRead(5) == 0) //Deafen F14 [0,3]
    {
      Keyboard.press(KEY_F14);
      delay(100);
      Keyboard.releaseAll();
      delay(delayms);
    }
  else if (digitalRead(4) == 0) //Recap [0,2]
    {
      Keyboard.press(KEY_LEFT_CTRL);
      delay(100);
      Keyboard.press(KEY_LEFT_SHIFT);
      delay(100);
      Keyboard.press('i');
      delay(100);
      Keyboard.releaseAll();
      delay(delayms-200);
    }
  else if (digitalRead(3) == 0) //Hold Mouse [0,1]
    {
      if(toggleClick){
        Mouse.release(MOUSE_LEFT);
        toggleClick = false;
      } else {
        Mouse.press(MOUSE_LEFT);
        toggleClick = true;
      }
      delay(delayms+100);
    }
  else if (digitalRead(2) == 0) //Nothing F15 [0,0]
    {
      Keyboard.press(KEY_F15);
      delay(100);
      Keyboard.releaseAll();
      delay(delayms);
    }
      ////other side////
  else if (digitalRead(14) == 0) //Nothing F16 [1,0]
	{
      Keyboard.press(KEY_F16);
      delay(100);
      Keyboard.releaseAll();
      delay(delayms);
    }
  else if (digitalRead(16) == 0) //Nothing F17 [1,1]
	{
    Keyboard.press(KEY_F17);
    delay(100);
    Keyboard.releaseAll();
    delay(delayms);
  }
  else if (digitalRead(9) == 0) //Hold Run [1,2]
	{
      if(toggleRun){
        Keyboard.release(KEY_LEFT_SHIFT);
        Keyboard.release('w');
        toggleRun = false;
      } else {
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press('w');
        toggleRun = true;
      }
      delay(delayms+100);
    }
  else if (digitalRead(8) == 0) //Fast String 1 [1,3]
	{
    Keyboard.print(".deboink");
    Keyboard.press(KEY_RETURN);
    delay(100);
    Keyboard.releaseAll();
    delay(delayms);
  }
  else if (digitalRead(7) == 0) //Fast String 2 [1,4]
	{
    Keyboard.print(".boink");
    Keyboard.press(KEY_RETURN);
    delay(100);
    Keyboard.releaseAll();
    delay(delayms);
  }

  Keyboard.end();
}
