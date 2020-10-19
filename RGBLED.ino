/* YourDuinoStarter Example: RGB_LED_Fade
 - Red-Green-Blue LED fades between colors automatically
   - Left:  RED
   - Second: +5V "Common Anode"
   - Third: BLUE
   - Right: Green
 - V1.00 09/17/12
   Based on code by Matthew L Beckler
   Questions: terry@yourduino.com */
/*-----( Declare Constants and Pin Numbers )-----*/
#define redPin   11
#define bluePin 10
#define greenPin   9

#define brighter  1  
#define dimmer    0
/*-----( Declare Variables )-----*/
int  redValue ;  // Hold the current brightness value
int  greenValue;
int  blueValue;

int  updateDelay; // Milliseconds delay on changes


void setup()   /****** SETUP: RUNS ONCE ******/
{
/* NOTE: Because the LED is "common Anode", the LEDs get brighter
   as the Arduino pin goes towards 0 volts. (It is "Inverted").
   So value=255 of OFF and value=0 in brightest.  */

  redValue = 255;  // Start with all off
  greenValue = 255;
  blueValue = 255;
  updateDelay = 5; // Ms delay. Higher will be slower. Try 2 also.
  SetLED_brightness();  // This is defined at the end of this text
}//--(end setup )---


void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{

  ColorChange(&redValue, brighter ); // Red only
  ColorChange(&redValue, dimmer );
  delay(updateDelay * 100);

  ColorChange(&greenValue, brighter ); // Green only
  ColorChange(&greenValue, dimmer );
  delay(updateDelay * 100);

  ColorChange(&blueValue, brighter ); // Blue only
  ColorChange(&blueValue, dimmer );
  delay(updateDelay * 100);

  ColorChange(&redValue, brighter ); // Red plus Green = Yellow
  ColorChange(&greenValue, brighter );
  delay(updateDelay * 100);
  ColorChange(&blueValue, brighter ); // plus Blue 
  delay(updateDelay * 100);
  ColorChange(&redValue, dimmer );
  ColorChange(&greenValue, dimmer );
  ColorChange(&blueValue, dimmer );
  delay(updateDelay * 200);


}//--(end main loop )---

/*-----( Declare User-written Functions )-----*/

/*------( This function updates the LED outputs)----*/
void SetLED_brightness()
{
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
} // End SetLED_brightness

/*--(Update one of the Colors )--------------------------*/

void ColorChange(int* LEDvalue, int howBright)
/*--( Brighten an LED to full, or dim to dark )---*/
{
  for (int i = 0; i < 255; i++)
  {
    if (howBright == dimmer)    (*LEDvalue)++;
    if (howBright == brighter)  (*LEDvalue)--;
    SetLED_brightness();
    delay(updateDelay);
  }
}
