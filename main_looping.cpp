void loop() { 
    while (1) {
        serialEvent(); // Checks for serial input events (e.g., ambulance signal)
        read_sensor(); // Reads sensor data to count vehicles

        // Timer for traffic clearance
        if (one_sec_timer == TIMER_CNT_MAX) {
            clear_traffic();
            one_sec_timer--;
        } else {
            if (one_sec_timer == 0)
                one_sec_timer = TIMER_CNT_MAX;
            else
                one_sec_timer--;
        }
    }
}

void clear_traffic() {
    if (!DISTANCE_MONITOR()) {
        Serial.println("VEHICLE IS NEAR BY DIVIDER");
        digitalWrite(BUZZER, LOW);
        delay(1000);
    } else {
        // Logic to control the divider based on traffic density
        if (count1 > count2 && count1 > 50 && (road_flag == 1 || road_flag == 0)) {
            Serial.print("Clearing ROAD1:");
            ROAD2();
            MOVE_DIVIDER_LEFT();
            delay(3000);
            MOVE_DIVIDER_RIGHT();
            road_flag = 2;
        } else if (count2 > count1 && count2 > 50 && (road_flag == 2 || road_flag == 0)) {
            Serial.print("Clearing ROAD2:");
            ROAD1();
            MOVE_DIVIDER_RIGHT();
            delay(3000);
            MOVE_DIVIDER_LEFT();
            road_flag = 1;
        }
    }
}

void read_sensor() {
    // Traffic counting logic based on sensor input
    if (digitalRead(in1) == 0)
        count1++;
    if (digitalRead(out1) == 0)
        count1--;

    if (digitalRead(in2) == 0)
        count2++;
    if (digitalRead(out2) == 0)
        count2--;

    if (count1 < 0) count1 = 0;
    if (count2 < 0) count2 = 0;
    if (count1 == 0 && count2 == 0) road_flag = 0;

    // Display the traffic count on the LCD
    Serial.print(" VEHICLE IN ROAD1:");
    Serial.print(count1);
    Serial.print(" VEHICLE IN ROAD2:");
    Serial.print(count2);
    Serial.print("----");
    Serial.print(road_flag);
    Serial.println("--------");
    lcd.clear();
    lcd.print("ROAD1:");
    lcd.print(count1);
    lcd.setCursor(0, 1);
    lcd.print("ROAD2:");
    lcd.print(count2);

    delay(100);
}
