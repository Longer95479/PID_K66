#ifndef _PID_H
#define _PID_H

typedef struct { 
    float SetSpeed; //�����趨ֵ 
    float ActualSpeed; //����ʵ��ֵ 
    float err; //����ƫ��ֵ 
    float err_next; //������һ��ƫ��ֵ 
    float err_last; //������һ��ƫ��ֵ 
    float Kp,Ki,Kd; //������������֡�΢��ϵ��
} _pid;

void PID_init(void);
float PID_realize(float speed);

#endif
