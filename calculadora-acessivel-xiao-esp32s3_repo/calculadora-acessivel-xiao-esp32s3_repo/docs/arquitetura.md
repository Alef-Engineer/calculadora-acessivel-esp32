# Arquitetura

```text
Botões físicos
      ↓
   MCP23017
      ↓
 XIAO ESP32-S3
      ↓
 ┌───────────────┬────────────────┐
 ↓               ↓                ↓
Cálculo         Buzzer        MAX98357A
                                  ↓
                             Alto-falante
```

Durante o desenvolvimento, o Serial Monitor substitui temporariamente os botões físicos.
