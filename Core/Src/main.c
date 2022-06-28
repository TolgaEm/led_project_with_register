
#include "main.h"

void SystemClock_Config(void);
void led_blink_init(void);


int main(void)
{




  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();


  while (1)
  {
    led_blink_init();
  }
}

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}



void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

void led_blink_init(void){

	RCC->AHB1ENR ; // D port clock is enable

	// SET OUPUT MODE FOR D12-13-14-15
	GPIOD->MODER &= ~(1<<31);
	GPIOD->MODER |=  (1<<30);
	GPIOD->MODER &= ~(1<<29);
	GPIOD->MODER |=  (1<<28);
	GPIOD->MODER &= ~(1<<27);
	GPIOD->MODER |=  (1<<26);
	GPIOD->MODER &= ~(1<<25);
	GPIOD->MODER |=  (1<<24);


	// SET PUSH-PULL MODE
	GPIOD->OTYPER &= ~(1<<15);
	GPIOD->OTYPER &= ~(1<<14);
	GPIOD->OTYPER &= ~(1<<13);
	GPIOD->OTYPER &= ~(1<<12);

	// SET CLOCK SPEED
	GPIOD->OSPEEDR &= ~(1 << 31);
	GPIOD->OSPEEDR |=  (1 << 30);
	GPIOD->OSPEEDR &= ~(1 << 29);
	GPIOD->OSPEEDR |=  (1 << 28);
	GPIOD->OSPEEDR &= ~(1 << 27);
	GPIOD->OSPEEDR |=  (1 << 26);
	GPIOD->OSPEEDR &= ~(1 << 25);
	GPIOD->OSPEEDR |=  (1 << 24);

	// SET NO-PULL
	GPIOD->PUPDR &= ~(1 << 31);
	GPIOD->PUPDR &= ~(1 << 30);
	GPIOD->PUPDR &= ~(1 << 29);
	GPIOD->PUPDR &= ~(1 << 28);
	GPIOD->PUPDR &= ~(1 << 27);
	GPIOD->PUPDR &= ~(1 << 26);
	GPIOD->PUPDR &= ~(1 << 25);
	GPIOD->PUPDR &= ~(1 << 24);


	GPIOD->ODR |=  (1<<15);
	HAL_Delay(500);
	GPIOD->ODR &= ~(1<<15);
	HAL_Delay(500);

	GPIOD->ODR |=  (1<<14);
	HAL_Delay(500);
	GPIOD->ODR &= ~(1<<14);
	HAL_Delay(500);

	GPIOD->ODR |=  (1<<13);
	HAL_Delay(500);
	GPIOD->ODR &= ~(1<<13);
	HAL_Delay(500);

	GPIOD->ODR |= (1<<12);
	HAL_Delay(500);
	GPIOD->ODR |= (1<<12);
	HAL_Delay(500);
}

