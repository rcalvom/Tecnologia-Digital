//===================================================
//================== TaskSoundAlarm =======================

void TaskSoundAlarm(void *pvParameters)  // This is a task.
{
  (void) pvParameters;
  //-----------para hacer que una tarea sea periodica ----------------------------------------
    TickType_t xPreviousWakeTime;
    xPreviousWakeTime=xTaskGetTickCount(); //Ultima vez que la tarea paso del estado Blocked al estado Ready 
                                           //se hace igual al numero de ticks actuales
  //------------------------------------------------------------------------------------------

  /*
    TaskSoundAlarm: Suena la alarma
  */

    enum state_type{START};
    state_type state;
    bool Fsm_isActive=false;
    int contador=0;
    bool stBuzzer=LOW;

  for (;;) // A Task shall never return or exit.
  {     
    if (Fsm_isActive==false){
      Fsm_isActive=true;  //activar la FSM
      digitalWrite(buzzer,LOW);//silence
      state=START;         //ir al estado Start
    }else{  
      switch(state){
        case START: //alarma suena a la hora señalada y durante un minuto
          //ToDo:
            if(hour == 15 && minute == 52){
               digitalWrite(buzzer,HIGH);
               
            }else{
              digitalWrite(buzzer,LOW);
            }
          //
          break;
      }//end switch
    }//end if
    vTaskDelayUntil(&xPreviousWakeTime,100/ portTICK_PERIOD_MS ); // Bloquea task de forma periodica por 100 ms                                                                             //esperar 1 segundo en el estado bloqueado                                                                                                                
  }//end for
}//end task
//===========================================================
