/*
 * Arduino LED control
 * 
 * Introductory Text: 
 * This code allows an arduino to take digital inputs from pins (i.e. TTL pulses from med associates) and drive multiple LEDs based on 
 * 1. the duration of the input (length of TTL pulse) 
 * 2. your desired Hz (milliseconds on and milliseconds off) 
 * 
 * Notes: 
 * 1. Our LEDs are currently wired such that high & low output are switched in what they do (turn off and on the LED). 
 *    Be sure to test yours to see if they are turning on and off appropriately. 
 * 2. Currently the setup is a 5 ms pulse at 20 Hz. (on for 5, off for 15). 
 *    
 * Last Updated by Emily Baltz 11/18/2017 
 * (Gremel Lab, UCSD Dept of Psychology. Support: Please contact cgremel at ucsd.edu) 
 */
class Flasher
{
        // Class Member Variables
        // These are initialized at startup
        int inputPin;     // the number of the input pin
        int ledPin;      // the number of the LED pin
        long OnTime;     // milliseconds of on-time
        long OffTime;    // milliseconds of off-time

        // These maintain the current state
        int ledState;                 // ledState used to set the LED
        int inputState;               // input state 
        unsigned long previousMillis; // will store last time LED was updated
        

  // Constructor - creates a Flasher 
  // and initializes the member variables and state
  public:
  Flasher(int input, int pin, long on, long off)// long duration: for totalTime/duration
  {
        inputPin = input;
        pinMode(inputPin, INPUT_PULLUP);   //input pullup is used here rather than input because we want the pin to be High (turning the LED off)
        ledPin = pin;
        pinMode(ledPin, OUTPUT);     

        OnTime = on;
        OffTime = off;
        
        ledState = LOW; 
        inputState = LOW;
        previousMillis = 0; 
      
  }

  void Update()
  {
    unsigned long currentMillis = millis();
    inputState = digitalRead(inputPin); 

    if (inputState == LOW) 
    {
       if ((ledState == LOW) && (currentMillis - previousMillis >= OnTime))
          {
             ledState = !ledState;  // Turn it off
             previousMillis = currentMillis;  // Remember the time
             digitalWrite(ledPin, ledState);  // Update the actual LED             
          }
       if ((ledState == HIGH) && (currentMillis - previousMillis >= OffTime))
          {
              ledState = !ledState;  // turn it on
              previousMillis = currentMillis;   // Remember the time
              digitalWrite(ledPin, ledState);   // Update the actual LED
          }
    }
   if (inputState == HIGH)
       {
        ledState = HIGH;  // turn it off
        digitalWrite(ledPin, ledState);
       }    
  };
   
};


// UPDATE HERE for pins and hz

// 5 ms pulse 20X in 1 second
Flasher led1(A5, 5, 15, 5); //thick cable input
Flasher led2(A5, 7, 15, 5); ///
Flasher led3(9, 1, 15, 5);
Flasher led4(9, 3, 15, 5);

void setup()
{
}

void loop()
{
  led1.Update();
  led2.Update();
  led3.Update();
  led4.Update();
 }

