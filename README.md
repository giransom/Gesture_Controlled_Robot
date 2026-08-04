# Gesture_Controlled_Robot
The goal of the project is for a robot car to mover based on the movement of the hand controller. This project utilizes UART communication through HC 05 bluetooth modules to create send and receive messages between an UNO &amp; Nano.

![Headstone Image](Gesture_Controlled_Robot_Picture.HEIC)

# Code
Base Project Code
- [Complete Hand Module Code: Nano](Gesture_Controlled_Robot_Hand_Code.ino)
- [Complete Robot Car Module Code](Gesture_Controlled_Robot_Robot_Code.ino)
- [Bluetooth Connection Test: UNO](Bluetooth_Tester_UNO.ino)
- [Bluetooth Connection Test: BLE 33 Sense](Bluetooth_Tester_BLE_33_Sense.ino)
- [AT Mode Code: UNO](AT_Mode_UNO.ino)
- [AT Mode Code: BLE 33 Sense](AT_Mode_BLE_33_Sense.ino)

HPV Camera & Screen
- [Stream Live Video from Camera](server.py)
- [Stream Capture Images from Camera](image_stream_server.py)
- [Setting Up IP Adrdess](setup_server.py)
- [Final Camera Live Stream Code](ESP32_Camera.ino)
- [Final Display Live Stream Code](Display_Camera.ino)


