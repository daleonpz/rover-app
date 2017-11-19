/*
 * Copyright (c) 2017 FH Dortmund and others
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Description:
 *    Rover Driving API - Interfaces for Rover driving application development - Header file
 *
 * Contributors:
 *    M.Ozcelikors <mozcelikors@gmail.com>, created API 17.11.2017
 *
 */

#ifndef API_ROVER_DRIVING_HPP_
#define API_ROVER_DRIVING_HPP_

#include <roverapi/rover_api.hpp>

namespace rover
{
	int FULL_SPEED = 480; //rover::FULL_SPEED
	int LOW_SPEED  = 360; //rover::LOW_SPEED
	/**
	 * @brief Contains the member functions to drive the rover or perform behaviors such as parking and ACC using its motors.
	 */
	class RoverDriving : public RoverBase
	{
		private:
			/**
			 * @brief Speed for the rover movement. 360 -> Lowest speed (rover::LOW_SPEED), 480 -> Highest speed (rover::FULL_SPEED).
			 */
			int SPEED;

		public:
			/**
			 * @brief Initializes wiringPi library and Analog to Digital Converter to start driving the rover.
			 */
			void initialize();

			/**
			 * @brief Commands the rover to stop.
			 */
			void stop();

			/**
			 * @brief Sets the speed.
			 */
			void setSpeed (int speed_setpoint);

			/**
			 * @brief Retrieves the current speed setpoint.
			 */
			int getSpeed (void);

			/**
			 * @brief Commands the rover to go forward.
			 */
			void goForward ();

			/**
			 * @brief Commands the rover to go backward.
			 */
			void goBackward ();

			/**
			 * @brief Commands the rover to turn right on its spot.
			 */
			void turnRight ();

			/**
			 * @brief Commands the rover to turn left on its spot.
			 */
			void turnLeft ();

			/**
			 * @brief Commands the rover to perform ACC behavior until stopped. RoverSensors should be initialized beforehand.
			 */
			void performACC();

			/**
			 * @brief Commands the rover to perform Parking behavior until stopped. RoverSensors should be initialized beforehand.
			 */
			void performParking();

			/**
			 * @brief Commands the rover to perform Booth Mode 1 behavior until stopped. RoverSensors should be initialized beforehand.
			 */
			void performBoothMode1();

			/**
			 * @brief Commands the rover to perform Booth Mode 2 behavior until stopped. RoverSensors should be initialized beforehand.
			 */
			void performBoothMode2();

	};
}


#endif /* API_ROVER_DRIVING_HPP_ */
