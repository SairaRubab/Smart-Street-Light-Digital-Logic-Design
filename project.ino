// Define LED pin connections
int led_start = 2;
int led_second = 3;
int led_third = 4;
int led_fourth = 5;
int led_fifth = 9;

// Define sensor pin connections
int ldr = A0;         // Light Dependent Resistor (LDR) to detect ambient light
int ir_start = A1;    // IR sensor for detecting motion near the first LED
int ir_second = A2;   // IR sensor for the second LED
int ir_third = A3;    // IR sensor for the third LED
int ir_fourth = A4;   // IR sensor for the fourth LED
int ir_fifth = A5;    // IR sensor for the fifth LED

void setup() {
    // Set LED pins as OUTPUT
    pinMode(led_start, OUTPUT);
    pinMode(led_second, OUTPUT);
    pinMode(led_third, OUTPUT);
    pinMode(led_fourth, OUTPUT);
    pinMode(led_fifth, OUTPUT);

    // Set IR sensor and LDR pins as INPUT
    pinMode(ir_start, INPUT);
    pinMode(ir_second, INPUT);
    pinMode(ir_third, INPUT);
    pinMode(ir_fourth, INPUT);
    pinMode(ir_fifth, INPUT);
    pinMode(ldr, INPUT);

    // Start serial communication for debugging
    Serial.begin(9600);
}

void loop() {
    // Read sensor values
    int ir_status_start = analogRead(ir_start);
    int ir_status_second = analogRead(ir_second);
    int ir_status_third = analogRead(ir_third);
    int ir_status_fourth = analogRead(ir_fourth);
    int ir_status_fifth = analogRead(ir_fifth);

    // Read ambient light level
    int ldr_status = analogRead(ldr);
    Serial.println(ldr_status);  // Print LDR value for debugging

    // If ambient light is high (daytime), turn off all LEDs
    if (ldr_status > 1000) {
        digitalWrite(led_start, LOW);
        digitalWrite(led_second, LOW);
        digitalWrite(led_third, LOW);
        digitalWrite(led_fourth, LOW);
        digitalWrite(led_fifth, LOW);
    } else {  // If it's dark, proceed with motion detection

        // If motion is detected near the first IR sensor
        if (ir_status_start < 500) {
            digitalWrite(led_start, HIGH);  // Turn on first LED
            digitalWrite(led_second, 128);  // Dim second LED
            digitalWrite(led_third, LOW);
            digitalWrite(led_fourth, LOW);
            digitalWrite(led_fifth, LOW);
        }

        // If motion is detected near the second IR sensor
        if (ir_status_second < 500) {
            digitalWrite(led_start, HIGH);
            digitalWrite(led_second, HIGH);  // Turn on second LED
            analogWrite(led_third, 128);  // Dim third LED
            digitalWrite(led_fourth, LOW);
            digitalWrite(led_fifth, LOW);
        }

        // If no motion near the second sensor, turn off LEDs after the first one
        if (ir_status_second > 500) {
            digitalWrite(led_start, HIGH);
            digitalWrite(led_second, LOW);
            analogWrite(led_third, LOW);
            digitalWrite(led_fourth, LOW);
            digitalWrite(led_fifth, LOW);
        }

        // If motion is detected near the third IR sensor
        if (ir_status_third < 500) {
            digitalWrite(led_start, HIGH);
            digitalWrite(led_second, LOW);
            digitalWrite(led_third, HIGH);  // Turn on third LED
            digitalWrite(led_fourth, 128);  // Dim fourth LED
            digitalWrite(led_fifth, LOW);
        }

        // If no motion near the third sensor, turn off LEDs after the first one
        if (ir_status_third > 500) {
            digitalWrite(led_start, HIGH);
            digitalWrite(led_second, LOW);
            analogWrite(led_third, LOW);
            digitalWrite(led_fourth, LOW);
            digitalWrite(led_fifth, LOW);
        }

        // If motion is detected near the fourth IR sensor
        if (ir_status_fourth < 500) {
            digitalWrite(led_start, HIGH);
            digitalWrite(led_second, LOW);
            digitalWrite(led_third, LOW);
            digitalWrite(led_fourth, HIGH);  // Turn on fourth LED
            digitalWrite(led_fifth, HIGH);   // Turn on fifth LED
        }

        // If no motion near the fourth sensor, turn off LEDs after the first one
        if (ir_status_fourth > 500) {
            digitalWrite(led_start, HIGH);
            digitalWrite(led_second, LOW);
            digitalWrite(led_third, LOW);
            digitalWrite(led_fourth, LOW);
            digitalWrite(led_fifth, LOW);
        }

        // If motion is detected near the fifth IR sensor
        if (ir_status_fifth < 500) {
            digitalWrite(led_start, HIGH);
            digitalWrite(led_second, LOW);
            digitalWrite(led_third, LOW);
            digitalWrite(led_fourth, LOW);
            analogWrite(led_fifth, 1023);  // Fully brighten fifth LED
        }

        // If no motion near the fifth sensor, turn off LEDs after the first one
        if (ir_status_fifth > 500) {
            digitalWrite(led_start, HIGH);
            digitalWrite(led_second, LOW);
            digitalWrite(led_third, LOW);
            digitalWrite(led_fourth, LOW);
            digitalWrite(led_fifth, LOW);
        }
    }
}
