# AT24C08 EEPROM - PID Gain 저장 (I2C)

- 8kbits 메모리
- 내부적으로 64개의 apges로 영역을 구분.
- 1page당 16bytes의 크기를 가짐.
- I2C 인터페이스
  
  ## EEPROM Protocol 관리
  사용자가 자체 정의해서 제작한다.
  -'E'(0x45),'P'(0x50) 로 시작
|'E'|'P'|ID|P|P|P|P|I|I|I|I|D|D|D|D|CheckSUM|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|


  ```C

  #include "i2c.h"

    void AT24C08_Page_Write(uint8_t page, uint8_t* data, uint8_t len){

        uint8_t devAddress= ((page * 16)>>8)<<1 | 0xA0;
        uint8_t wordAddress = (page * 16) & 0xff;

        LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_13);
        HAL_I2C_Mem_Write(&hi2c1, devAddress, wordAddress, I2C_MEMADD_SIZE_8BIT, data, 16, 1);
        HAL_Delay(1);
        LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_13);
    }

    void AT24C08_Page_Read(uint8_t page, uint8_t* data, uint8_t len){

        uint8_t devAddress= ((page * 16)>>8)<<1 | 0xA0;
        uint8_t wordAddress = (page * 16) & 0xff;

        HAL_I2C_Mem_Write(&hi2c1, devAddress, wordAddress, I2C_MEMADD_SIZE_8BIT, data, 16, 1);
        HAL_Delay(1);
    }

  ```

# 배터리 전압 확인

# BNO080 sensor calibration

# ICM-20602 Gyro offset 제거




