/*
 * Copyright (c) 2017 FH Dortmund and others
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Description:
 *    Rover Gpio API - Interfaces for Rover general purpose I/O application development - Header file
 *
 * Contributors:
 *    M.Ozcelikors <mozcelikors@gmail.com>, created API 17.11.2017
 *
 */

#ifndef API_ROVER_GPIO_HPP_
#define API_ROVER_GPIO_HPP_

#include <api/rover_api.hpp>

namespace rover
{
	class RoverGpio : public RoverBase
	{
		public:
			void initialize();
			void setBuzzerOn();
			void setBuzzerOff();
			void setBuzzerTone(int tone_freq);
			void readUserButtonState();
	};
}



#endif /* API_ROVER_GPIO_HPP_ */
