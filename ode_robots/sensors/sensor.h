/***************************************************************************
 *   Copyright (C) 2005 by Robot Group Leipzig                             *
 *    martius@informatik.uni-leipzig.de                                    *
 *    fhesse@informatik.uni-leipzig.de                                     *
 *    der@informatik.uni-leipzig.de                                        *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 *                                                                         *
 *   $Log$
 *   Revision 1.1  2006-08-08 11:59:01  martius
 *   new abstract class for sensors
 *
 *   Revision 1.1  2005/11/22 10:24:04  martius
 *   abstract class for position sensor
 *
 *                                                                         *
 ***************************************************************************/
#ifndef __SENSOR_H
#define __SENSOR_H

#include <list>
#include <selforg/types.h>
#include "pos.h"

namespace lpzrobots {

  // forward declaration 
  class Primitive;

  /** Abstract class for sensors 
      that have no specific position at the robots skeleton  
  */
  class Sensor {
  public:  
    Sensor() {}
    virtual ~Sensor() {}
  
    /** initialises sensor with body of robot. This is usually done by the robot itself.
    */
    virtual void init(Primitive* own) = 0;  
  
    /** performs sense action
     */
    virtual bool sense(const GlobalData& globaldata) = 0;

    /** returns the number of sensors values produced by this sensor
     */
    virtual int getSensorNumber() const  = 0;

    /** returns a list of sensor values (usually in the range [0,1] )
     */
    virtual std::list<sensor> get() const  = 0;

    /** writes the sensor values (usually in the range [0,1] ) 
	into the giben sensor array and returns the number of sensors written
	@param sensors call by refernce array which received the values
	@param length capacity of sensors array
	@return number of sensor values written
     */
    virtual int get(sensor* sensors, int length) const  = 0;

  };

}

#endif