#include <stdint.h>
#include "timer.h"

int main(void)
{
    uint32_t volatile RegValue = 0;

    RegValue = REG_RD ( RCC_AHB2ENR );
    RegValue |= EN_GPIOA_CLK;
    REG_WR( RCC_AHB2ENR, RegValue );

    RegValue = REG_RD( GPIOA_MODER );
    RegValue &= CLR_PORT5_BITS;
    RegValue |= GPIOA_PORT_OP_MODE ;
    REG_WR( GPIOA_MODER , RegValue );

    RegValue = REG_RD( RCC_APB1ENR1 );
    RegValue |= EN_TIM6_CLK ;
    REG_WR(RCC_APB1ENR1 , RegValue );

    RegValue = REG_RD ( TIM6_CR1 );
    RegValue &= CLR_CTR_EN;
    RegValue |= SET_ARPE;
    REG_WR ( TIM6_CR1 , RegValue );

    RegValue = ARR_VALUE;
    REG_WR( TIM6_ARR , RegValue );

    RegValue = PSC_VALUE;    
    REG_WR( TIM6_PSC , RegValue );

    RegValue = REG_RD(TIM6_CR1);
    RegValue |= EN_CTR; 
    REG_WR(TIM6_CR1, RegValue);

    while(TRUE)
    {
        RegValue = REG_RD( GPIOA_ODR );
        RegValue ^= GPIOA_P5_OP_DATA;
        REG_WR( GPIOA_ODR , RegValue );
        while(( REG_RD( TIM6_SR ) & IS_FLAG_SET ) == FLAG_NOT_SET );
        REG_WR( TIM6_SR , FLAG_NOT_SET );

    }

}




 