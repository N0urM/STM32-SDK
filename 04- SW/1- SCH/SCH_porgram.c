// 1- include Libraries 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

// 2- include interface file of needed lower layers
#include "STK_interface.h"

// 3- include driver files
#include "SCH_interface.h"
#include "SCH_config.h"
#include "SCH_private.h"

void SCH_voidInit(void){
    u8 i;
    for (i = 0; i < SCH_MAX_TASKS; i++)
    {
    	SCH_voidDeleteTask(i);
    }
    /* Initiate Timer at 1MHZ clock */
    STK_voidInit();
    
}

void SCH_voidStart(void){
    /* Start Scheduler with 1ms tick */
    STK_voidSetIntervalPeriodic(SCH_TICK_1ms , SCH_voidUpdate);
}

void SCH_voidDispatchTasks(void)
{
    u8  index ;
    for (index = 0 ; index < SCH_MAX_TASKS ; index ++){
        if ( (SCH_tasks_G[index].RunMe > 0 ) 
            && 
            ( SCH_tasks_G[index].pTask != 0 ) 
            && 
            (SCH_tasks_G[index].taskState == READY_STATE) )
        {
            (*SCH_tasks_G[index].pTask)();         // Run the task
            SCH_tasks_G[index].RunMe -= 1;         // Reset / reduce RunMe flag
             
             // Periodic tasks will automatically run again
             // - if this is a 'one shot' task, remove it from the array
            if (SCH_tasks_G[index].Period == 0)
            {
            	SCH_voidDeleteTask(index);
            }
        }
    }
    // The scheduler enters idle mode at this point
     SCH_Go_To_Sleep();
}


u8 SCH_u8AddTask( PTask pFunction, const u16 DELAY, const u16 PERIOD)
{
    unsigned char Index = 0;
      // First find a gap in the array (if there is one)
    while ((SCH_tasks_G[Index].pTask != 0) && (Index < SCH_MAX_TASKS))
    {
        Index++;
    }
      // Have we reached the end of the list?
    if (Index == SCH_MAX_TASKS)
    {
         
        return SCH_MAX_TASKS;           // ERROR TASK NOT ADDED
    }
    else 
    {
        // If we're here, there is a space in the task array
        SCH_tasks_G[Index].pTask = pFunction;
        SCH_tasks_G[Index].Delay = DELAY;
        SCH_tasks_G[Index].Period = PERIOD;
        SCH_tasks_G[Index].RunMe = 0;
        return Index;                   // Return Task Index to enable delete later
    }
}



void SCH_voidDeleteTask(const u8 TASK_IDX)
{
   if (TASK_IDX < SCH_MAX_TASKS)
   {
        if (SCH_tasks_G[TASK_IDX].pTask == 0)
        {
            // ERROR TASK ID DOESN'T EXIST
        }
        else 
        {
            SCH_tasks_G[TASK_IDX].pTask = 0x00000000;
            SCH_tasks_G[TASK_IDX].Delay = 0;
            SCH_tasks_G[TASK_IDX].Period = 0;
            SCH_tasks_G[TASK_IDX].RunMe = 0;    
        }
   }
}

void SCH_Go_To_Sleep()
{
  asm("WFI");
}

void SCH_voidUpdate(){
    u8 Index = 0;
    // NOTE: calculations are in *TICKS* (not milliseconds)
    for (Index = 0; Index < SCH_MAX_TASKS; Index++)
    {
        // Check if there is a task at this location
        if (SCH_tasks_G[Index].pTask != 0){
            if (SCH_tasks_G[Index].Delay == 0)
            {
                // The task is due to run
                SCH_tasks_G[Index].RunMe += 1; // Inc. the 'RunMe' flag
                if (SCH_tasks_G[Index].Period)
                {
                    // Schedule regular tasks to run again
                    SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period;
                }
            }
            else
            {
                // Not yet ready to run: just decrement the delay
                SCH_tasks_G[Index].Delay -= 1;
            }
        }
    }
}


void SCH_voidPauseTask (const u8 TASK_IDX){
    SCH_tasks_G[TASK_IDX].taskState = WAIT_STATE;
}

void SCH_voidResumeTask(const u8 TASK_IDX){
    SCH_tasks_G[TASK_IDX].taskState = READY_STATE;
}