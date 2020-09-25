void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    Serial.println("Arduino : I'm genius");
    char val = Serial.read();

    if (val == '5') {
      Serial.println("equal to 5");
    }
    else if (val > '5') {
      Serial.println("over 5");
    }
    else if (val < '4') {
      Serial.println("under 4");
    }

    if (val != '4') {
      Serial.println("not equal to 4");
    }
    else {
      Serial.println("equal to 4");
    }

    if (val == '1') {
      Serial.println("It is 1");
    } else if (val == '0') {
      Serial.println("It is 0");
    } else {
      Serial.println("I don't know");
    }

    if (val > '3' && val < '6') {
      Serial.println("3 < val < 6");
    } else if (val < '4' || val > '6') {
      Serial.println("val < 4 or val > 6");
    } else if ( !(val == '6') ) {
      Serial.println("can't print");
    }

  }
}
