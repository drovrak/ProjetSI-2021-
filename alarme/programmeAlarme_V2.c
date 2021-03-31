//helloThere
int floatSensor = 2;
int bzr = 3;
int _trig_ = 4; //émission
int _echo_ = 5; //réception
long lecture_echo;
long cm;
int btnState = 1 //btnState = 1 par default

void setup()
{
  pinMode(floatSensor, INPUT);  //position reception du bouton
  pinMode(bzr, OUTPUT);         //position sortie du buzzer
  pinMode(_trig_, OUTPUT);      //position sortie du capteur (emission)
  digitalWrite(_trig_,LOW);     //position éteint au demarrage du capteur de song
  pinMode(_echo_,INPUT);        //position entrée du capteur (reception)
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
  btnState = digitalRead(floatSensor)

  if (btnState == HIGH){ //si le switch = true alors on buzze
    tone(bzr, 100);
    delay(200);
  }
  else{noTone(bzr);}
//programme de détection des rebords
    //émission signal
    digitalWrite(_trig_, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trig_, LOW);

    //lecture de l'echo
    lecture_echo = pulseIn(_echo_,HIGH);

    //calcule de la distance
    cm = lecture_echo /3333;

    //print de la distance dans le terminale serie
    //(à supprimer dans l'avenir)
    Serial.print("Distance cm :");
    Serial.println(cm);
    delay(1000);

    if(cm < 5){//declanchement du buzzer selon la distance robot->bord
      tone(bzr, 100);
      delay(200);}
    else{noTone(bzr);}
}
