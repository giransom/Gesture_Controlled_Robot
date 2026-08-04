#include "esp_camera.h"
#include <WiFi.h>
#include <HTTPClient.h>


// ===========================
// WiFi Settings
// ===========================

const char* ssid = "Homedeco21";
const char* password = "8?9srj=64wtg";


// ===========================
// Flask Server
// ===========================

String serverIP = "192.168.68.119";

String uploadURL =
"http://" + serverIP + ":8080/upload";


// ===========================
// AI Thinker ESP32-CAM Pins
// ===========================

#define PWDN_GPIO_NUM     32
#define RESET_GPIO_NUM    -1

#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27

#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5

#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22



// ===========================
// Camera Setup
// ===========================

void startCamera()
{

  camera_config_t config;

  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;


  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;


  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;

  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;


  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;


  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;


  config.xclk_freq_hz = 20000000;

  config.pixel_format = PIXFORMAT_JPEG;


config.frame_size = FRAMESIZE_QVGA;
config.jpeg_quality = 8;
  config.fb_count = 2;


  esp_err_t result = esp_camera_init(&config);
sensor_t *s = esp_camera_sensor_get();

s->set_brightness(s, 0);
s->set_contrast(s, 0);
s->set_saturation(s, -1);

  if(result != ESP_OK)
  {
    Serial.println("Camera init failed");
    while(true);
  }


  Serial.println("Camera Ready");

}



// ===========================
// WiFi
// ===========================

void connectWiFi()
{

  WiFi.mode(WIFI_STA);

  WiFi.begin(ssid,password);


  Serial.print("Connecting WiFi");


  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }


  Serial.println();

  Serial.println("WiFi Connected");

  Serial.print("Camera IP: ");
  Serial.println(WiFi.localIP());

}



// ===========================
// Send Image
// ===========================

void sendImage()
{

  if(WiFi.status() != WL_CONNECTED)
  {
    Serial.println("WiFi disconnected");
    return;
  }


  camera_fb_t *fb = esp_camera_fb_get();


  if(!fb)
  {
    Serial.println("Camera capture failed");
    return;
  }


  HTTPClient http;


  http.begin(uploadURL);

  http.addHeader(
    "Content-Type",
    "image/jpeg"
  );


  int response =
  http.POST(
    fb->buf,
    fb->len
  );


  Serial.print("Upload response: ");
  Serial.println(response);


  http.end();


  esp_camera_fb_return(fb);

}



// ===========================
// Setup
// ===========================

void setup()
{

  Serial.begin(115200);

  delay(1000);


  connectWiFi();

  startCamera();

}



// ===========================
// Loop
// ===========================

void loop()
{

  sendImage();

  delay(100);

}