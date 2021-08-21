#include<IRremote>

IRsend remoteSend;
void setup(){

}

void loop(){
    remoteSend.sendNEC();    
}