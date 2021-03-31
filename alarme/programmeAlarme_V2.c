#include <Ultrasonic.h>
//helloThere
int floatSensor = 2;
int bzr = 3;
Ultrasonic ultrasonic(7);
long RangeInCentimeters;
int btnState = 1; //btnState = 1 par default

void setup()
{
  pinMode(floatSensor, INPUT);  //position reception du bouton
  pinMode(bzr, OUTPUT);         //position sortie du buzzer
  Serial.begin(9600);           //demarrage de la com serie
}

void loop(){
//programme de détection de vague (avec un btn)
//  int wavedtct=digitalRead(btn);
//  if (wavedtct==HIGH){
//     tone(bzr, 100);
//     delay(200);
//   }
//     else{
//       noTone(bzr);
//  }
//programme detection de vague avec le switch
  btnState = digitalRead(floatSensor);

  if (btnState == HIGH){ //si le switch = true alors on buzze
    tone(bzr, 100);
    delay(200);
    Serial.print("up");
  }
  else{noTone(bzr); Serial.print("down");}
//programme de détection des rebords

    //lecture de l'echo
   
    RangeInCentimeters = ultrasonic.MeasureInCentimeters(); // two measurements should keep an interval
    Serial.print(RangeInCentimeters);//0~400cm
    Serial.println(" cm");
    delay(200);

    if(RangeInCentimeters <= 5){//declanchement du buzzer selon la distance robot->bord
      tone(bzr, 10);
      delay(200);}
    else{noTone(bzr);}
}
//Les serialprint seront à suprimmer à la fin !
