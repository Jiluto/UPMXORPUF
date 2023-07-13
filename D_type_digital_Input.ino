int CPin = A1; //Pin A1 for CLK1
int QPin = A0; //Pin A0 for Q1
int DPin = A2; //Pin A2 for D1

int CPin2 = A5; //Pin A1 for CLK2
int QPin2 = A3; //Pin A5 for Q2
int DPin2 = A4; //Pin A0 for D2

int high = 0;  // variable to store the value read
int low = 0;  // variable to store the value read
int i = 0;
int j = 0;
char val[] = "000000000000000000000000000000";

int salida = 0;

int QL = 0;  // variable to store the value read
int DL = 0;  // variable to store the value read
int CL = 0;  // variable to store the value read

int QH = 0;  // variable to store the value read
int DH = 0;  // variable to store the value read
int CH = 0;  // variable to store the value read

int QL2 = 0;  // variable to store the value read
int DL2 = 0;  // variable to store the value read
int CL2 = 0;  // variable to store the value read

int QH2 = 0;  // variable to store the value read
int DH2 = 0;  // variable to store the value read
int CH2 = 0;  // variable to store the value read

int clockPin = 8;
int prePin = 7;

void setup() {
  Serial.begin(9600);           //  setup serial
  pinMode(clockPin, OUTPUT);
  pinMode(prePin, OUTPUT);
}

void loop() {


 // digitalWrite(prePin, LOW); // sets the digital pin 7 on CLK
 //digitalWrite(clockPin, LOW); // sets the digital pin 8 on CLK

 // CL = analogRead(CPin);  // read the input Cpin
 // Serial.print("CL:");          
 // Serial.println(CL);

//  DL = analogRead(DPin);  // read the input Dpin
//  Serial.print("DL:");          
//  Serial.println(DL);

//  QL = analogRead(QPin);  // read the input Qpin
//  Serial.print("QL:");          
//  Serial.println(QL);
//  Serial.println();

 // digitalWrite(prePin, HIGH); // sets the digital pin 7 on CLK
 //digitalWrite(clockPin, HIGH); // sets the digital pin 8 on CLK
  
  CH = analogRead(CPin);  // read the input Cpin
 // Serial.print("CH:");          
 // Serial.println(CH);

  DH = analogRead(DPin);  // read the input Dpin
 // Serial.print("DH:");          
 // Serial.println(DH);

  QH = analogRead(QPin);  // read the input Qpin
 // Serial.print("QH:");          
 // Serial.println(QH);
 // Serial.println();

  CH2 = analogRead(CPin2);  // read the input Cpin
 // Serial.print("CH:");          
 // Serial.println(CH);

  DH2 = analogRead(DPin2);  // read the input Dpin
 // Serial.print("DH:");          
 // Serial.println(DH);

  QH2 = analogRead(QPin2);  // read the input Qpin
 // Serial.print("QH:");          
 // Serial.println(QH);
 // Serial.println();

  if(QH > 900) QH = 1;
  if(QH < 500) QH = 0;

  if(QH2 > 900) QH2 = 1;
  if(QH2 < 500) QH2 = 0;
  

  salida = QH ^ QH2;

    if(salida == 1){
    high = high + 1;
    val[i]='1';
    i++;
  } 
  if(salida == 0){
    low = low + 1;
    val[i]='0';
    i++;
  } 
  Serial.print("salida:");          
  Serial.println(salida);
  Serial.println();
52
 // Serial.print("high:");          
 // Serial.println(high);
 // Serial.print("low:");          
 // Serial.println(low);
 // Serial.println();
 delay(5);

  if(i==30 && j==0){
    long value1= strtol(val, NULL, 2);
    //for (int i = 0; i < 30; i++) {
    //  Serial.print(val[i]);
    //}
    i=0;
    j=1;
    Serial.println();
    Serial.print("value1:");
    Serial.println(value1);
    Serial.println();
  }

  if(i==30 && j==1){
    long value2= strtol(val, NULL, 2);
    //for (int i = 0; i < 30; i++) {
    //  Serial.print(val[i]);
    //}
    i=0;
    j=2;
    Serial.println();
    Serial.print("value2:");
    Serial.println(value2);
    Serial.println();
  }

  if(i==30 && j==2){
    long value3= strtol(val, NULL, 2);
    //for (int i = 0; i < 30; i++) {
    //  Serial.print(val[i]);
    //}
    i=0;
    j=0;
    Serial.println();
    Serial.print("value3:");
    Serial.println(value3);
    Serial.println();
  }

}


