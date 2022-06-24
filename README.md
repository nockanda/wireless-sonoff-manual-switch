# wireless-sonoff-manual-switch
Make a manual switch to control the Sonoff Basic R2!

Sonoff basic r2 is controlled by esp8266 board.

Esp8266 boards are capable of ESPNOW communication with each other!

Therefore, wireless communication is possible without special equipment!

When the sonoff is embedded in the ceiling, it cannot be controlled without a smartphone!

Sometimes you just need a button that you can remote control manually!

![499-2_bb](https://user-images.githubusercontent.com/106683637/175529352-55a658d6-ad98-46ae-92e4-f01e1f705de7.jpg)

The video below is the process of uploading the esphome firmware to sonoff basic r2!

[![Video Label](http://img.youtube.com/vi/l5DErl9LNeg/0.jpg)](https://youtu.be/l5DErl9LNeg)

The link below is the final result! Sorry, it's in Korean!

[![Video Label](http://img.youtube.com/vi/fMAzSfnHPMc/0.jpg)](https://youtu.be/fMAzSfnHPMc)

1. Modify the software to use sonoff basic r2 in esphome.
2. Connect the battery and button to the wemos d1 mini board.
4. When the button is pressed, power is supplied to the wemos d1 mini board.
3. When the button is pressed, a control signal is transmitted using espnow.
4. If the transmission is successful, the wemos d1 mini board goes into deep sleep mode.
5. When the button is released, the power is cut off and the board turns off.
