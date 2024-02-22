/*************************************************************************/
/****     Target    : GPIO_prog,c                                      ****/
/****     Target    : STM32F103C8T6                                   ****/
/****     Author    : Mahmoud Abdelmoniem                             ****/
/****     Date      : 1/2024                                          ****/
/****     version    : 0.0                                            ****/
/*************************************************************************/
#include "GPIO_interface.h"
static GPIO_RegDef_t* GPIO_Ports[5]={GPIOA,GPIOB,GPIOC,GPIOD,GPIOE};

/**************************************************
 * @Func   :GPIO_u8PinInit
 * @brief  :this function initilizes modes of pins according to input parameters
 * @para   :PinConfig_t[in] the initilization vales of the pin
 * @retval :return Error status
 */
uint8_t GPIO_u8PinInit(const PinConfig_t * pinconfg)
{
	uint8_t Local_u8ErrorState = NOK ;
    if( pinconfg != NULL)
    {

    		if(pinconfg->Mode == GPIO_INPUT)
    		{
    			if(pinconfg->PinNum > 7)
    			{
    				GPIO_Ports[pinconfg->Port]->CRH &= ~(CONTROL_REGISTER_MASK << ((pinconfg->PinNum-8)*2));    //clear the MODE bits in the register to select input
    				GPIO_Ports[pinconfg->Port]->CRH &= ~(CONTROL_REGISTER_MASK << (((pinconfg->PinNum-8)+1))*2); //clear the CFG bits in the register
    				GPIO_Ports[pinconfg->Port]->CRH |= ((pinconfg->InMode) << (((pinconfg->PinNum-8) *4)+2)); //set bits CFG to set input mode
    			}
    			else if(pinconfg->PinNum <= 7)
    			{
    				GPIO_Ports[pinconfg->Port]->CRL &= ~(CONTROL_REGISTER_MASK << ((pinconfg->PinNum)*2));    //clear the MODE bits in the register to elect input
    				GPIO_Ports[pinconfg->Port]->CRL &= ~(CONTROL_REGISTER_MASK << (((pinconfg->PinNum)+1))*2); //clear the CFG bits in the register
    				GPIO_Ports[pinconfg->Port]->CRL |= ((pinconfg->InMode) << (((pinconfg->PinNum) *4)+2)); //set bits CFG to set input mode
    			}
    			else{
    				Local_u8ErrorState =  NOK;  //if undefined pin number
    			}
    		}
    		else if(pinconfg->Mode == GPIO_OUTPU)
    		{
    			if(pinconfg->PinNum > 7)
    			{
    				/*fill MODE bits*/
    				GPIO_Ports[pinconfg->Port]->CRH &= ~(CONTROL_REGISTER_MASK << ((pinconfg->PinNum-8)*4));    //clear the MODE bits in the register
    				GPIO_Ports[pinconfg->Port]->CRH |= ((pinconfg->OutMaxSpeed) << ((pinconfg->PinNum-8)*4));    //Select the output max speed MODE
    				/*fill CFG bits*/
    				GPIO_Ports[pinconfg->Port]->CRH &= ~(CONTROL_REGISTER_MASK << ((pinconfg->PinNum-8)*4 +2)); //clear the CFG bits in the register
    				GPIO_Ports[pinconfg->Port]->CRH |= ((pinconfg->Outmode) << (((pinconfg->PinNum-8) *4)+2)); //set bits CFG to set output mode
    				/************set pull up or pull down*************/
    				/*clear ODR register*/
    				GPIO_Ports[pinconfg->Port]->ODR &= ~(1 << pinconfg->PinNum);
    				/*state pull up or pull down value to ODR*/
    				GPIO_Ports[pinconfg->Port]->ODR |= (pinconfg->Pull << pinconfg->PinNum);
    			}
    			else if(pinconfg->PinNum <= 7)
    			{
    				/*fill MODE bits to select :push pull,open drain,AF push pull,AF open drain*/
    				GPIO_Ports[pinconfg->Port]->CRL &= ~(CONTROL_REGISTER_MASK << ((pinconfg->PinNum)*4));    //clear the MODE bits in the register
    				GPIO_Ports[pinconfg->Port]->CRL |= ((pinconfg->OutMaxSpeed) << ((pinconfg->PinNum)*4));    //Select the output max speed MODE
    				/*fill CFG bitsto select : max speed*/
    				GPIO_Ports[pinconfg->Port]->CRL &= ~(CONTROL_REGISTER_MASK << (((pinconfg->PinNum)*4)+2)); //clear the CFG bits in the register
    				GPIO_Ports[pinconfg->Port]->CRL |= ((pinconfg->Outmode) << (((pinconfg->PinNum) *4)+2)); //set bits CFG to set output mode
    			}
    			else{
    				Local_u8ErrorState =  NOK;  //if undefined pin number
    			}
    		}
    		else
    		{
    			Local_u8ErrorState =  NOK;  //if undefined mode
    		}

    }
    else{
    	Local_u8ErrorState = NULL_PTR_ERROR ;
    }

    return Local_u8ErrorState;
}
/******************************************************************
 * @Func : GPIO_u8SetPinValue
 * @beif : this function that rest or set pin value
 * @para port[in] port name in the enum Port_t
 * @para pinNum[in] the pin number in the port in the enum pin
 * @para pinStatus[in] the state of the pin in port the value in this enum GPIO_PinSts
 * @retval :return Error status
 */
