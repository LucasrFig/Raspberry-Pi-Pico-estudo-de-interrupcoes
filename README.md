──────────────────────────────────────────────────────────────────────  
# PROJETO - ESTUDO DE ROTINAS DE INTERRUPÇÃO
(SUB GRUPO 6)  
**Aluno: Lucas Ricardo de Lima Figueiredo** 

──────────────────────────────────────────────────────────────────────  
## OBJETIVO DO PROJETO  
──────────────────────────────────────────────────────────────────────  

O objetivo deste projeto é criar um contador na matriz de LEDs que varie de 0 a 9, com o uso de rotinas de interrupção ligadas aos botões da placa Bit Dog Lab, ao mesmo tempo que, na função principal, o led pisca 5 vezes por segundo. Com isso pude explorar algumas funções relacionadas a solucionar o problema boucing dos botões via software e me aprofundar dentro das rotinas de interrupção.

──────────────────────────────────────────────────────────────────────  
## FUNCIONALIDADES DO PROJETO  
──────────────────────────────────────────────────────────────────────  

Comandos do código:

**Botão A 'Incrementar':** Incrementa o valor exibido na matriz de LEDs, caso o valor seja 9 o valor passa a ser 0.

**Botão B 'Decrementar':** Decrementa o valor exibido na matriz de LEDs, caso o valor seja 0 o valor passa a ser 9.

**Botão JoyStick 'Bootloader':** Apaga a matriz de LEDs e põe a placa em modo de gravação (BootLoader);

──────────────────────────────────────────────────────────────────────  
## TECNOLOGIAS UTILIZADAS  
──────────────────────────────────────────────────────────────────────  
- Linguagem: C;
- Microcontrolador: Raspberry Pi Pico (RP2040);
- Plataforma de simulação Wokwi.

──────────────────────────────────────────────────────────────────────  
## COMO EXECUTAR O PROJETO
──────────────────────────────────────────────────────────────────────  
- **Clone o Repositório:**
  git clone [https://github.com/LucasrFig/Atividade-2_Controle-de-pinos-GPIO-com-BitDogLab.git](https://github.com/LucasrFig/Raspberry-Pi-Pico-estudo-de-interrupcoes.git)
  
- **Compile o Código:**
  Utilize o ambiente de desenvolvimento VS Code. 
  Instalar extensão: Raspberry Pi Pico.

- **Carregue na Raspberry Pi Pico:**
  Conecte a Raspberry Pi Pico em modo de boot.
  Copie o arquivo .uf2 gerado para a unidade de armazenamento da Pico.

──────────────────────────────────────────────────────────────────────  
## VÍDEO DO PROJETO  
────────────────────────────────────────────────────────────────────── 

https://drive.google.com/file/d/1BTZqWgYYjLG-UxNNoCXMs_mewUZ807mC/view?usp=drivesdk
