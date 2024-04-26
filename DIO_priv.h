#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_
// $1B ($3B) PORTA
// $1A ($3A) DDRA 
// $19 ($39) PINA 
// $18 ($38) PORTB
// $17 ($37) DDRB 
// $16 ($36) PINB 
// $15 ($35) PORTC
// $14 ($34) DDRC 
// $13 ($33) PINC 
// $12 ($32) PORTD
// $11 ($31) DDRD 
// $10 ($30) PIND 

#define PORTA_REG   *((volatile u8*)(0x3B))
#define DDRA_REG   *((volatile u8*)(0x3A))
#define PINA_REG   *((volatile u8*)(0x39))

#define PORTB_REG   *((volatile u8*)(0x38))
#define DDRB_REG   *((volatile u8*)(0x37))
#define PINB_REG   *((volatile u8*)(0x36))

#define PORTC_REG   *((volatile u8*)(0x35))
#define DDRC_REG   *((volatile u8*)(0x34))
#define PINC_REG   *((volatile u8*)(0x33))

#define PORTD_REG   *((volatile u8*)(0x32))
#define DDRD_REG   *((volatile u8*)(0x31))
#define PIND_REG   *((volatile u8*)(0x30))



#endif