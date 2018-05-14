
#include <Servo.h>

volatile long countR; //Set counter to zero  

byte servoPin = 9; //Servo pin (thruster) set to #9
Servo servo; //

int BTNPIN=4; //Set button pin to number 4, this is the switch pin
int OUTPIN=5; //Set output (5 mV) from ardiuno through switch to pin 4
 
void setup() {
  servo.attach(servoPin);
  servo.writeMicroseconds(1500); // send "stop" signal to ESC.
  delay(10000); // delay to allow the ESC to recognize the stopped signal

//Motor setup
  #define motor 6 //motor speed control
  #define dir 7 //motor direction control
  #define encoderR 3 //encoder pulse

// Motors
pinMode(motor, OUTPUT); 
pinMode(dir, OUTPUT);
pinMode(encoderR, INPUT);

digitalWrite(encoderR, HIGH);

//initialize the motor directions to forward and the speed to zero
digitalWrite(dir, 1);
analogWrite(motor, 0);

//button pin
pinMode(BTNPIN,INPUT);
pinMode(OUTPIN,OUTPUT);
digitalWrite(OUTPIN,HIGH);
}

void loop() {


//HERE IS WHERE WE USE THE MAGNET TO CLOSE
countR==0;
attachInterrupt(digitalPinToInterrupt(encoderR), read_encoderR, FALLING);
int btnOn=digitalRead(BTNPIN);
digitalWrite(dir, 0);
analogWrite(motor, 100);
while(btnOn==HIGH&countR<10884.47*12*20*20){
btnOn=digitalRead(BTNPIN);
read_encoderR() ;
}

digitalWrite(dir, 1);
analogWrite(motor, 0);


  int num=1; 
// Set signal value to sit for 15 minutes 
  servo.writeMicroseconds(1425); // Send signal to ESC.
  delay(900000); //run for 15 minutes = 900000 us

//Set signal value to run forward 1 minutes
  servo.writeMicroseconds(1375); // Send signal to ESC.
  delay(60000); //run for 1 minutes = 300000 us

//Set signal value to sit for 1 minutes
  servo.writeMicroseconds(1500); // Send signal to ESC.
  delay(60000); //run for 1 minutes = 180000 us

 // Set signal value to run reverse 12 minutes
    servo.writeMicroseconds(1800); // Send signal to ESC.
    delay(720000); //run for 12 minutes = 900000 us

//HERE IS WHERE WE UNHOOK THE MAGNET

digitalWrite(dir, 1); //GO IN REVERSE
analogWrite(motor, 100); 

countR==0;
attachInterrupt(digitalPinToInterrupt(encoderR), read_encoderR, FALLING);
while(countR<10884.47*12*20*20){
read_encoderR() ;
}
    
digitalWrite(dir, 1);
analogWrite(motor, 0);

//  int signal = 1500; // Set signal value to stop
   servo.writeMicroseconds(1500); // Send signal to ESC.
    delay(1000);
    
//delay(10000); //NEED TO SET THE TIME WHEN THIS IS FAR ENOUGH FROM MAGNET

if(num=1){
   while(1);
}
}

void read_encoderR()
{
countR++;
}




