int DISTANCE_MONITOR() {
    long duration, cm;

    pinMode(trigPin, OUTPUT);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    pinMode(echoPin, INPUT);
    duration = pulseIn(echoPin, HIGH);
    cm = microsecondsToCentimeters(duration);

    Serial.print(cm);
    Serial.println("cm");

    // Trigger the buzzer if a vehicle is near the divider
    if (cm < 10) {
        Serial.println("VEHICLE IS NEAR BY DIVIDER");
        lcd.print("VEHICLE IS NEAR");
        lcd.setCursor(0, 1);
        lcd.print("BY DIVIDER");
        digitalWrite(BUZZER, HIGH);
        delay(1000);
        return 0;
    } else {
        digitalWrite(BUZZER, LOW);
    }
    return 1;
}

void MOVE_DIVIDER_LEFT() {
    lcd.clear();
    Serial.println("moving Left");
    lcd.print("LEFT..");

    // Motor control logic for moving the divider left
    digitalWrite(motor_in1, LOW);
    digitalWrite(motor_in2, HIGH);
    digitalWrite(motor_in3, LOW);
    digitalWrite(motor_in4, HIGH);
    delay(1000);

    // Stop the motor after movement
    digitalWrite(motor_in1, LOW);
    digitalWrite(motor_in2, LOW);
    digitalWrite(motor_in3, LOW);
    digitalWrite(motor_in4, LOW);
}

void MOVE_DIVIDER_RIGHT() {
    lcd.clear();
    Serial.println("moving Right");
    lcd.print("RIGHT");

    // Motor control logic for moving the divider right
    digitalWrite(motor_in1, HIGH);
    digitalWrite(motor_in2, LOW);
    digitalWrite(motor_in3, HIGH);
    digitalWrite(motor_in4, LOW);
    delay(1000);

    // Stop the motor after movement
    digitalWrite(motor_in1, LOW);
    digitalWrite(motor_in2, LOW);
    digitalWrite(motor_in3, LOW);
    digitalWrite(motor_in4, LOW);
}

long microsecondsToCentimeters(long microseconds) {
    return microseconds / 29 / 2;
}
