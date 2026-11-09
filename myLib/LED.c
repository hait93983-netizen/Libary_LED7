#include "LED.H"

uint8_t seg_code[10] = {
	0x3F, //0  
	0x06, //1
	0x5B, //2
	0x4F, //3
 	0x66, //4	
	0x6D, //5
	0x7D, //6
	0x07, //7
	0x7F, //8
	0x6F, //9
};


void LED7_Init(LED7_Handdle_t *hLed,
	             LED7_GPIO_t seg_a,
               LED7_GPIO_t seg_b,
               LED7_GPIO_t seg_c,
               LED7_GPIO_t seg_d,
               LED7_GPIO_t seg_e,
               LED7_GPIO_t seg_f,
               LED7_GPIO_t seg_g,
               LED7_Type_t type) 
{
		hLed->type = type;
	  hLed->seg[0] = seg_a;
	  hLed->seg[1] = seg_b;
	  hLed->seg[2] = seg_c;
	  hLed->seg[3] = seg_d;
	  hLed->seg[4] = seg_e;
	  hLed->seg[5] = seg_f;
	  hLed->seg[6] = seg_g;
}

void LED7_Display(LED7_Handdle_t *hled,uint8_t number) {
	 if(number > 9) {return;}
	 
	 uint8_t data = seg_code[number];
	 
	 for(int i=0;i<7;i++) {
		  uint8_t bit = (data >> i) & 0x01;
		 GPIO_PinState state;
	 if(hled->type == LED7_ANODE) {
		 state = bit ? 0:1; 
	 }else{ 
		  state = bit ? 1:0; 
	 }
	 HAL_GPIO_WritePin(hled->seg[i].port_GPIO,hled->seg[i].pin,state);
 }

}

