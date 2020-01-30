/*-----------------------------------------------------------------------------------------------------
【平    台】龙邱K66核心板-智能车板
【编    写】LQ-005
【E-mail  】chiusir@163.com
【软件版本】V1.0，龙邱开源代码，仅供参考，后果自负
【最后更新】2019年04月02日
【网    站】http://www.lqist.cn
【淘宝店铺】http://shop36265907.taobao.com
【编译平台】IAR 8.2
【功    能】
【注意事项】
-------------------------------------------------------------------------------------------------------*/
#include "include.h"

uint8_t flag = 1;

int main(void) 
{
    PLL_Init(PLL180);                   //初始化PLL为180M 
    
    /* 设置中断优先级组  0: 0个抢占优先级16位个子优先级 
     * 1: 2个抢占优先级 8个子优先级 2: 4个抢占优先级 4个子优先级 
     * 3: 8个抢占优先级 2个子优先级 4: 16个抢占优先级 0个子优先级
     */
    /* 配置优先级组 2: 4个抢占优先级 4个子优先级 */
    NVIC_SetPriorityGrouping(0x07 - 2);
    
    /* 优先级配置 抢占优先级0  子优先级2   越小优先级越高  抢占优先级可打断别的中断 */
    NVIC_SetPriority(UART4_RX_TX_IRQn,NVIC_EncodePriority(NVIC_GetPriorityGrouping(),1,2));
    
    LED_Init();
    
    LPTMR_PulseInit(LPT0_ALT1,32768,LPT_Rising);  
    systime.init(); 
    
    UART_Init(UART4, 115200);           //用于显示波形
    
    UART_Init(UART3, 9600);           //用于两板通讯
    
    NVIC_EnableIRQ(UART4_RX_TX_IRQn);   //使能UART4_RX_TX_IRQn的中断
    
    Enc_TPM12_Init();                   //编码器模式初始化
    
    PID_init();
    
    PIT_Init_For_IT(PIT0, 20);          //用于中断测速调速
    
    while(1);
    
}



