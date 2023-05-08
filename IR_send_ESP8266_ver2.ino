#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <SPI.h>
#include <SD.h>
#include <IRremote.h>

IRsend irsend(15);
//uint16_t irSignal[500];
uint16_t irSignal[500];
const int khz = 38;

File myFile;
int i = 0;

#define STASSID "****"
#define STAPSK "****"

const char* ssid = STASSID;
const char* pass = STAPSK;
const int SD_pin = 16;

ESP8266WebServer server(80);

////////open File and read code ///////////

void openFile(String command_name) {

  Serial.print("Initializing SD card ...");

  if(!SD.begin(SD_pin)){
    Serial.println("initialization failed!");
  }
  Serial.println("initialization done.");
  String f_name = command_name + ".TXT";
  myFile = SD.open(f_name);
  if(myFile){
    
    String line;
      while(myFile.available()) {
        //Serial.print("i::");
        //Serial.println(i);
        char ch = myFile.read();
        if(ch == ',' || ch == '\n') {
      
          line.trim();
          Serial.println(line);
          int tmp = line.toInt();
          irSignal[i] = tmp;
          line = "";
          i++;
        }else if(ch == '\n'){
          //Serial.print(":::");
          //Serial.println(i);
          
          myFile.close();
          break;
        }else{
          line += String(ch);
        }
      }
  }else{
    Serial.println("error opening text.txt");
  }
  i = 0;
  myFile.close();
 }


////////////////////////////////////////////////////////
///////command/////////////////////////////////////////
///////////////////////////////////////////////////////
void ir_send(String FileName) {
  openFile(FileName);
  for(int j=0; j<10; j++){
    irsend.sendRaw(irSignal, sizeof(irSignal)/sizeof(irSignal[0]),khz);
    //Serial.println("a");
    delay(100);
  }
  
}

void handleRoot() {
  server.send(200,"text/plain","hello from esp8266!\r\n");
}

void hello() {
  server.send(200, "text/plain","hello from esp8266!!\r\n");
  delay(3000);
}

// power 
void ac_on() {
  
  ir_send("ON");
  server.send(200, "text/plain","hello from esp8266!!\r\n");

}


void ac_off() {
  
  ir_send("OFF");
  server.send(200, "text/plain","ac_off from esp8266!!\r\n");
  
}

//AC mode

void ac_auto() {
  ir_send("auto");
  server.send(200, "text/plain","ac_auto from esp8266!!\r\n");
}

void ac_cool() {
  ir_send("ac_cool");
  server.send(200, "text/plain","ac_cool from esp8266!!\r\n");
}

void ac_hot() {
  ir_send("ac_hot");
  server.send(200, "text/plain","ac_hot from esp8266!!\r\n");
  
}

void ac_dehumidification() {
  ir_send("dehumidification");
  server.send(200, "text/plain","dehumidification from esp8266!!\r\n");
  
}

void ac_dehumidification_low() {
  ir_send("dehumidification_low");
  server.send(200, "text/plain","dehumidification_low from esp8266!!\r\n");

}

//fan mode

void fan_1() {
  ir_send("fan_1");
  server.send(200, "text/plain","fan_1 from esp8266!!\r\n");
  
}

void fan_2() {
  ir_send("fan_2");
  server.send(200, "text/plain","fan_2 from esp8266!!\r\n");
  
}

void fan_3() {
  ir_send("fan_3");
  server.send(200, "text/plain","fan_3 from esp8266!!\r\n");
  
}

void fan_4() {
  ir_send("fan_4");
  server.send(200, "text/plain","fan_4 from esp8266!!\r\n");
  
}

void fan_auto() {
  ir_send("fan_auto");
  server.send(200, "text/plain","fan_auto from esp8266!!\r\n");
  
}

void fan_mini() {
  ir_send("fan_mini");
  server.send(200, "text/plain","fan_mini from esp8266!!\r\n");
  
}

//swing mode

void swing_1() {
  ir_send("swing_1");
  server.send(200, "text/plain","swing_1 from esp8266!!\r\n");
  
}

void swing_2() {
  ir_send("swing_2");
  server.send(200, "text/plain","swing_2 from esp8266!!\r\n");
  
}


void swing_3() {
  ir_send("swing_3");
  server.send(200, "text/plain","swing_3 from esp8266!!\r\n");
  
}

