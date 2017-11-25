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

namespace rover
{
	/**
	 * @brief Contains the member functions to drive the rover or perform behaviors such as parking and ACC using its motors.
	 */
	class RoverDriving
	{
		private:
			/**
			 * @brief Speed for the rover movement. 360 -> Lowest speed (RoverDriving::LOWEST_SPEED), 480 -> Highest speed (RoverDriving::HIGHEST_SPEED).
			 */
			int SPEED;

		public:
			/* Rover driving speeds */
			/**
			 * @brief Static definition to hold lowest driving speed for rover.
			 */
			static const int LOWEST_SPEED = 360;

			/**
			 * @brief Static definition to hold highest driving speed for rover.
			 */
			static const int HIGHEST_SPEED = 480;

			/**
			 * @brief Static definition to hold stopping speed for rover.
			 */
			static const int STOPPING_SPEED = 0;

			/**
			 * @brief Constructor for RoverDriving class.
			 */
			RoverDriving();

			/**
			 * @brief Initializes wiringPi library and Analog to Digital Converter to start driving the rover.
			 */
			void initialize();

			/**
			 * @brief Commands the rover to stop.
			 */
			void stopRover();

			/**
			 * @brief Sets the speed. 360 -> Lowest speed (RoverDriving::LOWEST_SPEED), 480 -> Highest speed (RoverDriving::HIGHEST_SPEED)
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

	};
}


#endif /* API_ROVER_DRIVING_HPP_ */
