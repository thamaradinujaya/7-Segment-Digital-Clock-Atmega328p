// Define pin numbers
int pinA = 6;
int pinB = 7;
int pinC = 8;
int pinD = 13;
int pinE = 10;
int pinF = 11;
int pinG = 12;
int D1 = 5;
int D2 = 4;
int D3 = 3;
int D4 = 2;

// Variables for time
int hours = 12;  // Initial hours
int minutes = 12;// Initial minutes
int seconds = 0;

// Buttons
int buttonHourPin = A0;    // Connect one button for hours adjustment
int buttonMinutePin = A1;  // Connect another button for minutes adjustment


void displayDigit(int a, int b, int c, int d, int e, int f, int g, int digitPin) {
  digitalWrite(pinA, a);
  digitalWrite(pinB, b);
  digitalWrite(pinC, c);
  digitalWrite(pinD, d);
  digitalWrite(pinE, e);
  digitalWrite(pinF, f);
  digitalWrite(pinG, g);
  digitalWrite(digitPin, LOW);
  delay(5); // Adjust delay as needed
  digitalWrite(digitPin, HIGH);
}

void checkButtons() {
  // Check the button for hours adjustment
  if (digitalRead(buttonHourPin) == LOW) {
    delay(50);  // debounce delay
    while (digitalRead(buttonHourPin) == LOW) {
      // Button is held down, increase hours
      hours = (hours + 1) % 24;
      delay(250);  // delay to prevent rapid increase
    }
  }

  // Check the button for minutes adjustment
  if (digitalRead(buttonMinutePin) == LOW) {
    delay(50);  // debounce delay
    while (digitalRead(buttonMinutePin) == LOW) {
      // Button is held down, increase minutes
      minutes = (minutes + 1) % 60;
      delay(250);  // delay to prevent rapid increase
    }
  }
}


