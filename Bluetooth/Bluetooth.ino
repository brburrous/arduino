
string bluetoothInput;

void setup(){
    Serial.begin(9600);
}

void loop(){
    if(Serial.available()){
        bluetoothInput = Serial.readStringUntil('\n');
    }
}