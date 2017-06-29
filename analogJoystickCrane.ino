#define trollyInput A0
#define trollyOutput 3
#define trollyOutBtn 4
#define trollyInBtn 5

void setup() {
  pinMode(trollyInput, INPUT);
  pinMode(trollyOutput, OUTPUT);
  pinMode(trollyOutBtn, INPUT_PULLUP);
  pinMode(trollyInBtn, INPUT_PULLUP);
}

void loop() {
  trollyVal = (map(analogRead(trollyInput), 1, 1023, 0, 255);
  static enum {moving, stoppedOut, stoppedIn, moving, trollyStopped} state;
  static unsigned long trollyStopped;
  unsigned long now = millis();
  
//  if (buttonState == HIGH && analogRead(input) > 500)
//{
//  digitalWrite(motorPin, 250);
//  }
  switch(trollyState) {
    case moving:
      if (analogRead(trollyInput) < 550 && analogRead(trollyInput) > 450 && digitalRead(trollyOutBtn) == HIGH && digitalRead(trollyInBtn) == HIGH) 
      {
        digitalWrite(trollyOutput, analogRead(trollyInput);
        state = trollyStopped;
       }
        else if (analogRead(trollyInput) > 550 && digitalRead(trollyOutBtn) == HIGH && digitalRead(trollyInBtn == HIGH)) 
       {
        digitalWrite(trollyOutput, analogRead(trollyInput);
        state = moving;
       }
        else if ((analogRead(trollyInput) < 450 && digitalRead(trollyOutBtn) == HIGH && digitalRead(trollyInBtn == HIGH)) 
       {
        digitalWrite(trollyOutput, analogRead(trollyInput));
        state = moving;
       }
        else if ((digitalRead(trollyOutBtn) == LOW)
      {
        digitalWrite(trollyOutput, 350);
        state = stoppedOut;
        timeStopped = now;
      }
        else if ((digitalRead(trollyInBtn) == LOW)
      {
        digitalWrite(trollyOutput, 650);
        state = stoppedIn;
        timeStopped = now;
      }
      break;
    case stoppedOut:
      if (now - timeStopped >= 3000 && analogRead(trollyInput) < 450)
      {
        digitalWrite(trollyOutput, analogRead(trollyInput);
        state moving;
      }
      break;
      case stoppedIn:
      if (now - timeStopped >= 3000 && analogRead(trollyInput) 550)
      {
        digitalWrite(trollyOutput, analogRead(trollyInput);
        state moving;
      }
      break;

  }
  
}