void showTime() {
  // Display tens of hours
  int tensHour = hours / 10;
  int unitsHour = hours % 10;
  
  // Define segments for the tens of hours
  switch (tensHour) {
    case 0:
      displayDigit(1, 1, 1, 1, 1, 1, 0, D1);
      break;
    case 1:
      displayDigit(0, 1, 1, 0, 0, 0, 0, D1);
      break;
    case 2:
      displayDigit(1, 1, 0, 1, 1, 0, 1, D1);
      break;
    case 3:
      displayDigit(1, 1, 1, 1, 0, 0, 1, D1);
      break;
    case 4:
      displayDigit(0, 1, 1, 0, 0, 1, 1, D1);
      break;
    case 5:
      displayDigit(1, 0, 1, 1, 0, 1, 1, D1);
      break;
    case 6:
      displayDigit(1, 0, 1, 1, 1, 1, 1, D1);
      break;
    case 7:
      displayDigit(1, 1, 1, 0, 0, 0, 0, D1);
      break;
    case 8:
      displayDigit(1, 1, 1, 1, 1, 1, 1, D1);
      break;
    case 9:
      displayDigit(1, 1, 1, 1, 0, 1, 1, D1);
      break;
  }
  
  // Define segments for the units of hours
  switch (unitsHour) {
    case 0:
      displayDigit(1, 1, 1, 1, 1, 1, 0, D2);
      break;
    case 1:
      displayDigit(0, 1, 1, 0, 0, 0, 0, D2);
      break;
    case 2:
      displayDigit(1, 1, 0, 1, 1, 0, 1, D2);
      break;
    case 3:
      displayDigit(1, 1, 1, 1, 0, 0, 1, D2);
      break;
    case 4:
      displayDigit(0, 1, 1, 0, 0, 1, 1, D2);
      break;
    case 5:
      displayDigit(1, 0, 1, 1, 0, 1, 1, D2);
      break;
    case 6:
      displayDigit(1, 0, 1, 1, 1, 1, 1, D2);
      break;
    case 7:
      displayDigit(1, 1, 1, 0, 0, 0, 0, D2);
      break;
    case 8:
      displayDigit(1, 1, 1, 1, 1, 1, 1, D2);
      break;
    case 9:
      displayDigit(1, 1, 1, 1, 0, 1, 1, D2);
      break;
  }

  // Display tens of minutes
  int tensMinute = minutes / 10;
  int unitsMinute = minutes % 10;
  
  // Define segments for the tens of minutes
  switch (tensMinute) {
    case 0:
      displayDigit(1, 1, 1, 1, 1, 1, 0, D3);
      break;
    case 1:
      displayDigit(0, 1, 1, 0, 0, 0, 0, D3);
      break;
    case 2:
      displayDigit(1, 1, 0, 1, 1, 0, 1, D3);
      break;
    case 3:
      displayDigit(1, 1, 1, 1, 0, 0, 1, D3);
      break;
    case 4:
      displayDigit(0, 1, 1, 0, 0, 1, 1, D3);
      break;
    case 5:
      displayDigit(1, 0, 1, 1, 0, 1, 1, D3);
      break;
    case 6:
      displayDigit(1, 0, 1, 1, 1, 1, 1, D3);
      break;
    case 7:
      displayDigit(1, 1, 1, 0, 0, 0, 0, D3);
      break;
    case 8:
      displayDigit(1, 1, 1, 1, 1, 1, 1, D3);
      break;
    case 9:
      displayDigit(1, 1, 1, 1, 0, 1, 1, D3);
      break;
  }

  // Define segments for the units of minutes
  switch (unitsMinute) {
    case 0:
      displayDigit(1, 1, 1, 1, 1, 1, 0, D4);
      break;
    case 1:
      displayDigit(0, 1, 1, 0, 0, 0, 0, D4);
      break;
    case 2:
      displayDigit(1, 1, 0, 1, 1, 0, 1, D4);
      break;
    case 3:
      displayDigit(1, 1, 1, 1, 0, 0, 1, D4);
      break;
    case 4:
      displayDigit(0, 1, 1, 0, 0, 1, 1, D4);
      break;
    case 5:
      displayDigit(1, 0, 1, 1, 0, 1, 1, D4);
      break;
    case 6:
      displayDigit(1, 0, 1, 1, 1, 1, 1, D4);
      break;
    case 7:
      displayDigit(1, 1, 1, 0, 0, 0, 0, D4);
      break;
    case 8:
      displayDigit(1, 1, 1, 1, 1, 1, 1, D4);
      break;
    case 9:
      displayDigit(1, 1, 1, 1, 0, 1, 1, D4);
      break;
  }
}

void setup() {
  // Set pin modes
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  // Set button pins as INPUT
  pinMode(buttonHourPin, INPUT_PULLUP);
  pinMode(buttonMinutePin, INPUT_PULLUP);
  Serial.begin(9600);
}
void updateInternalTime() {
  static unsigned long previousMillis = 0;
  unsigned long currentMillis = millis();

  // Check if 1 second has passed
  if (currentMillis - previousMillis >= 1000) {
    previousMillis = currentMillis;

    // Increment seconds every second
    seconds++;

    // Check if a minute has passed
    if (seconds == 60) {
      seconds = 0;

      // Increment minutes when seconds reach 60
      minutes++;

      // Check if minutes reached 60 and reset to 0
      if (minutes == 60) {
        minutes = 0;

        // Increment hours when minutes reach 60
        hours++;

        // Check if hours reached 24 and reset to 0
        if (hours == 24) {
          hours = 0;
        }
      }
    }
  }
}

void loop() {
  updateInternalTime();
  checkButtons();  // Call the function to check buttons for adjustments
  Serial.print("Hours: ");
  Serial.print(hours);
  Serial.print(", Minutes: ");
  Serial.println(minutes);
  // Update time and display every millisecond
  showTime();
  delay(1);  // Adjust delay as needed
}