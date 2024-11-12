	#include "uart.h"

	int main()
	{
		uint32_t volatile RegValue = 0;
		
		RegVal = REG_RD( RCC_AHB2ENR_ADD );
		RegVal |= EN_GPIOC_PORT;
		REG_WR( RCC_AHB2ENR_ADD , RegVal );

		RegVal = REG_RD( RCC_APB2ENR_ADD );
		RegVal |= EN_USART1_CLK;
		REG_WR( RCC_APB2ENR_ADD , RegVal );

		RegVal = REG_RD( GPIOC_MODE_REG_ADD );
		RegVal &= ~CLR_PIN4;
		RegVal &= ~CLR_PIN5;

		RegVal |= SET_PIN4_AF;
		RegVal |= SET_PIN5_AF;
		REG_WR( GPIOC_MODE_REG_ADD , RegVal );

		RegVal = REG_RD( GPIOC_AFRL_REG_ADD );
		RegVal &= ~CLR_PIN4_AFSEL;
		RegVal &= ~CLR_PIN5_AFSEL;
		
		RegVal |= SET_PIN4_USART1_TX;
		RegVal |= SET_PIN5_USART1_RX;
		REG_WR( GPIOC_AFRL_REG_ADD , RegVal );

		RegVal = REG_RD( USART1_CR1_REG_ADD );
		RegVal |= EN_RX | EN_TX;
		RegVal &= SET_WORD_LEN_M0;
		RegVal &= SET_EVEN_PARITY;
		RegVal &= EN_PARITY_CTRL;	
		REG_WR( USART1_CR1_REG_ADD , RegVal );

		RegVal = REG_RD( USART1_CR2_REG_ADD );
		RegVal &= SET_STOP_BITS0;	
		
		RegVal = REG_RD( USART1_BRR_REG_ADD );
		RegVal |= 0x681;
		REG_WR( USART1_BRR_REG_ADD , RegVal );

		REG_WR( USART1_RDR_REG_ADD , "A");
		ulRegVal = REG_RD( USART1_CR1_REG_ADD );
		ulRegVal |= 1;
		REG_WR( USART1_CR1_REG_ADD ,ulRegVal);

		while( REG_RD( USART1_ISR_REG_ADD )&(1 << 6));
	}
		
		
