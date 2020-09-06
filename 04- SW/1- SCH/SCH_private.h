/********************************************************/ 
/* Author : Nourhan Mansour                             */
/* Date   : 6/9/2020                                    */
/* Version: 1.0                                         */
/* File   : SCH_private.h                               */
/********************************************************/ 
#ifndef SCH_PRIVATE_H
#define SCH_PRIVATE_H


#define SCH_TICK_1ms         1000


/****************** Data types definitions *************************/
// The array of tasks
// Total memory per task is 7 bytes
typedef struct sTask
{
    // Pointer to the task (must be a 'void (void)' function)
    PTask pTask;
    // Delay (ticks) until the function will (next) be run
    u16 Delay;
    // Interval (ticks) between subsequent runs.
    u16 Period;
    // Incremented (by scheduler) when task is due to execute
    u8 RunMe;
} sTask;

sTask SCH_tasks_G[SCH_MAX_TASKS];


/****************** Private function prototypes *************************/
/*------------------------------------------------------------------*-
SCH_Go_To_Sleep()
  This scheduler enters 'idle mode' between clock ticks
  to save power. The next clock tick will return the processor
  to the normal operating state.

  Note: a slight performance improvement is possible if this
  function is implemented as a macro, or if the code here is simply
  pasted into the 'dispatch' function.
  However, by making this a function call, it becomes easier
  - during development - to assess the performance of the
  scheduler, using the 'performance analyser' in the Keil
  hardware simulator. See Chapter 14 for examples for this.

-*------------------------------------------------------------------*/
void SCH_Go_To_Sleep(void);

/*------------------------------------------------------------------*-
SCH_Update()
This is the scheduler ISR. It is called at a rate
determined by the timer settings in the 'init' function.
This version is triggered by Timer 2 interrupts:
timer is automatically reloaded.
-*------------------------------------------------------------------*/
void SCH_voidUpdate(void);

#endif // End Of File