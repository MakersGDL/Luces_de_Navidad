#define MEGA_VIXEN
//#define UNO_VIXEN

#ifdef MEGA_VIXEN
  #define MAX_CHANNELS 52
  int channels[MAX_CHANNELS] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53};
#endif

#ifdef UNO_VIXEN
  #define MAX_CHANNELS 18
  int channels[MAX_CHANNELS] = {2,3,4,5,6,7,8,9,10,11,12,13,A0,A1,A2,A3,A4,A5};
#endif

int incomingByte[MAX_CHANNELS];

void setup()
{
pinMode (10, OUTPUT);
pinMode (38, OUTPUT);

  int i;  
  Serial.begin(9600); // set up Serial at 9600 bps
  for ( i = 0; i < MAX_CHANNELS; i ++ )  pinMode(channels[i], OUTPUT);
}
void loop(){

digitalWrite (10, HIGH);
digitalWrite (38, HIGH);
  
  int i;  
  if (Serial.available() >= MAX_CHANNELS)
  {
    for (i=0; i < MAX_CHANNELS; i ++)      incomingByte[i] = Serial.read();
  }
  //for (i = 0; i < MAX_CHANNELS; i ++ )    analogWrite(channels[i], incomingByte[i]);
  for (i = 0; i < MAX_CHANNELS; i ++ ) digitalWrite(channels[i], ~incomingByte[i]);  
}