uint8_t GPIO_u8SetPinValue(Port_t port,Pin pinNum,GPIO_PinSts pinStatus)
{
	uint8_t Local_u8ErrorState = NOK ;
	if(port<=GPIO_PORTE && pinNum<= GPIO_PIN_15)
	{
		/*clear ODR register*/
		GPIO_Ports[port]->ODR &= ~(pinStatus << pinNum);
		/*Write the pinStatus value to ODR*/
		GPIO_Ports[port]->ODR |= (pinStatus << pinNum);
		Local_u8ErrorState = OK ;
	}
	else{
		Local_u8ErrorState = NOK ; //undefined port or pin number
	}
	return Local_u8ErrorState;
}
/******************************************************************
 * @Func : GPIO_u8TogglePinValue
 * @beif : this function that toggle pin value
 * @para port[in] port name in the enum Port_t
 * @retval :return Error status
 */
uint8_t GPIO_u8TogglePinValue(Port_t port,Pin pinNum)
{
	uint8_t Local_u8ErrorState = NOK ;
	if(port<=GPIO_PORTE && pinNum<= GPIO_PIN_15)
	{

		/*Write the pinStatus value to ODR*/
		TOGGLE_BIT(GPIO_Ports[port]->ODR,pinNum);
		Local_u8ErrorState = OK ;
	}
	else{
		Local_u8ErrorState = NOK ; //undefined port or pin number
	}
	return Local_u8ErrorState;
}
/******************************************************************
 * @Func : GPIO_u8GetPinValue
 * @beif : this function that get pin value
 * @para port[in] port name in the enum Port_t
 * @para pinNum[in] the pin number in the port in the enum pin
 * @para pinStatus[out] the state of the targeted pin in port the value in this enum GPIO_PinSts
 * @retval :return Error status
 */
uint8_t GPIO_u8GetPinValue(Port_t port,Pin pinNum,GPIO_PinSts *pinStatus)
{
	uint8_t Local_u8ErrorState = NOK ;
	if(port<=GPIO_PORTE && pinNum<= GPIO_PIN_15)
	{

		/*Write the pinStatus value to ODR*/
		*pinStatus = READ_BIT(GPIO_Ports[port]->ODR,pinNum);
		Local_u8ErrorState = OK ;
	}
	else{
		Local_u8ErrorState = NOK ;  //undefined port or pin number
	}
	return Local_u8ErrorState;
}
