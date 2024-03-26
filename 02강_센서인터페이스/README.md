# 센서인터페이스

Attitude, Heading : BNO080, ICM-20602
Altitude : LPS22HH  

# 2-1. BNO080 9축(자이로, 가속도, 자기장) 센서 인터페이스 (SPI)

## BNO080
- 3축 자이로, 3축 가속도, 3축 자기장
- 내장 컨트롤러 M0+
- 자체 센서퓨전
- 쿼터니언
- I2C, SPI, UART 인터페이스

## **PORT, PIN 설정**
- MOSI: (PORTB, 15) -> SPI2_MOSI
- MISO: (PORTB, 14) -> SPI2_MISO
- SCK: (PORTB, 13) -> SPI2_SCK
- CS: (PORTB, 12) -> GPIO_Output
  
**통신 제어**
- WAKE: (PORTA, 8) - GPIO_Output
- RST: (PORTC, 9) - GPIO_Output
- INT: (PORTC, 8) - GPIO_Input

## SPI2 설정
- Connectivity
    - Mode: Full-Duplex Master
    - NSS Signal: Disalbe (Software control)

    - Data Size: 8bit
    - Prescaler: 16 (42MHz/16 = 2.625MHz < MAX 3MHz)
    - Clock Polarity(CPOL): High
    - Clock Phase(CPHA): 2 Edge
    - First bit: MSB First

## Project Manager
- Advanced Setting
    - SPI: LL

## **Driver**
- [링크](https://github.com/ChrisWonyeobPark/BNO080-STM32F4-SPI-LL-Driver)

---

# 2-2. ICM-20602 6축(자이로, 가속도) 센서 인터페이스 (SPI)

## ICM-20602

- 3축 자이로, 3축 가속도
- Programmable Digital Filters
- I2C, SPI 인터페이스
- 작은 노이즈 레벨
- 1kB FIFO

## **PORT, PIN 설정**

- MISO: (PORTA, 6) -> SPI2_MISO
- MOSI: (PORTA, 7) -> SPI2_MOSI
- SCK: (PORTA, 5) -> SPI2_SCK
- CS: (PORTC, 4) -> GPIO_Output
- INT: (PORTC, 5) - GPIO_Input

## **SPI1 설정**
- Mode: Full-Duplex Master
- NSS Signal: Software control

- Data Size: 8bit
- Prescaler: 8 (84MHz/8 = 10.5MHz >= MAX 10MHz)
- Clock Polarity(CPOL): High
- Clock Phase(CPHA):Rising Edge (2 Edge)
- First bit: MSB First

## **Driver**
- [링크](https://github.com/ChrisWonyeobPark/ICM20602-STM32F4-SPI-LL-Driver)

---

## LPS22HH

- 기압고도센서(온도센서 포함)
- 동작범위(압력): 260hPa ~ 1260hPa (24bit)
- 동작범위(온도): -40°C ~ 80°C (16bit)
- 1Hz ~ 200Hz ODR(Pressure Output Data Rate)
- I2C, SPI, MIPI I3C 인터페이스


### **PORT, PIN 설정**

**SPI3**
- MISO: (PORTB, 4) -> SPI3_MISO
- MOSI: (PORTB, 5) -> SPI3_MOSI
- CS: (PORTB, 6) -> GPIO_Output
- SCK: (PORTB, 3) -> SPI3_SCK
  
**통신 제어**
- INT: (PORTB, 7) - GPIO_Input

### **SPI3 설정**
- Mode: Full-Duplex Master
- NSS Signal: Software control

- Data Size: 8bit
- Prescaler: 4(42Mhz/4 = 10.5MHz >= Max 10MHz)
- Clock Polarity(CPOL): High
- Clock Phase(CPHA):Rising Edge (2 Edge)
- First bit: MSB First

### **Driver**
- [링크](https://github.com/ChrisWonyeobPark/LPS22HH-STM32F4-SPI-LL-Driver)  

### IIR(Infinity Impulse Response)
- 결과가 input에 의해서만 관계식이 나타내어 지는 것이 아니라 이전의 결과도 영향을 주는 방정식
- Initial Rest Condition이 필요함  
$$y[n]=\sum_{l=0}^{N}{a_l y[n-l]}+\sum_{k=0}^{M}{b_k x[n-k]}$$
- x: input signal
- y: result 