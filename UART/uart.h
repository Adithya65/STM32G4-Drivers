#ifndef __STM_UART__
#define __STM_UART__

#define REG_WR(ADDRESS, VALUE)  (*(uint32_t*)(ADDRESS) = (VALUE))
#define REG_RD(ADDRESS)         (*(uint32_t*)(ADDRESS))

#define USART1_BASE_ADD                 ( 0x40004400 )
#define GPIOC_BASE_ADD					( 0x48000800 )
#define RCC_BASE_ADD					( 0X40021000 )

#define RCC_APHB2ENR_OFFSET 			( 0x4C )
#define RCC_APB2ENR_OFFSET				( 0x60 )

#define GPIOC_MODE_REG_OFFSET			( 0x0 )
#define GPIOC_AFRL_REG_OFFSET           ( 0x20 ) 

#define USART1_CR1_REG_OFFSET           ( 0x00 )
#define USART1_CR2_REG_OFFSET			( 0x04 )
#define USART1_CR3_REG_OFFSET			( 0x08 )
#define USART1_BRR_REG_OFFSET			( 0x0C )
#define USART1_RDR_REG_OFFSET			( 0x24 )
#define USART1_TDR_REG_OFFSET			( 0x28 )

#define USART1_CR1_REG_ADD              ( USART1_BASE_ADD + USART1_CR1_REG_OFFSET )
#define USART1_CR2_REG_ADD              ( USART1_BASE_ADD + USART1_CR2_REG_OFFSET )
#define USART1_CR3_REG_ADD              ( USART1_BASE_ADD + USART1_CR3_REG_OFFSET )
#define USART1_BRR_REG_ADD				( USART1_BASE_ADD + USART1_BRR_REG_OFFSET )
#define USART1_RDR_REG_ADD				( USART1_BASE_ADD + USART1_BRR_REG_OFFSET )
#define USART1_TDR_REG_ADD				( USART1_BASE_ADD + USART1_TDR_REG_OFFSET )

#define GPIOC_MODE_REG_ADD				( GPIOC_BASE_ADD + GPIOC_MODE_REG_OFFSET )
#define GPIOC_AFRL_REG_ADD				( GPIOC_BASE_ADD + GPIOC_AFRL_REG_OFFSET )

#define RCC_AHB2ENR_ADD 				( RCC_BASE_ADD +  RCC_AHB2ENR_OFFSET )
#define RCC_APB2ENR_ADD					( RCC_BASE_ADD +  RCC_APB2ENR_OFFSET )
 
#define EN_USART1_CLK					( 0x1 << 14 )
#define EN_GPIOC_PORT					( 0x1 << 2 )

#define CLR_PIN4						( 0x3 << 8 )
#define CLR_PIN5						( 0x3 << 10 )

#define SET_PIN4_AF						( 0x2 << 8 )
#define SET_PIN5_AF						( 0x2 << 10 )

#define CLR_PIN4_AFSEL					( 0xF << 16 )
#define CLR_PIN5_AFSEL					( 0xF << 20 )

#define SET_PIN4_USART1_TX				( 0x7 << 16 )
#define SET_PIN5_USART1_RX				( 0x7 << 20 )
#define EN_RX							( 0x1 << 2 )
#define EN_TX							( 0x1 << 3 )
#define SET_WORD_LEN_M0				   ~(( 0x1 << 12 )| ( 0x1 << 28 ))
#define EN_PARITY_CTRL				    ( 1 << 10 )
#define SET_EVEN_PARITY				   ~( 1 << 9 )
#define SET_STOP_BITS0				   ~(( 0x1 << 12 )| ( 0x1 << 13 ))

	
