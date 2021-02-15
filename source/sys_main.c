
//0.ducometation Section
//  29092020 code file,ADC_15_PINS_RTOS project,mainc

//  Runs on ARM TMS570LS0432 Hercules launchpad
//  INPUT to ADIN0-ADIN8 and ADIN16,ADIN17,ADIN20,ADIN21 ANALOG testing
//  Make ADIN0-ADIN8 and ADIN16,ADIN17,ADIN20,ADIN21 ANALOG as INPUT

//  Repeat this sequence of operation over and over
//  1)All ADIN Pins will be read
//  2)save the values into array
//  3)Wait 100 ms

//  Date:29.09.2020
//  Author: Mouaiad Salaas

//1.Pre-processor Directives Section
/* 
* Copyright (C) 2020-20121 INOVAR R&D SOLUTIONS Company
* 
* 
*  Redistribution and use in source and binary forms, with or without 
*  modification, are permitted provided that the following conditions 
*  are met:
*
*    Redistributions of source code must retain the above copyright 
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the 
*    documentation and/or other materials provided with the   
*    distribution.
*
*    Neither the name of INOVAR R&D SOLUTIONS Company nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/


/* USER CODE BEGIN (0) */
/* Include Files */
#include "sys_common.h"
#include "system.h"
#include "esm.h"
#include "adc.h"
#include "sci.h"
#include "gio.h"
#include "het.h"
/* Include FreeRTOS scheduler files */
#include "FreeRTOS.h"
#include "os_task.h"
/* USER CODE END */


/* USER CODE BEGIN (1) */
/*Define Task Handles*/
xTaskHandle xTask1Handle;
/* USER CODE END */

//1.Declarations Section
/* USER CODE BEGIN (2) */
/*  Global Variable*/
uint32 ch_count=0;

uint32 id_ADC_0=0,id_ADC_1=0,id_ADC_2=0,id_ADC_3=0,id_ADC_4=0,id_ADC_5=0,id_ADC_6=0,id_ADC_7=0,id_ADC_8=0;
uint32 id_ADC_9=0,id_ADC_10=0,id_ADC_11=0,id_ADC_16=0,id_ADC_17=0,id_ADC_20=0,id_ADC_21=0;

uint32 value_ADC_0 =0,value_ADC_1 =0,value_ADC_2 =0,value_ADC_3 =0,value_ADC_4 =0,value_ADC_5 =0,value_ADC_6 =0;
uint32 value_ADC_7 =0,value_ADC_8 =0,value_ADC_9 =0,value_ADC_10 =0,value_ADC_11 =0,value_ADC_16 =0;
uint32 value_ADC_17 =0,value_ADC_20 =0,value_ADC_21 =0;

/*define SCI tesxt arrays for Terminal*/
#define  TSIZE1 12
uint8  TEXT1[TSIZE1]= {'\r','\n','|','\t','C','H','.','I','D','=','0','x'};
#define  TSIZE2 9
uint8  TEXT2[TSIZE2]= {'\t','V','A','L','U','E','=','0','x'};

/*defining the struct which contain the data we will get from analog pins*/
adcData_t adc_data[21];

//  Functions Prototypes
void sciDisplayText(sciBASE_t *sci, uint8 *text, uint32 length);
void sciDisplayData(sciBASE_t *sci, uint8 *text,uint32 length);
void wait(uint32 time);
/* USER CODE END */

//2.Declarations Section
/* USER CODE BEGIN (3) */

