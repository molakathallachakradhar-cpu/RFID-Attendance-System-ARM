typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;
typedef char s8;

void i2c_init(void);
void i2c_send(u8 sa,u8 mr,u8 data);
u8 i2c_read(u8 sa,u8 mr);

void uart0_init(unsigned int baud);
void uart0_tx(unsigned char data);
unsigned char uart0_rx(void);
void uart0_string(s8 *p);
void uart0_integer(u8 data);

void lcd_data(u8 data);
void lcd_cmd(u8 cmd);
void lcd_init(void);
void lcd_string(u8 *p);

void uart_intr(void);

void delay_ms(u32 delay);
void delay_sec(u32 delay);


