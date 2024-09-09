void serialEvent() {
    char ch;
    if (Serial3.available() > 0) {
        ch = Serial3.read();

        if (ch == 'A') {
            if (road_flag == 1) {
                Serial.println("Ambulance in ROAD1 already, ROAD CLEARED FOR TRAFFIC");
            } else {
                Serial.println("Ambulance in ROAD1");
                lcd.clear();
                lcd.print("ROAD1");

                // Activate signals for ROAD1
                digitalWrite(IN_sig1, HIGH);
                digitalWrite(IN_sig2, LOW);

                digitalWrite(IN_sig3, LOW);
                digitalWrite(IN_sig4, HIGH);

                delay(1500);
                ALL_ZERO();
                delay(1000);

                digitalWrite(RELAY_1_A, HIGH);
                digitalWrite(RELAY_2_B1, HIGH);

                // Move divider for ambulance clearance
                MOVE_DIVIDER_RIGHT();
                delay(3000);
                MOVE_DIVIDER_LEFT();

                ALL_ZERO();
                delay(1000);

                // Reset signals for ROAD1
                digitalWrite(IN_sig1, HIGH);
                digitalWrite(IN_sig2, LOW);
                digitalWrite(IN_sig3, HIGH);
                digitalWrite(IN_sig4, LOW);

                delay(1000);
            }
        }

        if (ch == 'B') {
            if (road_flag == 2) {
                Serial.println("Ambulance in ROAD2 already, ROAD CLEARED FOR TRAFFIC");
            } else {
                Serial.println("Ambulance in ROAD2");
                lcd.clear();
                lcd.print("ROAD2");

                // Activate signals for ROAD2
                digitalWrite(IN_sig1, LOW);
                digitalWrite(IN_sig2, HIGH);

                digitalWrite(IN_sig3, HIGH);
                digitalWrite(IN_sig4, LOW);

                delay(1000);
                ALL_ZERO();
                delay(1000);

                digitalWrite(RELAY_1_A1, HIGH);
                digitalWrite(RELAY_2_B, HIGH);

                // Move divider for ambulance clearance
                MOVE_DIVIDER_LEFT();
                delay(3000);
                MOVE_DIVIDER_RIGHT();

                ALL_ZERO();
                delay(1000);

                // Reset signals for ROAD2
                digitalWrite(IN_sig1, HIGH);
                digitalWrite(IN_sig2, LOW);
                digitalWrite(IN_sig3, HIGH);
                digitalWrite(IN_sig4, LOW);
            }
        }
    }
}
