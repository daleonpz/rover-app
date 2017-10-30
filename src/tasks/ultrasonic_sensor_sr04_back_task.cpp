/*
 * Copyright (c) 2017 FH Dortmund and others
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Description:
 *    HCSR-04 ultrasonic sensor code with wiringPi and pThreads
 *
 * Authors:
 *    M. Ozcelikors,            R.Hottger
 *    <mozcelikors@gmail.com>   <robert.hoettger@fh-dortmund.de>
 *
 * Contributors:
 *    Resource: https://ninedof.wordpress.com/2013/07/16/rpi-hc-sr04-ultrasonic-sensor-mini-project/
 *
 * Update History:
 *    02.02.2017   -    first compilation
 *    15.03.2017   -    updated tasks for web-based driving
 *    25.03.2017   -    timing library and ultrasonic hcsr-04 added
 *
 */

//Only necessary if you do not use logic level converter:
//A voltage divided should be used and it should be made sure that the grounds are not isolated and are connected to same line.
// ___________
//        +5V|----------------------------> Raspberry Pi +5V Pin
//           |
//           |
//       TRIG|----------------------------> Raspberry Pi BCM-24 Pin
//           |
//           |
//           |                           -----> Connect to Raspberry Pi  BCM-25 Pin
//  HC-SR04  |                           |
//           |                           |
//           |              330 ohm      |     470 ohm
//       ECHO|-------------^^^^^^^^^^--------^^^^^^^^^^--------> Connect to Raspberry Pi GND
//           |
//           |
//        GND|---------------------------------------------------> Connect to Raspberry Pi GND
// __________|


#include <tasks/ultrasonic_sensor_sr04_back_task.h>

#include <wiringPi.h>
#include <ctime>
#include <pthread.h>

#include <libraries/timing/timing.h>
#include <api/basic_psys_rover.h>
#include <interfaces.h>
#include <pthread.h>

#include <libraries/pthread_monitoring/collect_thread_name.h>
#include <roverapp.h>

void setup_HCSR04UltrasonicBack() {
    //wiringPiSetup();
    pinMode(TRIG1, OUTPUT);
    pinMode(ECHO1, INPUT);

    //TRIG pin must start LOW
    digitalWrite(TRIG1, LOW);
    delayMicroseconds(2);
}

int getCM_HCSR04UltrasonicBack() {
	int distance = 0;
    //Send trig pulse
    digitalWrite(TRIG1, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG1, LOW);
//    printf("x\n");

    //Wait for echo start
    long startTime = micros();
    while(digitalRead(ECHO1) == LOW && micros() < startTime + 100000);

    //Wait for echo end
    startTime = micros();
    while(digitalRead(ECHO1) == HIGH);
    long travelTime = micros() - startTime;

    //Get distance in cm
    distance = travelTime * 34300;
	distance = distance / 1000000;
	distance = distance / 2;
	// The below protection is to ensure there is no value fluctuation due to timeout
	if (distance > 40 )
		distance = 40;
//	printf("dist=%d\n",distance);

    return distance;
}


void *Ultrasonic_Sensor_SR04_Back_Task(void *unused)
{
	timing ultrasonic_sr04_back_task_tmr;

	CollectThreadName("Ultrasonic_Sensor_SR04_Back_Task");

	ultrasonic_sr04_back_task_tmr.setTaskID("Ultrasonic_SR04_Back");
	ultrasonic_sr04_back_task_tmr.setDeadline(0.1);
	ultrasonic_sr04_back_task_tmr.setPeriod(0.1);

	setup_HCSR04UltrasonicBack();
	while (1)
	{
		ultrasonic_sr04_back_task_tmr.recordStartTime();
		ultrasonic_sr04_back_task_tmr.calculatePreviousSlackTime();

		//Task content starts here -----------------------------------------------
		pthread_mutex_lock(&distance_sr04_back_lock);
			distance_sr04_back_shared = getCM_HCSR04UltrasonicBack();
		pthread_mutex_unlock(&distance_sr04_back_lock);

		//printf("Distance: %dcm\n", getCM_GrooveUltrasonicRanger());
		//Task content ends here -------------------------------------------------

		ultrasonic_sr04_back_task_tmr.recordEndTime(); //!!!
		ultrasonic_sr04_back_task_tmr.calculateExecutionTime();
		ultrasonic_sr04_back_task_tmr.calculateDeadlineMissPercentage();
		ultrasonic_sr04_back_task_tmr.incrementTotalCycles();
		pthread_mutex_lock(&ultrasonic_sr04_back_task_ti_l);
			ultrasonic_sr04_back_task_ti.deadline = ultrasonic_sr04_back_task_tmr.getDeadline();
			ultrasonic_sr04_back_task_ti.deadline_miss_percentage = ultrasonic_sr04_back_task_tmr.getDeadlineMissPercentage();
			ultrasonic_sr04_back_task_ti.execution_time = ultrasonic_sr04_back_task_tmr.getExecutionTime();
			ultrasonic_sr04_back_task_ti.period = ultrasonic_sr04_back_task_tmr.getPeriod();
			ultrasonic_sr04_back_task_ti.prev_slack_time = ultrasonic_sr04_back_task_tmr.getPrevSlackTime();
			ultrasonic_sr04_back_task_ti.task_id = ultrasonic_sr04_back_task_tmr.getTaskID();
			ultrasonic_sr04_back_task_ti.start_time = ultrasonic_sr04_back_task_tmr.getStartTime();
			ultrasonic_sr04_back_task_ti.end_time = ultrasonic_sr04_back_task_tmr.getEndTime();
		pthread_mutex_unlock(&ultrasonic_sr04_back_task_ti_l); //!!
		ultrasonic_sr04_back_task_tmr.sleepToMatchPeriod();
	}

	//the function must return something - NULL will do
	return NULL;
}