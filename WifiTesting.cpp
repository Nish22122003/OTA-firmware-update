#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "PinAllocation.h"
#include <ESP8266WiFiMulti.h>
#include <WiFiClient.h>
#include "ESP8266httpUpdate.h"
ESP8266WiFiMulti WiFiMulti;

String esid     = "";
String epass    = "";


HTTPClient http;
//*******************************************RSSI_Strength*******************************************************************************************************************************//

void WiFi_RSSI_STR(void)
{
  //Serial.begin(9600);
//  initWiFi();
  Serial.print("RRSI: ");
  Serial.println(WiFi.RSSI());
}

void WiFi_RSSI_SIG_LOOP()
{
  long WiFi_Sig = WiFi.RSSI();

      if(WiFi_Sig < 0 && WiFi_Sig > -10)
      {
       Serial.println("High quality: 98% ");
       Serial.println(WiFi.RSSI());
      }
       else if(WiFi_Sig < -10 && WiFi_Sig > -39)
      {
       Serial.println("High quality: 95% ");
       Serial.println(WiFi.RSSI());
      }
        else if(WiFi_Sig < -40 && WiFi_Sig > -50)
       {
        Serial.println("High quality: 90% ");   // foe -55 db
        Serial.println(WiFi.RSSI());
       }
      else if (WiFi_Sig < -50 && WiFi_Sig > -60)
      {
        Serial.println ("Good quality: 75% ");         // for -75 db
        Serial.println(WiFi.RSSI());
      }
       else if (WiFi_Sig < -60 && WiFi_Sig > -70)
      {
        Serial.println ("Midium quality: 50% ");         // for -75 db
        Serial.println(WiFi.RSSI());
      }
      else if (WiFi_Sig < -70 && WiFi_Sig > -80)
      {
        Serial.println ("Midium quality: 40% ");         // for -75 db
        Serial.println(WiFi.RSSI());
      }
      else if (WiFi_Sig < -80 && WiFi_Sig > -90)
      {
        Serial.println ("Low quality: 30% ");         // for -75 db
        Serial.println(WiFi.RSSI());
      }
      else if (WiFi_Sig < -90 && WiFi_Sig > -96)
      {
        Serial.println ("Low quality: 10% ");         // for -75 db
        Serial.println(WiFi.RSSI());
      }
      else if (WiFi_Sig < -100)
      {
        Serial.println ("No Signal : 0% ");         // for -75 db
        Serial.println(WiFi.RSSI());
      }
      else
        Serial.print("WiFi is not Connected");
      delay(100);
}





/*********************************THINKSPEAK BEGIN********************************************************/


// void THINK_SPEAK_RD_WRT(void)
// {
//     String serverName = "http://api.thingspeak.com/update?";
//     String apiKey;
//     char SerialStarData;
//     String ReadWriteData;
//     String field1;
//     String field2;
//     String field3;
//     String field4;
//     String field5;
//     String field6;
//     String field7;
//     String field8;
    
//     String Channel;
//     String field;
//     String Outputdata;
//     String payload;
//     String MainData;
//     String DataToMicrocon;
//    // if (Serial.available())
//     //{
//      //SerialStarData = Serial.read();
//      //if (SerialStarData == '*')
//      //{
//         ReadWriteData = Serial.readStringUntil('<');
//         if(ReadWriteData == "W")
//         {
//           apiKey = Serial.readStringUntil('>');
//           field1 = Serial.readStringUntil('&');
//           field2 = Serial.readStringUntil('&');
//           field3 = Serial.readStringUntil('&');
//           field4 = Serial.readStringUntil('&');
//           field5 = Serial.readStringUntil('&');
//           field6 = Serial.readStringUntil('&');
//           field7 = Serial.readStringUntil('&');
//          // field8 = Serial.readStringUntil('\n');

//            delay(100);

//       //Check WiFi connection status
//       if(WiFi.status()== WL_CONNECTED)
//       {
//         HTTPClient http; 
       
//         // Data to send with HTTP POST
//         String httpRequestData = serverName + "api_key=" + apiKey + + "&field1=" + field1 + "&field2=" + field2 + "&field3=" + field3 + "&field4=" + field4 + "&field5=" + field5 + "&field6=" + field6 +  "&field7=" + field7;          
//         // Send HTTP POST request
//         http.begin(httpRequestData);
//         // Specify content-type header
//         http.addHeader("Content-Type", "application/x-www-form-urlencoded");
//         Serial.println(httpRequestData);
//         int httpResponseCode = http.GET();
   
//         Serial.print("HTTP Response code: ");
//         Serial.println(httpResponseCode);

//         payload = http.getString();
//         Serial.print("payload is: ");
//         Serial.println(payload);
       
//         // Free resources
//         http.end();
//         }
//      }
//      else if(ReadWriteData == "R")
//       {
//          apiKey  = Serial.readStringUntil('>');
//          Channel = Serial.readStringUntil('>');
//          field   = Serial.readStringUntil('>');
//          String httpRequestData = "http://api.thingspeak.com/channels/" + Channel + "/fields/" + field + "/last.json?api_key=" + apiKey + "&results=2";
//          Serial.print("httpRequestData is ");
//          Serial.println(httpRequestData);
//            if(WiFi.status()== WL_CONNECTED)
//              {
//                 HTTPClient http;        
//                 http.begin(httpRequestData);
//             // Specify content-type header
//                 http.addHeader("Content-Type", "application/x-www-form-urlencoded");
//                 Serial.println(httpRequestData);
//                 int httpResponseCode = http.GET();
           
