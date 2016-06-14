#include <VirtualWire.h>

const int led_pin = 13;
const int transmit_pin = 12;

void setup()
{
    // Initialise the IO and ISR
    vw_set_tx_pin(transmit_pin);
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(2000);       // Bits per sec
    pinMode(led_pin, OUTPUT);
}


void loop()
{
  char msg[7] = {'0','7','7','1','0','0','7'};
  digitalWrite(led_pin, HIGH); // Flash a light to show transmitting
  vw_send((uint8_t *)msg, 7);
  vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(led_pin, LOW);
  delay(1000);
}
