# 1-1. 디버그 LED 점멸 (GPIO)

## System Core
### RCC
- Mode
    - High Speed Clock(HSE): Crystal/Ceramic Resonator

## Clock Configuration
    - Input Frequency: 8
    - PPL Source Mux: HSE
    - HCLK:168

## Pinout
- LED1:PC0 -> GPIO_Output
- LED2:PC1 -> GPIO_Output
- LED3:PC2 -> GPIO_Output

--------------------------------------

# 1-2. 디버그 부저 (TIM-PWM)

## Timers
### Timer3
- Mode
    - Clock source: Internal Clock
    - Channel4 : PWM Generation CH4
- Configuration
    - Parameter Settings
        - Counter Settings
            - Prescaler: 999
            - Counter Period: 20
            - Auto-reload Preload: Enable

        - PWM  Generation Channel 4

            - Pulse: 10
            - Fast Mode: Enable

## pinout
- Buzzer: PB1 -> TIM3_CH4

## Project Manager
    - Advanced Setting
        - TIM: LL

작동시 카운터와 채널을 활성화 해주어야 함
```C
  LL_TIM_EnableCounter(TIMx);
  LL_TIM_CC_EnableChannel(TIMx, LL_TIM_CHANNEL_CHx);
```

출력 주파수를 변경하려면 PSC 혹은 ARR을 변경하면 되는데 이 강의에서는 PSC를 변경함
```C
TIMx->PSC = 2000; // 2kHz
HAL_Delay(100);
TIMx->PSC = 1500; // 3kHz
HAL_Delay(100);
TIMx->PSC = 1000; // 4kHz
HAL_Delay(100);
```

PWM 중단
```C
LL_TIM_CC_DisableChannel(TIMx, LL_TIM_CHANNEL_CHx);
```

----------------------------------

# 1-3. 디버그 UART 및 printf() 함수 사용법

## Connectivity
### USART6
- Mode: Asynchronous

- Configuration
    - Parameter Settings
        - Baud Rate: 921600

    - NVIC Settings
        - USART6 global interrupt : Enable

## pinout
- PC6 : USART6_TX
- PC7 : USART6_RX

## Project Manager
- Advanced Setting
    - USART: LL

A라는 문자를 송신하는 테스트
```C
LL_USART_TransmitData8(USARTx, 'A');
```

인터럽트 방식으로 수신
```C
LL_USART_EnableIT_RXNE(USARTx);
```

stm32f4xx_it.c 에 있는 인터럽트 핸들러 함수 수정
```C 
void USART6_IRQHandler(void)
{
	if(LL_USART_IsActiveFlag_RXNE(USARTx))
	{
		LL_USART_ClearFlag_RXNE(USARTx);
		uart6_rx_data = LL_USART_ReceiveData8(USARTx);
		uart6_rx_flag = 1;
	}
}
```

printf 사용하기
표준 출력장치를 설정해 주어야 함
```C 
int _write(int file, char* p, int len)
{
    for(int i=0;i<len;i++)
    {
        LL_USART_TransmitData8(USARTx, *(p+i));
        HAL_Delay(1);
    }

    return len;
}
```

실수형 printf로 출력하기
프로젝트 properties - C/C++ Build - Settings - other flags 에 Add
```text
-u _printf_float
```

만약 출력값이 맞지 않으면 링커 스크립트를 변경해야함