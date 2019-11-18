 /*  PRIZM Controller example program
 *  Spin DC motor channel 1 for 5 seconds, then coast to a stop.
 *  After stopping, wait for 2 seconds, spin in opposite direction.
 *  Continue to repeat until RED reset button is pressed.
 *  author PWU on 08/05/2016
*/

  #include <PRIZM.h>    // include the PRIZM library in the sketch
  PRIZM prizm;          // instantiate a PRIZM object “prizm” so we can use its functions

void setup() {


  prizm.PrizmBegin();   // Initialize the PRIZM controller
  prizm.setMotorInvert(2,1);
}

void loop() {     // repeat in a loop

  prizm.setServoPosition(2,90);
  prizm.setServoPosition(2,100);
  prizm.setMotorSpeeds(360,360);
 //prism.setMotorPowers(speedMotor1, speedMotor2)
  delay(2000);  // After stopping, wait here for 2 seconds
  
  prizm.setMotorSpeeds(200,360);
  delay(1000);                  // After stopping, wait here for 2 seconds, then repeat
  prizm.setMotorSpeeds(360,360);   //go forward  
  delay (2000);
  prizm.setMotorSpeeds(360,200);  //turn right
  delay (1000);
  prizm.setMotorSpeeds(360,360);   //go forward
  delay (1000);
   prizm.setServoPosition(2,80);
  prizm.PrizmEnd();
  }
