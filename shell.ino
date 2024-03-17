#include "uptime_formatter.h"

String ver = "v0.1-devel";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Arduino shell " + ver);
}

void loop() {
  // put your main code here, to run repeatedly:
  String input;
  Serial.print(">");
  while (input.length() < 1) {
    input = Serial.readStringUntil('\n');
  }
  Serial.println(input);
  if (input == "help") {
    Serial.println("help");
    Serial.println("uptime");
    Serial.println("version / ver");
  }
  else if (input == "uptime") {
    Serial.println("uptime " + uptime_formatter::getUptime());
  }
  else if (input == "ver" || input == "version") {
    Serial.println("Arduino shell " + ver);
  }
  else {
    Serial.println("ERROR: command " + input + " is not found. Use command help for valid commands.");
  }
}