/* Task1 */
// TASK to read the ADIN PINS
// Inputs:  ALL ADIN PINS
// Outputs: None
// Notes:   None
void vTask1(void *pvParameters)
{
    for(;;)
    {
        /* Taggle HET[1] with timer tick */
        /* trigger using het port 1, pin 8  */
            gioSetBit(hetPORT1, 8, 1);

            /* ... wait and read the conversion count */
            while((adcIsConversionComplete(adcREG1,adcGROUP1))==0);
                ch_count = adcGetData(adcREG1, adcGROUP1,&adc_data[0]);
                ch_count = ch_count;

            /* conversion results :                                       */
            /* adc_data[0] -> should have conversions for Group1 channel1 */
            /* adc_data[1] -> should have conversions for Group1 channel2 */

//            id_ADC_0   = adc_data[0].id;
//            value_ADC_0 = adc_data[0].value;
//            gioSetBit(hetPORT1, 8, 0);
//            //////////////////////////////////////
//            id_ADC_1   = adc_data[1].id;
//            value_ADC_1 = adc_data[1].value;
//            gioSetBit(hetPORT1, 8, 0);
//            //////////////////////////////////////
//            //////////////////////////////////////
//            id_ADC_2   = adc_data[2].id;
//            value_ADC_2 = adc_data[2].value;
//            gioSetBit(hetPORT1, 8, 0);
//            //////////////////////////////////////
//            //////////////////////////////////////
//            id_ADC_3   = adc_data[3].id;
//            value_ADC_3 = adc_data[3].value;
//            gioSetBit(hetPORT1, 8, 0);
//            //////////////////////////////////////
//            //////////////////////////////////////
//            id_ADC_4   = adc_data[4].id;
//            value_ADC_4 = adc_data[4].value;
//            gioSetBit(hetPORT1, 8, 0);
//            //////////////////////////////////////
//            //////////////////////////////////////
//            id_ADC_5   = adc_data[5].id;
//            value_ADC_5 = adc_data[5].value;
//            gioSetBit(hetPORT1, 8, 0);
//            //////////////////////////////////////
//            //////////////////////////////////////
//            id_ADC_6   = adc_data[6].id;
//            value_ADC_6 = adc_data[6].value;
//            gioSetBit(hetPORT1, 8, 0);
//            //////////////////////////////////////
//            //////////////////////////////////////
//            id_ADC_7   = adc_data[7].id;
//            value_ADC_7 = adc_data[7].value;
//            gioSetBit(hetPORT1, 8, 0);
//            //////////////////////////////////////
//            //////////////////////////////////////
//            id_ADC_8   = adc_data[8].id;
//            value_ADC_8 = adc_data[8].value;
//            gioSetBit(hetPORT1, 8, 0);
//            //////////////////////////////////////
//            //////////////////////////////////////
//            id_ADC_9   = adc_data[9].id;
//            value_ADC_9 = adc_data[9].value;
//            gioSetBit(hetPORT1, 8, 0);
//            //////////////////////////////////////
//            //////////////////////////////////////
//            id_ADC_10   = adc_data[10].id;
//            value_ADC_10 = adc_data[10].value;
//            gioSetBit(hetPORT1, 8, 0);
//            //////////////////////////////////////
//            //////////////////////////////////////
//            id_ADC_11   = adc_data[11].id;
//            value_ADC_11 = adc_data[11].value;
//            gioSetBit(hetPORT1, 8, 0);
//            //////////////////////////////////////
            //////////////////////////////////////
            id_ADC_16   = adc_data[16].id;
            value_ADC_16 = adc_data[16].value;
            gioSetBit(hetPORT1, 8, 0);
            //////////////////////////////////////
            //////////////////////////////////////
            id_ADC_17   = adc_data[17].id;
            value_ADC_17 = adc_data[17].value;
            gioSetBit(hetPORT1, 8, 0);
            //////////////////////////////////////
            //////////////////////////////////////
            id_ADC_20   = adc_data[20].id;
            value_ADC_20 = adc_data[20].value;
            gioSetBit(hetPORT1, 8, 0);
            //////////////////////////////////////
            //////////////////////////////////////
            id_ADC_21   = adc_data[21].id;
            value_ADC_21 = adc_data[21].value;
            gioSetBit(hetPORT1, 8, 0);
            //////////////////////////////////////
        vTaskDelay(100); //delay for (100ms)
    }
}
/* USER CODE END */



//1.MAIN FUNCTION Section
void main(void)
{
    /* USER CODE BEGIN (4) */

        /* initialize gio     */
        gioInit();
        gioSetDirection(hetPORT1, 0x100);

        /* initialize sci/sci-lin  : even parity , 2 stop bits */
        sciInit();

        /* initialize ADC  */
        /* Group1 -> Channel 0 and 1                        */
        /* HW trigger trigger source as HET1  Pin 8         */
        adcInit();

        /* start adc conversion */
        adcStartConversion(adcREG1,adcGROUP1);
        wait(0xFFFFFF);

        /* Set high end timer GIO port hetPort pin direction to all output */
        gioSetDirection(hetPORT1, 0xFFFFFFFF);


        /* Create Task 1 (Analog pins read Task)*/
        if (xTaskCreate(vTask1,"Task1", configMINIMAL_STACK_SIZE, NULL, 1, &xTask1Handle) != pdTRUE)
        {
        /* Task could not be created */
        while(1);
        }

        /* Start Scheduler */
        vTaskStartScheduler();


/* USER CODE END */
}



/* USER CODE BEGIN (5) */
void sciDisplayData(sciBASE_t *sci, uint8 *text,uint32 length)
{
    uint8 txt = 0;
    uint8 txt1 = 0;

#if ((__little_endian__ == 1) || (__LITTLE_ENDIAN__ == 1))
text = text + (length -1);
#endif

    while(length--)
    {
#if ((__little_endian__ == 1) || (__LITTLE_ENDIAN__ == 1))
        txt = *text--;
#else
        txt = *text++;
#endif

        txt1 = txt;

        txt  &= ~(0xF0);
        txt1 &= ~(0x0F);
        txt1  =txt1>>4;

        if(txt<=0x9)
        {
            txt +=0x30;
        }
        else if(txt > 0x9 && txt < 0xF)
        {
            txt +=0x37;
        }
        else
        {
            txt = 0x30;
        }

        if(txt1 <= 0x9)
        {
            txt1 +=0x30;
        }
        else if((txt1 > 0x9) && (txt1 <= 0xF))
        {
            txt1 +=0x37;
        }
        else
        {
            txt1 = 0x30;
        }

        while ((scilinREG->FLR & 0x4) == 4); /* wait until busy */
        sciSendByte(scilinREG,txt1);      /* send out text   */
        while ((scilinREG->FLR & 0x4) == 4); /* wait until busy */
        sciSendByte(scilinREG,txt);      /* send out text   */
    };
}

void sciDisplayText(sciBASE_t *sci, uint8 *text,uint32 length)
{
    while(length--)
    {
        while ((scilinREG->FLR & 0x4) == 4); /* wait until busy */
        sciSendByte(scilinREG,*text++);      /* send out text   */
    };
}

void wait(uint32 time)
{
    while(time){time--;};
}
/* USER CODE END */
