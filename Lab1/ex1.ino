int led1 = 13; //define o apelido led para o valor 13
int led2 = 8;

void setup(){
  pinMode(led1,OUTPUT); //declara o pino13 (led) como saida
  pinMode(led2,OUTPUT);
}


void loop(){ //verde
  digitalWrite(led1, HIGH); //acende o led
  digitalWrite(led2, HIGH); //acende o led
  delay(500); //delay em milisegundos
  delay(500); //delay em milisegundos
  digitalWrite(led1, LOW); //apaga o led
  digitalWrite(led2, LOW); //apaga o led
  delay(500); //delay em milisegundos
  delay(500); //delay em milisegundos

//vermelho
//   digitalWrite(led2, HIGH); //acende o led
//  delay(1000); //delay em milisegundos
//  digitalWrite(led2, LOW); //apaga o led
//  delay(1000); //delay em milisegundos
}