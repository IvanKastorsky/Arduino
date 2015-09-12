//Variáveis
float Leitura = 0;
int Delay = 2000;

float calcDivisorTensao(int PinoLeitura)
{
  int raw = 0;
  int Vin = 5;
  float rReferencia = 10000000;
  float Vout = 0;
  float buffer = 0;

  raw = analogRead(PinoLeitura);
  if (raw)
  {
    //Cálculo Circuito divisor de tensão
    buffer = raw * Vin;
    Vout = (buffer) / 1024.0;
    buffer = (Vin / Vout) - 1;
    return rReferencia * buffer;
  }
}

void setup()
{
  pinMode(9, OUTPUT);
  pinMode(10, INPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(11, LOW);
  //Verifica se o botão do teste foi pressionado
  if (digitalRead(10) == LOW)
  {
    //Ligar 5V na saída D12
    digitalWrite(12, HIGH);
    digitalWrite(9, HIGH);
    delay(500);

    //Leitura da Resistência na saída A0
    Leitura = calcDivisorTensao(0);
    Serial.println("Teste Continuo");
    Serial.print("Resistencia: ");
    Serial.println(Leitura);
  }
  else
  {
    //Leitura da Resistência na saída A1 pé esquerdo
    //Ligar 5V na saída D12
    digitalWrite(9, LOW);
    digitalWrite(12, HIGH);
    delay(Delay);
    Leitura = calcDivisorTensao(0);
    digitalWrite(12, LOW);
    Serial.println("Teste Botao Esquerdo");
    Serial.print("Resistencia: ");
    Serial.println(Leitura);

    //Leitura da Resistência na saída A1 pé direito
    //Ligar 5V na saída D11
    digitalWrite(11, HIGH);
    delay(Delay);
    Leitura = calcDivisorTensao(0);
    digitalWrite(11, LOW);
    Serial.println("Teste Botao Direito");
    Serial.print("Resistencia: ");
    Serial.println(Leitura);
  }
}


