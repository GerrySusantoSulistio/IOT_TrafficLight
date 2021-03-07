int merah =  21;
int kuning =  22;
int hijau =  23;

const long intervalMerah = 3000;
const long intervalKuning = 1000;
const long intervalHijau = 2000;

unsigned long previousMillis = 0; 

int ubahWarnaLed = 0;

void setup() {
  Serial.begin(9600);
  pinMode(merah, OUTPUT);
  pinMode(kuning, OUTPUT);
  pinMode(hijau, OUTPUT);
}

void loop() {
   unsigned long currentMillis = millis();
   if (ubahWarnaLed == 0) {
    digitalWrite(merah,LOW);
    digitalWrite(kuning,HIGH);
    digitalWrite(hijau,HIGH);
    ubahWarnaLed++;
    previousMillis += intervalMerah;
    
  }else if (ubahWarnaLed == 1 &&  previousMillis - currentMillis == 0) {
    digitalWrite(merah,HIGH);
    digitalWrite(kuning,LOW);
    digitalWrite(hijau,HIGH);
    ubahWarnaLed++;
    previousMillis += intervalKuning;
  }else if (ubahWarnaLed == 2 &&  previousMillis - currentMillis == 0) {
    digitalWrite(merah,HIGH);
    digitalWrite(kuning,HIGH);
    digitalWrite(hijau,LOW);
    ubahWarnaLed++;
    previousMillis += intervalHijau;
  }else if (ubahWarnaLed == 3 &&  previousMillis - currentMillis == 0) {
    digitalWrite(merah,LOW);
    digitalWrite(kuning,HIGH);
    digitalWrite(hijau,HIGH);
    ubahWarnaLed=1;
    previousMillis += intervalMerah; 
  }
    
  
}
