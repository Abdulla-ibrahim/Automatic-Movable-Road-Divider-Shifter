#include <LiquidCrystal.h>

const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Pin definitions for sensors and relays
const int trigPin = 2;
const int echoPin = 3;
#define in1 34
#define out1 36
#define in2 38
#define out2 40
#define motor_in1 22
#define motor_in2 24
#define motor_in3 22
#define motor_in4 24
#define IN_sig1 46
#define IN_sig2 48
#define IN_sig3 42
#define IN_sig4 44
#define RELAY_1_A 26
#define RELAY_2_B 28
#define RELAY_1_A1 30
#define RELAY_2_B1 32
#define BUZZER 50
#define TIMER_CNT_MAX 50

// Variables for road traffic
int count1 = 0, count2 = 0, one_sec_timer = TIMER_CNT_MAX;
int road_flag = 0; 

// Function declarations
int DISTANCE_MONITOR();
void WIFI(void);
long microsecondsToCentimeters(long microseconds);
void read_sensor(void);
void Input1(void);
void Input2(void);
void Output1();
void Output2();
void serialEvent();

void setup() {
    // Set pin modes for traffic sensors and motor controls
    pinMode(in1, INPUT);
    pinMode(in2, INPUT);
    pinMode(out1, INPUT);
    pinMode(out2, INPUT);
    pinMode(IN_sig1, OUTPUT);
    pinMode(IN_sig2, OUTPUT);
    pinMode(IN_sig3, OUTPUT);
    pinMode(IN_sig4, OUTPUT);
    pinMode(RELAY_1_A, OUTPUT);
    pinMode(RELAY_2_B, OUTPUT);
    pinMode(RELAY_1_A1, OUTPUT);
    pinMode(RELAY_2_B1, OUTPUT);
    pinMode(motor_in1, OUTPUT);
    pinMode(motor_in2, OUTPUT);
    pinMode(motor_in3, OUTPUT);
    pinMode(motor_in4, OUTPUT); 
    pinMode(BUZZER, OUTPUT); 
    digitalWrite(BUZZER, LOW);

    // Initial settings for traffic lights and LCD
    digitalWrite(RELAY_1_A, HIGH);
    digitalWrite(RELAY_2_B, LOW);
    digitalWrite(RELAY_1_A1, HIGH);
    digitalWrite(RELAY_2_B1, LOW);
    digitalWrite(IN_sig1, HIGH);
    digitalWrite(IN_sig2, LOW);
    digitalWrite(IN_sig3, HIGH);
    digitalWrite(IN_sig4, LOW);

    lcd.begin(16, 2);
    lcd.print("MOVABLE ROAD");
    lcd.setCursor(0, 1);
    lcd.print("DIVIDER..");

    Serial.begin(9600);
    Serial3.begin(9600);
    Serial.println("Density based Traffic Control And Divider Movement.");
    delay(2000);

    lcd.clear();
    lcd.print("ROAD1:");
    lcd.print(count1);
    lcd.setCursor(0, 1);
    lcd.print("ROAD2:");
    lcd.print(count2);
}
