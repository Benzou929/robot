
//Arduino PWM Speed Controlï¼š

int E1 = 5;    // moteur gauche vitesse 0..255
int M1 = 4;   // LOW avancer, HIGH reculer

int E2 = 6; // moteur droit vitesse 0..255
int M2 = 7;   // LOW avancer, HIGH reculer               

void robotAvancer(int vitesse);

void setup() {
  Serial.begin(9600); // initialisation liaison serie a 9600 bauds
  Serial1.begin(9600);
  robotInit();
  delay(2000);
  Serial.println("Arduino OK");
}

void loop() {
  char c;
  if (Serial1.available()) {
    c = Serial1.read();
    if (c == 'a') {
      robotAvancer(255);
    }
    else if (c == 'b') {
      robotAvancer(200);
    }
    else if (c == 'r') {
      robotReculer(255);
    }
    else if (c == 'd') {
      robotDroite(255);
    }
    else if (c == 'g') {
      robotGauche(255);
    }
    else if (c == 's') {
      robotStop();
    }
  }
}


void robotInit() {
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT); 
}

void robotAvancer(int vitesse) { // vitesse 0..255

  // moteur gauche
  digitalWrite(M1,LOW);   // direction
  analogWrite(E1, vitesse);     // vitesse

  // moteur droit
  digitalWrite(M2,LOW);   // direction
  analogWrite(E2, vitesse);     // vitesse
}

void robotReculer(int vitesse) { // vitesse 0..255

  // moteur gauche
  digitalWrite(M1,HIGH);  // direction
  analogWrite(E1, vitesse);     // vitesse

  // moteur droit
  digitalWrite(M2,HIGH);  // direction
  analogWrite(E2, vitesse);     // vitesse
}

void robotDroite(int vitesse) { // vitesse 0..255

  // moteur gauche
  digitalWrite(M1,LOW);   // direction
  analogWrite(E1, vitesse);     // vitesse

  // moteur droit
  digitalWrite(M2,HIGH);  // direction
  analogWrite(E2, vitesse);     // vitesse
}

void robotGauche(int vitesse) { // vitesse 0..255

  // moteur gauche
  digitalWrite(M1,HIGH);    // direction
  analogWrite(E1, vitesse);     // vitesse

  // moteur droit
  digitalWrite(M2,LOW); // direction
  analogWrite(E2, vitesse);     // vitesse
}

void robotStop() {

  // moteur gauche
  analogWrite(E1, 0);     // vitesse 0

  // moteur droit
  analogWrite(E2, 0);     // vitesse 0
}



