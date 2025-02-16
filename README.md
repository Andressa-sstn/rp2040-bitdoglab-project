Projeto RP2040 com BitDogLab

# Projeto RP2040 com BitDogLab

Este projeto implementa um sistema para controle de LEDs RGB e exibição em um display SSD1306 utilizando um joystick, desenvolvido para a placa BitDogLab com o microcontrolador RP2040.

## Funcionalidades
- Controle PWM dos LEDs RGB baseado na posição do joystick.
- Exibição de um quadrado móvel no display SSD1306 via I2C.
- Interrupções para detecção de pressionamento do joystick e botão extra.
- Debouncing via software para os botões.
- Alternância de estado do LED verde ao pressionar o botão do joystick.
- Modificação do estilo da borda do display a cada acionamento do joystick.
- Ativação e desativação dos LEDs PWM pelo botão A.

## Estrutura do Projeto
```
📂 rp2040-bitdoglab-project
│── 📂 src
│   │── main.c                # Código principal do projeto
│   │── joystick.c            # Módulos para leitura do joystick
│   │── joystick.h            # Cabeçalho do joystick
│   │── display.c             # Módulo para controle do display OLED
│   │── display.h             # Cabeçalho do display
│   │── pwm_control.c         # Controle PWM dos LEDs
│   │── pwm_control.h         # Cabeçalho do PWM
│── 📂 include
│   │── ssd1306.h             # Biblioteca do display SSD1306
│── 📂 lib
│   │── ssd1306.c             # Implementação da biblioteca do display
│── README.md                 # Documentação do projeto
│── CMakeLists.txt            # Configuração do projeto para compilação
│── .gitignore                # Arquivos a serem ignorados no Git
```

## Configuração e Compilação
1. Clone este repositório:
   ```sh
   git clone https://github.com/seu-usuario/rp2040-bitdoglab-project.git
   cd rp2040-bitdoglab-project
   ```
2. Configure o ambiente de desenvolvimento do RP2040 (Pico SDK instalado).
3. Compile o projeto:
   ```sh
   mkdir build
   cd build
   cmake ..
   make
   ```
4. Carregue o firmware gerado no RP2040.

## Requisitos
- Placa BitDogLab com RP2040
- Display OLED SSD1306 (I2C)
- Joystick analógico
- LEDs RGB

## Autor
Andressa Silva Santos.

