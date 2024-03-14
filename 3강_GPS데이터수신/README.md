# GPS 데이터 수신

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
