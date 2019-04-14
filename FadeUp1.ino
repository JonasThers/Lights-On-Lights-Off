#include <DmxSimple.h>
boolean state = false;

int podmeter1;
int podmeter2;
int podmeter3;
int podmeter4;
int button;
int lampe1intensitet;
int lampe1temperatur;
int lampe2intensitet;
int lampe2temperatur;
int gennemsnitintensitet;
int gennemsnittemperatur;

void setup() {
  Serial.begin(9600);
  pinMode(4, INPUT_PULLUP);
  DmxSimple.usePin(3);
  DmzSimple.maxChannel(6);
}

void loop() {
  button = digitalRead(4);
  Serial.println(state);
  Serial.println();
  if(button == 0) {
    state = true;
  }

 if(state == false) {
  podmeter1 = analogRead(A1);
  podmeter2 = analogRead(A2);
  podmeter3 = analogRead(A3);
  podmeter4 = analogRead(A4);
  lampe1intensitet = (int) map (podmeter1, 0, 1023, 0, 255);
  lampe1temperatur = (int) map (podmeter2, 0, 1023, 0, 255);
  lampe2intensitet = (int) map (podmeter3, 0, 1023, 0, 255);
  lampe2temperatur = (int) map (podmeter4, 0, 1023, 0, 255; 

     DmxSimple.write(1, lampe1intensitet);
     DmxSimple.write(2, lampe1temperatur);
     DmxSimple.write(3, lampe2intensitet);
     DmxSimple.write(4, lampe2temperatur);
  }

  else {
  gennemsnitintensitet = (lampe1intensitet + lampe2intensitet) / 2;
  gennemsnittemperatur = (lampe1temperatur + lampe2temperatur) / 2;

     DmxSimple.write(1, lampe1intensitet);
     DmxSimple.write(2, lampe1temperatur);
     DmxSimple.write(3, lampe2intensitet);
     DmxSimple.write(4, lampe2temperatur);
  }
}

delay(10);
