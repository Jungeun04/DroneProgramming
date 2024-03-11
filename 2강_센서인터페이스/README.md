# 센서인터페이스

## BNO080
- 3축 자이로, 3축 가속도, 3축 자기장
- 내장 컨트롤러 M0+
- 자체 센서퓨전
- 쿼터니언
- I2C, SPI, UART 인터페이스

### **PORT, PIN 설정**
**SPI2**
- MOSI: (PORTB, 15) -> SPI2_MOSI
- MISO: (PORTB, 14) -> SPI2_MISO
- SCK: (PORTB, 13) -> SPI2_SCK
- CS: (PORTB, 12) -> GPIO_Output
  
**통신 제어**
- WAKE: (PORTA, 8) - GPIO_Output
- RST: (PORTC, 9) - GPIO_Output
- INT: (PORTC, 8) - GPIO_Input

### **Driver**
- [링크](https://github.com/ChrisWonyeobPark/BNO080-STM32F4-SPI-LL-Driver)

### SPI2 설정
- Mode: Full-Duplex Master
- NSS Signal: Software control

- Data Size: 8bit
- Prescaler: 16 (42MHz/16 = 2.625MHz < MAX 3MHz)
- Clock Polarity(CPOL): High
- Clock Phase(CPHA): 2 Edge
- First bit: MSB First

---

## ICM-20602

- 3축 자이로, 3축 가속도
- Programmable Digital Filters
- I2C, SPI 인터페이스
- 작은 노이즈 레벨
- 1kB FIFO

### **PORT, PIN 설정**

**SPI1**
- MISO: (PORTA, 6) -> SPI2_MISO
- MOSI: (PORTA, 7) -> SPI2_MOSI
- SCK: (PORTA, 5) -> SPI2_SCK
- CS: (PORTC, 4) -> GPIO_Output
  
**통신 제어**
- INT: (PORTC, 5) - GPIO_Input

### **SPI1 설정**
- Mode: Full-Duplex Master
- NSS Signal: Software control

- Data Size: 8bit
- Prescaler: 8 (84MHz/8 = 10.5MHz >= MAX 10MHz)
- Clock Polarity(CPOL): High
- Clock Phase(CPHA):Rising Edge (2 Edge)
- First bit: MSB First

### **Driver**
- [링크](https://github.com/ChrisWonyeobPark/ICM20602-STM32F4-SPI-LL-Driver)

---

## LPS22HH

email test