void swing_4() {
  ir_send("swing_4");
  server.send(200, "text/plain","swing_4 from esp8266!!\r\n");
  
}

void swing_5() {
  ir_send("swing_5");
  server.send(200, "text/plain","swing_5 from esp8266!!\r\n");
  
}

void swing_auto() {
  ir_send("swing_auto");
  server.send(200, "text/plain","swing_auto from esp8266!!\r\n");
  
}


//below the codes about temperature 
void temp_16C() {
  ir_send("16C");
  server.send(200, "text/plain","16C from esp8266!!\r\n");
  
}

void temp_17C() {
  ir_send("17C");
  server.send(200, "text/plain","17C from esp8266!!\r\n");
  
}

void temp_18C() {
  ir_send("18C");
  server.send(200, "text/plain","18C from esp8266!!\r\n");
  
}

void temp_19C() {
  ir_send("19C");
  server.send(200, "text/plain","19C from esp8266!!\r\n");
  
}

void temp_20C() {
  ir_send("20C");
  server.send(200, "text/plain","20C from esp8266!!\r\n");
  
}

void temp_21C() {
  ir_send("21C");
  server.send(200, "text/plain","21C from esp8266!!\r\n");
  
}

void temp_22C() {
  ir_send("22C");
  server.send(200, "text/plain","22C from esp8266!!\r\n");
  
}

void temp_23C() {
  ir_send("23C");
  server.send(200, "text/plain","23C from esp8266!!\r\n");

}

void temp_24C() {
  ir_send("24C");
  server.send(200, "text/plain","24C from esp8266!!\r\n");
  
}

void temp_25C() {
  ir_send("25C");
  server.send(200, "text/plain","25C from esp8266!!\r\n");


}

void temp_26C() {
   ir_send("26C");
  server.send(200, "text/plain","26C from esp8266!!\r\n");
 
}


void temp_27C() {
  ir_send("27C");
  server.send(200, "text/plain","27C from esp8266!!\r\n");
 
}

void temp_28C() {
  ir_send("28C");
  server.send(200, "text/plain","28C from esp8266!!\r\n");
  
  
}

void temp_29C() {
  ir_send("29C");
  server.send(200, "text/plain","29C from esp8266!!\r\n");
  
  
}

void temp_30C() {
  ir_send("30C");
  server.send(200, "text/plain","30C from esp8266!!\r\n");
  
 
}


/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
////////////////////////////////////////////////////////




void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);
  Serial.print("");


  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
    
  }
  Serial.print("");
  Serial.print("Connected to");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if(MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/ac_on",ac_on);
  server.on("/ac_off",ac_off);

  server.on("/ac_auto",ac_auto);
  server.on("/ac_cool",ac_cool);
  server.on("/ac_hot",ac_hot);
  server.on("/ac_dehumidification",ac_dehumidification);
  server.on("/ac_dehumidification_low",ac_dehumidification_low);

  server.on("/fan_1",fan_1);
  server.on("/fan_2",fan_2);
  server.on("/fan_3",fan_3);
  server.on("/fan_4",fan_4);
  server.on("/fan_auto",fan_auto);
  server.on("/fan_mini",fan_mini);

  server.on("/swing_1",swing_1);
  server.on("/swing_2",swing_2);
  server.on("/swing_3",swing_3);
  server.on("/swing_4",swing_4);
  server.on("/swing_5",swing_5);
  server.on("/swing_auto",swing_auto);
  
  server.on("/16C",temp_16C);
  server.on("/17C",temp_17C);
  server.on("/18C",temp_18C);
  server.on("/19C",temp_19C);
  server.on("/20C",temp_20C);
  server.on("/21C",temp_21C);
  server.on("/22C",temp_22C);
  server.on("/23C",temp_23C);
  server.on("/24C",temp_24C);
  server.on("/25C",temp_25C);
  server.on("/26C",temp_26C);
  server.on("/27C",temp_27C);
  server.on("/28C",temp_28C);
  server.on("/29C",temp_29C);
  server.on("/30C",temp_30C);
  
  server.on("/hello",hello);
  server.on("/",[](){
      server.send(200,"text/plain","this works as well");
    });
  
  server.begin();
  
}



void loop() {
  server.handleClient();
  MDNS.update();
  
}



  
 
