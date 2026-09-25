# Pseudocódigo

```text
INÍCIO

Inicializar o sistema
Zerar os valores da calculadora

ENQUANTO a calculadora estiver ligada

    Aguardar uma tecla ser pressionada

    SE a tecla for um número
        Adicionar o dígito ao número atual
        Emitir confirmação sonora
    FIM SE

    SE a tecla for uma operação
        Guardar o primeiro número
        Guardar a operação escolhida
        Preparar a entrada do segundo número
    FIM SE

    SE a tecla for "="
        Guardar o segundo número

        SE a operação for válida
            Realizar o cálculo

            SE houver divisão por zero
                Informar erro
            SENÃO
                Mostrar e reproduzir o resultado
                Guardar o resultado para nova operação
            FIM SE

        SENÃO
            Informar que nenhuma operação foi selecionada
        FIM SE
    FIM SE

    SE a tecla for "C"
        Apagar os valores armazenados
        Preparar a calculadora para uma nova conta
    FIM SE

FIM ENQUANTO

FIM
```
