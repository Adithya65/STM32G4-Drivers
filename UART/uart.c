#include "uart.h"

int main()
{
	uint32_t volatile RegValue = 0;
	
	RegVal = RD_REG32( RCC_AHB2ENR_ADD );
	RegVal |= EN_GPIOC_PORT;
	WR_REG32( RCC_AHB2ENR_ADD , RegVal );

	RegVal = RD_REG32( RCC_APB2ENR_ADD );
	RegVal |= EN_USART1_CLK;
	WR_REG32( RCC_APB2ENR_ADD , RegVal );

	RegVal = RD_REG32( GPIOC_MODE_REG_ADD );
	RegVal &= ~CLR_PIN4;
	RegVal &= ~CLR_PIN5;

	RegVal |= SET_PIN4_AF;
	RegVal |= SET_PIN5_AF;
	WR_REG32( GPIOC_MODE_REG_ADD , RegVal );

	RegVal = RD_REG32( GPIOC_AFRL_REG_ADD );
	RegVal &= ~CLR_PIN4_AFSEL;
	RegVal &= ~CLR_PIN5_AFSEL;
	
	RegVal |= SET_PIN4_USART1_TX;
	RegVal |= SET_PIN5_USART1_RX;

	WR_REG32( GPIOC_AFRL_REG_ADD , RegVal );
}
	
	
