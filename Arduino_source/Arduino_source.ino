//TEENSY CODE

#include <RF24.h>
#define ce_pin 9
#define cs_pin 10
#define green 6
#define yellow 4
#define red 2
//#define w_pipe 0x78787878
//#define r_pipe 0xb3b4b5b6f1


RF24 radio(ce_pin, cs_pin);
byte w_pipe[] = {0x78, 0x78, 0x78, 0x78, 0x78};
byte r_pipe[] = {0xb3, 0xb4, 0xb5, 0xb6, 0xf1};

char yes = 'Y;
char no = 'N';

void setup() { 
  radio.begin();
  radio.setRetries(7, 7);
  radio.setChannel(1);
  radio.setPALevel(RF24_PA_MIN); 
  radio.openReadingPipe( 1, w_pipe); 
  radio.openWritingPipe( r_pipe ); //uses pipe 0
  radio.setCRCLength( RF24_CRC_16 );
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
//    radio.startListening( );
//
//    char data[] = "";
//  
//    char write[] = "abcdef";
//    radio.stopListening();
//
//    
//    if(radio.write(&write, sizeof(write)))
//      Serial.println("success");
//
//
//    if(radio.available())
//    {
//      Serial.println("hello world");
//      radio.read(&data, sizeof(data));
//    }

  //recieve data from TEENSY
  char data[] = "";
  radio.startListening();
  while (!radio.available()){
    ;}
  radio.read(&data, sizeof(data));
  radio.stopListening();
  
  //check the user input
  char input[] = "";
  //lol idk how to do this

  //check user input against the data
  if (input == data)
    radio.write(&yes, sizeof(yes));
  else
    radio.write(&no, sizeof(no));
}











