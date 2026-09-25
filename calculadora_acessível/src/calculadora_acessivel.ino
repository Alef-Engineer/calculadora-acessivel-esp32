const int LED = 21;
bool errocalculo = false;

double primeironumero = 0;
double numeroatual = 0;

char operacao = ' ';
bool contafinalizada = false;

void confirmartecla()
{
  digitalWrite(LED, LOW);
  delay(100);
  digitalWrite(LED, HIGH);
}

char lertecla()
{
  if (Serial.available() > 0)
  {
    return Serial.read();
  }

  return '\0';
}

void limparcalculadora()
{
  primeironumero = 0;
  numeroatual = 0;
  operacao = ' ';
  contafinalizada = false;
}

double calcularresultado(double numero1, double numero2, char op)
{
  errocalculo = false;
  double resultado = 0;

  if (op != '+' && op != '-' && op != '*' && op != '/')
  {
    Serial.println("ERRO: nenhuma operacao selecionada!");
    errocalculo = true;
    limparcalculadora();
    return 0;
  }

  if (op == '+')
    resultado = numero1 + numero2;

  if (op == '-')
    resultado = numero1 - numero2;

  if (op == '*')
    resultado = numero1 * numero2;

  if (op == '/')
  {
    if (numero2 == 0)
    {
      Serial.println("ERRO: divisao por zero!");
      errocalculo = true;
      limparcalculadora();
      return 0;
    }

    resultado = numero1 / numero2;
  }

  return resultado;
}

void setup()
{
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);

  Serial.begin(115200);

  while (!Serial)
  {
    delay(10);
  }

  Serial.println("Digite um numero:");
}

void loop()
{
  char tecla = lertecla();

  if (tecla != '\0')
  {
    if (tecla >= '0' && tecla <= '9')
    {
      confirmartecla();

      if (contafinalizada == true)
      {
        limparcalculadora();
      }

      int digito = tecla - '0';
      numeroatual = numeroatual * 10 + digito;

      Serial.print("Numero atual: ");
      Serial.println(numeroatual, 0);
    }

    if (tecla == '+' || tecla == '-' || tecla == '*' || tecla == '/')
    {
      confirmartecla();

      primeironumero = numeroatual;
      operacao = tecla;

      numeroatual = 0;
      contafinalizada = false;

      Serial.print("Operacao escolhida: ");
      Serial.println(operacao);
      Serial.println("Digite o segundo numero:");
    }

    if (tecla == '=')
    {
      confirmartecla();

      double segundonumero = numeroatual;
      double resultado = calcularresultado(
        primeironumero,
        segundonumero,
        operacao
      );

      if (errocalculo == false)
      {
        Serial.print("Resultado: ");
        Serial.println(resultado, 2);

        numeroatual = resultado;
        contafinalizada = true;
      }
    }

    if (tecla == 'C' || tecla == 'c')
    {
      confirmartecla();

      limparcalculadora();

      Serial.println("Calculadora limpa!");
      Serial.println("Digite um novo numero:");
    }
  }
}
