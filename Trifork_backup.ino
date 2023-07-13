int n = 0;
unsigned long mod = 4147483647;
int ini = 0;

int  r1 = 7;
int  r2 = 5;
int  r3 = 24;

int  s1 = 10;
int  s2 = 17;
int  s3 = 55;

int d = 0;

unsigned long Xn[100];
unsigned long Yn[100];
unsigned long Zn[100];

unsigned long Wn = random(mod);



void setup() {

  Serial.begin(9600);
}

void loop() {


//Inicialización de valores random

  if(ini == 0){

    for(n=0;n<55;n++){
    Xn[n] = random(mod);
    //Serial.print("Xn = ");
    //Serial.println(Xn[n]);
    Yn[n] = random(mod);
    //Serial.print("Yn = ");
    //Serial.println(Yn[n]);
    Zn[n] = random(mod);
    //Serial.print("Zn = ");
    //Serial.println(Zn[n]);
    
    }
    ini=1;
  }
  else{

//Definición de valores X' Y' Z'

    unsigned long Xnp = (((Xn[n-r1]) + (Xn[n-s1])) %mod) >> d;

    //Xnp += Xnp<0?mod:0;
    //Xnp = Xnp >> d;
    //Serial.print("Xnp = ");
    //Serial.println(Xnp);

    unsigned long Ynp = (((Yn[n-r2]) + (Yn[n-s2])) %mod) >> d;

    //Ynp += Ynp<0?mod:0;
    //Ynp = Ynp >> d;
    //Serial.print("Ynp = ");
    //Serial.println(Ynp);

    unsigned long Znp = (((Zn[n-r3]) + (Zn[n-s3])) %mod) >> d;

    //Znp += Znp<0?mod:0;
    //Znp = Znp >> d;
    //Serial.print("Znp = ");
    //Serial.println(Znp);

//Definición de valores X Y Z

    Xn[n] = (((Xn[n-r1]) + (Xn[n-s1])) %mod) ^ Znp;
    
    //Xn[n] += Xn[n]<0?mod:0;
    //Xn[n] = Xn[n] ^ Znp;
    //Serial.print("Xn^ = ");
    //Serial.println(Xn[n]);

    Yn[n] = (((Yn[n-r2]) + (Yn[n-s2])) %mod) ^ Xnp;

    //Yn[n] += Yn[n]<0?mod:0;
    //Yn[n] = Yn[n] ^ Xnp;
    //Serial.print("Yn^ = ");
    //Serial.println(Yn[n]);

    Zn[n] = (((Zn[n-r3]) + (Zn[n-s3])) %mod) ^ Ynp;

    //Zn[n] += Zn[n]<0?mod:0;
    //Zn[n] = Zn[n] ^ Ynp;
    //Serial.print("Zn^ = ");
    //Serial.println(Zn[n]);


//Salida de trifork

    Wn = Xn[n] ^ Zn[n];
    Serial.print("Wn = ");
    Serial.println(Wn);

//Contador variable n
    n = n + 1;
    //Serial.print("n = ");
    //Serial.println(n);
    if(n == 100){
      ini = 0;
    }     
  }
  delay(500);

}
