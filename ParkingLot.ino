const int num_parking_spots = 6;
const int default_rate = 5;
const int P1_TRIG = 3;
const int P1_ECHO = 4;
const int P2_TRIG = 5;
const int P2_ECHO = 6;

struct parkingSpot {
    int spotNumber; 
    bool occupied; 
    double timeStart; 
    double rate; 
};

parkingSpot P1;

void setup() {  
  // Serial:
  Serial.println("Parking Lot Communication System Setting Up");
  Serial.begin(9600);
  
  // HARDWARE:
  Serial.println("Parking Lot Hardware Setting Up");
  pinMode(P1_TRIG,OUTPUT);
  pinMode(P1_ECHO,INPUT);
  pinMode(P2_TRIG,OUTPUT);
  pinMode(P2_ECHO,INPUT);
  
  // Initializing Software:
  Serial.println("Software Initializing");
  
  
}

void initializeLot(){
  Serial.println("Parking Spot 1 Initialized");
  
}

void checkSpot(int parkingSpot){
  long duration, inches, cm;
  pinMode(P1_TRIG, OUTPUT);
  digitalWrite(P1_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(P1_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(P1_TRIG, LOW);
  pinMode(P1_ECHO, INPUT);
  duration = pulseIn(P1_ECHO, HIGH);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  //Serial.print(inches);
  //Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm - ");
  //Serial.println();
  if(cm < 6){
    Serial.println("Parking Spot 1 is occupied.");
    P1.occupied = true;
  }
  else {
    //Serial.println("Parking Spot 1 is not occupied.");
    P1.occupied = false; 
  }
  delay(100);
}

void checkSystem(){
  for(i = 1; i < 3; i++){
    checkSpot();
  }
  
  
}

void shutDown(){ 
}


void loop() {
  checkSystem();
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
  
  
