#include <rtthread.h>
#include <entry.h>

#define SAMPLE_UART_NAME       "uart2"

extern rt_mq_t usart_mq;

/* The semaphore used to receive data from usart */
static rt_device_t serial;

/* Callback of receive data */
static rt_err_t uart_input(rt_device_t dev, rt_size_t size)
{
  char ch;
  rt_err_t uwRet = RT_EOK;

  /* The serial port generates an interrupt after receiving the data */

  rt_device_read(serial, -1, &ch, 1);

  uwRet = rt_mq_send(usart_mq,
                     &ch,
                     sizeof(ch));
	
  if(RT_EOK != uwRet) {
    rt_kprintf("serial receive data can not send to message queue, code: %lx\n", uwRet);
  }

  return RT_EOK;
}

void serial_send_thread_entry(void *parameter)
{
  rt_err_t uwRet = RT_EOK;
  char rcv_byte = 0;
  while(1) {
    uwRet = rt_mq_recv(usart_mq,
                       &rcv_byte,
                       sizeof(rcv_byte),
                       RT_WAITING_FOREVER);
    if(RT_EOK == uwRet) {
      rt_device_write(serial, 0, &rcv_byte, 1);
    } else {
      rt_kprintf("usart message queue recv error, code: 0x%lx\n", uwRet);
    }

    rt_thread_delay(1);
  }
}

void uart_sample(void)
{
  char uart_name[RT_NAME_MAX];
  char str[] = "hello RT-Thread!\r\n";

  rt_strncpy(uart_name, SAMPLE_UART_NAME, RT_NAME_MAX);

  serial = rt_device_find(uart_name);
  if (!serial) {
    rt_kprintf("find %s failed!\n", uart_name);
    return;
  }

  rt_device_open(serial, RT_DEVICE_FLAG_INT_RX);
  /* Receive callback */
  rt_device_set_rx_indicate(serial, uart_input);

  rt_device_write(serial, 0, str, (sizeof(str) - 1));
}