# Bill of Materials
Base Project Parts
| **Part** | **Note** | **Price** | **Link** |
|:--:|:--:|:--:|:--:|
| Sunfounder Kit | Has main components including Arduino Uno, ultrasonic sensor, etc. | $62.99 | <a href="https://www.amazon.com/SunFounder-Compatible-Tutorials-Including-Controller/dp/B0B778L1DZ/ref=sr_1_1?crid=3JQTX3SPFIY9Z&dib=eyJ2IjoiMSJ9.D9LrCZJnua_keVMLJz2FWi87-vYq5Z0c0hghVjdTqVV5SxTVgutlUut8NIgJpkDha5RIUUEOd8ZL_9-liu4TuIX3Y5c9E3mrmlKMD_2d9cnuKu55yBqRD35FcNSR2oUIVkT7byKksfuqXVAx34A8gUuPMYKaM3Jepu1QA3uOutR5sR0O3bugifITwp4OocPwYE4ZDNZaCae7Y3Ydd5zuneo_8PLiYwbdyVH9QvcGEwg.-iuZvwFJywFFRggszeNpXLuAEE8nPtLKbqmhVUOfLc0&dib_tag=se&keywords=sunfounder+3+in+1+starter+kit+for+arduino+uno&qid=1718980379&sprefix=3+in+1+ard%2Caps%2C120&sr=8-1"> Link </a> |
| Arduino Nano BLE 33 Sense | Has main components including Arduino Uno, ultrasonic sensor, etc. | $39.7 | <a href="https://www.amazon.com/Arduino-Nano-Sense-headers-ABX00070/dp/B0BQHZ88WD/ref=sr_1_4?crid=1BTYPUQCTIWYN&dib=eyJ2IjoiMSJ9.5ykyUyT10Vdnbme1Ur85NoPh9YmzeyxQKWTP0jF0ju7Zw9b2hLtWjY3pTyREGe5HkneZz75CgR3J9S8HJbMwmvkj1c1Mu9x0rZ651S1aBHwNqxIYbKjWG8yzYzDh5tcKP57E9RxRmqavQMCJ-QtCLIFas8oQKdBZDx67b_JUYJ3hdfDjHDXrimHAEzVTZrVAwh6NOXZ8-yMZIcp72LVtDsuQxyCvkrDyZM1EbuZQHlc.iy6QHwMR4-UrQZrInFc0eTSZJP6LewrRVqwpOfrQCG0&dib_tag=se&keywords=arduino+nano+33+ble&qid=1748096993&sprefix=arduino+nano+33ble%2Caps%2C151&sr=8-4"> Link </a> |
| Accelerometer | Has main components including Arduino Uno, ultrasonic sensor, etc. | $9 | <a href="https://www.amazon.com/dp/B0D2TJVMNY?ref=fed_asin_title"> Link </a> |
| HC 05 Bluetooth Modules | Has main components including Arduino Uno, ultrasonic sensor, etc. | $9 | <a href="https://www.amazon.com/DSD-TECH-HC-05-Pass-through-Communication/dp/B01G9KSAF6/ref=sr_1_3?crid=2J833J7AYQJA&keywords=hc05&qid=1686187263&sprefix=hc0%2Caps%2C112&sr=8-3"> Link </a> |
| Breadboard Kit | Has main components including Arduino Uno, ultrasonic sensor, etc. | $8.69 | <a href="https://www.amazon.com/Breadboards-Solderless-Breadboard-Distribution-Connecting/dp/B07DL13RZH/ref=sxts_b2b_sx_reorder_acb_business?content-id=amzn1.sym.f63a3b0b-3a29-4a8e-8430-073528fe007f%3Aamzn1.sym.f63a3b0b-3a29-4a8e-8430-073528fe007f&crid=1RAL6PA1TZ81Q&cv_ct_cx=breadboard+kit&dib=eyJ2IjoiMSJ9.TUd5tu2T8rmms7ZuJ0UzmbtpLL1zsu93bQM0PzwnP4E.sT0V0vL_QtbYv8ymVTCcRkhFNgBtRvRiT7G4FT1oGTE&dib_tag=se&keywords=breadboard+kit&pd_rd_i=B07DL13RZH&pd_rd_r=1e3e6f57-5578-4452-b230-90d43c79b5d3&pd_rd_w=rFN6B&pd_rd_wg=3mMuA&pf_rd_p=f63a3b0b-3a29-4a8e-8430-073528fe007f&pf_rd_r=JC9D7T4VYRDQ9HJVY5X8&qid=1715912837&s=electronics&sbo=RZvfv%2F%2FHxDF%2BO5021pAnSA%3D%3D&sprefix=breadboard+kit%2Celectronics%2C102&sr=1-1-9f062ed5-8905-4cb9-ad7c-6ce62808241a"> Link </a> |
| 9V Batteries | Has main components including Arduino Uno, ultrasonic sensor, etc. | $8.69 | <a href="https://www.amazon.com/Amazon-Basics-Performance-All-Purpose-Batteries/dp/B00MH4QM1S/ref=sr_1_5_pp?crid=3TQ7ANPH958JM&dib=eyJ2IjoiMSJ9.bmcV2Upj_vpB6G9CFlPPxYAryat512da7ekZjc52HecXSTmtx7PbJ50EgQFPCMqlAxjOUq-tL4vQTpozlHvH89bMwx-HJoyGcdz6EY8HrMxahTiqOXkoP7ewkDcgHoMhmHamdlQfW6FBHO0Gm-DYZZnnMuvEU3qOpemA8PGEvRhEx4-lGaBZhrvls039G1-9SizAW-YRGXZ2fFrdVDlREyyOhAuxXZaE5QqUxWesRQgP9UfGOYaInRWTTPwhDbXFa-RPzGbU1C_u4wq-NMqKBtWEQqR9-cA8O3FYOx3icEY.dtKJmI2T-iCmMM_bYnbiHUWzhKpJDRxS-bBmZIwYFKM&dib_tag=se&keywords=9v+batteries&qid=1720651326&rdc=1&s=electronics&sprefix=9v+batteries%2Celectronics%2C105&sr=1-5"> Link </a> |
| Velcro Tape | Has main components including Arduino Uno, ultrasonic sensor, etc. | $8 | <a href="https://www.amazon.com/Art3d-Sticky-Double-Sided-Command-Adhesive/dp/B0B58FGF8H/ref=sr_1_1_sspa?crid=2N0JOMEZLJ2DS&dib=eyJ2IjoiMSJ9.qGUGB_MXfmbL0MW7bqNJbxvZC9pzliDJ9KYyRNNrctnh03kCcUXONRrcPYdGeo7Jwzrm83HyF8Jsb1RkcdlLPAw-8RkxbTCMiW6UI1Fpnjv9GjXUg9VBOLxmLVUbmMp5J7gFXKKLTWQ-w_L4Q9rykEUqKmjv-v6GRykMMZLY2cVt__lLxMIlwr6qBnQLWpHiklifUJwjiURxO--TTt2VReYgmN0z7118ifSucrkvRrg.mwA0L4zMSlJP2RO8IBba7dVqwa1Lkr8KvY1JmeQEfCg&dib_tag=se&keywords=velcro+tape+pieces&qid=1716734034&sprefix=velcro+tape+piece%2Caps%2C89&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1"> Link </a> |
| DMM | Has main components including Arduino Uno, ultrasonic sensor, etc. | $9.99 | <a href="https://www.amazon.com/dp/B0CXM242J1?ref=fed_asin_title&th=1"> Link </a> |

