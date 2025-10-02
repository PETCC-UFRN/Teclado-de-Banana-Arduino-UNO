# Teclado de Banana Arduino UNO

Esse [tutorial](https://www.instructables.com/How-to-Make-a-Arduino-HID-Keyboard/) foi utilizado como referência para a execução desse projeto.
Os arquivos da pasta 'ArduinoHIDKeyboard by Eward Hage' foram disponibilizados nesse tutorial pelo Eward Hage, todos os créditos a ele.

## Antes de começar
- Instale a ultima versão disponivel do java
- Instale o FLIP, disponibilizado em 'ArduinoHIDKeyboard by Eward Hage/FLIP install/'
- Monte o circuito [dessa maneira](https://github.com/PETCC-UFRN/Teclado-de-Banana-Arduino-UNO/blob/main/Arduino.png).
## Como transformar o Arduino UNO em teclado

Com o código já carregado no arduino, siga os seguintes passos:

### 1. Conecte o arduino ao computador

### 2. Abra o FLIP, e no botão de device selection selecione 'ATmega16U2'

### 3. Dê o curto nos dois pinos da placa indicados [aqui](https://github.com/PETCC-UFRN/Teclado-de-Banana-Arduino-UNO/blob/main/Arduino.png) rapidamente.
  O Arduino sera desconectado e conectado novamente no computador automaticamente.

### 4. Vá em USB Port Connection e selecione open

Caso tenha erros nesse passo ou no passo 2 relacionados a "AtLibUsbDfu.dll not found", siga a [solução](https://www.youtube.com/watch?v=KQ9BjKjGnIc)  feita por MDGrein.

### 5. Vá em File -> Load HEX File e carregue:

- Caso queira transformar em teclado: ArduinoHIDKeyboard by Eward Hage/HEX/KeyboardFirmware/Arduino-keyboard-0.3.hex

- Caso queira voltar ao estado reprogramável do Arduino: ArduinoHIDKeyboard by Eward Hage/HEX/ArduinoFirmware/Arduino-usbserial-uno.hex

### 6. Clique em Run

### 7. Desconecte e conecte novamente o Arduino ao computador

### 8. Pronto!

Ao completar o passo 7 seu teclado de banana deve estar funcional.

Note que toda vez que for preciso reprogramar o teclado você precisará repetir esse tutorial utilizando o Arduino-keyoard-0.3.hex.
