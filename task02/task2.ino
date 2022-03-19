#include <TaskManagerIO.h>

bool pin5State = false;
bool pin6State = false;
bool pin9State = false;
bool pin10State = false;
bool pin11State = false;


void togglePin5() {
    digitalWrite(5, pin5State);
    pin5State = !pin5State;           
}

void togglePin6() {
    digitalWrite(6, pin6State);
    pin6State = !pin6State;           
}

void togglePin9() {
    digitalWrite(9, pin9State);
    pin9State = !pin9State;           
}

void togglePin10() {
    digitalWrite(10, pin10State);
    pin10State = !pin10State;           
}

void togglePin11() {
    digitalWrite(11, pin11State);
    pin11State = !pin11State;           
}

void setup() {
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  
  taskManager.scheduleFixedRate(111000, togglePin5, TIME_MICROS);
  taskManager.scheduleFixedRate(11000, togglePin6,TIME_MICROS);
  taskManager.scheduleFixedRate(1110, togglePin9,TIME_MICROS);
  taskManager.scheduleFixedRate(111, togglePin10,TIME_MICROS);
  taskManager.scheduleFixedRate(11, togglePin11,TIME_MICROS);

}

void loop() {
  taskManager.runLoop();
}
