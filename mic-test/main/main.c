#include <stdio.h>
#include <driver/adc.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

void app_main()
{
    // Configurar el ADC
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(ADC1_CHANNEL_0, ADC_ATTEN_DB_11);

    while (1)
    {
        // Leer el valor analógico del pin ADC1_CHANNEL_0
        int val = adc1_get_raw(ADC1_CHANNEL_0);

        // Imprimir el valor en la consola
        printf("Valor leído: %d\n", val);

        // Esperar 1 segundo antes de leer nuevamente
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
