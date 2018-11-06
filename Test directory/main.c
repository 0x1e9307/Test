/*
 * Test.c
 *
 * Created: 06.11.2018 22:01:10
 * Author : 0x1e9307
 */ 

#include "main.h"

//----------------------------------------

void port_ini(void)
{
	PORTD=0x00;
	DDRD=0xFF;
	PORTB=0x00;
	DDRB=0b00111111;
}

//----------------------------------------

int main(void)
{
	float n;
	adc_value=0;
	adc_counter=0;
	adc_tmp=0;
	port_ini(); // ������������� ������
	LCD_ini(); // ������������� �������
	ADC_Init(); // �������������� ���
	sei();
	clearlcd(); //������� �������
	
	
	while (1)
	{
		setpos(0,0); // ������������� �������
		sendcharlcd(adc_value/1000+0x30); // ����������� ����� � ��� �����
		sendcharlcd((adc_value%1000)/100+0x30); // ����������� ����� � ��� �����
		sendcharlcd((adc_value%100)/10+0x30); // ����������� ����� � ��� �����
		sendcharlcd(adc_value%10+0x30); // ����������� ����� � ��� �����
		setpos(11,0); // ������������� �������
		n = (float) adc_value / 212.448; //  1024/Vcc=�����.(232.19)
		sendcharlcd((unsigned char) n +0x30); // ����������� ����� � ��� �����
		sendcharlcd('.'); // ������ ����� ����� �������� ����� �� �������
		sendcharlcd(((unsigned char) (n*10))%10 +0x30); // ����������� ����� � ��� �����
		sendcharlcd(((unsigned char) (n*100))%10 +0x30); // ����������� ����� � ��� �����
		setpos(0,1);
		str_lcd("ADC Value");
		setpos(11,1);
		str_lcd("Volts");
		
		_delay_ms(500); // ��������
		
		if (n<3.5) // ���� ���������� ������� ������ ��� 3.5v
		{
			unsigned int i=0;
			for (i=0;i<2;i++)
			{
				PORTB|=(1<<PB0);
				_delay_ms(50);
				PORTB|=(1<<PB1);
				_delay_ms(50);
				PORTB|=(1<<PB2);
				_delay_ms(50);
				PORTB|=(1<<PB3);
				_delay_ms(50);
				PORTB|=(1<<PB4);
				_delay_ms(50);
				PORTB|=(1<<PB5);
				_delay_ms(50);
				PORTB&=~(1<<PB0);
				_delay_ms(50);
				PORTB&=~(1<<PB1);
				_delay_ms(50);
				PORTB&=~(1<<PB2);
				_delay_ms(50);
				PORTB&=~(1<<PB3);
				_delay_ms(50);
				PORTB&=~(1<<PB4);
				_delay_ms(50);
				PORTB&=~(1<<PB5);
				_delay_ms(50);
			}
		}
		else
		{
			PORTB=0;
		}
	}
}
