#define trollyInput A0
#define trollyOutput 3
#define trollyOutBtn 4
#define trollyInBtn 5
#define led1 13
#define led2 12
int TrollyVal;

void setup() {
  pinMode(trollyInput, INPUT);
  pinMode(trollyOutput, OUTPUT);
  pinMode(trollyOutBtn, INPUT_PULLUP);
  pinMode(trollyInBtn, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  
               //set led1 variables
  unsigned long led1Time = 0;
  unsigned long newLed1Time = millis();
  int led1State = LOW;   
  const int led1TimeInterval = 1000;
   
               //start led1
   if (newLed1Time - led1Time >= led1TimeInterval) 
    {
      led1Time = newLed1Time;
      if (led1State == LOW) {
          led1State = HIGH;
    } 
      else {
      led1State = LOW;
    }
    digitalWrite(led1, led1State);
    }
  
              //set led2 variables
  unsigned long led2Time = 0;
  unsigned long newLed2Time = millis();
  int led2State = HIGH;   
  const int led2TimeInterval = 1500;
               
  //start led2
    if (newLed2Time - led2Time >= led2TimeInterval) 
    {
      led2Time = newLed2Time;
      if (led2State == HIGH) {
          led2State = LOW;
    } 
      else {
      led2State = HIGH;
    }
    digitalWrite(led2, led2State);
    }
  
//  if (buttonState == HIGH && analogRead(input) > 500)
//{
//  digitalWrite(motorPin, 250);
//  }
              // set trolly variables
  int trollyVal;
  trollyVal = analogRead(trollyInput);
  trollyVal = (map(analogRead(trollyInput), 1, 1023, 0, 255));
  static enum {moving, stoppedOut, stoppedIn, trollyStopped} state;
  static unsigned long timeStopped;
  const int autoPilot = 3000;
  unsigned long now = millis();
               
  switch(state) {
    case moving:
      if (analogRead(trollyInput) <= 550 && analogRead(trollyInput) >= 450 && digitalRead(trollyOutBtn) == HIGH && digitalRead(trollyInBtn) == HIGH) 
      {
        analogWrite(trollyOutput, analogRead(trollyInput));
        state = trollyStopped;
       }
        else if (analogRead(trollyInput) >= 550 && digitalRead(trollyOutBtn) == HIGH && digitalRead(trollyInBtn == HIGH)) 
       {
        analogWrite(trollyOutput, analogRead(trollyInput));
        state = moving;
       }
        else if ((analogRead(trollyInput) <= 450 && digitalRead(trollyOutBtn) == HIGH && digitalRead(trollyInBtn == HIGH))) 
       {
        analogWrite(trollyOutput, analogRead(trollyInput));
        state = moving;
       }
        else if ((digitalRead(trollyOutBtn) == LOW))
      {
        analogWrite(trollyOutput, 350);
        state = stoppedOut;
        timeStopped = now;
      }
        else if ((digitalRead(trollyInBtn) == LOW))
      {
        analogWrite(trollyOutput, 650);
        state = stoppedIn;
        timeStopped = now;
      }
      break;
    case stoppedOut:
      if (now - timeStopped >= 3000 && analogRead(trollyInput) <= 450)
      {
        analogWrite(trollyOutput, analogRead(trollyInput));
        state = moving;
      }
      break;
      case stoppedIn:
      if (now - timeStopped >= 3000 && analogRead(trollyInput) >= 550)
      {
        analogWrite(trollyOutput, analogRead(trollyInput));
        state = moving;
      }
      break;

  }
  
}
