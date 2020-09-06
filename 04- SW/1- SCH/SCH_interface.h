/********************************************************/ 
/* Author : Nourhan Mansour                             */
/* Date   : 6/9/2020                                    */
/* Version: 1.0                                         */
/* File   : SCH_interface.h                             */
/********************************************************/ 
#ifndef SCH_INTERFACE_H
#define SCH_INTERFACE_H

typedef void (*PTask)(void);


/******************* public functions *************************/

/**************************************************************
 * Function   : SCH_voidInit
 * Parameters : NONE
 * RETURN     : NONE
 * Description: initialize SysTick Timer and tasks array
 * ***********************************************************/
void SCH_voidInit(void);


/**************************************************************
 * Function   : SCH_voidStart
 * Parameters : NONE
 * RETURN     : NONE
 * Description: Start Scheduler tick operation
 * ***********************************************************/
void SCH_voidStart(void);

/**************************************************************
 * Function   : SCH_Dispatch_Tasks
 * Parameters : NONE
 * RETURN     : NONE
 * Description: When a task (function) is due to run, 
 *              SCH_Dispatch_Tasks() will run it.
 * Note       : This function must be called (repeatedly) from 
 *              the main loop.
 * ***********************************************************/
void SCH_voidDispatchTasks(void);


/**************************************************************
 * Function   : SCH_Add_Task
 * Parameters : 
 *              Fn_P   : The name of the function which is to be scheduled.
                DELAY  : The interval (TICKS) before the task is first executed
                PERIOD : If 'PERIOD' is 0, the function is only called once,
                    at the time determined by 'DELAY'. If PERIOD is non-zero,
                    then the function is called repeatedly at an interval
                    determined by the value of PERIOD 
 * RETURN     : Task index: if successful 
 *              MAX Tasks num: if failed 
 * Description: Causes a task (function) to be executed at regular 
 *              intervals or after a user-defined delay
 * NOTE       : All scheduled functions must be 'void, void' -
                that is, they must take no parameters, and have
                a void return type. 
EXAMPLES      :
Task_ID = SCH_Add_Task(Do_X,1000,0);
        Causes the function Do_X() to be executed once after 1000 sch ticks.
Task_ID = SCH_Add_Task(Do_X,0,1000);
        Causes the function Do_X() to be executed regularly, every 1000 sch ticks.
Task_ID = SCH_Add_Task(Do_X,300,1000);
        Causes the function Do_X() to be executed regularly, every 1000 ticks.
Task will be first executed at T = 300 ticks, then 1300, 2300, etc.
 * ***********************************************************/
u8 SCH_u8AddTask( PTask pFunction, const u16 DELAY, const u16 PERIOD);


/**************************************************************
 * Function   : SCH_Delete_Task
 * Parameters : TASK_IDX - The task index. Provided by SCH_Add_Task().
 * RETURN     : NONE
 * Description: Removes a task from the scheduler. Note that 
 *              this does *not* delete the associated function 
 *              from memory: it simply means that it is no 
 *              longer called by the scheduler.
 * ***********************************************************/
void SCH_voidDeleteTask(const u8 TASK_IDX);


#endif // End Of File