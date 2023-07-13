int n = 0;
int i = 0;
int j = 0;

unsigned long mod = 4147483647;
int ini = 0;

int  r1 = 7;
int  r2 = 5;
int  r3 = 24;

int  s1 = 10;
int  s2 = 17;
int  s3 = 55;

int d = 2;
int salida = 0;

int QPin = A0; //Pin A0 for Q1
//int CPin = A1; //Pin A1 for CLK1
//int DPin = A2; //Pin A2 for D1

int QPin2 = A3; //Pin A5 for Q2
//int DPin2 = A4; //Pin A0 for D2
//int CPin2 = A5; //Pin A1 for CLK2

char val[] = "000000000000000000000000000000";

int QH = 0;  
//int DH = 0;  
//int CH = 0;  

int QH2 = 0;  
//int DH2 = 0;  
//int CH2 = 0;  

//int clockPin = 8;
//int prePin = 7;

unsigned long Xn[110];
unsigned long Yn[110];
unsigned long Zn[110];

unsigned long Wn = random(mod);



void setup() {

  Serial.begin(9600);
  //pinMode(clockPin, OUTPUT);
  //pinMode(prePin, OUTPUT);
}

void loop() {


//Inicialización de valores random

  if(ini==0){

    while(n<55){
      //CH = analogRead(CPin);  // read the input Cpin
      //DH = analogRead(DPin);  // read the input Dpin
      QH = analogRead(QPin);  // read the input Qpin

      //CH2 = analogRead(CPin2);  // read the input Cpin2
      //DH2 = analogRead(DPin2);  // read the input Dpin2
      QH2 = analogRead(QPin2);  // read the input Qpin2


      if(QH > 900) QH = 1;
      if(QH < 500) QH = 0;

      if(QH2 > 900) QH2 = 1;
      if(QH2 < 500) QH2 = 0;

      salida = QH ^ QH2;

      if(salida == 1){
        val[i]='1';
        i++;
      } 

      if(salida == 0){
        val[i]='0';
        i++;
      } 

      delay(5);

      if(i==30 && j==0){
        long value1= strtol(val, NULL, 2);
        i=0;
        j=1;
        Serial.print("Xn:");
        Serial.println(value1);
        Serial.println();
        Xn[n] = value1;
      }

      if(i==30 && j==1){
        long value2= strtol(val, NULL, 2);
        i=0;
        j=2;
        Serial.print("Yn:");
        Serial.println(value2);
        Serial.println();
        Yn[n] = value2;
      }

      if(i==30 && j==2){
        long value3= strtol(val, NULL, 2);
        i=0;
        j=0;
        Serial.print("Zn:");
        Serial.println(value3);
        Serial.println();
        Zn[n] = value3;
        n++;
        //Serial.print("N:");
        //Serial.println(n);
      }

    }
    ini=1;
  }
  else{

//Definición de valores X' Y' Z'

    unsigned long Xnp = (((Xn[n-r1]) + (Xn[n-s1])) %mod) >> d;
    unsigned long Ynp = (((Yn[n-r2]) + (Yn[n-s2])) %mod) >> d;
    unsigned long Znp = (((Zn[n-r3]) + (Zn[n-s3])) %mod) >> d;


//Definición de valores X Y Z

    Xn[n] = (((Xn[n-r1]) + (Xn[n-s1])) %mod) ^ Znp;
    Yn[n] = (((Yn[n-r2]) + (Yn[n-s2])) %mod) ^ Xnp;
    Zn[n] = (((Zn[n-r3]) + (Zn[n-s3])) %mod) ^ Ynp;


//Salida de trifork

    Wn = Xn[n] ^ Zn[n];
    Serial.print("Wn = ");
    Serial.println(Wn);

//Contador variable n
    n = n + 1;
    //Serial.print("n = ");
    //Serial.println(n);
    if(n==110){
      ini = 0;
      n=0;
    }     
  }
  delay(500);

}
