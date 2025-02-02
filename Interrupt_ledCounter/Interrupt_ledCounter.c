//Incluir bibliotecas base para o projeto
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "pico/bootrom.h"

//incluir bibliotecas criadas
#include "interrupt_ledCounter.pio.h"
#include "library/led_commands.h"
#include "library/numbers.h"

//definir GPIOs
#define LED_MATRIX 7
#define BUT_A 5
#define BUT_B 6
#define BUT_JSTICK 22
#define LED_RED 13

// Variáveis de ocorrência para interrupção
static volatile uint a = 1;
static volatile uint32_t last_time = 0; // Armazena o tempo do último evento (em microssegundos)

//Escopo rotina de interrupção
static void gpio_irq_handler(uint gpio,uint32_t events);


//Número na matriz será inicialmente 0:
uint count = 0;

PIO pio;
uint sm;

int main()
{
    //inicializa PIO para a matriz de LEDs
    pio = pio0; 
    bool ok;

    printf("iniciando a transmissão PIO");
    if (ok) printf("clock set to %ld\n", clock_get_hz(clk_sys));

    //configurações da PIO
    uint offset = pio_add_program(pio, &interrupt_ledCounter_program);
    sm = pio_claim_unused_sm(pio, true);
    interrupt_ledCounter_program_init(pio, sm, offset, LED_MATRIX);

    
    //Inicializar LED
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED,GPIO_OUT);
    
    //Inicializar Botões
    gpio_init(BUT_A);
    gpio_set_dir(BUT_A,GPIO_IN);
    gpio_pull_up(BUT_A);

    gpio_init(BUT_B);
    gpio_set_dir(BUT_B,GPIO_IN);
    gpio_pull_up(BUT_B);

    gpio_init(BUT_JSTICK);
    gpio_set_dir(BUT_JSTICK,GPIO_IN);
    gpio_pull_up(BUT_JSTICK);

    //Inicializar funções da stdio
    stdio_init_all();



    //interrupção da gpio habilitada incrementar contagem
    gpio_set_irq_enabled_with_callback(BUT_A, GPIO_IRQ_EDGE_FALL, 1, &gpio_irq_handler);
    //interrupção da gpio habilitada decrementar contagem
    gpio_set_irq_enabled_with_callback(BUT_B, GPIO_IRQ_EDGE_FALL, 1, &gpio_irq_handler);
    //interrupção da gpio habilitada decrementar contagem
    gpio_set_irq_enabled_with_callback(BUT_JSTICK, GPIO_IRQ_EDGE_FALL, 1, &gpio_irq_handler);

    //Escrever 0
    print_number(count,pio,sm);
    printf("count: %d\n",count);


    //Led Pisca 5 Vezes por segundo:
    while (true) {
        
        gpio_put(LED_RED,1);
        busy_wait_ms(100);
        gpio_put(LED_RED,0);
        busy_wait_ms(100);
        printf("repeat\n");
    }
}

static void gpio_irq_handler(uint gpio,uint32_t events){
    
    // Obtém o tempo atual em microssegundos
    uint32_t current_time = to_us_since_boot(get_absolute_time());
    printf("A = %d\n", a);
    // Verifica se passou tempo suficiente desde o último evento

    if (current_time - last_time > 200000){ // 200 ms de debouncing

        last_time = current_time;

        if(gpio == BUT_A){
            if(count<9) count++; else count=0;
            printf("count: %d\n",count);
            print_number(count,pio,sm);
        }

        if(gpio == BUT_B){
            if(count>0) count--; else count = 9;
            printf("count: %d\n",count);
            print_number(count,pio,sm);
        }
        a++;
    }
    
    if(gpio == BUT_JSTICK){
        printf("Reiniciando a placa em modo de gravação...\n");
        print_number(10,pio,sm);
        reset_usb_boot(0,0);
    }
}