HPV Camera & Display Attachment
| **Part** | **Note** | **Price** | **Link** |
|:--:|:--:|:--:|:--:|
| Arduino ESP 32 Camera | Has main components including Arduino Uno, ultrasonic sensor, etc. | $25.99 | <a href="https://www.amazon.com/ESP32-CAM-Development-ESP32-CAM-Bluetooth/dp/B0FLPMGHLR/ref=sr_1_5?dib=eyJ2IjoiMSJ9.LTQ8QA0yrlsQjvOEHKz0wYVcZ5xnBzG8J5dNZ0DD9vK11jvjGTFJtL39sGUAjU3dNiXJSXYA6t1zcGZKwYnqnEsdlTXOk9EUlBNYYxZ_XbXnYUCCkJkt6YdChnvlVZtUdRPqIlzLv0EKk0VjGx3pK4yIJCaUgB_8GZ_-m6o3IubfTEh9j7GT3CWQRVzJeFY4Gdt_v37uU_J4kiPno6K16fKSP0ZUY68CKTV7Zhzxrbg.pow71Y8J_2nlVpcXed_CIAh-7aD0di5reLI-XqlXg7E&dib_tag=se&keywords=esp32%2Bcam%2Bai%2Bthinker&qid=1785507257&sr=8-5&th=1"> Link </a> |
| ELGOO Arduino ESP 32 Dev Module | Has main components including Arduino Uno, ultrasonic sensor, etc. | $19.99 | <a href="https://www.amazon.com/ELEGOO-ESP-WROOM-32-Development-Bluetooth-Microcontroller/dp/B0D8T53CQ5/ref=sr_1_1_sspa?dib=eyJ2IjoiMSJ9.XBINg-sjhfF_gUtnMiKGjlYIs5fbGLEtV5OoF1sxMf27Rfc2O_KsdJBqrrOxUPgaBfpwxr4ceJV_1hPSeBg-JXkudqK2GzAKZLtSYkq_WJdvV7RNK86Kc6BFmuzs9rC5XMXOYY23KGwQqHhm6gmNoQIwceKZcxOE2S-XH0ES9FvgwJXj-d4uXH_IM9bDCv3-Eie0rQ6tmI6yKYm3Nz2WZUzKWDAeKlp0vU3Gt8iTo1Y.Td_p-rGjAMSyxueBID97hXUHdWhfVEgF0T_XOEHP6sk&dib_tag=se&hvadid=816689653647&hvdev=c&hvexpln=67&hvlocphy=9004400&hvnetw=g&hvocijid=10874705126247536321--&hvqmt=e&hvrand=10874705126247536321&hvtargid=kwd-602894126864&hydadcr=13897_13839999&keywords=esp32+devkit+v1&mcid=9db9d615892f37a7ba07ac50b6376aca&qid=1785507587&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1"> Link </a> |
| SPI TFT Display Touch Panel | Has main components including Arduino Uno, ultrasonic sensor, etc. | $11.99 | <a href="https://www.amazon.com/DIANN-ILI9341-Display-320x240-Screen/dp/B0BNQBKFCT/ref=sr_1_7_sspa?crid=2VY1U06T8X68O&dib=eyJ2IjoiMSJ9.QdQv9Z60xKItFJyKtGDGVA9LSUj8e95nuyVGxUMmd62W6PKby7mDym3YuwefmtVO_aNIADyASySJuV5ogSZFaZG1CqKHjbGf2ERpb3qE5GmKg2a6XjVhmqPE5ZE6ktAhYHldI7SEkWVKibEHuZRudEdkkRNGNFEXQxkOnpIEqh8q9yteedTFjg6Kqj3mE0cztzn0xyh8qXalW-zjhjzZP1R3rEb8odqS4oRz663Vn60.TeYZg1U3cCBKXGkdwWGHAOyvHOBIqh8iD7kGnQSiX9c&dib_tag=se&keywords=2.8%22%2BILI9341%2BSPI%2BTFT%2Bdisplay&qid=1785507658&sprefix=2.8%2Bili9341%2Bspi%2Btft%2Bdisplay%2Caps%2C117&sr=8-7-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9tdGY&th=1"> Link </a> |
