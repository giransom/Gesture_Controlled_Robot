#include <WiFi.h>
#include <HTTPClient.h>
#include <TFT_eSPI.h>
#include <JPEGDecoder.h>
#include "FS.h"
#include "SPIFFS.h"


const char* ssid = "Homedeco21";
const char* password = "8?9srj=64wtg";


String imageURL =
"http://192.168.68.119:8080/latest.jpg";


TFT_eSPI tft = TFT_eSPI();



void downloadImage()
{

  HTTPClient http;

  WiFiClient client;


  Serial.println("Downloading image...");


  http.begin(
    client,
    imageURL
  );


  int response = http.GET();


  Serial.print("HTTP: ");
  Serial.println(response);


  if(response == 200)
  {

    File file = SPIFFS.open(
      "/image.jpg",
      FILE_WRITE
    );


    if(!file)
    {
      Serial.println("SPIFFS open failed");
      http.end();
      return;
    }


    WiFiClient *stream =
    http.getStreamPtr();


    uint8_t buffer[1024];


    while(http.connected())
    {

      size_t available =
      stream->available();


      if(available)
      {

        int bytes =
        stream->readBytes(
          buffer,
          min(
            available,
            sizeof(buffer)
          )
        );


        file.write(
          buffer,
          bytes
        );

      }
      else
      {
        delay(1);
      }

    }


    file.close();


    Serial.println("Image saved");

  }


  http.end();

}




void drawImage()
{

  if(!SPIFFS.exists("/image.jpg"))
  {
    Serial.println("No image file");
    return;
  }


  JpegDec.decodeFsFile(
    "/image.jpg"
  );


  while(JpegDec.read())
  {

    tft.pushImage(
      JpegDec.MCUx * JpegDec.MCUWidth,
      JpegDec.MCUy * JpegDec.MCUHeight,
      JpegDec.MCUWidth,
      JpegDec.MCUHeight,
      JpegDec.pImage
    );

  }

}



void setup()
{

  Serial.begin(115200);


  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);


  if(!SPIFFS.begin(true))
  {
    Serial.println("SPIFFS failed");
    return;
  }


  WiFi.begin(
    ssid,
    password
  );


  Serial.print("Connecting");


  while(
    WiFi.status()!=WL_CONNECTED
  )
  {
    delay(500);
    Serial.print(".");
  }


  Serial.println();

  Serial.println("WiFi connected");


}



void loop()
{

  downloadImage();


  tft.fillScreen(
    TFT_BLACK
  );


  drawImage();


  delay(500);

}