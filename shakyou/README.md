System Core
RCC
 High Speed Clock(HSE): Crystal/Ceramic Resonator
Clock Configuration
 Input Frequency: 8
 PPL Source Mux: HSE
 HCLK:168
Pinout
 LED1:PC0->GPIO_Output
 LED2:PC1->GPIO_Output
 LED3:PC2->GPIO_Output
--------------------------------------
# 1-2. 디버그 부저 (TIM-PWM)

Timer3
Mode
Clock source: Internal Clock
Channel4 : PWM Generation CH4

Counter Settings
Prescaler: 999
Counter Period: 20
Auto-reload Preload: Enable

PWM  Generation Channel 4

Pulse: 10
Fast Mode: Enable

pinout
Buzzer: PB1->TIM3_CH4

Project Manager
Advanced Setting
TIM: LL

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
