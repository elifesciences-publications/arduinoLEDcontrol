# arduinoLEDcontrol
This code allows an arduino to take digital inputs from pins (i.e. TTL pulses from med associates) and drive multiple LEDs based on   * 1. the duration of the input (length of TTL pulse)   * 2. your desired Hz (milliseconds on and milliseconds off) 

 * Notes: 
 * 1. Our LEDs are currently wired such that high & low output are switched in what they do (turn off and on the LED). 
 *    Be sure to test yours to see if they are turning on and off appropriately. 
 * 2. Currently the setup is a 5 ms pulse at 20 Hz. (on for 5, off for 15). 
 *    
 * Last Updated by Emily Baltz 11/18/2017 
 * (Gremel Lab, UCSD Dept of Psychology. Support: Please contact cgremel at ucsd.edu) 
