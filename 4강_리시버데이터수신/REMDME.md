#Rate

## Flysky FS-i6B
- PWM 채널 수: 6채널
- PPM 출력
- i-Bus 출력
- 동작 전원: 4V ~ 8.4V
- i-Bus output rate 약 133Hz (7.5ms)
- Fail-safe 기능 내장 (조종기에서 설정)

### **PORT, PIN 설정**
- TX: RX5 (PORTD, 2)
-   : TX5 (PORTC, 12)

### **UART5 설정**
- Mode: Asynchronous 
- Word Length: 8 Bits
- Baud Rate: 115200bps
- Parity: None
- Stop bits: 1
- Interrupt: RXNE interrupt(수신인터럽트 사용)

### i-Bus 프로토콜로

- Flysky의 자체 프로토콜 (정식 설명 문서가 없음)
- UART 115200bps의 고정 속도
- 0x20, 0x40 으로 시작
- Little Endian의 16비트 데이터 타입
- 32byte의 고정 길이


