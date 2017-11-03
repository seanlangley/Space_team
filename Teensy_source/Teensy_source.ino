//TEENSY CODE
//hi 
#include <RF24.h>
#define ce_pin 9
#define cs_pin 10
#define green 6
#define yellow 4
#define red 2
//#define w_pipe 0x78787878
//#define r_pipe 0xb3b4b5b6f1

char randomnextchar(int a);
int chartopin(char a);

RF24 radio(ce_pin, cs_pin);
byte w_pipe[] = {0x78, 0x78, 0x78, 0x78, 0x78};
byte r_pipe[] = {0xb3, 0xb4, 0xb5, 0xb6, 0xf1};


void setup() { 
  radio.begin();
  radio.setRetries(7, 7);
  radio.setChannel(1);
  radio.setPALevel(RF24_PA_MIN); 
  radio.openReadingPipe( 1, r_pipe); 
  radio.openWritingPipe( w_pipe ); //uses pipe 0
  radio.setCRCLength( RF24_CRC_16 );
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
    radio.startListening( );

    char data[] = "";
  
    char write[] = "abcdef";
    radio.stopListening();

    

    for(int i = 0; i < sizeof(write); i++)
    {
      
        if(!radio.write(&(write[i]), 1))
          Serial.println("Failed on write");
    }


    if(radio.available())
    {
      radio.read(&data, sizeof(data));
    }

  //sends data and makes LEDs flash
//  char data[] = "";
//  int randomchar = random(1,3); //generates a random number than will be mapped to R G Y
//  char append = randomnextchar(randomchar); //converts int to char
//  strcat(data, append); //appends the next random char
//  Serial.println(data);//test to see if this works
//  if(radio.write(&data, sizeof(data))){
//    Serial.println("success");  //sends the char stream
//  }
//  for (int i = 0; i < sizeof(data); i ++ )
//  {
//    digitalWrite(chartopin(data[i]), HIGH); //makes corresponding LEDs flash
//  }
//
//
//  //listen for Arduino input
//  //Arduino should send Y if player succeeded or N if player did not
//  char reply[] = "";
//  radio.startListening();
//  if (radio.available()){
//     radio.read(&reply, sizeof(reply):
//  }
//  if (reply == "Y") {//player succeeded
//    digitalWrite(green, HIGH);//flash green    
//    //do something
//  }
//  else 
//    digitalWrite(red, HIGH);//flash red
//    //stop game??
//  radio.stopListening();
}

char randomnextchar(int a){
  if (a == 1) 
    return 'R';
  else if (a == 2)
    return 'G';
  else if (a == 3)
    return 'Y';
  //else ??? 
}

int chartopin(int a){
  if (a == 'R')
    return 2;
  else if (a == 'Y')
    return 4;
  else if (a == 'G')
    return 6;  
}










