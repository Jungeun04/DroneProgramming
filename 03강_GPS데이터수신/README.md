# GPS 데이터 수신

## u-blox M8 GNSS
- 수신가능 위성: GPS, Galileo, GLONASS, BeiDou
- NMEA, UBX, RTCM 메시지 프로토콜
- 설정 프로그램 u-center 제공

### **PORT, PIN 설정**

- RX: (PORTC, 10) -> UART4_TX
- TX: (PORTC, 11) -> UART4_RX

### **UART4 설정**
- Mode: Asynchronous
- Word Length: 8 Bits
- Baud Rate: 9600bps
- Parity: None
- Stop bits: 1
- Interrupt: RXNE interrupt(수신인터럽트 사용)

### UBX 프로토콜로 변경

- 데이터가 문자가 아닌 바이너리 형태
- Ublox 자체 프로토콜
- 0xB5 0x62로 시작