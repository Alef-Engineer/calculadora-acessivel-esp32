# Calculadora Acessível com XIAO ESP32-S3

Projeto de uma calculadora acessível baseada no **Seeed Studio XIAO ESP32-S3**.

A ideia é permitir operações matemáticas por meio de botões físicos, com confirmação sonora e reprodução por voz dos números, operações e resultados.

## Estado atual

A lógica está sendo testada primeiro pelo **Serial Monitor**.

Já implementado:

- leitura de teclas pelo Serial;
- números com vários dígitos;
- soma, subtração, multiplicação e divisão;
- resultados decimais;
- tecla `=`;
- tecla `C`;
- reaproveitamento do resultado anterior;
- tratamento de divisão por zero;
- tratamento de operação inválida;
- confirmação por LED;
- organização em funções.

## Hardware previsto

- XIAO ESP32-S3
- MCP23017
- 16 botões físicos
- Buzzer
- MAX98357A
- Alto-falante

## Teclas previstas

`0 1 2 3 4 5 6 7 8 9 + - * / = C`

## Próximas etapas

1. Adaptar `lertecla()` para o MCP23017.
2. Mapear os 16 botões.
3. Integrar o buzzer.
4. Integrar o MAX98357A.
5. Implementar reprodução por voz.
6. Testar o sistema completo.

## Estrutura do repositório

```text
calculadora-acessivel-xiao-esp32s3/
├── README.md
├── .gitignore
├── src/
│   └── calculadora_acessivel.ino
├── docs/
│   ├── pseudocodigo.md
│   ├── arquitetura.md
│   └── roadmap.md
├── hardware/
│   └── README.md
├── audio/
│   ├── numeros/
│   └── operacoes/
└── assets/
    ├── fluxogramas/
    └── imagens/
```
