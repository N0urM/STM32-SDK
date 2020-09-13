/********************************************************/ 
/* Author : Nourhan Mansour                             */
/* Date   : 12/9/2020                                   */
/* Version: 1.0                                         */
/* File   : DMA_private.h                               */
/********************************************************/ 
#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

typedef struct  
{
    volatile u32 CCR;
    volatile u32 CNDTR; 
    volatile u32 CPAR;
    volatile u32 CMAR;
    volatile u32 RESERVED;
}t_DMA_CH;

typedef struct 
{
    volatile u32 ISR; 
    volatile u32 IFCR;
    t_DMA_CH DMA_CH[7];
}t_DMA;

#define DMA     ( (volatile t_DMA*) 0x40020000 )

/* Error LOG */
u8 CHANNEL_STATUS[7];


/* Call back */ 
void (*DMA_functionCallBack[7])(void);


/*      Registers Bits Configuration   */
#define DMA_CCRx_EN            0
#define DMA_CCRx_TCIE          1
#define DMA_CCRx_HTIE          2
#define DMA_CCRx_TEIE          3
#define DMA_CCRx_DIR           4
#define DMA_CCRx_CIRC          5
#define DMA_CCRx_PINC          6
#define DMA_CCRx_MINC          7
#define DMA_CCRx_PSIZE0        8
#define DMA_CCRx_PSIZE1        9
#define DMA_CCRx_MSIZE0        10
#define DMA_CCRx_MSIZE1        11
#define DMA_CCRx_PL0           12
#define DMA_CCRx_PL1           13
#define DMA_CCRx_M2M           14


#define DMA_IFCR_CGIF1          0
#define DMA_IFCR_CTCF1          1
#define DMA_IFCR_CHTF1          2
#define DMA_IFCR_CTEF1          3

#define DMA_IFCR_CGIF2          4
#define DMA_IFCR_CTCF2          5
#define DMA_IFCR_CHTF2          6
#define DMA_IFCR_CTEF2          7

#define DMA_IFCR_CGIF3          8
#define DMA_IFCR_CTCF3          9
#define DMA_IFCR_CHTF3          10
#define DMA_IFCR_CTEF3          11

#define DMA_IFCR_CGIF4          12
#define DMA_IFCR_CTCF4          13
#define DMA_IFCR_CHTF4          14
#define DMA_IFCR_CTEF4          15

#define DMA_IFCR_CGIF5          16
#define DMA_IFCR_CTCF5          17
#define DMA_IFCR_CHTF5          18
#define DMA_IFCR_CTEF5          19

#define DMA_IFCR_CGIF6          20
#define DMA_IFCR_CTCF6          21
#define DMA_IFCR_CHTF6          22
#define DMA_IFCR_CTEF6          23

#define DMA_IFCR_CGIF7          24
#define DMA_IFCR_CTCF7          25
#define DMA_IFCR_CHTF7          26
#define DMA_IFCR_CTEF7          27

/**************************************8*/

#define DMA_ISR_GIF1             0
#define DMA_ISR_TCIF1            1
#define DMA_ISR_HTIF1            2
#define DMA_ISR_TEIF1            3


#define DMA_ISR_GIF2             4
#define DMA_ISR_TCIF2            5
#define DMA_ISR_HTIF2            6
#define DMA_ISR_TEIF2            7

#define DMA_ISR_GIF3             8
#define DMA_ISR_TCIF3            9
#define DMA_ISR_HTIF3            10
#define DMA_ISR_TEIF3            11

#define DMA_ISR_GIF4             12
#define DMA_ISR_TCIF4            13
#define DMA_ISR_HTIF4            14
#define DMA_ISR_TEIF4            15

#define DMA_ISR_GIF5             16
#define DMA_ISR_TCIF5            17
#define DMA_ISR_HTIF5            18
#define DMA_ISR_TEIF5            19

#define DMA_ISR_GIF6             20
#define DMA_ISR_TCIF6            21
#define DMA_ISR_HTIF6            22
#define DMA_ISR_TEIF6            23

#define DMA_ISR_GIF7             24
#define DMA_ISR_TCIF7            25
#define DMA_ISR_HTIF7            26
#define DMA_ISR_TEIF7            27

#endif // End Of File
