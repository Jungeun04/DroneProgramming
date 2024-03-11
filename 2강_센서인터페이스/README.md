# 센서인터페이스

## BNO080
- 3축 자이로, 3축 가속도, 3축 자기장
- 내장 컨트롤러 M0+
- 자체 센서퓨전
- 쿼터니언
- I2C, SPI, UART 인터페이스

### PORT, PIN 설정
**SPI**
- MOSI: (PORTB, 15) -> SPI_MOSI
- MISO: (PORTB, 14) -> SPI2_MISO
- SCK: (PORTB, 13) -> SPI2_SCK
- CSS: (PORTB,12) -> GPIO_Output
  
**통신 제어**
- WAKE: (PORTA, 8) - GPIO_Output
- RST: (PORTC, 9) - GPIO_Output
- INT: (PORTC, 8) - GPIO_Input


### SPI 설정
- Mode: Full-Duplex Master
- NSS Signal: Software control

- Data Size: 8bit
- Prescaler: 16 (42MHz/16 = 2.625MHz < 3MHz)
- Clock Polarity(CPOL): High
- Clock Phase(CPHA): 2 Edge
- First bit: MSB First

##