//                 Serial.print("HTTP Response code: ");
//                 Serial.println(httpResponseCode);
        
//                 payload = http.getString();
//                 Serial.print("payload is: ");
//                 Serial.println(payload);
               
//                 // Free resources
//                 http.end();
//              }
//              //*R<DY20OO1OKG1V0Q49>1369048>1>
//          Outputdata = payload.substring(61,62);
//          DataToMicrocon = payload.substring(61,64);
//          Serial.print("*<");
//          Serial.print(DataToMicrocon);
//          Serial.print(">");
//          MainData = Serial.readStringUntil('"');
//          Serial.print(Outputdata);
//          //Serial.print("MainData is : ");

//        }
  
// }
//**************************************Firmware_Update*****************************************************************************************************************************//

const float version= 1.00;
void FRMWR_UPD(void)
{
   //  http.begin(url_version);               // for security, ssl certification is required. 
   //  delay(100);
   //  int httpCode = http.GET();            // Get the version info 
   //  delay(100);                                     
   //  String payload; // String
   //  if (httpCode == HTTP_CODE_OK)         // Check flag for  version received 
   //  {
   //    payload = http.getString();         // save received version
   //    Serial.println(payload);
   //  }
   //  else
   //  {
   //    Serial.print("error in downloading version file:");
   //    Serial.println(httpCode);
   //   }
   //  http.end();
   //  if (httpCode == HTTP_CODE_OK)        
   //  {
   //    if( version >= payload.toFloat()  )              // Check flag, this is where it compares the previous version and the current version if( payload.equals(version))
   //    {   
   //       Serial.println("Device on latest firmware version");    // if its equal do nothing 
   //    }
   //  else
   //  {
   //     Serial.println("New firmware detected");    // else Get the frimware 
   //     Serial.println(payload.toFloat());
   //     WiFiClient client;
  
   //     ESPhttpUpdate.setLedPin(LED_BUILTIN, LOW);   // This blinks untill the code gets uploaded #notRequired tho', useful to note that uploading has initiated when the led flickers
  
   //    //," ","5B:FB:D1:D4:49:D3:0F:A9:C6:40:03:34:BA:E0:24:05:AA:D2:E2:01"); 
   //   t_httpUpdate_return ret = ESPhttpUpdate.update(url_bin);      // returns the binary of the firmware 
   //    switch (ret) 
   //    {
   //      case HTTP_UPDATE_FAILED:
   //        Serial.printf("HTTP request failed (%d): %s\n", ESPhttpUpdate.getLastError(), ESPhttpUpdate.getLastErrorString().c_str()); // error flag
   //        break;
   //    case HTTP_UPDATE_NO_UPDATES:
   //        Serial.println("No updates");
   //        break;
   //    case HTTP_UPDATE_OK:
   //        Serial.println("HTTP_UPDATE_OK");
   //        break;
   //    } 
   //   }
   // }  
}

void readDataFromURL(void)
{
  String payload;
 // wait for WiFi connection
  Serial.println("getting in the loop....");
  if ((WiFiMulti.run() == WL_CONNECTED)) 
  {

    WiFiClient client;
    HTTPClient http;
    int httpCode;
    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://www.kriyaanvan.com/wp-content/uploads/2023/10/test.version")) // HTTP url should be changed from here
    {  


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      httpCode = http.GET();
      Serial.print(httpCode);

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      //http.end();

    } else {
      Serial.println("[HTTP] Unable to connect");
    }
    Serial.println("################");
    Serial.println(payload);
    Serial.println("################");
    //int httpCode = http.GET();
    if (httpCode == HTTP_CODE_OK)        
    {
      if( version >= payload.toInt()  )              // Check flag, this is where it compares the previous version and the current version if( payload.equals(version))
      {   
        Serial.println("Device on latest firmware version");    // if its equal do nothing 
      }
    else
    {
      Serial.println("New firmware detected");    // else Get the frimware 
      Serial.println(payload.toFloat());
      WiFiClient client;
  
      ESPhttpUpdate.setLedPin(LED_BUILTIN, LOW);   // This blinks untill the code gets uploaded #notRequired tho', useful to note that uploading has initiated when the led flickers
  
      //," ","5B:FB:D1:D4:49:D3:0F:A9:C6:40:03:34:BA:E0:24:05:AA:D2:E2:01"); 
      t_httpUpdate_return ret = ESPhttpUpdate.update(client, "kriyaanvan.com", 80, "/wp-content/uploads/2023/10/BlinkG2_UART.ino_.bin");      // returns the binary of the firmware ESPhttpUpdate.update(url_bin); 
      switch (ret) 
      {                                                                                                                           //  http://www.kriyaanvan.com/wp-content/uploads/2023/10/BlinkG2_UART.ino_.bin
        case HTTP_UPDATE_FAILED:
          Serial.printf("HTTP request failed (%d): %s\n", ESPhttpUpdate.getLastError(), ESPhttpUpdate.getLastErrorString().c_str()); // error flag
          break;
        case HTTP_UPDATE_NO_UPDATES:
          Serial.println("No updates");
          break;
        case HTTP_UPDATE_OK:
          Serial.println("HTTP_UPDATE_OK");
          break;
      } 
     }
   }  
  }
  http.end();
  delay(10000);
 //readDataFromURL();  
}
