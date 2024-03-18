# ESC

**이제 FC를 작동시킬 때 배터리를 연결하여야 하는데, 배터리 보호 회로가 없으므로 배터리 전압이 10V미만으로 떨어지지 않게 주의하여야 한다.**

## FVT Little Bee 30-S ESC
- 30A
- Motor Driver 내장

## ESC 프로토콜
- 사용할 프로토콜: oneshot125

## Timer 설정
- PSC(Prescaler): 1
- ARR(Auto Reload Register): 42000
- CCR(Capture/Compare Register)
    - CCR1(TIM5-CH1, PA0): 10500
    - CCR2(TIM5-CH2, PA1): 21000
    - CCR3(TIM5-CH3, PA2): 31500
    - CCR4(TIM5-CH4, PA3): 10500 ~ 21000
- TIM5(32bit, APB1=84MHz)
    - TIM Clock: Internal Clock
    - Channel: PWM Generation CH1-CH4
    - Prescale:0(=1)
    - Count Mode: Up Count
    - Period: 41999(=42000)
    - Internal Clock Division: No Division
    - PWM Mode: Mode1
    - Pulse = 0 ~ ARR
    - CH Polarity: High

## ESC calibration
1. ESC Power Up
2. PWM을 최대 펄스 폭으로 set: MAX 펄스폭 설정 -> 3초 이상 대기
3. PWM을 최소 펄스 폭으로 set: MIN 펄스폭 설정 -> 3초 이상 대기
4. ESC calibration 완료
5. 모터 Ready