// ---------------------------------------------------------------- //
// Adruino Pulse Dialer
// 
// Mark L. Martin
// 2/7/2023
// ---------------------------------------------------------------- //


#define relayPin 4  // momentary relay to simulate person pressing button

// phone number for "It could always suck more 605-475-6964"

int number_to_dial[]={6,0,5,4,7,5,6,9,6,4};
int numbers = 0;
int number_loop = 0;

void setup() 
{
  pinMode( relayPin, OUTPUT ); // Sets the relayPin as output
  
  Serial.begin(9600); // Serial Communication is starting with 9600 of baudrate speed
  Serial.println( "Pulse Dialer Version 1.0  2/7/2023" );

  digitalWrite( LED_BUILTIN, LOW );
  digitalWrite( relayPin, LOW );
}  //end setup()


void pulse( int number )
{
  int little_loop = 0;
  Serial.print( number );
  if (number == 0 )    // zero is a special case.... needs 10 pulses
       number = 10;
   for ( little_loop = 0 ; little_loop < number; little_loop++ )
   {
      digitalWrite( relayPin, HIGH );  //press the close button
      digitalWrite( LED_BUILTIN, HIGH );
      delay ( 60 );
      digitalWrite( relayPin, LOW );  //press the close button
      digitalWrite( LED_BUILTIN, LOW );
      delay ( 40 );
   }
   delay( 500 );  // inter pulse delay 1/2 second
}

void loop()   // main function  
{
  numbers = sizeof ( number_to_dial )/ sizeof( number_to_dial[0]);
  
  Serial.print( " size of numbers " );
  Serial.println( numbers );
  for ( number_loop = 0; number_loop < numbers; number_loop++ )
  {
    pulse( number_to_dial[number_loop] );
  }
  Serial.println( );
  delay( 5000 );  // let the prints go out
  abort(); // stop the program
}  // end main loop
